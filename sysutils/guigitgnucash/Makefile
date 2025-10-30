PORTNAME=	GuiGitGnucash
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g744fd3a
CATEGORIES=	sysutils

USES=            desktop-file-utils  \
                qmake:outsource qt:5 shared-mime-info

RUN_DEPENDS=   	git>0:devel/git \
		gnupg>0:security/gnupg


USE_QT=         buildtools:build 
USE_GITHUB=	yes
GH_ACCOUNT=	definitly486


do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/.build/GuiGitGnucash            ${STAGEDIR}${PREFIX}/bin/GuiGitGnucash
		${CP}        files/gnucash-gui.desktop                       ${STAGEDIR}${PREFIX}/share/applications
		${CP}        files/gnucash.png                               ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>