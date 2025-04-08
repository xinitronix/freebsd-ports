PORTNAME=	furyunleashed
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/FuryUnleashed/
DISTNAME=	FuryUnleashed
PKGNAMEPREFIX=	wine-
COMMENT=        game GOG version "Fury Unleashed"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	FuryUnleashed


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/FuryUnleashed  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                              ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r FuryUnleashed ${STAGEDIR}${PREFIX}/share/GOG
	cp files/FuryUnleashed.png      ${STAGEDIR}${PREFIX}/share/pixmaps
	cp files/FuryUnleashed.desktop ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
