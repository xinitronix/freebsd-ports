--- src/components/latency/unix/ICMPPing.cpp.orig	2025-07-15 14:27:05.594920000 +0300
+++ src/components/latency/unix/ICMPPing.cpp	2025-07-15 14:28:15.777453000 +0300
@@ -62,7 +62,7 @@
             return;
         }
         // set TTL
-        if (setsockopt(socketId, SOL_IP, IP_TTL, &ttl, sizeof(ttl)) != 0)
+        if (setsockopt(socketId, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0)
         {
             data.errorMessage = "EPING_TTL: " + QObject::tr("Failed to setup TTL value");
             data.avg = LATENCY_TEST_VALUE_ERROR;
