PORTNAME=	arma
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/armacoldwar/
DISTNAME=	PoseidonGame
PKGNAMEPREFIX=	
COMMENT=        
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?= .tar.xz

CHROME_VER?=	v0.0.1


SUB_FILES=	arma

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/arma   ${STAGEDIR}${PREFIX}/bin
	mkdir -p                            ${STAGEDIR}${PREFIX}/share/arma
	cd ${WRKSRC}/ && ${CP} -r PoseidonGame     ${STAGEDIR}${PREFIX}/share/arma
	${CP}  files/arma.jpg              ${STAGEDIR}${PREFIX}/share/pixmaps
	${CP} files/arma.desktop           ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
