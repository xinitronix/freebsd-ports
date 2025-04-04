--- src/src.pro.orig	2021-02-04 16:15:38.000000000 +0300
+++ src/src.pro	2025-04-04 10:25:15.116677000 +0300
@@ -16,13 +16,13 @@
 
 !system($$PWD/translations/generate_translations_pm.sh): error("Failed to generate pm")
 qm_files.files = translations/*.qm
-qm_files.path = /usr/share/kylin-video/translations/
+qm_files.path = /usr/local/share/kylin-video/translations/
 inst1.files += res/kylin-video.png
-inst1.path = /usr/share/pixmaps
+inst1.path = /usr/local/share/pixmaps
 inst2.files += ../kylin-video.desktop
-inst2.path = /usr/share/applications
+inst2.path = /usr/local/share/applications
 target.source  += $$TARGET
-target.path = /usr/bin
+target.path = /usr/local/bin
 INSTALLS += inst1 \
     inst2 \
     qm_files \
