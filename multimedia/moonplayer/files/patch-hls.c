--- 3rdparty/hlsdl/src/hls.c.orig	2021-04-19 22:53:34.000000000 +0300
+++ 3rdparty/hlsdl/src/hls.c	2025-04-04 13:48:56.088061000 +0300
@@ -7,7 +7,7 @@
 #include <time.h>
 
 #ifndef _MSC_VER
-#if !defined(__APPLE__) && !defined(__MINGW32__) && !defined(__CYGWIN__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__CYGWIN__)
 #include <sys/prctl.h>
 #endif
 #include <unistd.h>
@@ -1162,7 +1162,7 @@
     char threadname[50];
     strncpy(threadname, __func__, sizeof(threadname));
     threadname[49] = '\0';
-#if !defined(__APPLE__) && !defined(__MINGW32__) && !defined(__CYGWIN__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__CYGWIN__)
     prctl(PR_SET_NAME, (unsigned long)&threadname);
 #endif
 #endif
