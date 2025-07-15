PORTNAME=	nekoray
DISTVERSION=	4.0.1
DISTVERSIONSUFFIX=	-gadef6cd
CATEGORIES=	net

USE_GITHUB=	yes
GH_ACCOUNT=	MatsuriDayo
GH_TUPLE+=      Skycoder42:QHotkey:52e25acf221e5ac86ce648f6922620fb2d6a712:3rdparty/3rdparty/QHotkey 


WWW=	      	https://matsuridayo.github.io/


USES=cmake:noninja

do-install:
		cp ${WRKSRC}/res/nekobox.ico          ${STAGEDIR}${PREFIX}/share/pixmaps/nekoray.png
		mkdir -p                               ${STAGEDIR}${PREFIX}/share/nekoray
		cd ${WRKDIR}/.build && ${CP}  nekobox  ${STAGEDIR}${PREFIX}/share/nekoray/nekoray

		cp      files/nekoray.desktop    ${STAGEDIR}${PREFIX}/share/applications
post-install:
		 ln -s  /usr/local/share/nekoray/nekoray /usr/local/bin/nekoray
.include <bsd.port.mk>
