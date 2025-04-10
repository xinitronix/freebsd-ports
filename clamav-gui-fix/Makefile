PORTNAME=	clamav-gui-fix
DISTVERSION=	1.1.2
DISTVERSIONSUFFIX=	-gf21364547
CATEGORIES=	x11
GH_PROJECT=     clamav-gui
USE_GITHUB=	yes
GH_ACCOUNT=	wusel1007

USES=    gmake qmake qt:5
USE_QT=		buildtools:build \
		qmake:build

PLIST_FILES= 	bin/clamav-gui-fix \
		share/applications/ClamAV-GUI-fix.desktop \
		share/icons/hicolor/128x128/apps/clamav-gui-fix.png \
		share/icons/hicolor/16x16/apps/clamav-gui-fix.png \
		share/icons/hicolor/22x22/apps/clamav-gui-fix.png \
		share/icons/hicolor/64x64/apps/clamav-gui-fix.png 

do-install:    
		${INSTALL_SCRIPT} ${WRKSRC}/clamav-gui  ${STAGEDIR}${PREFIX}/bin/clamav-gui-fix
		${INSTALL_SCRIPT} ${WRKSRC}/extra/ClamAV-GUI.desktop  ${STAGEDIR}${PREFIX}/share/applications/ClamAV-GUI-fix.desktop

.for sz in 16 22  32  48 64 128 256 
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/extra/icon${sz}/clamav-gui.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/clamav-gui-fix.png
.endfor
.include <bsd.port.mk>