include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-config-mode-plz
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)
PKG_BUILD_DEPENDS := respondd

include $(TOPDIR)/../package/gluon.mk

PKG_CONFIG_DEPENDS += $(GLUON_I18N_CONFIG)


define Package/gluon-config-mode-zip
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Set ZIP-Code location of a node
  DEPENDS:=+gluon-config-mode-core +gluon-node-info
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Configure
endef

define Build/Compile
	$(call Build/Compile/Default)
	$(call GluonBuildI18N,gluon-config-mode-zip,i18n)
	$(call GluonSrcDiet,./luasrc,$(PKG_BUILD_DIR)/luadest/)
endef

define Package/gluon-config-mode-zip/install
	$(INSTALL_DIR) $(1)/usr/lib/respondd
	$(CP) $(PKG_BUILD_DIR)/respondd.so $(1)/usr/lib/respondd/node-info-zip.so
	
	$(CP) $(PKG_BUILD_DIR)/luadest/* $(1)/
	$(call GluonInstallI18N,gluon-config-mode-zip,$(1))
endef

$(eval $(call BuildPackage,gluon-config-mode-zip))
