PORTNAME=	KodiGui
DISTVERSION=	1.0-2
DISTVERSIONSUFFIX=	-gf51b10b641a6b
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_QT=         buildtools:build 
USE_GITHUB=	yes
GH_ACCOUNT=	definitly486

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/kodigui      ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/kodigui.desktop              ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/kodigui.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>