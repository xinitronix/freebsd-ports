PORTNAME=	firefox-nightly
PORTVERSION=	1.0
CATEGORIES=	www 
MASTER_SITES=	https://dl.google.com/linux/chrome/rpm/stable/x86_64/
DISTNAME=	firefox-nightly




NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.gz




post-extract:
#	@${REINPLACE_CMD} -e 's|/usr/bin/google-chrome-stable|${LOCALBASE}/bin/google-chrome|' \
#		${WRKSRC}/arcticfox/arcticfox.desktop

do-install:
	
        ${INSTALL_SCRIPT} ${WRKDIR}/firefox-nightly-1.0/firefox-nightly/firefox-nightly ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${CP} -r firefox-nightly  ${STAGEDIR}${PREFIX}/lib

	cd ${WRKSRC}/firefox-nightly/browser/chrome/icons/default  && ${CP}  default32.png   ${STAGEDIR}${PREFIX}/share/pixmaps/firefox-nightly.png

#	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/firefox-nightly/nightly.desktop  ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
