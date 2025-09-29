PORTNAME=	helium
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/imputnet/helium-linux/releases/download/0.4.12.1/
DISTNAME=	helium-0.4.12.1-x86_64_linux
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

SHEBANG_FILES=	helium-0.4.12.1-x86_64_linux/chrome

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	0.4.12.1
CHROME_BUILD?=	0b1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	linux-helium


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-helium  ${STAGEDIR}${PREFIX}/bin
	mkdir  -p ${STAGEDIR}${PREFIX}/share/linux-helium 
	cd ${WRKSRC}/ && ${CP} -r helium-0.4.12.1-x86_64_linux/* ${STAGEDIR}${PREFIX}/share/linux-helium
	${CP} files/helium.desktop ${STAGEDIR}${PREFIX}/share/applications
	${CP} ${WRKSRC}/helium-0.4.12.1-x86_64_linux/product_logo_256.png ${STAGEDIR}${PREFIX}/share/pixmaps/helium.png

.include <bsd.port.mk>
