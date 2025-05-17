--- clients/touch-calibrator.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ clients/touch-calibrator.c	2025-05-17 05:04:43.125707000 +0300
@@ -868,6 +868,11 @@
 static void
 pr_err(const char *fmt, ...)
 {
+
+#ifndef __GLIBC__
+ const char *program_invocation_short_name = getprogname();
+#endif
+
 	va_list argp;
 
 	va_start(argp, fmt);
@@ -879,6 +884,11 @@
 static void
 help(void)
 {
+
+#ifndef __GLIBC__
+ const char *program_invocation_short_name = getprogname();
+#endif
+
 	fprintf(stderr, "Compute a touchscreen calibration matrix for "
 		"a Wayland compositor by\n"
 		"having the user touch points on the screen.\n\n");
