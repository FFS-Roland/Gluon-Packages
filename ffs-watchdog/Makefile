include $(TOPDIR)/rules.mk

PKG_NAME:=ffs-watchdog
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(GLUONDIR)/include/package.mk

PKG_CONFIG_DEPENDS += $(GLUON_I18N_CONFIG)


define Package/ffs-watchdog
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Checking Node running correctly
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ffs-watchdog/install
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/etc/init.d/ffs-watchdog $(1)/etc/init.d/ffs-watchdog
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) ./files/usr/sbin/ffs-watchdog $(1)/usr/sbin/ffs-watchdog
	$(INSTALL_DIR) $(1)/usr/lib/micron.d
	$(INSTALL_BIN) ./files/usr/lib/micron.d/ffs-watchdog $(1)/usr/lib/micron.d/ffs-watchdog
endef

$(eval $(call BuildPackage,ffs-watchdog))
