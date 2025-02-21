--- src/linux_uinput.cpp.orig	2025-02-15 04:46:31.000000000 +0300
+++ src/linux_uinput.cpp	2025-02-21 04:56:34.217684000 +0300
@@ -17,7 +17,7 @@
 */
 
 #include "linux_uinput.hpp"
-
+#include	<unistd.h>
 #include <fcntl.h>
 
 #include <cassert>
