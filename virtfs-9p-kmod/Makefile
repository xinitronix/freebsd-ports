PORTNAME=	virtfs-9p-kmod
DISTVERSION=	2025
DISTVERSIONSUFFIX=	-g572734c
CATEGORIES=	emulators 

USE_GITHUB=	yes
GH_ACCOUNT=	swills

do-build:
		cd  ${WRKSRC}/sys/modules/virtio/9pfs  && make  -j6 CWARNFLAGS="-Wno-incompatible-pointer-types-discards-qualifiers -Wno-pointer-sign -Wno-dangling-else"
		cd  ${WRKSRC}/sys/modules/virtio/9pnet  && make -j6 CWARNFLAGS="-Wno-incompatible-pointer-types-discards-qualifiers -Wno-pointer-sign -Wno-dangling-else"

do-install:
		mkdir  -p  ${STAGEDIR}/boot/modules
		cp  ${WRKSRC}/sys/modules/virtio/9pfs/virtio_9pfs.ko   ${STAGEDIR}/boot/modules
		cp  ${WRKSRC}/sys/modules/virtio/9pnet/virtio_9pnet.ko ${STAGEDIR}/boot/modules

.include <bsd.port.mk>