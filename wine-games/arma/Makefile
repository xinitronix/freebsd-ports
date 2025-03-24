PORTNAME=	arma
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/arma/ 
DISTFILES= 	arma.part_aa arma.part_ab
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Arma: Armed Assault"  GOG version 
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RUN_DEPENDS=    zenity>0:x11/zenity

CHROME_VER?=	v0.0.1

SUB_FILES=	arma

do-extract:
	cat  ${DISTDIR}/arma.part_*  >  ${WRKSRC}/arma.tar.xz
	tar -xvf ${WRKSRC}/arma.tar.xz  -C  ${WRKSRC}


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/arma                        ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                                ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r    arma                       ${STAGEDIR}${PREFIX}/share/GOG
	cp files/arma.desktop                                   ${STAGEDIR}${PREFIX}/share/applications
	cp files/arma.png                                       ${STAGEDIR}${PREFIX}/share/pixmaps
.include <bsd.port.mk>
