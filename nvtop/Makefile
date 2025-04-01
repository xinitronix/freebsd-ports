PORTNAME=	nvtop
DISTVERSION=	3.2.0
DISTVERSIONSUFFIX=	-g7329188
CATEGORIES=	sysutils

USE_GITHUB=	yes
GH_ACCOUNT=	Syllo

WWW=		https://github.com/Syllo/nvtop

USES=		cmake:noninja


PLIST_FILES=	bin/nvtop \
		share/applications/nvtop.desktop \
		share/pixmaps/nvtop.png

post-install:
		cp files/nvtop.png              ${STAGEDIR}${PREFIX}/share/pixmaps
		cp files/nvtop.desktop          ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
