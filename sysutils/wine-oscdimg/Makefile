PORTNAME=	oscdimg
DISTVERSION=	2.56
CATEGORIES=     sysutils
MASTER_SITES=   https://github.com/definitly486/uefi-bhyve/releases/download/oscdimg/
DISTFILES=      oscdimg.tar.xz
PKGNAMEPREFIX=	wine-

RUN_DEPENDS=    wine>0:emulators/wine

NO_BUILD=	yes

SUB_FILES=	oscdimg



do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/oscdimg                       ${STAGEDIR}${PREFIX}/bin
		mkdir        ${STAGEDIR}${PREFIX}/share/oscdimg
		${CP} -r     ${WRKDIR}/oscdimg.exe   		          ${STAGEDIR}${PREFIX}/share/oscdimg         
.include <bsd.port.mk>