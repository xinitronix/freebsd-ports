PORTNAME=	opera-proxy
DISTVERSION=	v1.12.0-1
DISTVERSIONSUFFIX=	-g6ddb8d2
 
CATEGORIES=	www 




BUILD_DEPENDS=	go:lang/go 


USE_GITHUB=	yes
GH_ACCOUNT=	Snawoot



do-build:

		cd  ${WRKSRC}/  && make 
do-install:
	
		cp 	${WRKSRC}/bin/opera-proxy    ${STAGEDIR}${PREFIX}/bin
		cp      files/opera-proxy.jpg        ${STAGEDIR}${PREFIX}/share/pixmaps
		cp      files/opera-proxy.py         ${STAGEDIR}${PREFIX}/bin
		cp      files/opera-proxy.desktop    ${STAGEDIR}${PREFIX}/share/applications    


.include <bsd.port.mk>