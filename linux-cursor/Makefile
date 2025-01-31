PORTNAME=	cursor
PORTVERSION=	${CHROME_VER}
CATEGORIES=	editors  linux
MASTER_SITES=	https://download.todesktop.com/230313mzl4w4u92/
#cursor-0.45.5-build-250128loaeyulq8-x86_64.AppImage
DISTFILES=	cursor-${CHROME_VER}-build-${CHROME_BUILD}-x86_64.AppImage
PKGNAMEPREFIX=	linux-

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Cursor is a code editor built for programming with AI.
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



SHEBANG_FILES=	cursor/cursor
NO_BUILD=	yes
NO_WRKSUBDIR=	yes




CHROME_VER?=	0.45.5
CHROME_BUILD?=	250128loaeyulq8

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	linux-cursor


do-extract:


	cp /usr/ports/distfiles/cursor-${CHROME_VER}-build-${CHROME_BUILD}-x86_64.AppImage  ${WRKSRC}
	chmod +x  ${WRKSRC}/cursor-${CHROME_VER}-build-${CHROME_BUILD}-x86_64.AppImage
	cd ${WRKSRC} && ${WRKSRC}/cursor-${CHROME_VER}-build-${CHROME_BUILD}-x86_64.AppImage --appimage-extract
	mv   ${WRKSRC}/squashfs-root ${WRKSRC}/cursor


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-cursor  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/  && ${CP} -r cursor  ${STAGEDIR}${PREFIX}/share

	cp files/cursor.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16  32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/cursor/usr/share/icons/hicolor/${sz}x${sz}/apps/cursor.png  ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/cursor.png
.endfor

.include <bsd.port.mk>
