PORTNAME=	huaweismsgateway
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-gcdd240a6e6d37cba9d
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	definitly486
GH_PROJECT=	Huawei-SMS-Gateway

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools \
		tinyxml2>0:textproc/tinyxml2 \
		qt5-buildtools>0:devel/qt5-buildtools


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/modem_sms  ${STAGEDIR}${PREFIX}/bin/huaweismsgateway
		${CP}        files/smsgateway.desktop         ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/sms.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>