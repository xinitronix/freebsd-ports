PORTNAME=	bdd-nes
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games emulators
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/bdd/
DISTNAME=	bdd-nes
PKGNAMEPREFIX=	
COMMENT=        game "Battletoads & Double Dragon: The Ultimate Team"  nes emulator
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	bdd-nes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bdd-nes   ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${CP} -r bdd-nes     ${STAGEDIR}${PREFIX}/share/
	${CP}  files/bdd.jpg       ${STAGEDIR}${PREFIX}/share/pixmaps
	${CP} files/bdd-nes.desktop             ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
