--- sys/dev/virtio/9pnet/trans_virtio.c.orig	2022-03-23 16:18:44.000000000 +0300
+++ sys/dev/virtio/9pnet/trans_virtio.c	2025-06-02 13:23:44.286817000 +0300
@@ -502,7 +502,6 @@
 	return (error);
 }
 
-DRIVER_MODULE(vt9p, virtio_pci, vt9p_drv, vt9p_class,
-    vt9p_modevent, 0);
+
 MODULE_VERSION(vt9p, 1);
 MODULE_DEPEND(vt9p, virtio, 1, 1, 1);
