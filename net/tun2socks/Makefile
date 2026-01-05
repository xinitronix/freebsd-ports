PORTNAME=	tun2socks
DISTVERSION=	v2.6.0-1
DISTVERSIONSUFFIX= -ga8e572b
CATEGORIES=	net
WWW=            https://github.com/SuzukiHonoka/tun2sock

USES=           go

USE_GITHUB=	yes
GH_ACCOUNT=	SuzukiHonoka


do-build:
		cd  ${WRKSRC}/  && make -j6
do-install:
		cp 	${WRKSRC}/build/tun2socks-freebsd-amd64-v3   ${STAGEDIR}${PREFIX}/bin/tun2socks

.include <bsd.port.mk>