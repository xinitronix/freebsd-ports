--- src/components/latency/TCPing.cpp.orig	2025-07-15 14:33:25.198559000 +0300
+++ src/components/latency/TCPing.cpp	2025-07-15 14:44:47.771263000 +0300
@@ -26,9 +26,9 @@
 #define TCP_MAXRT 5
 #endif
         setsockopt(fd, IPPROTO_TCP, TCP_MAXRT, (char *) &conn_timeout_sec, sizeof(conn_timeout_sec));
-#elif defined(__APPLE__)
+#elif defined(__FreeBSD__)
         // (billhoo) MacOS uses TCP_CONNECTIONTIMEOUT to do so.
-        setsockopt(fd, IPPROTO_TCP, TCP_CONNECTIONTIMEOUT, (char *) &conn_timeout_sec, sizeof(conn_timeout_sec));
+        setsockopt(fd, IPPROTO_TCP, TCP_KEEPINIT, (char *) &conn_timeout_sec, sizeof(conn_timeout_sec));
 #else // Linux like systems
         uint32_t conn_timeout_ms = conn_timeout_sec * 1000;
         setsockopt(fd, IPPROTO_TCP, TCP_USER_TIMEOUT, (char *) &conn_timeout_ms, sizeof(conn_timeout_ms));
