PORTNAME=	kodidlp-gui
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g3249a4d
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_QT=         buildtools:build 
USE_GITHUB=	yes
GH_ACCOUNT=	definitly486

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/kodidlp      ${STAGEDIR}${PREFIX}/bin/kodidlp-gui
		${CP}        files/kodidlp-gui.desktop          ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/kodidlp.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>