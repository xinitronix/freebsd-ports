PORTNAME=	explorer++
DISTVERSION=	v1.4.0
CATEGORIES=     multimedia
MASTER_SITES=   https://download.explorerplusplus.com/stable/1.4.0/
DISTFILES=      explorerpp_x64.zip
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-explorer++

do-extract:
		pkg fetch  -y -r FreeBSD wine-proton 
		tar  -C ${WRKDIR} -xf /var/cache/pkg/wine-proton-9.0.3.pkg  /usr/local   
		cp "/usr/ports/distfiles/${DISTFILES}"      ${WRKDIR}/"${DISTFILES}" 
		cd  ${WRKDIR} &&  7z -y x  "${DISTFILES}" -o${PORTNAME}-${DISTVERSION} 

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-explorer++                          ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/explorer++
		${CP} -r     ${WRKDIR}/usr/local/                                    ${STAGEDIR}${PREFIX}/share/explorer++
		${CP} -r     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/*    		     ${STAGEDIR}${PREFIX}/share/explorer++
		${CP}        files/wine-explorer++.desktop                           ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/wine-explorer++.png                               ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>