# ex:syn=make

AGMATH_LIBS=	${MATH_LIBS}
AGMATH_CFLAGS=	${ALTIVEC_CFLAGS} \
		${SSE_CFLAGS} ${SSE2_CFLAGS} ${SSE3_CFLAGS} \
		${MATH_CFLAGS}

AGMATH_LINKS=		ag_math ${AGMATH_LIBS}
AGMATH_LINKS_STATIC=	ag_math_static ${AGMATH_LIBS}
