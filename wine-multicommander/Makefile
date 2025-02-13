PORTNAME=	multicommander
DISTVERSION=	v15.0
CATEGORIES=     x11-fm
MASTER_SITES=   https://multicommander.com/files/updates/
DISTFILES=      MultiCommander_x64_(15.0.0.3072).exe
PKGNAMEPREFIX=	wine-

NO_BUILD=	yes

SUB_FILES=	wine-mc

do-extract:
		pkg fetch  -y -r FreeBSD wine-devel 
		tar  -C ${WRKDIR} -xf /var/cache/pkg/wine-devel-10.1,1.pkg  /usr/local                
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}"
		cd  ${WRKDIR} &&  7z -y x  "${DISTFILES}" -o${PORTNAME}-${DISTVERSION}
		
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-mc  ${STAGEDIR}${PREFIX}/bin
		mkdir 	     ${STAGEDIR}${PREFIX}/share/multicommander
		${CP} -r     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/*    ${STAGEDIR}${PREFIX}/share/multicommander
		${CP} -r     ${WRKDIR}/usr/local/*                     ${STAGEDIR}${PREFIX}/share/multicommander
		${CP}        files/wine-mc.desktop                     ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/wine-mc.png                         ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>