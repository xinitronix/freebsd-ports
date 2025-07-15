--- src/ui/common/autolaunch/QvAutoLaunch.cpp.orig	2025-07-15 15:02:03.682096000 +0300
+++ src/ui/common/autolaunch/QvAutoLaunch.cpp	2025-07-15 15:03:07.022096000 +0300
@@ -81,7 +81,7 @@
         return returnValue;
     }
 
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_FREEBSD
         QString appName = QCoreApplication::applicationName();
         QString desktopFileLocation = getUserAutostartDir_private() + appName + QLatin1String(".desktop");
         return QFile::exists(desktopFileLocation);
@@ -156,7 +156,7 @@
         CFRelease(urlRef);
     }
 
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_FREEBSD
         //
         // For AppImage packaging.
         auto binPath = qEnvironmentVariableIsSet("APPIMAGE") ? qEnvironmentVariable("APPIMAGE") : QCoreApplication::applicationFilePath();
