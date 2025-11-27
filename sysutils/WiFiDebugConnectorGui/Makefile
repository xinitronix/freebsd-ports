PORTNAME=	WiFiDebugConnector
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g48f22fc
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	definitly486
GH_PROJECT=	WiFiDebugConnector

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		tinyxml2>0:textproc/tinyxml2 \
		qt5-buildtools>0:devel/qt5-buildtools


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/WiFiDebugConnector  ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/wifidebug.desktop         ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/debug.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>