PORTNAME=	potplayer
DISTVERSION=	260114
CATEGORIES=     multimedia
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/PotPlayer/
DISTFILES=      PotPlayer.zip
PKGNAMEPREFIX=	wine-
COMMENT=        TKPlayer is a free media playe (wine)
RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-potplayer

do-extract:
		               
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}"
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
		
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-potplayer ${STAGEDIR}${PREFIX}/bin
		

		${CP} -r -LP     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/PotPlayer   ${STAGEDIR}${PREFIX}/share/

		${CP}        files/PotPlayer.desktop                  	        ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/potplayer.png                         	${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>