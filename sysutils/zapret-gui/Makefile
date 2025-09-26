PORTNAME=	zapret-gui
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-ga038d47
CATEGORIES=	sysutils

USES=           cmake:noninja
USE_GITHUB=	yes
GH_ACCOUNT=	definitly486

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/zapret_gui  ${STAGEDIR}${PREFIX}/bin/zapret-gui
		${CP}        files/zapret-gui.desktop          ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/zapret.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>