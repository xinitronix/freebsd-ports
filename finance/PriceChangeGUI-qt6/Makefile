PORTNAME=	PriceChangeGUI-qt6
DISTVERSION=	v0.1.0-1
DISTVERSIONSUFFIX=	-gc67562d
CATEGORIES=	finance

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk


WWW=	      	https://github.com/vcore486-afk/PriceChangeGUI-qt6

USES=           qmake:outsource qt:6

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools \
		qt6-webengine>0:www/qt6-webengine 




do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/PriceChangeGUI        ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/price.png                             ${STAGEDIR}${PREFIX}/share/pixmaps
		${CP}        files/PriceChangeGUI.desktop                ${STAGEDIR}${PREFIX}/share/applications
		

.include <bsd.port.mk>
