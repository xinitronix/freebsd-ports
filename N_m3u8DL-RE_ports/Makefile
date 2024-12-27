PORTNAME=	N_m3u8DL-RE
PORTVERSION=	1.0
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/nilaoda/N_m3u8DL-RE/releases/download/v0.3.0-beta/
DISTNAME=	N_m3u8DL-RE_v0.3.0-beta_linux-x64_20241203




NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.gz




post-extract:
#	@${REINPLACE_CMD} -e 's|/usr/bin/google-chrome-stable|${LOCALBASE}/bin/google-chrome|' \
#		${WRKSRC}/arcticfox/arcticfox.desktop

do-install:
#	${INSTALL_SCRIPT} ${WRKDIR}/linux-arcticfox-1.0/arcticfox/linux-arcticfox ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${CP} -r N_m3u8DL-RE  ${STAGEDIR}${PREFIX}/bin

#	cd ${WRKSRC}/arcticfox/browser/chrome/icons/default  && ${CP}  default32.png   ${STAGEDIR}${PREFIX}/share/pixmaps/arcticfox.png

#	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
#	${CP} ${WRKSRC}/arcticfox/arcticfox.desktop  ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>