--- src/rtl_sdr_fm.cpp.orig	2024-12-14 07:39:21.000000000 +0300
+++ src/rtl_sdr_fm.cpp	2024-12-31 06:31:02.717294000 +0300
@@ -30,6 +30,10 @@
 #include <queue>
 #include <rtl-sdr.h>
 #include "dsd.h"
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 
 #define DEFAULT_SAMPLE_RATE		48000
 #define DEFAULT_BUF_LENGTH		(1 * 16384)
