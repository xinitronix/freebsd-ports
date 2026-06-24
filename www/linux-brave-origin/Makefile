PORTNAME=	brave-origin
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/brave/brave-browser/releases/download/v1.93.100/

DISTNAME=	brave-browser-nightly-${CHROME_VER}-linux-amd64
PKGNAMEPREFIX=	linux-

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	New Brave Origin premium experience offers users a minimalist version of the Brave browser 
WWW=		https://brave.com/blog/brave-origin/

RUN_DEPENDS=	linux-rl9-wget>0:ftp/linux-rl9-wget \
		linux-rl9-gnupg2>0:security/linux-rl9-gnupg \
		update-mime-database:misc/shared-mime-info

USES=		cpe desktop-file-utils gnome linux:rl9 shared-mime-info shebangfix
USE_LINUX=	alsalib alsa-plugins-oss alsa-plugins-pulseaudio at-spi2-atk \
		ca-certificates cairo cups-libs curl dbuslibs dri expat \
		ffmpeg-libs gnupg gstreamer1-libav gtk3 libxkbcommon libunistring \
		nspr nss p11-kit pango sqlite3 wget xorglibs
ONLY_FOR_ARCHS=	amd64

SHEBANG_FILES=	brave

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.zip
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	1.93.100
CHROME_BUILD?=	1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	linux-brave-origin


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-brave-origin  ${STAGEDIR}${PREFIX}/bin
#	rm -r ${WRKSRC}/opt/vivaldi/WidevineCdm
	mkdir -p ${STAGEDIR}${PREFIX}/share/linux-brave-origin
	cd ${WRKSRC}/ && ${CP}  -r  -LP * ${STAGEDIR}${PREFIX}/share/linux-brave-origin
	cp files/linux-brave-origin.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/product_logo_${sz}_nightly.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/linux-brave-origin.png
.endfor

.include <bsd.port.mk>
