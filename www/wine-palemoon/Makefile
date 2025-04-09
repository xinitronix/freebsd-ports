PORTNAME=	palemoon
DISTVERSION=	33.7.0
CATEGORIES=     www 
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/palemoon/
DISTFILES=      palemoon.tar.xz
PKGNAMEPREFIX=	wine-
COMMENT=        Pale Moon wine version
RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-palemoon

EXTRACT_SUFX?=  .tar.xz


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-palemoon                          ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/wine-palemoon
		${CP} -r     "${WRKDIR}/Pale Moon/."                                    ${STAGEDIR}${PREFIX}/share/wine-palemoon

		${CP}        files/wine-palemoon.desktop                           ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/palemoon.png                               ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>