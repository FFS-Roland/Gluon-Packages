include $(TOPDIR)/rules.mk

PKG_NAME:=ffs-set-segment
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(TOPDIR)/../package/gluon.mk

PKG_CONFIG_DEPENDS += $(GLUON_I18N_CONFIG)


define Package/ffs-set-segment
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Modify fastd config for setting correct segment
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ffs-set-segment/install
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/etc/init.d/ffs-set-segment $(1)/etc/init.d/ffs-set-segment
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) ./files/usr/sbin/ffs-set-segment $(1)/usr/sbin/ffs-set-segment
	$(INSTALL_DIR) $(1)/usr/lib/micron.d
	$(INSTALL_BIN) ./files/usr/lib/micron.d/ffs-set-segment $(1)/usr/lib/micron.d/ffs-set-segment
endef

$(eval $(call BuildPackage,ffs-set-segment))
