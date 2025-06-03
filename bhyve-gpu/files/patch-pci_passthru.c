--- bhyve/pci_passthru.c.orig	2025-06-03 08:42:05.000000000 +0300
+++ bhyve/pci_passthru.c	2025-06-03 09:09:23.900570000 +0300
@@ -75,6 +75,8 @@
 
 #define PASSTHRU_MMIO_MAX 2
 
+#define   PCI_VENDOR_NVIDIA       0x10DE
+
 static int pcifd = -1;
 static uint8_t *nvidia_bar0;
 
