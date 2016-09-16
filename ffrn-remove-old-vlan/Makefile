include $(TOPDIR)/rules.mk

PKG_NAME:=ffrn-remove-old-vlan
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(GLUONDIR)/include/package.mk

define Package/ffrn-remove-old-vlan
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Remove old config parts surviving the upgrade to 0.5.12
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ffrn-remove-old-vlan/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) ./files/usr/sbin/dummy2 $(1)/usr/sbin/dummy2
endef

$(eval $(call BuildPackage,ffrn-remove-old-vlan))
