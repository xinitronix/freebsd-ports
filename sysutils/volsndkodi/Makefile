PORTNAME=       volsndkodi
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g8eb5029
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_QT=         buildtools:build 
USE_GITHUB=	yes
GH_ACCOUNT=	definitly486

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/volsndkodi      ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/volsndkodi.desktop              ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/volsndkodi.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>