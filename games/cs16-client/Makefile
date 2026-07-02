PORTNAME=	cs16-client
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g934a366
CATEGORIES=	games

BUILD_DEPENDS=	python>0:lang/python \
		clang19:devel/llvm19 \
		freetype2>0:print/freetype2

GH_ACCOUNT=	Velaron
GH_PROJECT=	cs16-client
USE_GITHUB=	yes

GH_TUPLE=	Velaron:ReGameDLL_CS:d1af1363e1aa91553ee5773217070208bf1e941f:regame/3rdparty/ReGameDLL_CS \
		yapb:yapb:4967a220ba3a58c461ee1cef8b6fb37c6fd93b5e:yapb/3rdparty/yapb \
		Velaron:mainui_cpp:aeb40bf2e0bf4809f1d5ab355b016b93f7a89099:mainui/3rdparty/mainui_cpp \
		FWGS:MiniUTL:048a416f4c54c501dfd728fd792bfdc9f2883f51:miniutl/3rdparty/miniutl \
		yapb:crlib:7efccddc085dbaef20e1310f3e270f07cb2b0eff:crli/3rdparty/yapb/ext/crlib \
		yapb:linkage:a21540a52d7559333ad9d8326411daf78af62891:linkage/3rdparty/yapb/ext/linkage


USES=		cmake
CMAKE_BUILD_TYPE=	Release


CMAKE_ARGS= \
    -DCMAKE_INSTALL_PREFIX=${PREFIX}/share/HL2 \
    -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=OFF \
    -DMINIUTL_DISABLE_TIER0_REDEFS=ON \
    -DCMAKE_CXX_FLAGS="\
        -I${WRKSRC}/3rdparty \
        -I${WRKSRC}/3rdparty/compat \
        -DCR_FREEBSD \
        -D__BSD_VISIBLE=1 \
        -DHL_DISABLE_MINIUTL_INLINE_COLLISIONS \
    "
CXXFLAGS+= \
    -I${WRKSRC}/3rdparty \
    -I${WRKSRC}/3rdparty/miniutl

SUB_FILES=	cs16

post-extract:
	${RM} -r ${WRKSRC}/3rdparty/mainui_cpp/miniutl
	${LN} -s ${WRKSRC}/3rdparty/miniutl ${WRKSRC}/3rdparty/mainui_cpp/miniutl


do-install:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${DESTDIRNAME}=${STAGEDIR} ${CMAKE_BIN} --install .
	${INSTALL_SCRIPT} ${WRKDIR}/cs16 ${STAGEDIR}${PREFIX}/bin/cs16


.include <bsd.port.mk>
