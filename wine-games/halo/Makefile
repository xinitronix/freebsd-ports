PORTNAME=	halo
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/halo/ 
DISTNAME=	Halo
PKGNAMEPREFIX=	wine-
COMMENT=        game  "rFactor" wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

CHROME_VER?=	v0.0.1

SUB_FILES=	halo

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/halo             ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${CP} -r  Halo              ${STAGEDIR}${PREFIX}/share/
	cp files/halo.png                            ${STAGEDIR}${PREFIX}/share/pixmaps
	cp files/halo.desktop                        ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
