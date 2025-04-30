--- build.sh.orig	2024-11-20 14:11:17.000000000 +0300
+++ build.sh	2025-04-30 23:04:10.976216000 +0300
@@ -8,14 +8,7 @@
 		$use_auth $@
 	fi
 }
-for auth in doas sudo su; do
-	which $auth >/dev/null 2>&1
-	if [ "$?" = "0" ]; then
-		echo "$auth would work (probably)"
-		use_auth="$auth"
-		break
-	fi
-done
+
 for i in $@; do
 	case "$i" in
 		--prefix=*)
