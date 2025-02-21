--- src/buttonevent/exec_button_event_handler.cpp.orig	2025-02-15 04:46:31.000000000 +0300
+++ src/buttonevent/exec_button_event_handler.cpp	2025-02-21 04:54:31.032855000 +0300
@@ -19,7 +19,7 @@
 #include "exec_button_event_handler.hpp"
 
 #include <sys/wait.h>
-
+#include	<unistd.h>
 #include <cerrno>
 #include <cstring>
 
