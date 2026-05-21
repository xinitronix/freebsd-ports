PORTNAME=	qemu_vmm
PORTVERSION=	16
CATEGORIES=	sysutils
COMMENT=        qemu accelerated with bhyve/vmm
MASTER_SITES=	https://github.com/definitly486/definitly486/releases/download/qemu_vmm/
DISTNAME=	qemu_vmm_16

EXTRACT_SUFX?=		.tar.xz
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	qemu_vmm


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/qemu_vmm  ${STAGEDIR}${PREFIX}/bin
		mkdir -p    ${STAGEDIR}${PREFIX}/share/qemu_vmm
		cd ${WRKSRC}/qemu_vmm_16 && ${CP} -r *   ${STAGEDIR}${PREFIX}/share/qemu_vmm


.include <bsd.port.mk>