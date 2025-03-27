# $FreeBSD$

PORTNAME=	wine-proton-5.13.6
DISTVERSION=	5.13-6
CATEGORIES=	emulators

MAINTAINER=	iwtcex@gmail.com
COMMENT=	Wine with a bit of extra spice

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libFAudio.so:audio/faudio \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgnutls.so:security/gnutls \
		libjpegxr.so:graphics/libjxr \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libvulkan.so:graphics/vulkan-loader \
		libxml2.so:textproc/libxml2

USES=		bison desktop-file-utils gettext-runtime gl gmake gnome jpeg localbase openal pkgconfig sdl shebangfix tar:xz xorg

USE_GITHUB=	yes
GH_ACCOUNT=	ValveSoftware
GH_PROJECT=	wine
GH_TAGNAME=	c14054e6923c3cbb4163c24ce41fcf2d0815e84b

USE_GCC=	yes
USE_GL=		glu
USE_GNOME=	glib20
USE_GSTREAMER1=	good
USE_SDL=	sdl2
USE_XORG=	x11 xext xcomposite xcursor xi xinerama xrandr xrender

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PORTNAME}

CONFIGURE_ARGS=	--verbose \
		--libdir=${PREFIX}/${PORTNAME}/lib \
		--disable-kerberos \
		--disable-tests \
		--with-cms \
		--with-fontconfig \
		--with-freetype \
		--with-glu \
		--with-gnutls \
		--with-gstreamer \
		--with-jpeg \
		--with-jxrlib \
		--with-openal \
		--with-opengl \
		--with-oss \
		--with-png \
		--with-sdl \
		--with-vulkan \
		--with-x \
		--with-xinerama \
		--with-xinput2 \
		--with-xrandr \
		--with-xrender \
		--without-alsa \
		--without-capi \
		--without-cups \
		--without-dbus \
		--without-gettext \
		--without-gettextpo \
		--without-gphoto \
		--without-gsm \
		--without-hal \
		--without-inotify \
		--without-krb5 \
		--without-ldap \
		--without-mingw \
		--without-mpg123 \
		--without-opencl \
		--without-osmesa \
		--without-pulse \
		--without-sane \
		--without-tiff \
		--without-udev \
		--without-unwind \
		--without-usb \
		--without-v4l2 \
		--without-vkd3d \
		--without-xslt

CONFIGURE_ENV=	CPPBIN="${CPP}" FLEX="${LOCALBASE}/bin/flex" JXRLIB_CFLAGS="-I${LOCALBASE}/include/jxrlib"

SHEBANG_FILES=	tools/make_requests tools/winemaker/winemaker \
		tools/winedump/function_grep.pl

.include <bsd.port.pre.mk>

.if ${LLVM_DEFAULT} == 11
_LLVM_VERSION=	15
.else
_LLVM_VERSION=	${LLVM_DEFAULT}
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	WINE32="@comment " WINE64="" WINEARCH="x86_64"
CONFIGURE_ARGS+=--enable-win64
.else
PLIST_SUB+=	WINE32="" WINE64="@comment " WINEARCH="i386"
.endif

post-patch:
	${REINPLACE_CMD} 's/CFLAGS="$$llvm_extra_cflags $$llvm_cflags"/CFLAGS="$$CROSSCFLAGS $$llvm_extra_cflags $$llvm_cflags"/g' ${WRKSRC}/configure.ac

pre-configure:
#	cd ${WRKSRC} && ${PYTHON_CMD} dlls/winevulkan/make_vulkan --xml vk.xml
#	cd ${WRKSRC} && ${PERL5} tools/make_specfiles

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} depend
	cd ${WRKSRC} && ${PERL5} tools/make_requests

post-install:
.if ${ARCH} == i386
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wineserver ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wineserver32
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine       ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine.bin
	-${ELFCTL} -e +noaslr                                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine
.else
	${INSTALL_SCRIPT} ${FILESDIR}/pkg32.sh                ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/pkg32.sh
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64     ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64.bin
	${INSTALL_SCRIPT} ${FILESDIR}/wine.sh                 ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine64
	${INSTALL_SCRIPT} ${FILESDIR}/wine-wow64.sh           ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/wine
.endif
	${RM} -r ${STAGEDIR}${PREFIX}/${PORTNAME}/include
	${RM} -r ${STAGEDIR}${PREFIX}/share/man
	${MKDIR} ${STAGEDIR}${DOCSDIR}


.include <bsd.port.post.mk>