PORTNAME=	ironmeat
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-ironmeat/releases/download/v0.0.1/
DISTNAME=	IronMeat
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

SUB_FILES=	ironmeat


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ironmeat  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                              ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r IronMeat ${STAGEDIR}${PREFIX}/share/GOG
	cp files/ironmeat.desktop ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
