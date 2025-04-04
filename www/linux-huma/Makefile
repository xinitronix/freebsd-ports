PORTNAME=	huma
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/Huma-Browser/browser/releases/download/0b1/
# huma-mutlilocal-0b1.zip
DISTNAME=	 huma-mutlilocal-${CHROME_BUILD}
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

SHEBANG_FILES=	huma/huma

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.zip
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	11.19.0
CHROME_BUILD?=	0b1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	linux-huma


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-huma  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/ && ${CP} -r huma ${STAGEDIR}${PREFIX}/share
#	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
	cp files/huma.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16  32 48 64 128 
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/huma/browser/chrome/icons/default/default${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/huma.png
.endfor

.include <bsd.port.mk>
