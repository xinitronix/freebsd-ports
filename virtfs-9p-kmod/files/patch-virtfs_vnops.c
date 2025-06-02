--- sys/dev/virtio/9pfs/virtfs_vnops.c.orig	2022-03-23 16:18:44.000000000 +0300
+++ sys/dev/virtio/9pfs/virtfs_vnops.c	2025-06-02 13:18:44.184288000 +0300
@@ -285,7 +285,7 @@
 			error = VOP_ACCESS(dvp, VWRITE, cnp->cn_cred,
 			    curthread);
 			if (!error) {
-				cnp->cn_flags |= SAVENAME;
+				cnp->cn_flags |= RENAME;
 				return (EJUSTRETURN);
 			}
 		}
@@ -305,7 +305,7 @@
 		if ((virtfs_node_cmp(vp, &newfid->qid) == 0) &&
 		    ((error = VOP_GETATTR(vp, &vattr, cnp->cn_cred)) == 0)) {
 			if (cnp->cn_nameiop != LOOKUP && (flags & ISLASTCN))
-				cnp->cn_flags |= SAVENAME;
+				cnp->cn_flags |= RENAME;
 			goto out;
 		}
 		/*
@@ -440,7 +440,7 @@
 	cnp->cn_nameptr[cnp->cn_namelen] = tmpchr;
 
 	if (cnp->cn_nameiop != LOOKUP && (flags & ISLASTCN))
-		cnp->cn_flags |= SAVENAME;
+		cnp->cn_flags |= RENAME;
 
 	/* Store the result the cache if MAKEENTRY is specified in flags */
 	if ((cnp->cn_flags & MAKEENTRY) != 0)
