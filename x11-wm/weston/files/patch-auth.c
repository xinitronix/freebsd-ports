--- libweston/auth.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ libweston/auth.c	2025-05-17 01:39:58.331799000 +0300
@@ -32,7 +32,7 @@
 #ifdef HAVE_PAM
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+
 
 static int
 weston_pam_conv(int num_msg, const struct pam_message **msg,
