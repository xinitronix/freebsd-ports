PORTNAME=	winscp
DISTVERSION=	v6.3.5
CATEGORIES=     x11-fm
MASTER_SITES=   https://download2.portableapps.com/portableapps/WinSCPPortable/
DISTFILES=      WinSCPPortable_6.3.5.paf.exe
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-winscp

do-extract:
		cp "/usr/ports/distfiles/${DISTFILES}"      ${WRKDIR}/"${DISTFILES}" 
		cd  ${WRKDIR} &&  7z -y x  "${DISTFILES}" -o${PORTNAME}-${DISTVERSION} 

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-winscp                          ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/winscp
		${CP} -r     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/*    		 ${STAGEDIR}${PREFIX}/share/winscp 
		${CP}        files/wine-winscp.desktop                           ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/wine-winscp.png                               ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>