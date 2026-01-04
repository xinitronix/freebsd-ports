PORTNAME=	tun2socks
DISTVERSION=	v2.6.0-1
DISTVERSIONSUFFIX= -g5755035
CATEGORIES=	net
WWW=            https://github.com/xjasonlyu/tun2socks

USES=           go

USE_GITHUB=	yes
GH_ACCOUNT=	xjasonlyu


do-build:
		cd  ${WRKSRC}/  && make -j6
do-install:
		cp 	${WRKSRC}/build/tun2socks-freebsd-amd64-v3   ${STAGEDIR}${PREFIX}/bin/tun2socks

.include <bsd.port.mk>