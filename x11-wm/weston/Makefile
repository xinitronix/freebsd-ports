PORTNAME=       weston 
DISTVERSION=    12.0.5
CATEGORIES=     x11-wm wayland

USE_GITLAB=     yes
GL_SITE=        https://gitlab.freedesktop.org
GL_ACCOUNT=	wayland

USES=           meson

MESON_ARGS=    	-Dbackend-rdp=false\
		-Dsystemd=false\
		-Db_lundef=false

post-install:
		${CP} files/weston.desktop           ${STAGEDIR}${PREFIX}/share/applications
		${CP} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/data/wayland.png   ${STAGEDIR}${PREFIX}/share/pixmaps/weston.png

.include <bsd.port.mk>