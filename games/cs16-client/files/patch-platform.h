--- 3rdparty/ReGameDLL_CS/regamedll/public/tier0/platform.h	2026-07-02 10:40:48.877073000 +0300
+++ 3rdparty/ReGameDLL_CS/regamedll/public/tier0/platform.h	2026-07-02 09:18:36.602146000 +0300
@@ -75,7 +75,7 @@
 // Can't use extern "C" when DLL exporting a global
 #define DLL_GLOBAL_EXPORT extern __declspec(dllexport)
 #define DLL_GLOBAL_IMPORT extern __declspec(dllimport)
-#elif defined __linux__ || defined __APPLE__
+#elif defined __linux__ || defined __APPLE__ || defined __FreeBSD__
 
 // Used for dll exporting and importing
 #define DLL_EXPORT extern "C"