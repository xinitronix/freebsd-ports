PORTNAME=	tg-ws-proxy
PORTVERSION=	1.3.0
DISTVERSION=	1.3.0
DISTVERSIONSUFFIX=	-1-gb3a9bc6
CATEGORIES=	sysutils

USE_GITHUB=	yes
GH_ACCOUNT=	Flowseal

USES=		python
USE_PYTHON=	pep517 autoplist

BUILD_DEPENDS=	rust>0:lang/rust \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling

.include <bsd.port.mk>