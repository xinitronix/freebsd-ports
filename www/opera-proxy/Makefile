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
	
		cp 	${WRKSRC}/bin/opera-proxy    ${STAGEDIR}${PREFIX}/bin
		cp      files/opera-proxy.jpg        ${STAGEDIR}${PREFIX}/share/pixmaps
		cp      files/opera-proxy.py         ${STAGEDIR}${PREFIX}/bin
		cp      files/opera-proxy.desktop    ${STAGEDIR}${PREFIX}/share/applications    


.include <bsd.port.mk>