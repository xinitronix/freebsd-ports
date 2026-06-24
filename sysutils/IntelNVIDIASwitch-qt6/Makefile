PORTNAME=	IntelNVIDIASwitch-qt6
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g097fccc
CATEGORIES=	sysutils

USES=           cmake  \
                qt:6
WWW=            https://github.com/vcore486-afk/IntelNVIDIASwitch-qt6

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk
GH_PROJECT=	IntelNVIDIASwitch-qt6

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt6-webengine>0:www/qt6-webengine 


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/SwitchToi915    ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/IntelNVIDIASwitch.desktop                    ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/SwitchToWindows.png                        ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>