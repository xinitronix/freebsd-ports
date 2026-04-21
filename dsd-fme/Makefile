PORTNAME=	dsd-fme
DISTVERSION=	2025-1
DISTVERSIONSUFFIX=	-ged1d1d6
CATEGORIES=	comms


USES=cmake:noninja
USE_GITHUB=	yes
GH_ACCOUNT=	lwvmobile

BUILD_DEPENDS=  mbelib>0:comms/mbelib

CMAKE_ARGS+=	    -DCURSES_LIBRARY=/usr/lib/libncurses.a \
                    -DCURSES_INCLUDE_PATH=/usr/include 


post-install:
		cp files/dsd-fme.png            ${STAGEDIR}${PREFIX}/share/pixmaps
		cp files/dsd-fme.desktop        ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>