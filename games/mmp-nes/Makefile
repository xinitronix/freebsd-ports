PORTNAME=	mmp-nes
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/MonsterinMyPocket/
DISTNAME=	mmp-nes
PKGNAMEPREFIX=	
COMMENT=        game "Monster in My Pocket" nes emulator
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	mmp-nes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mmp-nes   ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${CP} -r mmp-nes     ${STAGEDIR}${PREFIX}/share/
	${CP}  files/mmp-nes.jpg       ${STAGEDIR}${PREFIX}/share/pixmaps
	${CP} files/mmp-nes.desktop             ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
