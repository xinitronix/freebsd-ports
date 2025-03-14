PORTNAME=	coj
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/coj/ 
DISTFILES=	coj.part_ab coj.part_aa
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Call of Juarez" GOG wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

CHROME_VER?=	v0.0.1

#RUN_DEPENDS=    wine-proton-e>0:emulators/wine-proton-e

SUB_FILES=	coj

do-extract:
	cat  ${DISTDIR}/coj.part_*  >         ${WRKSRC}/coj.tar.xz
	tar -xvf ${WRKSRC}/coj.tar.xz  -C     ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/coj                   ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                          ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r   coj                   ${STAGEDIR}${PREFIX}/share/GOG
	rm -R                                             ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Settings
	mkdir -p 					  ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Settings
	touch                                             ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Settings/Audio.scr
	touch                                             ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Settings/Controller.scr
	touch                                             ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Settings/Video.scr
	chmod -R  0776	                                  ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Settings/
	rm -R                                             ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Profiles
	mkdir -p                                          ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Profiles/DefaultProfile
	touch   					  ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Profiles/DefaultProfile/Profile.scr
	touch   					  ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Profiles/DefaultProfile/ServerAdmins.scr
	chmod -R  0776	                                  ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Profiles/DefaultProfile/
	rm 						  ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Secrets.dat
	touch                                             ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Secrets.dat
	chmod -R  0776	                                  ${STAGEDIR}${PREFIX}/share/GOG/coj/out/Secrets.dat
#	chmod -R  0776	                                  ${STAGEDIR}${PREFIX}/share/GOG/painkiller/Bin/config.ini
	cp files/coj.reg                                  ${STAGEDIR}${PREFIX}/share/GOG/coj
	cp files/coj.desktop                              ${STAGEDIR}${PREFIX}/share/applications
	cp files/coj.png                                  ${STAGEDIR}${PREFIX}/share/pixmaps
.include <bsd.port.mk>
