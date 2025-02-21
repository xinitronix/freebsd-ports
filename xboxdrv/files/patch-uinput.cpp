--- src/uinput.cpp.orig	2025-02-15 04:46:31.000000000 +0300
+++ src/uinput.cpp	2025-02-21 05:02:07.837497000 +0300
@@ -24,7 +24,7 @@
 #include <iostream>
 #include <memory>
 #include <stdexcept>
-
+#include	<unistd.h>
 #include "helper.hpp"
 #include "log.hpp"
 #include "raise_exception.hpp"