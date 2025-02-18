PORTNAME=	firefox-dev
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www 
MASTER_SITES=	https://github.com/xinitronix/firefox-dev-browser-freebsd/releases/download/v0.0.2/

DISTNAME=	firefox-dev


MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Firefox Developer Edition is the blazing fast browser that offers cutting edge developer tools and latest features like CSS Grid support and framework
WWW=		https://firedragon.garudalinux.org/

RUN_DEPENDS=	nspr>=4.32:devel/nspr \
		nss>=3.107:security/nss \
		icu>=73.1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=10.1.0:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.44:graphics/png \
		dav1d>=1.0.0:multimedia/dav1d \
		libvpx>=1.15.0:multimedia/libvpx \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf2.13:devel/autoconf2.13 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip


ONLY_FOR_ARCHS=	amd64

SHEBANG_FILES=	firefox-dev/firefox

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.bz2
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	v0.0.2
CHROME_BUILD?=	1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	firefox-dev


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/firefox-dev  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/ && ${CP} -r  -LP firefox-dev ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
	cp files/firefox-dev.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16  32 48 64 128 
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/firefox-dev/browser/chrome/icons/default/default${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/firefox-dev.png
.endfor

.include <bsd.port.mk>
