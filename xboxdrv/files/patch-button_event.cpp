--- src/evdev_controller.cpp.orig	2025-02-15 04:46:31.000000000 +0300
+++ src/evdev_controller.cpp	2025-02-21 04:56:01.501369000 +0300
@@ -20,7 +20,7 @@
 
 #include <err.h>
 #include <fcntl.h>
-
+#include	<unistd.h>
 #include <algorithm>
 #include <cerrno>
 #include <cstdio>
