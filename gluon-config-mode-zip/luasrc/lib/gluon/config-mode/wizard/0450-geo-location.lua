
return function(form, uci)
    local location = uci:get_first("gluon-node-info", "location")
    local site_i18n = i18n 'gluon-site'
    local text = site_i18n.translate("gluon-config-mode:zip-help")
    
    local s = form:section(Section, nil, text)

    local o = s:option(Value, "zip", site_i18n.translate("ZIP-Code"), site_i18n.translatef("e.g. %s", "70499"))
    o.default = uci:get("gluon-node-info", location, "zip")
    o.datatype = "uinteger"
    o.optional = true
    function o:write(data)
        uci:set("gluon-node-info", location, "zip", data)
    end
    
    return {'gluon-node-info'}
end
