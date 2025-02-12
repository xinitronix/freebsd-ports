PORTNAME=	idesk2
DISTVERSION=	v0.7.8
DISTVERSIONSUFFIX=	-gb7397fc
CATEGORIES=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	neagix
GH_PROJECT=     idesk



do-build:
		cd  ${WRKSRC}/&& ./configure CXXFLAGS="-std=c++11 -L/usr/local/lib/ -lImlib2" && gmake -j6
		
do-install:
		cp  ${WRKSRC}/src/idesk   ${STAGEDIR}${PREFIX}/bin

 
.include <bsd.port.mk>