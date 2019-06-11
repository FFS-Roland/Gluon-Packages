include $(TOPDIR)/rules.mk

PKG_NAME:=ffs-lowmem-patches
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(TOPDIR)/../package/gluon.mk

PKG_CONFIG_DEPENDS += $(GLUON_I18N_CONFIG)


define Package/ffs-lowmem-patches
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Patch files for FFS routers with only 32mb ram
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ffs-lowmem-patches/install
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/etc/init.d/ffs-lowmem $(1)/etc/init.d/ffs-lowmem
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) ./files/usr/sbin/ffs-lowmem $(1)/usr/sbin/ffs-lowmem
endef

$(eval $(call BuildPackage,ffs-lowmem-patches))
