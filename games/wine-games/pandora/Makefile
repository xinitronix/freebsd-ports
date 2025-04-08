PORTNAME=	pandora
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/scpt/ 
DISTNAME=	scpt
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Tom Clancy’s Splinter Cell: Pandora Tomorrow" GOG wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1

SUB_FILES=	pandora

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pandora                   ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                              ${STAGEDIR}${PREFIX}/share/
	cd ${WRKSRC}/ && ${CP} -r   scpt                      ${STAGEDIR}${PREFIX}/share/
	cp files/pandora.desktop                              ${STAGEDIR}${PREFIX}/share/applications
	cp files/pandora.png                                  ${STAGEDIR}${PREFIX}/share/pixmaps
.include <bsd.port.mk>
