PORTNAME=	avz
DISTVERSION=	v5.99
CATEGORIES=     multimedia
MASTER_SITES=   https://dl.comss.org/download/
DISTFILES=      avz5.zip
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine-devel>0:emulators/wine-devel

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=	.zip

SUB_FILES=	avz

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/avz                                            ${STAGEDIR}${PREFIX}/bin
		mkdir -p                                                                   ${STAGEDIR}${PREFIX}/share/avz
		cd ${WRKSRC}  && ${CP} -r *                                                ${STAGEDIR}${PREFIX}/share/avz
		${CP}  files/avz.png                                                       ${STAGEDIR}${PREFIX}/share/pixmaps
		${CP}        files/avz.desktop                                             ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>