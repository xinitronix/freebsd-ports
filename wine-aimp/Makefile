PORTNAME=	aimp
DISTVERSION=	v5.40.2655
CATEGORIES=     multimedia
MASTER_SITES=   https://www.aimp.ru/files/windows/builds/
DISTFILES=      aimp_5.40.2655_w64_no-installer.zip
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-proton>0:emulators/wine-proton

NO_BUILD=	yes

SUB_FILES=	aimp

do-extract:
		pkg fetch  -y -r FreeBSD wine-proton 
		tar  -C ${WRKDIR} -xf /var/cache/pkg/wine-proton-9.0.3.pkg  /usr/local   
		cp "/usr/ports/distfiles/${DISTFILES}"      ${WRKDIR}/"${DISTFILES}" 
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/aimp                                     ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/AIMP
		${CP} -r     ${WRKDIR}/usr/local/                                    ${STAGEDIR}${PREFIX}/share/AIMP
		${CP} -r     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/AIMP/*             ${STAGEDIR}${PREFIX}/share/AIMP
		${CP}        files/aimp.desktop                                      ${STAGEDIR}${PREFIX}/share/applications
		mkdir  -p    ${STAGEDIR}${PREFIX}/share/AIMP/Profile
		chmod -R 0776 	${STAGEDIR}${PREFIX}/share/AIMP/Profile
.include <bsd.port.mk>