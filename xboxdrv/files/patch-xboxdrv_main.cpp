--- src/xboxdrv_main.cpp.orig	2025-02-15 04:46:31.000000000 +0300
+++ src/xboxdrv_main.cpp	2025-02-21 05:00:52.026990000 +0300
@@ -20,7 +20,7 @@
 
 #include <glib.h>
 #include <libusb.h>
-
+#include	<unistd.h>
 #include <cassert>
 #include <cstdio>
 #include <format>
