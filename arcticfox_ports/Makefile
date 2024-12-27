PORTNAME=	arcticfox
PORTVERSION=	1.0
CATEGORIES=	www linux
MASTER_SITES=	https://dl.google.com/linux/chrome/rpm/stable/x86_64/
DISTNAME=	arcticfox-45.1.en-US.linux-x86_64
PKGNAMEPREFIX=	linux-

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Google web browser based on WebKit
WWW=		https://www.chromium.org/Home




NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.bz2




post-extract:
#	@${REINPLACE_CMD} -e 's|/usr/bin/google-chrome-stable|${LOCALBASE}/bin/google-chrome|' \
#		${WRKSRC}/arcticfox/arcticfox.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-arcticfox-1.0/arcticfox/linux-arcticfox ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${CP} -r arcticfox  ${STAGEDIR}${PREFIX}/lib

	cd ${WRKSRC}/arcticfox/browser/chrome/icons/default  && ${CP}  default32.png   ${STAGEDIR}${PREFIX}/share/pixmaps/arcticfox.png

#	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/arcticfox/arcticfox.desktop  ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
