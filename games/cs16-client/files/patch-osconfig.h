--- 3rdparty/ReGameDLL_CS/regamedll/engine/osconfig.h	2026-07-02 10:40:48.802296000 +0300
+++ 3rdparty/ReGameDLL_CS/regamedll/engine/osconfig.h	2026-07-02 09:15:30.842775000 +0300
@@ -88,10 +88,10 @@
 	#include <sys/stat.h>
 	#include <sys/time.h>
 	#include <sys/types.h>
-#if !defined(__APPLE__)
-	#include <sys/sysinfo.h>
-#else
-	#include <sys/sysctl.h>
+#if defined(__linux__)
+    #include <sys/sysinfo.h>
+#elif defined(__APPLE__) || defined(__FreeBSD__)
+    #include <sys/sysctl.h>
 #endif
 	#include <unistd.h>
 #endif // _WIN32