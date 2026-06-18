PORTNAME=	basecamp 
DISTVERSION=	v4.62
CATEGORIES=     astro
MASTER_SITES=   https://github.com/definitly486/wine-apps/releases/download/basecamp/
DISTFILES=      BaseCamp.tar.xz
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine>0:emulators/wine \
		winetricks>0:emulators/winetricks

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=	.ziptar.xz

SUB_FILES=	basecamp

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/basecamp                                       ${STAGEDIR}${PREFIX}/bin
		mkdir -p                                                                   ${STAGEDIR}${PREFIX}/share/basecamp
		cd ${WRKSRC}  && ${CP} -r *                                                ${STAGEDIR}${PREFIX}/share/basecamp
		${CP}  files/basecamp.jpg                                                       ${STAGEDIR}${PREFIX}/share/pixmaps
		${CP}        files/basecamp.desktop                                             ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>