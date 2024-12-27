PORTNAME=	wine-sdrsharp-x64-next
PORTVERSION=	1.0
CATEGORIES=	www 
MASTER_SITES=	https://airspy.com/downloads/
DISTNAME=	sdrsharp-x64-next




RUN_DEPENDS=	wine-devel>=0:emulators/wine-devel
		




NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.zip





do-install:
	${MKDIR}  ${STAGEDIR}${PREFIX}/wine-sdrsharp-x64-next
	${INSTALL_SCRIPT}  files/sdrsharp  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT}  files/sdrsharp.png  ${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${CP} -r  *  ${STAGEDIR}${PREFIX}//wine-sdrsharp-x64-next
	${CP}  files/sdrsharp.desktop  ${STAGEDIR}${PREFIX}/share/applications


.include <bsd.port.mk>
