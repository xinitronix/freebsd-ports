PORTNAME=	byedpi-qt6
DISTVERSION=	v0.1.0-1
DISTVERSIONSUFFIX=	-g694a05bc8b926a1df66062
CATEGORIES=	net

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk
GH_TUPLE=       hufrea:byedpi:9938d74:byedpi

WWW=	      	https://github.com/vcore486-afk/byedpi-qt6

USES=          qmake:outsource qt:6

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools \
		qt6-webengine>0:www/qt6-webengine 

TAG= ${GH_TUPLE:C/^[^:]*:[^:]*:([^:]*):.*$/\1/}


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/byedpi-gui        ${STAGEDIR}${PREFIX}/bin/byedpi-qt6
		${CP}        files/byedpi.png                        ${STAGEDIR}${PREFIX}/share/pixmaps
		${CP}        files/byedpi-qt6.desktop                ${STAGEDIR}${PREFIX}/share/applications
		cd ${WRKDIR}/byedpi-${TAG} && make -j6
		${CP} ${WRKDIR}/byedpi-${TAG}/ciadpi                 ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
