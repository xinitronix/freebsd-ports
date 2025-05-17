--- shared/xalloc.h.orig	2025-04-29 11:35:46.000000000 +0300
+++ shared/xalloc.h	2025-05-17 01:33:34.979127000 +0300
@@ -39,6 +39,12 @@
 static inline void *
 abort_oom_if_null(void *p)
 {
+
+#ifndef __GLIBC__
+ const char *program_invocation_short_name = getprogname();
+#endif
+
+
 	static const char oommsg[] = ": out of memory\n";
 	size_t written __attribute__((unused));
 
