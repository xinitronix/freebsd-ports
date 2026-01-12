PORTNAME=	vimix-icon-theme
DISTVERSION=	2025-08-26
CATEGORIES=	x11-themes


COMMENT=	Icon pack for linux 
WWW=		https://github.com/vinceliuice/Vimix-icon-theme

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Vimix-icon-theme
GH_TAGNAME=	8c877b9
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} -p  ${STAGEDIR}${PREFIX}/share/icons/Vimix
		${CP}  -r    ${WRKSRC}/src/*   ${STAGEDIR}${PREFIX}/share/icons/Vimix

.include <bsd.port.mk>
