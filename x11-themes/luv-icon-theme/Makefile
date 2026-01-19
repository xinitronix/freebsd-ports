PORTNAME=	luv-icon-theme
DISTVERSION=	1.0.0
CATEGORIES=	x11-themes


COMMENT=	Luv icon theme
WWW=		https://github.com/Nitrux/luv-icon-theme

USE_GITHUB=	yes
GH_ACCOUNT=	Nitrux
GH_PROJECT=	luv-icon-theme
GH_TAGNAME=	5af1f34
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} -p  ${STAGEDIR}${PREFIX}/share/icons/luv
		
		${CP}  -r    ${WRKSRC}/Luv/*   ${STAGEDIR}${PREFIX}/share/icons/luv

.include <bsd.port.mk>
