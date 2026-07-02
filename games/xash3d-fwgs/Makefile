PORTNAME=	xash3d-fwgs
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g9f2b895
CATEGORIES=	games

BUILD_DEPENDS=	python>0:lang/python \
		freetype2>0:print/freetype2

GH_ACCOUNT=	fwgs
GH_PROJECT=	xash3d-fwgs
USE_GITHUB=	yes

GH_TUPLE= \
	FWGS:mainui_cpp:510c30c51a9ebabfb703b95872751357a63cd1d5:mainui/3rdparty/mainui \
	FWGS:nanogl:6c8aeca5e6c221e99d246a82916d1ca062cc681b:nanogl/3rdparty/nanogl \
	FWGS:gl-wes-v2:9c8ef67f97aa1640ea2e3eed08d87d3d1c670f2f:glwes/3rdparty/gl-wes-v2 \
	ptitSeb:gl4es:1543ec5074c55692ac25e0612bf8599f3c4de088:gl4es/3rdparty/gl4es/gl4es \
	FWGS:vgui_support:d2aaec107d70ffb45a167cfb33ecf849310aa330:vgui/3rdparty/vgui_support \
	xiph:opus:82ac57d9f1aaf575800cf17373348e45b7ce6c0d:opus/3rdparty/opus/opus \
	FWGS:xash-extras:9f5b017985981e5eadd1813c0cde1e4f217e12e1:extras/3rdparty/extras/xash-extras \
	FWGS:MultiEmulator:e369abc23c49310b0f5e58f12fef6f46563b0d21:multiemu/3rdparty/MultiEmulator \
	xiph:ogg:7cf42ea17aef7bc1b7b21af70724840a96c2e7d0:ogg/3rdparty/libogg/libogg \
	xiph:vorbis:bb4047de4c05712bf1fd49b9584c360b8e4e0adf:vorbis/3rdparty/vorbis/vorbis-src \
	xiph:opusfile:3ecc22aa0a4430f61c2403d57370a089536d197a:opusfile/3rdparty/opusfile/opusfile \
	ianlancetaylor:libbacktrace:b9e40069c0b47a722286b94eb5231f7f05c08713:libbacktrace/3rdparty/libbacktrace/libbacktrace \
	FWGS:xash3d-maintui:e5f143ee3370bf9c897015b60bcefbdf2937187e:maintui/3rdparty/maintui \
	FWGS:library-suffix:a35ac9c12ee31bb84c13dc1d633cca72d0b3264c:librarysuffix/3rdparty/library_suffix \
	FWGS:mbedtls-releases:701bb7cfdef4c8860e7fdafcec1e7ec8a05a37a9:mbedtls/3rdparty/mbedtls/mbedtls \
	Velaron:ReGameDLL_CS:4dddce6a10c267bc17c7afec1c020983fbdd0284:regame/3rdparty/ReGameDLL_CS \
	yapb:yapb:4967a220ba3a58c461ee1cef8b6fb37c6fd93b5e:yapb/3rdparty/yapb \
	FWGS:MiniUTL:048a416f4c54c501dfd728fd792bfdc9f2883f51:miniutl/3rdparty/mainui/miniutl \
	yapb:crlib:7efccddc085dbaef20e1310f3e270f07cb2b0eff:crlib/3rdparty/yapb/ext/crlib \
	yapb:linkage:a21540a52d7559333ad9d8326411daf78af62891:linkage/3rdparty/yapb/ext/linkage

SUB_FILES=	cs16

USES=           python
BUILD_DEPENDS= ${PYTHON_CMD}:lang/python

do-configure:
	cd ${WRKSRC} && \
		${PYTHON_CMD} ./waf configure -8

do-build:
	cd ${WRKSRC} && \
		${PYTHON_CMD} ./waf build

do-install:
	cd ${WRKSRC} && \
		${PYTHON_CMD} ./waf install --destdir=${STAGEDIR}${PREFIX}/local/share/xash3d-fwgs
	${INSTALL_SCRIPT} ${WRKDIR}/cs16 ${STAGEDIR}${PREFIX}/bin/cs16

.include <bsd.port.mk>
