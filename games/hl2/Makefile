PORTNAME=	hl2
DISTVERSION=    1.16
DISTVERSIONSUFFIX=	-g2998568
CATEGORIES=	games

BUILD_DEPENDS=  python>0:lang/python \
		clang17:devel/llvm17 \
		freetype2>0:print/freetype2 

GH_PROJECT=     source-engine
USE_GITHUB=     yes
GH_ACCOUNT=     nillerusr
GH_TUPLE+=	nillerusr:source-physics:47533475e01cbff05fbc3bbe8b4edc485f292cea:nilleru/ivp \
		nillerusr:source-thirdparty:cc41c319aabc287b1f7439228af5a9edeb31ee05:nillerusr/thirdparty

SUB_FILES=	hl2

do-build:

		cd  ${WRKSRC}/&& env CC=clang17 CXX=clang++17 ./waf configure -T release    --build-games=hl2  && ./waf build -j6

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/hl2  ${STAGEDIR}${PREFIX}/bin		
		mkdir  -p ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/datacache/libdatacache.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/engine/libengine.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/engine/voice_codecs/minimp3/libvaudio_minimp3.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/filesystem/libfilesystem_stdio.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/gameui/libGameUI.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/inputsystem/libinputsystem.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/launcher/liblauncher.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/materialsystem/libmaterialsystem.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/materialsystem/shaderapidx9/libshaderapidx9.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/materialsystem/stdshaders/libstdshader_dx9.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/scenefilecache/libscenefilecache.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/serverbrowser/libServerBrowser.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/soundemittersystem/libsoundemittersystem.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/studiorender/libstudiorender.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/tier0/libtier0.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/stub_steam/libsteam_api.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/vgui2/src/libvgui2.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/vguimatsurface/libvguimatsurface.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/video/libvideo_services.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/vphysics/libvphysics.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/vstdlib/libvstdlib.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/togl/libtogl.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/utils/vtex/libvtex_dll.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/launcher_main/hl2_launcher ${STAGEDIR}${PREFIX}/share/HL2/
		cp  ${WRKSRC}/build/game/client/libclient.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  ${WRKSRC}/build/game/server/libserver.so ${STAGEDIR}${PREFIX}/share/HL2/bin
		cp  files/hl2.png   ${STAGEDIR}${PREFIX}/share/pixmaps
		cp  files/hl2.desktop  ${STAGEDIR}${PREFIX}/share/applications
		
.include <bsd.port.mk>