PORTNAME=	dot-browser
PORTVERSION=	${CHROME_VER}
CATEGORIES=	www 
MASTER_SITES=	https://github.com/xinitronix/dot-browser-freebsd/releases/download/v0.0.1/

DISTNAME=	dot-browser


MAINTAINER=	chromium@FreeBSD.org
COMMENT=	The Dot Browser for Desktop source code, available on Windows, macOS and Linux.
WWW=		https://www.dothq.org/

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

SHEBANG_FILES=	dot-browser/dot-browser

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.bz2
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}



CHROME_VER?=	v0.0.1
CHROME_BUILD?=	1

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	dot-browser


do-install:
	rm ${WRKSRC}/dot-browser/browser/chrome/browser/content/browser/built_in_addons.json
	rm ${WRKSRC}/dot-browser/browser/chrome/devtools/modules/devtools/shared/webconsole/reserved-js-words.js
	rm ${WRKSRC}/dot-browser/modules/workers/PromiseWorker.mjs
	rm ${WRKSRC}/dot-browser/modules/workers/PromiseWorker.js
	rm ${WRKSRC}/dot-browser/modules/RFPTargetConstants.sys.mjs
	rm ${WRKSRC}/dot-browser/chrome/toolkit/content/global/neterror/aboutNetErrorCodes.js
	rm ${WRKSRC}/dot-browser/chrome/toolkit/res/nimbus/FeatureManifest.sys.mjs
	rm ${WRKSRC}/dot-browser/chrome/toolkit/featuregates/feature_definitions.json
	rm ${WRKSRC}/dot-browser/res/multilocale.txt
	${INSTALL_SCRIPT} ${WRKDIR}/dot-browser ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${CP} -r dot-browser ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share
	cp files/dot-browser.desktop ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16  32 48 64 128 
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/dot-browser/browser/chrome/icons/default/default${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/dot-browser.png
.endfor

.include <bsd.port.mk>
