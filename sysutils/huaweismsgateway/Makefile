PORTNAME=	huaweismsgateway
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-ge3f5341bf176ecc711726bdfd92570b32eef09cc
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	definitly486
GH_PROJECT=	Huawei-SMS-Gateway

BUILD_DEPENDS=  qt6-tools>0:devel/qt6-tools


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/modem_sms  ${STAGEDIR}${PREFIX}/bin/huaweismsgateway
		${CP}        files/smsgateway.desktop         ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/sms.png                  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>