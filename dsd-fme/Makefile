PORTNAME=	dsd-fme
DISTVERSION=	2024
DISTVERSIONSUFFIX=	-gbc140ec
CATEGORIES=	www devel




USES=cmake:noninja
USE_GITHUB=	yes
GH_ACCOUNT=	lwvmobile


CMAKE_ARGS+=	    -DCURSES_LIBRARY=/usr/lib/libncurses.a \
                    -DCURSES_INCLUDE_PATH=/usr/include 


post-install:
		cp files/dsd-fme.png            ${STAGEDIR}${PREFIX}/share/pixmaps
		cp files/dsd-fme.desktop        ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>