--- shared/file-util.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ shared/file-util.c	2025-05-16 21:37:58.511379000 +0300
@@ -35,6 +35,10 @@
 
 #include "file-util.h"
 
+#ifndef ETIME
+#define ETIME 62
+#endif
+
 static int
 current_time_str(char *str, size_t len, const char *fmt)
 {
