PORTNAME=	SwitchToWindows-Qt6 
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g96dd86a
CATEGORIES=	sysutils

USES=           cmake  \
                qt:6
WWW=            https://github.com/vcore486-afk/SwitchToWindows-qt6

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk
GH_PROJECT=	SwitchToWindows-qt6

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt6-webengine>0:www/qt6-webengine 


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/SwitchToWindows    ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/SwitchToWindows.desktop                    ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/windows.png                        ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>