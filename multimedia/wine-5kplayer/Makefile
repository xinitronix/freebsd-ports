PORTNAME=	5kplayer
DISTVERSION=	v6.10
CATEGORIES=     multimedia
MASTER_SITES=   https://www.5kplayer.com/download/
DISTFILES=      5kplayer-64bit.exe
PKGNAMEPREFIX=	wine-

NO_BUILD=	yes

SUB_FILES=	wine-5kplayer

do-extract:
		pkg fetch  -y -r FreeBSD wine-proton 
		tar  -C ${WRKDIR} -xf /var/cache/pkg/wine-proton-9.0.3.pkg  /usr/local                
		cp "/usr/ports/distfiles/${DISTFILES}"  ${WRKDIR}/"${DISTFILES}" 
		cd  ${WRKDIR} &&  7z -y x  "${DISTFILES}" -o${PORTNAME}-${DISTVERSION} app.7z
		7z -y x   ${WRKSRC}/app.7z   -o${WRKSRC}/5kplayer

		cd  ${DISTDIR} && fetch  https://github.com/videolang/native-pkgs/archive/refs/heads/master.tar.gz
		tar  -C ${WRKDIR}/  -xf ${DISTDIR}/master.tar.gz  native-pkgs-master/ffmpeg-x86_64-win32

		tar  -C ${WRKDIR}/  -xf ${DISTDIR}/master.tar.gz  native-pkgs-master/ffmpeg-x86_64-win32

do-install:
		${INSTALL_SCRIPT} ${WRKDIR}/wine-5kplayer                          ${STAGEDIR}${PREFIX}/bin
		${CP} -r     ${WRKSRC}/5kplayer                                    ${STAGEDIR}${PREFIX}/share/
		${CP} -r     ${WRKDIR}/native-pkgs-master/ffmpeg-x86_64-win32/*    ${STAGEDIR}${PREFIX}/share/5kplayer
		${CP} -r     ${WRKDIR}/usr/local/                                  ${STAGEDIR}${PREFIX}/share/5kplayer
		${CP}        files/wine-5kplayer.desktop                           ${STAGEDIR}${PREFIX}/share/applications		
		${CP}        files/wine-5kplayer.png                               ${STAGEDIR}${PREFIX}/share/pixmaps          
.include <bsd.port.mk>