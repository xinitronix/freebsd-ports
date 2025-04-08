PORTNAME=	valfaris
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-valfaris/releases/download/v0.0.1/
DISTNAME=	valfaris
PKGNAMEPREFIX=	wine-
COMMENT=        game GOG version "Iron Meat"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	valfaris


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/valfaris  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                              ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r valfaris    ${STAGEDIR}${PREFIX}/share/GOG
	cp files/valfaris.desktop             ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
