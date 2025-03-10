PORTNAME=	rainbowsix3
PORTVERSION=	${CHROME_VER}
CATEGORIES=	games 
MASTER_SITES=	https://github.com/definitly486/wine-games/releases/download/rainbowsix3/
DISTNAME=	rainbowsix3
PKGNAMEPREFIX=	wine-
COMMENT=        game  "Tom Clancy’s Rainbow Six 3: Raven Shield"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

CHROME_VER?=	v0.0.1
CHROME_BUILD?=	0b1

SUB_FILES=	rainbowsix3

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rainbowsix3  ${STAGEDIR}${PREFIX}/bin
	mkdir -p                                 ${STAGEDIR}${PREFIX}/share/
	cd ${WRKSRC}/ && ${CP} -r rainbowsix3    ${STAGEDIR}${PREFIX}/share/
	rm -R                                    ${STAGEDIR}${PREFIX}/share/rainbowsix3/Save
	cp -R files/Save                         ${STAGEDIR}${PREFIX}/share/rainbowsix3/
	chmod -R 0776                             ${STAGEDIR}${PREFIX}/share/rainbowsix3/Save
	cp files/rainbowsix3.desktop             ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>
