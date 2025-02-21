PORTNAME=	xboxdrv
DISTVERSION=	v0.8.14
DISTVERSIONSUFFIX=	-ga7be450
CATEGORIES=	x11




USES=meson
USE_GITHUB=	yes
GH_ACCOUNT=	xiota

BUILD_DEPENDS=  gsed>=4.9:textproc/gsed \
                meson>0:devel/meson \
		ninja>0:devel/ninja


post-install:
		cp files/xboxdrv           ${STAGEDIR}${PREFIX}/etc/rc.d/

               
.include <bsd.port.mk>