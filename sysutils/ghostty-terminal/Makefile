PORTNAME=	ghostty-terminal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0-1
DISTVERSIONSUFFIX=	-g3e38e28
 
CATEGORIES=	sysutils


COMMENT=	Ghostty is a fast, feature-rich, and cross-platform terminal emulator that uses platform-native UI and GPU acceleration. 
WWW=		https://github.com/ghostty-org/ghostty

USE_GITHUB=	yes
GH_ACCOUNT=	ghostty-org
GH_PROJECT=	ghostty

RUN_DEPENDS=    gtk4-layer-shell>0:x11-toolkits/gtk4-layer-shell \
		zig>0:lang/zig \
		ca_root_nss>0:security/ca_root_nss \
		hs-pandoc>0:textproc/hs-pandoc \
		gettext-tools>0:devel/gettext-tools \
		blueprint-compiler>0:devel/blueprint-compiler \
		libadwaita>0:x11-toolkits/libadwaita

NO_ARCH=	yes
NO_BUILD=	yes



do-install:
	cd ${WRKSRC} && zig build -p ${STAGEDIR}${PREFIX}/share/ghostty -Dapp-runtime=gtk -Doptimize=ReleaseFast
	cp files/ghostty.desktop        ${STAGEDIR}${PREFIX}/share/applications
.for sz in 16  32  128 256 512 1024
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps
	${CP} ${WRKSRC}/images/icons/icon_${sz}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${sz}x${sz}/apps/ghostty.png
.endfor

.include <bsd.port.mk>
