PORTNAME=	YUView
DISTVERSION=	2.4
DISTVERSIONSUFFIX=	-gf95d35c
CATEGORIES=	multimedia

BUILD_DEPENDS=	qt5-buildtools>0:devel/qt5-buildtools qt5-qmake>0:devel/qt5-qmake

USES=           qt:5 qmake
USE_QT=         buildtools:build qmake:build
USE_GITHUB=	yes
GH_ACCOUNT=	IENT

do-install:
	
		cp 	${WRKSRC}/YUViewApp/YUView       ${STAGEDIR}${PREFIX}/bin
		cp      ${WRKSRC}/YUViewLib/images/IENT-YUView-64.png       ${STAGEDIR}${PREFIX}/share/pixmaps
		cp      ${WRKSRC}/YUView.desktop   ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>