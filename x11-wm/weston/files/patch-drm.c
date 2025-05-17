--- libweston/backend-drm/drm.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ libweston/backend-drm/drm.c	2025-05-17 04:24:19.996484000 +0300
@@ -37,7 +37,6 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <linux/input.h>
-#include <linux/vt.h>
 #include <assert.h>
 #include <sys/mman.h>
 #include <time.h>
