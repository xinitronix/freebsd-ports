PORTNAME=	webcatalog
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www  linux
MASTER_SITES=	https://cdn-2.webcatalog.io/webcatalog/
DISTFILES=	WebCatalog-${CHROME_VER}.AppImage
PKGNAMEPREFIX=	linux-

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Turn websites into desktop apps with WebCatalog Desktop.
WWW=		https://www.cursor.com/

RUN_DEPENDS=	linux-rl9-wget>0:ftp/linux-rl9-wget \
		linux-rl9-gnupg2>0:security/linux-rl9-gnupg \
		update-mime-database:misc/shared-mime-info

USES=		cpe desktop-file-utils gnome linux:rl9 shared-mime-info shebangfix
USE_LINUX=	alsalib alsa-plugins-oss alsa-plugins-pulseaudio at-spi2-atk \
		ca-certificates cairo cups-libs curl dbuslibs dri expat \
		ffmpeg-libs gnupg gstreamer1-libav gtk3 libxkbcommon libunistring \
		nspr nss p11-kit pango sqlite3 wget xorglibs
ONLY_FOR_ARCHS=	amd64



SHEBANG_FILES=	webcatalog/@webcatalogdesktop
NO_BUILD=	yes
NO_WRKSUBDIR=	yes




CHROME_VER?=	65.3.0


DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	webcatalog


do-extract:


	cp /usr/ports/distfiles/WebCatalog-${CHROME_VER}.AppImage ${WRKSRC}
	chmod +x  ${WRKSRC}/WebCatalog-${CHROME_VER}.AppImage
	cd ${WRKSRC} && ${WRKSRC}/WebCatalog-${CHROME_VER}.AppImage --appimage-extract
	mv   ${WRKSRC}/squashfs-root ${WRKSRC}/webcatalog


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/webcatalog  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/  && ${CP} -r webcatalog  ${STAGEDIR}${PREFIX}/share

	cp files/@webcatalogdesktop.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/webcatalog/usr/share/icons/hicolor/${sz}x${sz}/apps/@webcatalogdesktop.png  ${STAGEDIR}${PREFIX}/share/pixmaps
.endfor

.include <bsd.port.mk>
