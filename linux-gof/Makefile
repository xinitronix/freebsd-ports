PORTNAME=	gof
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games linux
MASTER_SITES=	https://github.com/definitly486/linux-gof/releases/download/v0.0.1/
DISTNAME=	gof
PKGNAMEPREFIX=	linux-
COMMENT=        game Guns of Fury
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	linux-gof


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-gof  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/ && ${CP} -r gof ${STAGEDIR}${PREFIX}/share
	cp files/gof.desktop ${STAGEDIR}${PREFIX}/share/applications
	cp files/icon.png  ${STAGEDIR}${PREFIX}/share/pixmaps/gof.png


.include <bsd.port.mk>
