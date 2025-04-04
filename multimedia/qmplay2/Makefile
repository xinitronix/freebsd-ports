PORTNAME=       QMPlay2
DISTVERSION=    25.01.19
CATEGORIES=     multimedia

MAINTAINER=     ports@FreeBSD.org
COMMENT=        QMPlay2 is a video and audio player 
WWW=            https://github.com/zaps166/QMPlay2

BUILD_DEPENDS=   portaudio>0:audio/portaudio

USES=           cmake ninja 
USE_GITHUB=     yes
GH_ACCOUNT=     zaps166
GH_TUPLE+=	zaps166:QmVk:6fcba890694d7a5524d5f67e7387365d187b6286:QmVk/src/qmvk \
		KhronosGroup:Vulkan-Headers:5a5c9a643484d888873e32c5d7d484fae8e71d3d:KhronosGroup/src/qmplay2/vulkan/headers


post-patch:

.include <bsd.port.mk>