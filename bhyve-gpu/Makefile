PORTNAME=	bhyve-gpu 
DISTVERSION=	2025
DISTVERSIONSUFFIX=	-g44806f9
CATEGORIES=	sysutils

WWW=            https://dflund.se/~getz/Notes/2024/freebsd-gpu/

USE_GITHUB=	yes
GH_ACCOUNT=	definitly486

BUILD_WRKSRC=      	${WRKSRC}/bhyve

do-install:

		cp ${WRKSRC}/bhyve/bhyve  ${STAGEDIR}${PREFIX}/sbin/bhyve-gpu

.include <bsd.port.mk>