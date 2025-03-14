PORTNAME=	painkiller
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/halo/ 
DISTNAME=	painkiller
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Painkiller: Black Edition" GOG wine
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

CHROME_VER?=	v0.0.1

SUB_FILES=	painkiller

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/painkiller            ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                          ${STAGEDIR}${PREFIX}/share/GOG
	cd ${WRKSRC}/ && ${CP} -r   painkiller            ${STAGEDIR}${PREFIX}/share/GOG
	cp files/painkiller.desktop                       ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
