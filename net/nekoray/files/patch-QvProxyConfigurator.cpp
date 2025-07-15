--- 3rdparty/qv2ray/v2/components/proxy/QvProxyConfigurator.cpp.orig	2025-07-15 10:04:16.841428000 +0300
+++ 3rdparty/qv2ray/v2/components/proxy/QvProxyConfigurator.cpp	2025-07-15 10:05:18.296449000 +0300
@@ -271,7 +271,7 @@
         }
 
         __QueryProxyOptions();
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_FREEBSD)
         QList<ProcessArgument> actions;
         actions << ProcessArgument{"gsettings", {"set", "org.gnome.system.proxy", "mode", "manual"}};
         //
@@ -388,7 +388,7 @@
         if (!__SetProxyOptions(nullptr, false)) {
             LOG("Failed to clear proxy.");
         }
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_FREEBSD)
         QList<ProcessArgument> actions;
         const bool isKDE = qEnvironmentVariable("XDG_SESSION_DESKTOP") == "KDE" ||
                            qEnvironmentVariable("XDG_SESSION_DESKTOP") == "plasma";
