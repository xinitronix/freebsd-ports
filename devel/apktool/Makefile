PORTNAME=	apktool
DISTVERSION=	3.0.3
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/iBotPeaches/Apktool/releases/download/v${DISTVERSION}/
DISTNAME=	apktool_${DISTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for reverse engineering Android APK files
WWW=		https://apktool.org/

LICENSE=	APACHE20
LICENSE_FILE=  ${FILESDIR}/LICENSE

USES=		java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}

PLIST_FILES=	bin/apktool \
		${DATADIR_REL}/apktool.jar

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.jar \
		${STAGEDIR}${DATADIR}/apktool.jar
	${INSTALL_SCRIPT} ${FILESDIR}/apktool \
		${STAGEDIR}${PREFIX}/bin/apktool

.include <bsd.port.mk>
