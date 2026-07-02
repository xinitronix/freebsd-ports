--- common/interface.cpp	2026-07-02 10:40:04.228707000 +0300
+++ common/interface.cpp	2026-07-02 09:01:23.528961000 +0300
@@ -14,7 +14,7 @@
 #include <unistd.h>
 #define VRTLD_LIBDL_COMPAT
 #include <vrtld.h>
-#elif XASH_APPLE == 1
+#elif !defined(_WIN32)
 #include <dlfcn.h>
 #include <unistd.h>
 #endif