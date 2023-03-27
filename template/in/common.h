#ifndef MATHC_COMMON_H
#define MATHC_COMMON_H

//
// some macros to make life easies
//


#define mathc_min(a, b) ((a)<(b)?(a):(b))
#define mathc_max(a, b) ((a)>(b)?(a):(b))

#define mathc_sign(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
#define mathc_clamp(x, min, max) (x) < (min) ? (min) : ((x) > (max) ? (max) : (x))
#define mathc_step(x, edge) (x) < (edge) ? 0 : 1;


// unpack arrays (and matrices 3x3=9, 4x4=16)
#define mathc_u2(x) (x).v0, (x).v1
#define mathc_u3(x) (x).v0, (x).v1, (x).v2
#define mathc_u4(x) (x).v0, (x).v1, (x).v2, (x).v3
#define mathc_u9(x) (x).v0, (x).v1, (x).v2, (x).v3, (x).v4, (x).v5, (x).v6, (x).v7, (x).v8
#define mathc_u16(x) (x).v0, (x).v1, (x).v2, (x).v3, (x).v4, (x).v5, (x).v6, (x).v7, \
(x).v8, (x).v9, (x).v10, (x).v11, (x).v12, (x).v13, (x).v14, (x).v15

#endif //MATHC_COMMON_H
