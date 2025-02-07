PORTNAME=	xfce-winxp-tc
GH_TAGNAME=	4f73e4a
CATEGORIES=	x11-themes gnome



MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

USE_GITHUB=	yes
GH_ACCOUNT=	rozniak
GH_PROJECT=     xfce-winxp-tc



NO_ARCH=	yes


BUILD_DEPENDS=	cmake:devel/cmake
		

do-build:
		cd ${WRKSRC}/packaging && ./buildall.sh


do-install:
	
.for dir in    shared/comctl shared/comgtk shared/exec shared/msgina shared/registry shared/shcommon shared/shell shared/shelldpa shared/shellext shared/shlang shared/sndapi shared/syscfg shared/winbrand base/bootvid base/bldtag base/logonui base/regsvc cursors/no-shadow/standard cursors/with-shadow/standard fonts icons/luna sounds themes/native themes/professional themes/luna/blue themes/luna/metallic shell/cpl/desk shell/cpl/printers shell/cpl/sysdm shell/desktop shell/explorer shell/run shell/shext/zip shell/taskband shell/winver wallpapers windows/notepad
		cp  -rLP ${WRKSRC}/packaging/build/${dir}/out/usr  ${STAGEDIR}/
.endfor
.include <bsd.port.mk>