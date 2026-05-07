PORTNAME=	vmm
PORTVERSION=	15
CATEGORIES=	sysutils

COMMENT=	vmm.ko module for gpu passthrough windows

MASTER_SITES=	https://github.com/definitly486/definitly486/releases/download/vmm/

KERNBRANCH!=	uname  -v | awk '{print $$3}'

.if ${KERNBRANCH:Mreleng/15.1*}
DISTNAME=	vmm_win_releng_FreeBSD15.1
.elif ${KERNBRANCH:Mstable/15*}
DISTNAME=	vmm_win_FreeBSD15
.else
DISTNAME=	vmm_win_FreeBSD15
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/winbox
	${INSTALL_DATA} \
		${WRKSRC}/${DISTNAME}.ko \
		${STAGEDIR}${PREFIX}/etc/winbox/vmm.ko

.include <bsd.port.mk>