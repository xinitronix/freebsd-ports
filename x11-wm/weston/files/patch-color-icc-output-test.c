--- tests/color-icc-output-test.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ tests/color-icc-output-test.c	2025-05-17 05:22:36.992040000 +0300
@@ -29,7 +29,11 @@
 #include <math.h>
 #include <string.h>
 #include <stdio.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#else
+#include <sys/param.h>
+#endif
 
 #include <lcms2.h>
 
