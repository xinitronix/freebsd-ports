PORTNAME=	kylin-video
PORTVERSION=	v2.0.1
DISTVERSION=	2024
DISTVERSIONSUFFIX=	-g39ccf8c
CATEGORIES=	multimedia

BUILD_DEPENDS=	bash>0:shells/bash

USES=		qmake:outsource qt:5
USE_QT6=	        buildtools_build	
USE_GITHUB=	yes
GH_ACCOUNT=	UbuntuKylin
QMAKE_CONFIGURE_ARGS+=     PREFIX="${PREFIX}"
QMAKE_ARGS+=	           PREFIX="${PREFIX}"
post-install:


.include <bsd.port.mk>
