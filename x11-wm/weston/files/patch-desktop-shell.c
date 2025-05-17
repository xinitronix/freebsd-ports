--- clients/desktop-shell.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ clients/desktop-shell.c	2025-05-17 05:07:11.663108000 +0300
@@ -1168,6 +1168,11 @@
 static struct background *
 background_create(struct desktop *desktop, struct output *output)
 {
+
+#ifndef __GLIBC__
+ const char *program_invocation_short_name = getprogname();
+#endif
+
 	struct background *background;
 	struct weston_config_section *s;
 	char *type;
