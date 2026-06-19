PORTNAME=	sasplanet
DISTVERSION=	v260404
CATEGORIES=     astro
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/SASPlanet/
DISTFILES=      SASPlanet_260404.zip
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine>0:emulators/wine \
		winetricks>0:emulators/winetricks

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=	.zip

SUB_FILES=	sasplanet

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/sasplanet                                       ${STAGEDIR}${PREFIX}/bin
		mkdir -p                                                                   ${STAGEDIR}${PREFIX}/share/sasplanet
		cd ${WRKSRC}  && ${CP} -r *                                                ${STAGEDIR}${PREFIX}/share/sasplanet
		${CP}  files/sasplanet.jpg                                                       ${STAGEDIR}${PREFIX}/share/pixmaps
		${CP}        files/sasplanet.desktop                                             ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>