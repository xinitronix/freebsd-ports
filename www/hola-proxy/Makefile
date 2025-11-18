PORTNAME=	hola-proxy
DISTVERSION=	v1.18.2-2
DISTVERSIONSUFFIX=	-g25958fd
CATEGORIES=	www 




BUILD_DEPENDS=	go:lang/go 


USE_GITHUB=	yes
GH_ACCOUNT=	Snawoot



do-build:

		cd  ${WRKSRC}/  && make -buildvcs=false
do-install:
	
		cp 	${WRKSRC}/bin/hola-proxy       ${STAGEDIR}${PREFIX}/bin
		cp      files/hola-proxy.svg        ${STAGEDIR}${PREFIX}/share/pixmaps
		cp      files/hola-proxy.py         ${STAGEDIR}${PREFIX}/bin
		cp      files/hola-proxy.desktop    ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>