PORTNAME=       ImPlay
DISTVERSION=    1.5.1
CATEGORIES=     multimedia

MAINTAINER=     ports@FreeBSD.org
COMMENT=        ImPlay is a Cross-Platform Desktop Media Player, built on top of mpv and ImGui.
WWW=            https://tsl0922.github.io/ImPlay/

BUILD_DEPENDS=  glfw>0:graphics/glfw \
		gcc13>0:lang/gcc13

USES=           cmake
USE_GITHUB=     yes
GH_ACCOUNT=     tsl0922
GH_TUPLE+=      
USE_GCC=        yes

post-patch:

.include <bsd.port.mk>