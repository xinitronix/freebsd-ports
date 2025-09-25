PORTNAME=	totalcommander
DISTVERSION=	11.56
CATEGORIES=     x11-fm 
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/totalcmd/
DISTFILES=      totalcmd.tar.xz
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-totalcmd



do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-totalcmd                          ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/totalcmd
		${CP} -r     ${WRKDIR}/totalcmd/*    		                   ${STAGEDIR}${PREFIX}/share/totalcmd
		${CP}        files/wine-totalcmd.desktop                           ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/wine-totalcmd.png                               ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>