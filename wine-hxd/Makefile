PORTNAME=	hxd
DISTVERSION=	2.5.0.0
CATEGORIES=     editors
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/hxd/
DISTFILES=      HxD.tar.xz
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-hxd



do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-hxd                          ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/hxd
		${CP} -r     ${WRKDIR}/HxD/*    		 ${STAGEDIR}${PREFIX}/share/hxd
		${CP}        files/wine-hxd.desktop                           ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/wine-hxd.png                               ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>