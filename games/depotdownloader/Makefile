PORTNAME=	depotdownloader
DISTVERSIONPREFIX=	DepotDownloader_
DISTVERSION=	3.4.0
CATEGORIES=	games

MAINTAINER=	you@example.com
COMMENT=	Steam depot downloader utilizing the SteamKit2 library
WWW=		https://github.com/SteamRE/DepotDownloader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dotnet:lang/dotnet
RUN_DEPENDS=	dotnet:lang/dotnet

USE_GITHUB=	yes
GH_ACCOUNT=	SteamRE
GH_PROJECT=	DepotDownloader

NO_ARCH=	no

DOTNET_PROJ=	DepotDownloader/DepotDownloader.csproj
DOTNET_ENV=	${SETENV} HOME=${WRKDIR} \
		DOTNET_CLI_TELEMETRY_OPTOUT=1 \
		DOTNET_NOLOGO=1 \
		DOTNET_SKIP_FIRST_TIME_EXPERIENCE=1

SUB_FILES=	depotdownloader
PLIST_FILES=	bin/depotdownloader

do-build:
	cd ${WRKSRC} && ${DOTNET_ENV} \
	    dotnet publish ${DOTNET_PROJ} -c Release --no-self-contained

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/depotdownloader
	@publishdir=`find ${WRKSRC}/DepotDownloader/bin/Release -maxdepth 2 -type d -name publish` ; \
	    cd "$$publishdir" && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/depotdownloader
	${INSTALL_SCRIPT} ${WRKDIR}/depotdownloader ${STAGEDIR}${PREFIX}/bin/depotdownloader

.include <bsd.port.mk>