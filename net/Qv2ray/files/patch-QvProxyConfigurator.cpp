---src/components/proxy/QvProxyConfigurator.cpp.orig	2025-07-15 14:53:30.947210000 +0300
+++ src/components/proxy/QvProxyConfigurator.cpp	2025-07-15 14:54:24.262404000 +0300
@@ -807,7 +807,7 @@
         }
 
         __QueryProxyOptions();
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_FREEBSD)
         QList<ProcessArgument> actions;
         actions << ProcessArgument{ "gsettings", { "set", "org.gnome.system.proxy", "mode", "manual" } };
         //
@@ -942,7 +942,7 @@
         {
             LOG("Failed to clear proxy.");
         }
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_FREEBSD)
         QList<ProcessArgument> actions;
         const bool isKDE = qEnvironmentVariable("XDG_SESSION_DESKTOP") == "KDE" || qEnvironmentVariable("XDG_SESSION_DESKTOP") == "plasma";
         const auto configRoot = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
