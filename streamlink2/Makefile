PORTNAME=	streamlink2
CATEGORIES=	multimedia 
MASTER_SITES=	https://github.com/definitly486/definitly486/releases/download/streamlink2/
DISTNAME=	streamlink2



NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_SUFX?=		.tar.xz
SRC_SUFX?=		.src${EXTRACT_SUFX}

SUB_FILES=	streamlink


do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/streamlink  ${STAGEDIR}${PREFIX}/bin

	cd ${WRKSRC}/ && ${CP} -r -LP streamlink2  ${STAGEDIR}${PREFIX}/share
	${MKDIR}  -p ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/streamlink_cli  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/streamlink  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/attr  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/attrs  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/Crypto  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/isodate  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	#cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/lxml  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/outcome  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/pycountry  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/sniffio  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/sortedcontainers  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/trio  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages
	cd ${WRKSRC}/ && ${CP} -r  streamlink2/pipx/venvs/streamlink/lib/python3.11/site-packages/websocket  ${STAGEDIR}${PREFIX}/lib/python3.11/site-packages

.include <bsd.port.mk>
