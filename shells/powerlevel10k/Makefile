PORTNAME=	zsh-theme-powerlevel10k
DISTVERSION=	1.20.0
DISTVERSIONSUFFIX=	-g36f3045
CATEGORIES=	shells

WWW=            https://github.com/romkatv/powerlevel10k

USE_GITHUB=	yes
GH_ACCOUNT=	romkatv
GH_PROJECT=     powerlevel10k

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
		mkdir -p     ${STAGEDIR}${PREFIX}/share/${PORTNAME}             
		cd ${WRKSRC}/${GH_PROJECT}-${DISTVERSION}${DISTVERSIONSUFFIX}/  && ${CP} -r *  ${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>