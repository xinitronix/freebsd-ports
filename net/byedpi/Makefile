PORTNAME=	byedpi
DISTVERSION=	v0.17.3-1
DISTVERSIONSUFFIX= -g9938d74
CATEGORIES=	net
WWW=            https://github.com/hufrea/byedpi

USE_GITHUB=	yes
GH_ACCOUNT=	hufrea

do-install:
		cp 	${WRKSRC}/ciadpi    ${STAGEDIR}${PREFIX}/bin/
		cp      files/ciadpi        ${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>