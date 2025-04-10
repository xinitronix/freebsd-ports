PORTNAME=       wine-steam
DISTVERSION=    1.0.7
CATEGORIES=     games
MASTER_SITES=   https://github.com/es-j3/${GH_PROJECT}/archive/${PORTVERSION}${EXTRACT_SUFX}?dummy=/
GH_PROJECT=     steam-bottler
MAINTAINER=     alexander.nogal@proton.me
COMMENT=        Steam Windows gaming in a wine bottle on FreeBSD
WWW=            https://github.com/es-j3/steam-bottler

ONLY_FOR_ARCHS= amd64 i386
ONLY_FOR_ARCHS_REASON=  Wine is only supported on x86 platforms

RUN_DEPENDS=    wine:emulators/wine \
		${LOCALBASE}/wine-proton:emulators/wine-proton \
		winetricks:emulators/winetricks \
		zenity:x11/zenity

NO_BUILD=       yes

WRKSRC=         ${WRKDIR}/${GH_PROJECT}-${PORTVERSION}

PLIST_FILES=    bin/wine-steam

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/steam-bottler ${STAGEDIR}${PREFIX}/bin/wine-steam
	${CP}   files/wine-steam.png   ${STAGEDIR}${PREFIX}/share/pixmaps
	${CP}   files/wine-steam-Configurator.desktop  ${STAGEDIR}${PREFIX}/share/applications
	${CP}   files/wine-steam.desktop   ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
