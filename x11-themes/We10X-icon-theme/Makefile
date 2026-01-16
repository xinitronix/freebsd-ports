PORTNAME=	we10x-icon-theme
DISTVERSION=	2025-08-26
CATEGORIES=	x11-themes


COMMENT=	Icon pack for linux 
WWW=		https://github.com/yeyushengfan258/We10X-icon-theme

USE_GITHUB=	yes
GH_ACCOUNT=	yeyushengfan258
GH_PROJECT=	We10X-icon-theme
GH_TAGNAME=	0f52ff2
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} -p  ${STAGEDIR}${PREFIX}/share/icons/We10X
		${CP}  -r    ${WRKSRC}/src/*   ${STAGEDIR}${PREFIX}/share/icons/We10X

.include <bsd.port.mk>
