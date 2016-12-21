/*
  Copyright (c) 2016, Matthias Schiffer <mschiffer@universe-factory.net> and Philippe Käufer <freifunk@philhil.de>
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include <respondd.h>

#include <json-c/json.h>
#include <libgluonutil.h>

#include <uci.h>

#include <stdlib.h>
#include <string.h>


static struct uci_section * get_first_section(struct uci_package *p, const char *type) {
	struct uci_element *e;
	uci_foreach_element(&p->sections, e) {
		struct uci_section *s = uci_to_section(e);
		if (!strcmp(s->type, type))
			return s;
	}

	return NULL;
}

static struct json_object * get_number(struct uci_context *ctx, struct uci_section *s, const char *name) {
	const char *val = uci_lookup_option_string(ctx, s, name);
	if (!val || !*val)
		return NULL;

	char *end;
	double d = strtod(val, &end);
	if (*end)
		return NULL;

	struct json_object *jso = json_object_new_double(d);
	json_object_set_serializer(jso, json_object_double_to_json_string, "%.8f", NULL);
	return jso;
}

static void maybe_add_number(struct uci_context *ctx, struct uci_section *s, const char *name, struct json_object *parent) {
	struct json_object *jso = get_number(ctx, s, name);
	if (jso)
		json_object_object_add(parent, name, jso);
}

static struct json_object * get_location(struct uci_context *ctx, struct uci_package *p) {
	struct uci_section *s = get_first_section(p, "location");
	if (!s)
		return NULL;

	struct json_object *ret = json_object_new_object();

	maybe_add_number(ctx, s, "zip", ret);

	return ret;
}

static struct json_object * respondd_provider_nodeinfo_zip(void) {
	struct json_object *ret = json_object_new_object();

	struct uci_context *ctx = uci_alloc_context();
	ctx->flags &= ~UCI_FLAG_STRICT;

	struct uci_package *p;
	if (!uci_load(ctx, "gluon-node-info", &p)) {
		struct json_object *location = get_location(ctx, p);
		if (location)
			json_object_object_add(ret, "location", location);
	}

	uci_free_context(ctx);

	return ret;
}


const struct respondd_provider_info respondd_providers[] = {
	{"nodeinfo-zip", respondd_provider_nodeinfo_zip},
	{}
};
