PORTNAME=	wine-sdrsharp-x86
PORTVERSION=	1.0
CATEGORIES=	www 
MASTER_SITES=	https://airspy.com/downloads/
DISTNAME=	sdrsharp-x86




RUN_DEPENDS=	wine-devel>=0:emulators/wine-devel
		




NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.zip





do-install:
	${MKDIR}  ${STAGEDIR}${PREFIX}/wine-sdrsharp-x86
	${INSTALL_SCRIPT}  files/sdrsharp-x86  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT}  files/sdrsharp-x86.png  ${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${CP} -r  *  ${STAGEDIR}${PREFIX}//wine-sdrsharp-x86
	${CP}  files/sdrsharp-x86.desktop  ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
