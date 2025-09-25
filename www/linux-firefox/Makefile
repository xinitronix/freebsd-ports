PORTNAME=	firefox
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www linux
MASTER_SITES=	https://ftp.mozilla.org/pub/firefox/releases/143.0/linux-x86_64/ru/

DISTNAME=	firefox-${CHROME_VER}
PKGNAMEPREFIX=	linux-

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Google web browser based on WebKit
WWW=		https://www.chromium.org/Home

RUN_DEPENDS=	linux-rl9-wget>0:ftp/linux-rl9-wget \
		linux-rl9-gnupg2>0:security/linux-rl9-gnupg \
		update-mime-database:misc/shared-mime-info

USES=		cpe desktop-file-utils gnome linux:rl9 shared-mime-info shebangfix
USE_LINUX=	alsalib alsa-plugins-oss alsa-plugins-pulseaudio at-spi2-atk \
		ca-certificates cairo cups-libs curl dbuslibs dri expat \
		ffmpeg-libs gnupg gstreamer1-libav gtk3 libxkbcommon libunistring \
		nspr nss p11-kit pango sqlite3 wget xorglibs
ONLY_FOR_ARCHS=	amd64

SHEBANG_FILES=	firefox/firefox

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	143.0
CHROME_BUILD?=	1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	linux-firefox


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-firefox  ${STAGEDIR}${PREFIX}/bin
#	rm -r ${WRKSRC}/opt/vivaldi/WidevineCdm
	mkdir -p ${STAGEDIR}${PREFIX}/share/linux-firefox
	cd ${WRKSRC}/ && ${CP}  -r  -LP firefox/* ${STAGEDIR}${PREFIX}/share/linux-firefox
	cp files/linux-firefox.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16  32 48 64 128 
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/firefox/browser/chrome/icons/default/default${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/linux-firefox.png
.endfor

.include <bsd.port.mk>
