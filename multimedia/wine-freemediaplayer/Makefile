PORTNAME=	freemediaplayer
DISTVERSION=    1.1.1
CATEGORIES=     multimedia
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/freemediaplayer/
DISTFILES=      FreeMediaPlayer.zip
PKGNAMEPREFIX=	wine-
COMMENT=        Aisesoft Free Media Player (wine)
RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-freemediaplayer

do-extract:
		               
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}"
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
		
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-freemediaplayer ${STAGEDIR}${PREFIX}/bin
		

		${CP} -r -LP     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/FreeMediaPlayer   ${STAGEDIR}${PREFIX}/share/

		${CP}        files/freemediaplayer.desktop                  	        ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/freemediaplayer.png                         	${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>