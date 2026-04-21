PORTNAME=	sdr++
DISTVERSION=	20260421 # rolling (nightly) release is the current release model (see README)
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform SDR software
WWW=		https://github.com/AlexandreRouma/SDRPlusPlus

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libglfw.so:graphics/glfw \
		libvolk.so:devel/volk \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gl pkgconfig xorg
USE_GL=		gl glew glu opengl
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	AlexandreRouma
GH_PROJECT=	SDRPlusPlus
GH_TAGNAME=	a6df4d5



.include <bsd.port.mk>
