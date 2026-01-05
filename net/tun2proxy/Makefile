PORTNAME=       tun2proxy
DISTVERSION=	v0.7.19-1
DISTVERSIONSUFFIX= -g4a6429c
CATEGORIES=	net
WWW=            https://github.com/tun2proxy/tun2proxy

#USES=           cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tun2proxy

NO_BUILD=	yes

BUILD_DEPENDS=  rust>=1.91.1:lang/rust


CARGO_CRATES=	async-trait-0.1.89 \
		base64easy-0.1.7 \
		chrono-0.4.42 \
		clap-4.5.54 \
		ctrlc2-3.6.5 \
		digest_auth-0.3.1 \
		dotenvy-0.15.7 \
		env_logger-0.11.8 \
		hashlink-0.11.0 \
		hickory-proto-0.25.1 \
		httparse-1.10.1  \
		thiserror-2.0.17 \
		tokio-1.49.0 \
		tokio-util-0.7.18 \
		tproxy-config-7.0.2  \
		tun-0.8.1 \
		udp-stream-0.0.12 \
		unicase-2.8.1  \
		url-2.5.7 \
		ipstack-1.0.0 \
		log-0.4.29 \
		mimalloc-0.1.48 \
		percent-encoding-2.3.2 \
		socks5-impl-0.8.0 \
		serde-1.0.228 \
		shlex-1.3.0 \
		serde_json-1.0.148 \
		android_logger-0.15.1 \
		jni-0.21.1 \
		bincode-2.0.0 \
		windows-service-0.8.0 \
		daemonize-0.5.0 \
		nix-0.30.1 \
		proc-macro2-1.0.104 \
		quote-1.0.42 \
		syn-2.0.113 \
		num-traits-0.2.19 \
		js-sys-0.3.38 \
		wasm-bindgen-0.2.106 \
		iana-time-zone-0.1.64 \
		windows-link-0.2.1 \
		clap_builder-4.5.54 

CARGO_TARGET_DIR=       ${WRKSRC}/target


do-install:
		cd ${WRKSRC} && cargo build --release
		cp 	${WRKSRC}/target/release/tun2proxy-bin   ${STAGEDIR}${PREFIX}/bin/tun2proxy
		cp      files/tun2proxy        ${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>