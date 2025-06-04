PORTNAME=	opera-proxy
DISTVERSION=	v1.8.0
DISTVERSIONSUFFIX=	-g5b8bd17
CATEGORIES=	www 




BUILD_DEPENDS=	go:lang/go 


USE_GITHUB=	yes
GH_ACCOUNT=	Snawoot



do-build:

		cd  ${WRKSRC}/  && make
do-install:
	
		cp 	${WRKSRC}/bin/opera-proxy   ${STAGEDIR}${PREFIX}/bin
                     


.include <bsd.port.mk>