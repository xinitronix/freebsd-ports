PORTNAME=	zapret
DISTVERSION=	v69.9
DISTVERSIONSUFFIX=	-gf5cf791
CATEGORIES=	www 



USE_GITHUB=	yes
GH_ACCOUNT=	bol-van

do-build:

		cd  ${WRKSRC}/  && make


do-install:
	
		cp 	${WRKSRC}/binaries/my/dvtws   ${STAGEDIR}${PREFIX}/bin
                     

.include <bsd.port.mk>