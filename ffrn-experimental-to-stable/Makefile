include $(TOPDIR)/rules.mk

PKG_NAME:=ffrn-experimental-to-stable
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(GLUONDIR)/include/package.mk

PKG_CONFIG_DEPENDS += $(GLUON_I18N_CONFIG)


define Package/ffrn-experimental-to-stable
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Move nodes from experimental to stable
endef

define Build/Preparedd
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ffrn-lowmem-patches/install
$(INSTALL_BIN) ./files/tmp/ets $(1)/tmp/ets
endef

$(eval $(call BuildPackage,ffrn-experimental-to-stable))
