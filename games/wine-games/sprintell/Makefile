PORTNAME=	sprintell
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/TCSC/ 
DISTNAME=	TCSC
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Tom Clancy’s Splinter Cell"  wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

RUN_DEPENDS=    zenity>0:x11/zenity

CHROME_VER?=	v0.0.1

SUB_FILES=	sprintell

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sprintell                   ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                                ${STAGEDIR}${PREFIX}/share/
	cd ${WRKSRC}/ && ${CP} -r    TCSC                       ${STAGEDIR}${PREFIX}/share/
	cp files/tcsc.gamecontroller.amgp                       ${STAGEDIR}${PREFIX}/share/TCSC
	cp files/sprintell.desktop                              ${STAGEDIR}${PREFIX}/share/applications
	cp files/sprintell.png                                  ${STAGEDIR}${PREFIX}/share/pixmaps
.include <bsd.port.mk>
