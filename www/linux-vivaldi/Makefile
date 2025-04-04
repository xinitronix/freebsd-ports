PORTNAME=	vivaldi
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www linux
MASTER_SITES=	https://downloads.vivaldi.com/stable/
#vivaldi-stable-7.1.3570.39-1.x86_64.rpm
DISTNAME=	vivaldi-stable-${CHROME_VER}-${CHROME_BUILD}.x86_64
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

SHEBANG_FILES=	opt/vivaldi/vivaldi

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.rpm
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	7.1.3570.39
CHROME_BUILD?=	1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	linux-vivaldi


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-vivaldi ${STAGEDIR}${PREFIX}/bin
	rm -r ${WRKSRC}/opt/vivaldi/WidevineCdm
	cd ${WRKSRC}/opt/ && ${CP} -r vivaldi ${STAGEDIR}${PREFIX}/share
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
	cp files/vivaldi-stable.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16 24 32 48 64 128 256
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${STAGEDIR}${DATADIR}/product_logo_${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/vivaldi.png
.endfor

.include <bsd.port.mk>
