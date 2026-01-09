PORTNAME=	operaproxy-qt6
DISTVERSION=	v0.1.0-1
DISTVERSIONSUFFIX=	-gc034a42760c75a65
CATEGORIES=	net

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk
GH_TUPLE=       Snawoot:opera-proxy:6ddb8d2:Snawoot/vendor/github.com/Snawoot/opera-proxy

WWW=	      	https://github.com/vcore486-afk/operaproxy-qt6

USES=           qmake:outsource qt:6

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools \
		qt6-webengine>0:www/qt6-webengine \
                go>0:lang/go

TAG= ${GH_TUPLE:C/^[^:]*:[^:]*:([^:]*):.*$/\1/}


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/operaproxy-qt6        ${STAGEDIR}${PREFIX}/bin/operaproxy-qt6
		${CP}        files/opera-proxy.jpg                    ${STAGEDIR}${PREFIX}/share/pixmaps
		${CP}        files/opera-proxy.desktop               ${STAGEDIR}${PREFIX}/share/applications
		cd ${WRKDIR}/opera-proxy-${TAG} && make -j6
		${CP} ${WRKSRC}/vendor/github.com/Snawoot/opera-proxy/bin/opera-proxy            ${STAGEDIR}${PREFIX}/bin/
		${CP}        files/operaproxy                  ${STAGEDIR}${PREFIX}/etc/rc.d  
               

.include <bsd.port.mk>