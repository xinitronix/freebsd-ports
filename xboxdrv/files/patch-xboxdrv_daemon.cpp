--- src/xboxdrv_daemon.cpp.orig	2025-02-15 04:46:31.000000000 +0300
+++ src/xboxdrv_daemon.cpp	2025-02-21 04:57:24.853013000 +0300
@@ -21,7 +21,7 @@
 #include <dbus/dbus-glib-lowlevel.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus.h>
-
+#include	<unistd.h>
 #include <cassert>
 #include <cerrno>
 #include <cstring>
