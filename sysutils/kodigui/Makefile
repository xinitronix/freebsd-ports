PORTNAME=	KodiGui
DISTVERSION=	1.0-2
DISTVERSIONSUFFIX=	-g7093b49eb2b2d2a0733e9fee9
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:6 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	definitly486

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools \
		py311-beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR}

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/kodigui      ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/kodigui.desktop              ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/kodigui.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>