PORTNAME=	obsidian-icon-theme
DISTVERSION=	Release-4.15
CATEGORIES=	x11-themes


COMMENT=	Icon pack for linux 
WWW=		https://github.com/madmaxms/iconpack-obsidian

USE_GITHUB=	yes
GH_ACCOUNT=	madmaxms
GH_PROJECT=	iconpack-obsidian
GH_TAGNAME=	4cccdd3
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} -p  ${STAGEDIR}${PREFIX}/share/icons/obsidian
		${RM}        ${WRKSRC}/Obsidian/actions/96/lock.svg
		${CP}  -r    ${WRKSRC}/Obsidian/*   ${STAGEDIR}${PREFIX}/share/icons/obsidian/

.include <bsd.port.mk>
