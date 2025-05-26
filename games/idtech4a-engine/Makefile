PORTNAME=	idtech4a-engine
DISTVERSION=	v1.1.0harmattan65

CATEGORIES=	games
GH_PROJECT=     com.n0n3m4.diii4a
USE_GITHUB=	yes
GH_ACCOUNT=	glKarin
COMMENT=	idTEch4a Engine provided Doom3/Quake4/Prey source port
WWW=		https://github.com/glKarin/com.n0n3m4.diii4a

USES=           cmake
#USE_GCC=	yes	

BUILD_DEPENDS =	ninja>0:devel/ninja \
		libogg>0:audio/libogg \
		libvorbis>0:audio/libvorbis \
		openal-soft>0:audio/openal-soft \
		curl>0:ftp/curl \
		sdl2>0:devel/sdl20 \
		gcc>0:lang/gcc




CMAKE_ARGS +=	-DUSE_SYSTEM_ZLIB=ON -DOPENAL=TRUE
CMAKE_ARGS +=	-DCMAKE_BUILD_TYPE=Release -DSDL2=ON 
CMAKE_ARGS +=	-DUSE_SYSTEM_CURL=ON -DNO_ALSA=ON
 
WRKSRC=		${WRKDIR}/com.n0n3m4.diii4a-1.1.0harmattan65/Q3E/src/main/jni/doom3/neo

.include <bsd.port.mk>