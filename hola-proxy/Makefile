PORTNAME=	hola-proxy
DISTVERSION=	v1.15.0
DISTVERSIONSUFFIX=	-ge2dbbb9
CATEGORIES=	www 




BUILD_DEPENDS=	go:lang/go 


USE_GITHUB=	yes
GH_ACCOUNT=	Snawoot



do-build:

		cd  ${WRKSRC}/  && make
do-install:
	
		cp 	${WRKSRC}/bin/hola-proxy   ${STAGEDIR}${PREFIX}/bin
                     


.include <bsd.port.mk>