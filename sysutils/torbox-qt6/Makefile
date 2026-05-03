PORTNAME=	torbox-qt6
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g8ed0c2e946bcf528d
CATEGORIES=	sysutils

USES=           desktop-file-utils  \
                qmake:outsource qt:6 shared-mime-info
WWW=            https://github.com/vcore486-afk//torbox-qt6

USE_GITHUB=	yes
GH_ACCOUNT=	vcore486-afk
GH_PROJECT=	torbox-qt6

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		qt5-buildtools>0:devel/qt5-buildtools 
		

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/TorBox    ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>