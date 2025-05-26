--- externlibs/curl/lib/getdate.c.orig	2025-05-09 05:17:34.000000000 +0300
+++ externlibs/curl/lib/getdate.c	2025-05-26 11:17:06.858624000 +0300
@@ -41,9 +41,11 @@
 
 #include "setup.h"
 
-# ifdef HAVE_ALLOCA_H
-#  include <alloca.h>
-# endif
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
+ #include <alloca.h>
+#endif
 
 # ifdef HAVE_TIME_H
 #  include <time.h>
