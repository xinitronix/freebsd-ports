--- libweston/backend-x11/x11.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ libweston/backend-x11/x11.c	2025-05-17 04:37:55.636329000 +0300
@@ -37,6 +37,9 @@
 #include <errno.h>
 #include <sys/time.h>
 #include <sys/shm.h>
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
 #include <linux/input.h>
 
 #include <xcb/xcb.h>
