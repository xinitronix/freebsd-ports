PORTNAME=	painkiller
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/painkiller/ 
DISTFILES=	painkiller.tar.xz.part_aa painkiller.tar.xz.part_ab
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Painkiller: Black Edition" GOG wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

CHROME_VER?=	v0.0.1

SUB_FILES=	painkiller

do-extract:
	cat  ${DISTDIR}/thething.part_*  >  ${WRKSRC}/thething.tar.xz
	tar -xvf ${WRKSRC}/thething.tar.xz  -C  ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/painkiller            ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                          ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r   painkiller            ${STAGEDIR}${PREFIX}/share/GOG
	cp files/painkiller.desktop                       ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
