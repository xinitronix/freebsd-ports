PORTNAME=	nr2003
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/NASCAR2003/
DISTNAME=	NASCAR2003
PKGNAMEPREFIX=	wine-
COMMENT=        game GOG version "Fury Unleashed"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	nr2003

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/nr2003  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                              ${STAGEDIR}${PREFIX}/share/
	cd ${WRKSRC}/ && ${CP} -r NASCAR2003  ${STAGEDIR}${PREFIX}/share/
	touch                         ${STAGEDIR}${PREFIX}/share/NASCAR2003/rend_ogl.ini
	chmod 0766                    ${STAGEDIR}${PREFIX}/share/NASCAR2003/rend_ogl.ini
	touch                         ${STAGEDIR}${PREFIX}/share/NASCAR2003/app.ini
	chmod 0766                    ${STAGEDIR}${PREFIX}/share/NASCAR2003/app.ini
	cp  files/nr2003.reg          ${STAGEDIR}${PREFIX}/share/NASCAR2003
	cp  files/4F2E_NR2003.0.png   ${STAGEDIR}${PREFIX}/share/pixmaps
	cp "files/NASCAR Racing 2003 Season.desktop" ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
