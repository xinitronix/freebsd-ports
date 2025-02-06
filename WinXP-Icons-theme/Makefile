PORTNAME=	WinXP-Icons-theme
DISTVERSION=	3.1
DISTVERSIONSUFFIX=	-gb6d1fe9
CATEGORIES=	x11-themes





USE_GITHUB=	yes
GH_ACCOUNT=	B00merang-Artwork
GH_PROJECT=     Windows-XP

NO_BUILD=	yes


do-install:
		${MKDIR}    ${STAGEDIR}${PREFIX}/share/icons/${GH_PROJECT}
		${CP}   -r  ${WRKSRC}/.     ${STAGEDIR}${PREFIX}/share/icons/${GH_PROJECT}/

.include <bsd.port.mk>