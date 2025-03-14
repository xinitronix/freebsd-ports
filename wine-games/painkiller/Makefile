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

#RUN_DEPENDS=    wine-proton-e>0:emulators/wine-proton-e

SUB_FILES=	painkiller

do-extract:
	cat  ${DISTDIR}/painkiller.tar.xz.part_*  >  ${WRKSRC}/painkiller.tar.xz
	tar -xvf ${WRKSRC}/painkiller.tar.xz  -C     ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/painkiller            ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                          ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r   painkiller            ${STAGEDIR}${PREFIX}/share/GOG
	rm -R                                             ${STAGEDIR}${PREFIX}/share/GOG/painkiller/SaveGames
	mkdir -p 					  ${STAGEDIR}${PREFIX}/share/GOG/painkiller/SaveGames
	chmod -R  0776	                                  ${STAGEDIR}${PREFIX}/share/GOG/painkiller/SaveGames/
	rm -R                                             ${STAGEDIR}${PREFIX}/share/GOG/painkiller/Bin/config.ini
	touch   					  ${STAGEDIR}${PREFIX}/share/GOG/painkiller/Bin/config.ini
	chmod -R  0776	                                  ${STAGEDIR}${PREFIX}/share/GOG/painkiller/Bin/config.ini
	cp files/painkiller.desktop                       ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
