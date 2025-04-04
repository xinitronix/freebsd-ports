PORTNAME=	fmp
DISTVERSION=	v6.6.26
CATEGORIES=     multimedia
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/FreeMediaPlayer/
DISTFILES=      FreeMediaPlayer.zip
PKGNAMEPREFIX=	wine-
COMMENT=        Free Mac Media Player – The best free all- in-one media player for Mac users.  (wine)
RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-fmp

do-extract:
		               
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}"
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
		
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-fmp ${STAGEDIR}${PREFIX}/bin
		

		${CP} -r -LP     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/FreeMediaPlayer   ${STAGEDIR}${PREFIX}/share/

		${CP}        files/fmp.desktop                     	${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/fmp.png                         	${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>