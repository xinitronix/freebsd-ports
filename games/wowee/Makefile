PORTNAME=	WoWee
DISTVERSION=	3.1.22-1
DISTVERSIONSUFFIX=	-g3f92198
CATEGORIES=	games

USE_GITHUB=	yes
GH_ACCOUNT=	Kelsidavis
GH_TUPLE+=	ocornut:imgui:814c6a194bcb1172df8b8ac9d6520ac0e77654dc:imgui \
                charles-lunarg:vk-bootstrap:2e7c8e8323c0fe7efc96dc241610fcba35d8f530:vk_bootstrap
GH_SUBDIR=	extern/imgui:imgui \
		extern/vk-bootstrap:vk_bootstrap

WWW=	      	https://github.com/Kelsidavis/WoWee

USES=		cmake:noninja

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/bin/wowee                ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_SCRIPT} ${WRKDIR}/.build/wowee.desktop            ${STAGEDIR}${PREFIX}/share/applications
		mkdir   -p                                                  ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/ 
		${INSTALL_SCRIPT} ${WRKSRC}/assets/Wowee.png                ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/wowee.png

.include <bsd.port.mk>
