PORTNAME=	js-nes
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games emulators
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/JungleStrike/
DISTNAME=	js-nes
PKGNAMEPREFIX=	
COMMENT=        game Jungle Strike nes emulator
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	js-nes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/js-nes   ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${CP} -r js-nes     ${STAGEDIR}${PREFIX}/share/
	${CP}  files/js.jpg       ${STAGEDIR}${PREFIX}/share/pixmaps
	${CP} files/js-nes.desktop             ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
