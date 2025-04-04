PORTNAME=	lightalloy
DISTVERSION=	v4.11.2
CATEGORIES=     multimedia
MASTER_SITES=   https://dl.light-alloy.com/
DISTFILES=      LA_Portable_v4.11.2.zip
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	lightalloy

do-extract:
 		
		cp "/usr/ports/distfiles/${DISTFILES}"      ${WRKDIR}/"${DISTFILES}" 
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/lightalloy                                     ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/lightalloy
		${CP} -r     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/*                        ${STAGEDIR}${PREFIX}/share/lightalloy
		${CP}        files/lightalloy.desktop                                      ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>