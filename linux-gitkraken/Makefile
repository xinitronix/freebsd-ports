PORTNAME=	gitkraken
PORTVERSION=	${CHROME_VER}
CATEGORIES=	devel linux
MASTER_SITES=   https://release.axocdn.com/linux/
DISTNAME=	gitkraken-amd64
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

SHEBANG_FILES=	gitkraken/gitkraken

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.gz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	10.7.0
CHROME_BUILD?=	0b1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	linux-gitkraken


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-gitkraken  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/ && ${CP} -r gitkraken ${STAGEDIR}${PREFIX}/share
#	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
	cp files/gitkraken.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in  32 64 128 256 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/gitkraken/gitkraken.png ${STAGEDIR}${PREFIX}/share/pixmaps/gitkraken.png
.endfor

.include <bsd.port.mk>
