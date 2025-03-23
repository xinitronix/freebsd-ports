PORTNAME=	mafia
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/Mafia/ 
DISTFILES= 	Mafia.part_aa Mafia.part_ab
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Mafia: The City of Lost Heaven" GOG wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RUN_DEPENDS=    zenity>0:x11/zenity

SUB_FILES=	mafia

CHROME_VER?=	v0.0.1
do-extract:
	cat  ${DISTDIR}/Mafia.part_*  >  ${WRKSRC}/Mafia.tar.xz
	tar -xvf ${WRKSRC}/Mafia.tar.xz  -C  ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mafia     ${STAGEDIR}${PREFIX}/bin
	mkdir -p                              ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r Mafia ${STAGEDIR}${PREFIX}/share/GOG
	rm -R  ${STAGEDIR}${PREFIX}/share/GOG/Mafia/savegame
	mkdir  -p ${STAGEDIR}${PREFIX}/share/GOG/Mafia/savegame
	chmod -R 775 ${STAGEDIR}${PREFIX}/share/GOG/Mafia/savegame
	cp files/mafia.png     ${STAGEDIR}${PREFIX}/share/pixmaps
	cp files/mafia.desktop ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
