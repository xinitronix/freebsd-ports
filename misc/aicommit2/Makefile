PORTNAME=       aicommit2
DISTVERSION=    2.4.17
CATEGORIES=     misc

MAINTAINER=     your@email.com
COMMENT=        Reactive CLI tool that writes git/jj commit messages using Ollama, ChatGPT, Gemini, Claude, etc.
WWW=            https://github.com/tak-bro/aicommit2

LICENSE=        MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=           nodejs:build,run     # ← всё, что нужно
USE_GITHUB=     yes
GH_ACCOUNT=     tak-bro
GH_TAGNAME=     v${DISTVERSION}          # ← правильный тег


NO_ARCH=        yes


do-build:	 
		
		cd ${WRKSRC} && npm  install pkgroll && npm  install simple-git-hooks   && npm run build

do-install:   
		cd  ${WRKSRC}
		cd ${WRKSRC} && npm install -g .
		mkdir -p   ${STAGEDIR}${PREFIX}/lib/node_modules/aicommit2
		cp -R ${WRKSRC}/dist ${STAGEDIR}${PREFIX}/lib/node_modules/aicommit2/
		ln -s ${STAGEDIR}${PREFIX}/lib/node_modules/aicommit2/dist/cli.mjs  ${STAGEDIR}${PREFIX}/bin/aicommit2
		chmod +x  ${STAGEDIR}${PREFIX}/bin/aicommit2

.include <bsd.port.mk>