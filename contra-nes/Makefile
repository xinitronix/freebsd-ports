PORTNAME=	contra-nes
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/contra/
DISTNAME=	contra-nes
PKGNAMEPREFIX=	
COMMENT=        game "Contra" nes emulator
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	contra-nes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/contra-nes   ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${CP} -r contra-nes     ${STAGEDIR}${PREFIX}/share/
	${CP}  files/contra-nes.jpg              ${STAGEDIR}${PREFIX}/share/pixmaps
	${CP} files/contra-nes.desktop           ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
