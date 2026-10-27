PORTNAME=	android-sdk-build-tools
DISTVERSION=	v36.1.0
CATEGORIES=     devel
MASTER_SITES=   https://github.com/definitly486/definitly486/releases/download/android-sdk-build-tools/
DISTFILES=      android-sdk-build-tools.zip

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=	.zip

SUB_FILES=	aapt aapt2 zipalign

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/aapt                                           ${STAGEDIR}${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKDIR}/aapt2                                          ${STAGEDIR}${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKDIR}/zipalign                                       ${STAGEDIR}${PREFIX}/bin
		mkdir -p                                                                   ${STAGEDIR}${PREFIX}/share/android-sdk-build-tools
		cd ${WRKSRC}/android-sdk-build-tools  && ${CP} -r *                                                ${STAGEDIR}${PREFIX}/share/android-sdk-build-tools

.include <bsd.port.mk>