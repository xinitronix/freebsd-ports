--- src/base/settings.cpp	2025-12-02 18:12:03.011684000 +0300
+++ src/base/settings.cpp.orig	2025-01-18 23:52:29.000000000 +0300
@@ -252,7 +252,7 @@
     const int defaultSize = 11;
 #elif defined(Q_OS_MACOS)
     const int defaultSize = 12;
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_FREEBSD)
     const int defaultSize = 10;
 #endif
     return settings->value("CodeEditor/FontSize", defaultSize).toInt();
