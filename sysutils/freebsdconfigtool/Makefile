PORTNAME=	freebsdconfigtool
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g8c950d1
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	definitly486
GH_PROJECT=	FreeBSDConfigTool

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/FreeBSDConfigTool  ${STAGEDIR}${PREFIX}/bin/freebsdconfigtool
		${CP}        files/freebsdconfigtool.desktop         ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/freebsd.jpg                 ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>