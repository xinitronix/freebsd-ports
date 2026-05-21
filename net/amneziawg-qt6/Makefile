PORTNAME=	amneziawg-qt6
DISTVERSION=	v0.1.0-1
DISTVERSIONSUFFIX=	-ge3bd477
CATEGORIES=	net

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk


WWW=	      	https://github.com/vcore486-afk/amneziawg-qt6

USES=           qmake:outsource qt:6

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools \
		qt6-webengine>0:www/qt6-webengine \
               
do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/amneziawg-qt6        ${STAGEDIR}${PREFIX}/bin/amneziawg-qt6
		${CP}        files/amneziawg.png                    ${STAGEDIR}${PREFIX}/share/pixmaps
		${CP}        files/amneziawg-qt6.desktop               ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>