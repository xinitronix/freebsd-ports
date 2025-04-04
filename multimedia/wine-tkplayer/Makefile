PORTNAME=	tkplayer
DISTVERSION=	v2.2.0
CATEGORIES=     multimedia
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/TKPlayer/
DISTFILES=      TKPlayer.zip
PKGNAMEPREFIX=	wine-
COMMENT=        TKPlayer is a free media playe (wine)
RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-tkplayer

do-extract:
		               
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}"
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
		
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-tkplayer ${STAGEDIR}${PREFIX}/bin
		

		${CP} -r -LP     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/TKPlayer   ${STAGEDIR}${PREFIX}/share/

		${CP}        files/TKPlayer.desktop                     	${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/TKPlayer.png                         	${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>