PORTNAME=	orbitron
DISTVERSION=	v3.71
CATEGORIES=     comms astro
MASTER_SITES=   https://raw.githubusercontent.com/definitly486/Orbitron/refs/heads/main/
DISTFILES=      orbitron.zip
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes

SUB_FILES=	wine-orbitron

do-extract:
		               
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}"
		cd  ${WRKDIR} &&  unzip   "${DISTFILES}" -d ${PORTNAME}-${DISTVERSION}
		
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-orbitron ${STAGEDIR}${PREFIX}/bin
		mkdir 	     ${STAGEDIR}${PREFIX}/share/orbitron

		${CP} -r -LP     ${WRKDIR}/${PORTNAME}-${DISTVERSION}/Orbitron/*    ${STAGEDIR}${PREFIX}/share/orbitron

		${CP}        files/wine-orbitron.desktop                     	${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/orbitron.png                         	${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>