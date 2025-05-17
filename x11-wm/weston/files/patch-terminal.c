--- clients/terminal.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ clients/terminal.c	2025-05-17 04:58:47.144291000 +0300
@@ -33,14 +33,18 @@
 #include <unistd.h>
 #include <math.h>
 #include <time.h>
+#ifdef __linux__
 #include <pty.h>
+#elif __FreeBSD__
+#include <libutil.h>
+#endif
 #include <ctype.h>
 #include <cairo.h>
 #include <sys/epoll.h>
 #include <wchar.h>
 #include <locale.h>
 #include <errno.h>
-
+#include	<sys/ioctl.h>
 #include <linux/input.h>
 
 #include <wayland-client.h>
