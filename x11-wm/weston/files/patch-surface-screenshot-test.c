--- tests/surface-screenshot-test.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ tests/surface-screenshot-test.c	2025-05-17 05:18:14.302071000 +0300
@@ -33,6 +33,10 @@
 #include <errno.h>
 #include <linux/input.h>
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 #include <libweston/libweston.h>
 #include "compositor/weston.h"
 #include "shared/file-util.h"
