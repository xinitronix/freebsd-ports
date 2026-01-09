PORTNAME=	marwaita-icon-theme
DISTVERSION=	20210111
CATEGORIES=	x11-themes


COMMENT=	Icon pack for linux 
WWW=		https://github.com/darkomarko42/Marwaita-Icons

USE_GITHUB=	yes
GH_ACCOUNT=	darkomarko42
GH_PROJECT=	Marwaita-Icons
GH_TAGNAME=	15e9463
NO_ARCH=	yes
NO_BUILD=	yes

do-install:

		${CP} -r     ${WRKSRC}/Marwaita   ${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>
