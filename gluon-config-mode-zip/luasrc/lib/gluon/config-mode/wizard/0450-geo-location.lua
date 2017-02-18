local cbi = require "luci.cbi"
local i18n = require "luci.i18n"
local uci = luci.model.uci.cursor()

local M = {}

function M.section(form)
        local text = i18n.translate("gluon-config-mode:zip-help")
	local fieldlabel = i18n.translate("ZIP-Code")
        local s = form:section(cbi.SimpleSection, nil, text)

	local o = s:option(cbi.Value, "_zip", fieldlabel)
        o.value = uci:get_first("gluon-node-info", "location", "zip")
        o.rmempty = true
        o.datatype = "float"
        o.description = i18n.translatef("e.g. %s", "70499")
end

function M.handle(data)
        local sname = uci:get_first("gluon-node-info", "location")
        uci:set("gluon-node-info", sname, "zip", data._zip:trim())
        uci:save("gluon-node-info")
        uci:commit("gluon-node-info")  
   
end
        
return M
