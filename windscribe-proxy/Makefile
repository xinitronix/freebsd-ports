PORTNAME=	windscribe-proxy
DISTVERSION=	v1.5.0
DISTVERSIONSUFFIX=	-g05f6019
CATEGORIES=	www 




BUILD_DEPENDS=	go:lang/go 


USE_GITHUB=	yes
GH_ACCOUNT=	Snawoot



do-build:

		cd  ${WRKSRC}/  && make
do-install:
	
		cp 	${WRKSRC}/bin/windscribe-proxy   ${STAGEDIR}${PREFIX}/bin
                     


.include <bsd.port.mk>