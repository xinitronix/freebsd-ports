--- src/base/models/QvSettingsObject.hpp.orig	2025-07-15 14:04:59.703191000 +0300
+++ src/base/models/QvSettingsObject.hpp	2025-07-15 14:06:03.318397000 +0300
@@ -89,7 +89,7 @@
         QString v2CorePath_win;
         QString v2AssetsPath_win;
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_FREEBSD
 #define _VARNAME_VCOREPATH_ v2CorePath_linux
 #define _VARNAME_VASSETSPATH_ v2AssetsPath_linux
 #elif defined(Q_OS_MACOS)
