PORTNAME=	rfactor
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/rFactor/ 
DISTNAME=	rFactor
PKGNAMEPREFIX=	wine-
COMMENT=        game  "rFactor" wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	rfactor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rfactor          ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${CP} -r  rFactor           ${STAGEDIR}${PREFIX}/share/
	cp files/rfactor.png                         ${STAGEDIR}${PREFIX}/share/pixmaps
	cp files/rfactor.desktop                     ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
