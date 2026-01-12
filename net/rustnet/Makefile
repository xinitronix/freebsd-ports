PORTNAME=	rustnet
DISTVERSION=	v0.18.0-1
DISTVERSIONSUFFIX= -g6f05f29
CATEGORIES=	net
WWW=            https://github.com/domcyrus/rustnet


USE_GITHUB=	yes
GH_ACCOUNT=	domcyrus

NO_BUILD=	yes
BUILD_DEPENDS=  rust>=1.91.1:lang/rust

do-install:
		cd      ${WRKSRC}/  && cargo build --release
		cp 	${WRKSRC}/target/release/rustnet   ${STAGEDIR}${PREFIX}/bin/rustnet
		cp      files/rustnet.desktop              ${STAGEDIR}${PREFIX}/share/applications
		cp       files/rustnet.png                 ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>