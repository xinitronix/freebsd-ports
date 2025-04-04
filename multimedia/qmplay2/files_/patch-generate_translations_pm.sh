--- src/translations/generate_translations_pm.sh.orig	2021-02-04 16:15:38.000000000 +0300
+++ src/translations/generate_translations_pm.sh	2025-04-04 08:34:37.914143000 +0300
@@ -1,8 +1,8 @@
-#! /bin/bash
+#! /usr/local/bin/bash
 
 ts_file_list=(`ls translations/*.ts`)
 
 for ts in "${ts_file_list[@]}"
 do
-	lrelease "${ts}"
+	/usr/local/lib/qt6/bin/lrelease "${ts}"
 done
