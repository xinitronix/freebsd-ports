PORTNAME=	zsh2
PORTVERSION=	1
CATEGORIES=	shells
MASTER_SITES=	https://github.com/definitly486/zsh2/releases/download/zsh/
DISTNAME=	zsh

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz

do-install:
		cd ${WRKSRC}/zsh  && ${CP} -r . ${STAGEDIR}${PREFIX}/share/zsh
.include <bsd.port.mk>