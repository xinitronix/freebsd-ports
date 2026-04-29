PORTNAME=	vmm
PORTVERSION=	16
CATEGORIES=	sysutils
COMMENT=        vmm.ko module for gpu passthrough windows
MASTER_SITES=	https://github.com/definitly486/definitly486/releases/download/vmm/
DISTNAME=	vmm_win_FreeBSD16


NO_BUILD=	yes
NO_WRKSUBDIR=	yes


do-install:
		mkdir -p  ${STAGEDIR}${PREFIX}/etc/winbox
		cd ${WRKSRC}/ && ${CP} -r vmm_win_FreeBSD16.ko   ${STAGEDIR}${PREFIX}/etc/winbox/vmm.ko


.include <bsd.port.mk>