--- itpp/comm/siso_dem.cpp.orig	2013-07-06 13:11:56.000000000 +0400
+++ itpp/comm/siso_dem.cpp	2025-01-21 16:22:28.700164000 +0300
@@ -31,7 +31,7 @@
 #ifndef INFINITY
 #define INFINITY std::numeric_limits<double>::infinity()
 #endif
-
+#define register
 namespace itpp
 {
 void SISO::find_half_const(int &select_half, itpp::vec &re_part, itpp::bmat &re_bin_part, itpp::vec &im_part, itpp::bmat &im_bin_part)
--- itpp/comm/siso.h.orig	2013-07-06 13:11:56.000000000 +0400
+++ itpp/comm/siso.h	2025-01-21 16:22:45.052280000 +0300
@@ -31,7 +31,7 @@
 
 #include <itpp/itbase.h> //IT++ base module
 #include <itpp/itexports.h>
-
+#define register
 namespace itpp
 {
 
--- itpp/comm/stc.cpp.orig	2013-07-06 13:11:56.000000000 +0400
+++ itpp/comm/stc.cpp	2025-01-21 16:24:10.129135000 +0300
@@ -27,7 +27,7 @@
  */
 
 #include <itpp/comm/stc.h>
-
+#define register
 namespace itpp
 {
 
