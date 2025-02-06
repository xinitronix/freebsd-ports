PORTNAME=	buuf-nestort-icons-themes
GL_COMMIT=      master
CATEGORIES=	x11-themes gnome



MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

USE_GITLAB=	yes
GL_ACCOUNT=	beucismis
GL_PROJECT=     buuf-nestort


NO_BUILD=	yes
NO_ARCH=	yes


do-install:
		mkdir    ${STAGEDIR}${PREFIX}/share/icons/${GL_PROJECT}
		rm     ${WRKSRC}/apps/preferences-web-browser-shortcuts.png
		rm      ${WRKSRC}/places/kde-plasma_badge-symbolic.png
		rm      ${WRKSRC}/actions/send-to.png
		rm      ${WRKSRC}/actions/blueman-send.png
		rm      ${WRKSRC}/actions/document-share.png
	  	rm      ${WRKSRC}/actions/blueman-send-symbolic.png
		cp  -r  ${WRKSRC}/.     ${STAGEDIR}${PREFIX}/share/icons/${GL_PROJECT}/




.include <bsd.port.mk>