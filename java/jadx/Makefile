PORTNAME=	jadx
DISTVERSION=	1.5.6
CATEGORIES=     java
MASTER_SITES=   https://github.com/skylot/jadx/releases/download/v1.5.6/
DISTFILES=      jadx-1.5.6.zip




NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=	.zip

SUB_FILES=	jadx

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/jadx                                           ${STAGEDIR}${PREFIX}/bin
		mkdir -p                                                                   ${STAGEDIR}${PREFIX}/share/jadx
		cd ${WRKSRC}  && ${CP} -r *                                                ${STAGEDIR}${PREFIX}/share/jadx

.include <bsd.port.mk>