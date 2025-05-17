--- libweston/linux-sync-file-uapi.horig	1970-01-01 03:00:00.000000000 +0300
+++ libweston/linux-sync-file-uapi.h	2025-05-17 01:55:07.437433000 +0300
@@ -0,0 +1,30 @@
+/* Sync file Linux kernel UAPI */
+
+#ifndef WESTON_LINUX_SYNC_FILE_UAPI_H
+#define WESTON_LINUX_SYNC_FILE_UAPI_H
+
+
+#include <linux/types.h>
+
+struct sync_fence_info {
+	char obj_name[32];
+	char driver_name[32];
+	__s32 status;
+	__u32 flags;
+	__u64 timestamp_ns;
+};
+
+struct sync_file_info {
+	char name[32];
+	__s32 status;
+	__u32 flags;
+	__u32 num_fences;
+	__u32 pad;
+
+	__u64 sync_fence_info;
+};
+
+#define SYNC_IOC_MAGIC '>'
+#define SYNC_IOC_FILE_INFO _IOWR(SYNC_IOC_MAGIC, 4, struct sync_file_info)
+
+#endif /* WESTON_LINUX_SYNC_FILE_UAPI_H */
