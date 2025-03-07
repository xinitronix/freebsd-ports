PORTNAME=	thething
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/v0.0.1/ 
                
DISTFILES= 	thething.part_aa thething.part_ab
PKGNAMEPREFIX=	wine-
COMMENT=        game GOG version "The Thing: Remastered"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes


CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	thething

do-extract:
	cat  ${DISTDIR}/thething.part_*  >  ${WRKSRC}/thething.tar.xz
	tar -xvf ${WRKSRC}/thething.tar.xz  -C  ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/thething  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                              ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r thething ${STAGEDIR}${PREFIX}/share/GOG
	cp files/thething.png     ${STAGEDIR}${PREFIX}/share/pixmaps
	cp files/thething.desktop ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
