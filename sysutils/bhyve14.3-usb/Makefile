PORTNAME=	bhyve_usb
PORTVERSION=	14.3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/definitly486/bhyve-usb/releases/download/bhyve_usb_14.3/
DISTNAME=	bhyve_usb_14.3
EXTRACT_SUFX?=		.tar.xz

NO_BUILD=	yes
NO_WRKSUBDIR=	yes


do-install:
		cd ${WRKSRC}/bhyve_usb_14.3 && ${CP} -r usr   ${STAGEDIR}


.include <bsd.port.mk>