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
	
		cp 	${WRKSRC}/bin/hola-proxy       ${STAGEDIR}${PREFIX}/bin
		cp      files/hola-proxy.svg        ${STAGEDIR}${PREFIX}/share/pixmaps
		cp      files/hola-proxy.py         ${STAGEDIR}${PREFIX}/bin
		cp      files/hola-proxy.desktop    ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>