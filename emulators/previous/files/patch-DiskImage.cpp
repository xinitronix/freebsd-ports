--- src/ditool/DiskImage.cpp.orig	2024-01-12 21:37:18.000000000 +0300
+++ src/ditool/DiskImage.cpp	2025-05-16 09:45:23.480519000 +0300
@@ -19,15 +19,10 @@
     extern "C" uint32_t htonl(uint32_t);
     extern "C" uint16_t htons(uint16_t);
 #else
-    #if HAVE_ARPA_INET_H
-        #include <arpa/inet.h>
-    #endif
-    #if HAVE_NETINET_IN_H
-        #include <netinet/in.h>
-    #endif
-    #if HAVE_WINSOCK_H
-        #include <winsock.h>
-    #endif
+    extern "C" uint32_t ntohl(uint32_t);
+    extern "C" uint16_t ntohs(uint16_t);
+    extern "C" uint32_t htonl(uint32_t);
+    extern "C" uint16_t htons(uint16_t);
 #endif
 
 using namespace std;
