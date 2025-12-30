PORTNAME=	zapret-gui
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g98d117a9aa5af9b665eb9a51c
CATEGORIES=	sysutils
WWW=            https://github.com/vcore486-afk/zapret-gui

USES=           desktop-file-utils  \
                qmake:outsource qt:6 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools \
		qt6-webengine>0:www/qt6-webengine

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/zapret-gui  ${STAGEDIR}${PREFIX}/bin/zapret-gui
		${CP}        files/zapret-gui.desktop          ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/zapret.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>