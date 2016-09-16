include $(TOPDIR)/rules.mk

PKG_NAME:=ffrn-experimental-to-stable
PKG_VERSION:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(GLUONDIR)/include/package.mk

define Package/ffrn-experimental-to-stable
  SECTION:=gluon
  CATEGORY:=Gluon
  TITLE:=Move nodes from experimental to stable
endef

define Build/Preparedd
	mkdir -p $(PKG_BUILD_DIR)
endef

define Package/ffrn-experimental-to-stable/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) ./files/usr/sbin/ets $(1)/usr/sbin/ets
endef

$(eval $(call BuildPackage,ffrn-experimental-to-stable))
