PORTNAME=	firefox-nightly
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www 
MASTER_SITES=	https://github.com/xinitronix/firefox-dev-browser-freebsd/releases/download/v0.0.3/
DISTNAME=	firefox-nightly




NO_BUILD=	yes
NO_WRKSUBDIR=	yes


SHEBANG_FILES=	firefox-nightly/firefox-nightly

EXTRACT_SUFX?=		.tar.bz2

SUB_FILES=	firefox-nightly

CHROME_VER?=	v0.0.3

do-install:
	
	${INSTALL_SCRIPT} ${WRKDIR}/firefox-nightly ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${CP} -r  -LP firefox-nightly  ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/firefox-nightly/browser/chrome/icons/default  && ${CP}  default32.png   ${STAGEDIR}${PREFIX}/share/pixmaps/firefox-nightly.png
	cp files/nightly.desktop ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
