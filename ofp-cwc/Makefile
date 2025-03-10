PORTNAME=	flashpoint
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/flashpoint/
DISTNAME=	flashpoint
PKGNAMEPREFIX=	wine-
COMMENT=        game   "Operation Flashpoint: Cold War Crisis" wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	flashpoint

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/flashpoint  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                ${STAGEDIR}${PREFIX}/share/
	cd ${WRKSRC}/ && ${CP} -r flashpoint    ${STAGEDIR}${PREFIX}/share/
	chmod -R 0776                           ${STAGEDIR}${PREFIX}/share/flashpoint/Users
	cp  files/flashpoint.png                ${STAGEDIR}${PREFIX}/share/pixmaps
	cp "files/flashpoint.desktop"           ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
