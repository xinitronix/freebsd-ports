PORTNAME=	utorrent
DISTVERSION=    3.6
CATEGORIES=     net
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/utorrent/
DISTFILES=      utorrent.zip
PKGNAMEPREFIX=	wine-
COMMENT=        Utorrent (wine)
RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-utorrent

do-extract:
		               
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}"
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
		
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-utorrent ${STAGEDIR}${PREFIX}/bin
		

		${CP} -r -LP     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/utorrent   ${STAGEDIR}${PREFIX}/share/

		${CP}        files/utorrent.desktop                  	        ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/utorrent.png                         	${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>