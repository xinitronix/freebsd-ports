PORTNAME=	hollowknight
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/HollowKnight/
DISTNAME=	HollowKnight
PKGNAMEPREFIX=	wine-
COMMENT=        game GOG version "Hollow Knight"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	HollowKnight


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/HollowKnight  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                              ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r HollowKnight ${STAGEDIR}${PREFIX}/share/GOG
	cp files/HollowKnight.jpg      ${STAGEDIR}${PREFIX}/share/pixmaps
	cp files/HollowKnight.desktop ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
