PORTNAME=	openmohaa
DISTVERSION=	2024
DISTVERSIONSUFFIX=	-gf16bec1
CATEGORIES=	games
USE_GITHUB=	yes
GH_ACCOUNT=	openmoh

BUILD_DEPENDS=    gcc>0:lang/gcc

do-build:
		cd  ${WRKSRC}/&& cmake  -D CMAKE_C_COMPILER=/usr/local/bin/gcc13 -D CMAKE_CXX_COMPILER=/usr/local/bin/g++13  && gmake -j6
post-install:
		cp files/mohaa.png              ${STAGEDIR}${PREFIX}/share/pixmaps
		cp files/mohaa.desktop          ${STAGEDIR}${PREFIX}/share/applications
.include <bsd.port.mk>