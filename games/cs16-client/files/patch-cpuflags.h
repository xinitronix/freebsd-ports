--- 3rdparty/yapb/ext/crlib/crlib/cpuflags.h.orig	2026-07-02 12:49:11.222244000 +0300
+++ 3rdparty/yapb/ext/crlib/crlib/cpuflags.h	2026-07-02 12:47:48.141966000 +0300
@@ -1,72 +1,90 @@
 //
 // crlib, simple class library for private needs.
 // Copyright © RWSH Solutions LLC <lab@rwsh.ru>.
-//
 // SPDX-License-Identifier: MIT
 //
 
 #pragma once
 
-#if (defined(CR_LINUX) || defined(CR_MACOS)) && !defined(CR_ARCH_NON_X86)
-#  include <cpuid.h>
-#elif defined(CR_WINDOWS) && !defined(CR_CXX_MSVC)
-#  include <cpuid.h>
+#include <cstdint>
+
+#if defined(__i386__) || defined(__x86_64__)
+
+  #if defined(_MSC_VER)
+    #include <intrin.h>
+  #elif defined(__GNUC__) || defined(__clang__)
+    #include <cpuid.h>
+  #endif
+
 #endif
 
-CR_DECLARE_SCOPED_ENUM (CpuCap,
-   SSE3 = cr::bit (0),
-   SSSE3 = cr::bit (9),
-   SSE41 = cr::bit (19),
-   SSE42 = cr::bit (20),
-   AVX = cr::bit (28),
-   AVX2 = cr::bit (5)
+
+CR_DECLARE_SCOPED_ENUM(CpuCap,
+   SSE3  = (1u << 0),
+   SSSE3 = (1u << 9),
+   SSE41 = (1u << 19),
+   SSE42 = (1u << 20),
+   AVX   = (1u << 28),
+   AVX2  = (1u << 5)
 )
 
 CR_NAMESPACE_BEGIN
 
-// cpu flags for current cpu
-class CpuFlags final : public Singleton <CpuFlags> {
+class CpuFlags final : public Singleton<CpuFlags> {
 public:
-   bool sse3 {}, ssse3 {}, sse41 {}, sse42 {}, avx {}, avx2 {}, neon {};
+   bool sse3{}, ssse3{}, sse41{}, sse42{}, avx{}, avx2{}, neon{};
 
 public:
-   CpuFlags () {
-      detect ();
-   }
+   CpuFlags() { detect(); }
+   ~CpuFlags() = default;
 
-   ~CpuFlags () = default;
-
 private:
-   void detect () {
-#if !defined(CR_ARCH_NON_X86)
-      enum { eax, ebx, ecx, edx, regs };
 
-      uint32_t data[regs] {};
+#if defined(__i386__) || defined(__x86_64__)
 
-#if defined(CR_WINDOWS) && defined(CR_CXX_MSVC)
-   __cpuidex (reinterpret_cast <int32_t *> (data), 1, 0);
-#elif !defined(CR_EMSCRIPTEN)
-      __get_cpuid (0x1, &data[eax], &data[ebx], &data[ecx], &data[edx]);
-#endif
-      sse3 = !!(data[ecx] & CpuCap::SSE3);
-      ssse3 = !!(data[ecx] & CpuCap::SSSE3);
-      sse41 = !!(data[ecx] & CpuCap::SSE41);
-      sse42 = !!(data[ecx] & CpuCap::SSE42);
-      avx = !!(data[ecx] & CpuCap::AVX);
+   static inline void cpuid(uint32_t leaf, uint32_t subleaf,
+                            uint32_t &a, uint32_t &b,
+                            uint32_t &c, uint32_t &d)
+   {
+   #if defined(_MSC_VER)
+      int regs[4];
+      __cpuidex(regs, (int)leaf, (int)subleaf);
+      a = regs[0]; b = regs[1]; c = regs[2]; d = regs[3];
+   #else
+      __cpuid_count(leaf, subleaf, a, b, c, d);
+   #endif
+   }
 
-#if defined(CR_WINDOWS) && defined(CR_CXX_MSVC)
-      __cpuidex (reinterpret_cast <int32_t *> (data), 7, 0);
-#elif !defined(CR_EMSCRIPTEN)
-      __get_cpuid (0x7, &data[eax], &data[ebx], &data[ecx], &data[edx]);
 #endif
-      avx2 = !!(data[ebx] & CpuCap::AVX2);
-#elif defined(CR_ARCH_ARM)
+
+   void detect() {
+#if defined(__i386__) || defined(__x86_64__)
+
+      uint32_t a = 0, b = 0, c = 0, d = 0;
+
+      // Leaf 1
+      cpuid(1, 0, a, b, c, d);
+
+      sse3  = c & (1u << 0);
+      ssse3 = c & (1u << 9);
+      sse41 = c & (1u << 19);
+      sse42 = c & (1u << 20);
+      avx   = c & (1u << 28);
+
+      // Leaf 7
+      cpuid(7, 0, a, b, c, d);
+
+      avx2  = b & (1u << 5);
+
+#elif defined(__arm__) || defined(__aarch64__)
+
       neon = true;
+
 #endif
    }
 };
 
-// expose platform singleton
-CR_EXPOSE_GLOBAL_SINGLETON (CpuFlags, cpuflags);
+// global singleton
+CR_EXPOSE_GLOBAL_SINGLETON(CpuFlags, cpuflags);
 
-CR_NAMESPACE_END
+CR_NAMESPACE_END
\ No newline at end of file
