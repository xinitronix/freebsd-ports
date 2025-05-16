PORTNAME=       previous
PORTVERSION=    3.8
CATEGORIES=     emulators
MASTER_SITES=   https://sourceforge.net/code-snapshots/svn/p/pr/previous/code/

DISTNAME=       previous-code-r1648-trunk

MAINTAINER=     ports@FreeBSD.org
COMMENT=        Previous is a Next computer hardware emulator. It aims to emulate a Next Cube or a Next Station with all its peripheral.
WWW=            https://sourceforge.net/projects/previous/


EXTRACT_SUFX?=		.zip


USES=           cmake
SHEBANG_FILES=  previous
NO_ARCH=        yes

post-install:     
		cp files/previous.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>