--- tools/zunitc/src/zunitc_impl.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ tools/zunitc/src/zunitc_impl.c	2025-05-17 05:15:52.023633000 +0300
@@ -37,6 +37,12 @@
 #include <time.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/signal.h>
+#include <signal.h>
+#include <libgen.h>
+#endif
+
 #include "zunitc/zunitc_impl.h"
 #include "zunitc/zunitc.h"
 
