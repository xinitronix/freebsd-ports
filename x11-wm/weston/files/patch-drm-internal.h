--- libweston/backend-drm/drm-internal.h.orig	2025-04-29 11:35:46.000000000 +0300
+++ libweston/backend-drm/drm-internal.h	2025-05-17 04:20:28.232326000 +0300
@@ -36,8 +36,9 @@
 #include <string.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <linux/input.h>
-#include <linux/vt.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#include <termios.h>
 #include <assert.h>
 #include <sys/mman.h>
 #include <time.h>
