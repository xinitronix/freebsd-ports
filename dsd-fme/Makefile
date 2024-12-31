PORTNAME=	dsd-fme
DISTVERSION=	2024
DISTVERSIONSUFFIX=	-gbc140ec
CATEGORIES=	www devel




USES=cmake:noninja
USE_GITHUB=	yes
GH_ACCOUNT=	lwvmobile


CMAKE_ARGS+=	    -DCURSES_LIBRARY=/usr/lib/libncurses.a \
                    -DCURSES_INCLUDE_PATH=/usr/include 
                     

.include <bsd.port.mk>