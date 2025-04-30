PORTNAME=	kde1
DISTVERSION=	1.1.1
DISTVERSIONSUFFIX=	-ga601aa5
CATEGORIES=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	nishiowo
GH_TUPLE+=	nishiowo:kde1-kdebase:c9ef09a62075d2542d6a496b0ce7e9391322417d:kdebase/kdebase \
		nishiowo:qt1:02c4673d20e25428c6f3e19b928d70e3dfe0514c:qt1/qt1 \
		nishiowo:kde1-kdegames:81e3523b30451e9ee36fd597b92023bc296985ed:kdegames/kdegames \
		nishiowo:kde1-kdenetwork:2e2acf062228058672f33706bce4d97edb930f83:kdenetwork/kdenetwork \
		nishiowo:kde1-kdeutils:8063f81f9a684f5bd6fa8872662b35dab9d42524:kdeutils/kdeutils \
		nishiowo:kde1-kdelibs:93d3ecb7e98be959896d63e77b9dfd2872583df0:kdelibs/kdelibs \
		nishiowo:kde1-kdetoys:fecc457ae1290fde0b42ff3938ecc2b51a4ac589:kdetoys/kdetoys
WWW=	      	https://github.com/nishiowo/kde1

BUILD_DEPENDS= gcc>0:lang/gcc


do-build:
		cd  ${WRKSRC} && ./build.sh --prefix=${STAGEDIR}/opt/kde1

               

do-install:
		cp -R 	${STAGEDIR}/opt/ /

.include <bsd.port.mk>
