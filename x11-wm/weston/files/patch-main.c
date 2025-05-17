--- compositor/main.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ compositor/main.c	2025-05-17 04:46:15.304017000 +0300
@@ -45,7 +45,11 @@
 #include <libevdev/libevdev.h>
 #include <linux/input.h>
 #include <sys/time.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#else
+#include <sys/param.h>
+#endif
 
 #include "weston.h"
 #include <libweston/libweston.h>
@@ -816,9 +820,25 @@
 	static const char *names[] = {
 		[CLOCK_REALTIME] =		"CLOCK_REALTIME",
 		[CLOCK_MONOTONIC] =		"CLOCK_MONOTONIC",
+		#ifdef __linux__
+
 		[CLOCK_MONOTONIC_RAW] =		"CLOCK_MONOTONIC_RAW",
+
 		[CLOCK_REALTIME_COARSE] =	"CLOCK_REALTIME_COARSE",
+
 		[CLOCK_MONOTONIC_COARSE] =	"CLOCK_MONOTONIC_COARSE",
+
+
+#elif __FreeBSD__
+
+
+		[CLOCK_REALTIME_FAST] =		"CLOCK_REALTIME_FAST",
+
+
+		[CLOCK_MONOTONIC_FAST] =	"CLOCK_MONOTONIC_FAST",
+
+
+#endif
 #ifdef CLOCK_BOOTTIME
 		[CLOCK_BOOTTIME] =		"CLOCK_BOOTTIME",
 #endif
