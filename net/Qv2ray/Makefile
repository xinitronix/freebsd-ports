PORTNAME=	Qv2ray
DISTVERSION=	2.7.0
DISTVERSIONSUFFIX=	-gd5c5aeb
 
CATEGORIES=	net

USE_GITHUB=	yes
GH_ACCOUNT=	Qv2ray
GH_TUPLE+=      libuv:libuv:e8b989ea1f7f9d4083511a2caec7791e9abd1871:libuv/3rdparty/libuv \
		DHR60:QJsonStruct:02416895f2f1fb826f8e9207d8bbe5804b6d0441:DHR60/3rdparty/QJsonStruct \
		Qv2ray:QvPlugin-Interface:911c4adbb7b598435162da245ab248d215d3f018:src/src/plugin-interface \
		skypjack:uvw:0c1a21e75cd5b87181db8ee4cdf303a68eecabed:skypjack/3rdparty/uvw \
		ztxc:SingleApplication:e99b8df38f9e8bc7a9f6ce7b2a20db791c1e2bb3:ztxc/3rdparty/SingleApplication \
		danielsanfr:qt-qrcode:2d57d9c6e2341689d10f9360a16a08831a4a820b:danielsanfr/3rdparty/qt-qrcode \
		fukuchi:libqrencode:ca465caa9f497beab26dd17dc45cd08c76634820:fukuchi/3rdparty/qt-qrcode/lib/libqrencode \
		Qv2ray:QNodeEditor:808a7cf0359771a474db17a82cbf631746d8735d:3rdparty/3rdparty/QNodeEditor \
		Qv2ray:PureSource:a4872c1fb429ed70eb183c3846bcf791bda75459:Qv2ray/3rdparty/puresource


WWW=	      	https://qv2ray.net/

USES=cmake:noninja

do-install:

		mkdir -p                               ${STAGEDIR}${PREFIX}/share/qv2ray
		cd ${WRKDIR}/.build && ${CP}  qv2ray  ${STAGEDIR}${PREFIX}/share/qv2ray
		cd  ${WRKDIR}/.build && ${CP} libQvPlugin-BuiltinProtocolSupport.so  ${STAGEDIR}${PREFIX}/lib
		cd  ${WRKDIR}/.build && ${CP} libQvPlugin-BuiltinSubscriptionSupport.so  ${STAGEDIR}${PREFIX}/lib	
		cp      files/qv2ray.desktop    ${STAGEDIR}${PREFIX}/share/applications
post-install:
		 ln -s  /usr/local/share/qv2ray/qv2ray /usr/local/bin/qv2ray
.include <bsd.port.mk>

