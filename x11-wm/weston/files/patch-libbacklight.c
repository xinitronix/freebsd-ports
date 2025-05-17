--- libweston/backend-drm/libbacklight.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ libweston/backend-drm/libbacklight.c	2025-05-17 04:28:07.328241000 +0300
@@ -36,7 +36,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#ifdef __linux__
 #include <linux/types.h>
+#include <malloc.h>
+#elif __FreeBSD__
+#include <libgen.h>
+#endif
 #include <dirent.h>
 #include <drm.h>
 #include <fcntl.h>
