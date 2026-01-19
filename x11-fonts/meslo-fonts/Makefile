PORTNAME=	meslo-fonts
DISTVERSION=	1.0.0
CATEGORIES=	x11-fonts


COMMENT=	Meslo fonts 
WWW=		https://github.com/vcore486-afk/meslo-fonts

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk
GH_PROJECT=	meslo-fonts
GH_TAGNAME=	2252d8c
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} -p  ${STAGEDIR}${PREFIX}/share/fonts/meslo
		
		${CP}  -r    ${WRKSRC}/*   ${STAGEDIR}${PREFIX}/share/fonts/meslo

.include <bsd.port.mk>
