PORTNAME=	Colloid-icon-theme
DISTVERSION=	2025-07-19
CATEGORIES=	x11-themes


COMMENT=	Colloid icon theme
WWW=		https://github.com/vinceliuice/Colloid-icon-theme

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Colloid-icon-theme
GH_TAGNAME=	c9e702b
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} -p  ${STAGEDIR}${PREFIX}/share/icons/Colloid
		
		${CP}  -r    ${WRKSRC}/src/*   ${STAGEDIR}${PREFIX}/share/icons/Colloid

.include <bsd.port.mk>
