PORTNAME=	VMrunGui
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-gacf20318e9f5b3
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_QT=         buildtools:build 
USE_GITHUB=	yes
GH_ACCOUNT=	definitly486

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/vmrun      ${STAGEDIR}${PREFIX}/bin/vmrungui
		${CP}        files/vmrungui.desktop              ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/vmrungui.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>