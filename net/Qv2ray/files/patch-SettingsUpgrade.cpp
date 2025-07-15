--- src/core/settings/SettingsUpgrade.cpp.orig	2025-07-15 14:57:07.205626000 +0300
+++ src/core/settings/SettingsUpgrade.cpp	2025-07-15 14:57:50.557437000 +0300
@@ -172,7 +172,7 @@
             case 9:
             {
                 QJsonObject kernelConfig;
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_FREEBSD
 #define _VARNAME_VCOREPATH_ kernelConfig["v2CorePath_linux"]
 #define _VARNAME_VASSETSPATH_ kernelConfig["v2AssetsPath_linux"]
                 UPGRADELOG("Update kernel and assets paths for linux");
