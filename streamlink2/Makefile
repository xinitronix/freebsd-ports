PORTNAME=	streamlink2
CATEGORIES=	multimedia 
MASTER_SITES=	https://bitbucket.org/vcore/streamlink/downloads/
DISTNAME=	streamlink2



NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
SRC_SUFX?=		.src${EXTRACT_SUFX}

SUB_FILES=	streamlink


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/streamlink  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/ && ${CP} -r -LP streamlink2  ${STAGEDIR}${PREFIX}/share



.include <bsd.port.mk>
