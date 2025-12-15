PORTNAME=	LiveTvGUI-Qt6 
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g25fe3e467b83fc8d
CATEGORIES=	sysutils

USES=           desktop-file-utils  \
                qmake:outsource qt:6 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk
GH_PROJECT=	LiveTvGUI

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools \
		qt6-webengine>0:www/qt6-webengine 


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/LiveTvGUI-Qt6     ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/livetv.desktop                    ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/livetv.png                        ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>