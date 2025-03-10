PORTNAME=	notepad++
DISTVERSION=	v8.7.7
CATEGORIES=     multimedia
MASTER_SITES=   https://github.com/notepad-plus-plus/notepad-plus-plus/releases/download/v8.7.7/
DISTFILES=      npp.8.7.7.portable.x64.zip
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-notepad++

do-extract:
		pkg fetch  -y -r FreeBSD wine-proton 
		tar  -C ${WRKDIR} -xf /var/cache/pkg/wine-proton-9.0.3.pkg  /usr/local   
		cp "/usr/ports/distfiles/${DISTFILES}"       ${WRKDIR}/"${DISTFILES}" 
		cd  ${WRKDIR} &&  7z -y x  "${DISTFILES}"  -o${PORTNAME}-${DISTVERSION} 

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-notepad++                          ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/notepad++
		${CP} -r     ${WRKDIR}/usr/local/                                   ${STAGEDIR}${PREFIX}/share/notepad++
		${CP} -r     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/*    		    ${STAGEDIR}${PREFIX}/share/notepad++
		${CP}        files/wine-notepad++.desktop                           ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/wine-notepad++.png                               ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>