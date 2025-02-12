PORTNAME=	N_m3u8DL-RE
PORTVERSION=	1.0
CATEGORIES=	www linux
MASTER_SITES=	https://github.com/nilaoda/N_m3u8DL-RE/releases/download/v0.3.0-beta/
DISTNAME=	N_m3u8DL-RE_v0.3.0-beta_linux-x64_20241203

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.gz


do-install:

	cd ${WRKSRC} && ${CP} -r N_m3u8DL-RE  ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>