--- libweston/compositor.c.orig	2025-04-29 11:35:46.000000000 +0300
+++ libweston/compositor.c	2025-05-17 01:53:01.764303000 +0300
@@ -8735,7 +8735,7 @@
 {
 	/* In order of preference */
 	static const clockid_t clocks[] = {
-		CLOCK_MONOTONIC_RAW,	/* no jumps, no crawling */
+		CLOCK_MONOTONIC_FAST,	/* no jumps, no crawling */
 		CLOCK_MONOTONIC_COARSE,	/* no jumps, may crawl, fast & coarse */
 		CLOCK_MONOTONIC,	/* no jumps, may crawl */
 	};
