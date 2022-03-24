#ifndef MATHC_SCA_LONGDOUBLE_H
#define MATHC_SCA_LONGDOUBLE_H

#include <math.h>

/** dst = a * M_PI / 180 */
static long double ldsca_radians(long double deg) {
    return deg * M_PIl / 180.0L;
}

/** dst = a * 180 / M_PI */
static long double ldsca_degrees(long double rad) {
    return rad * 180.0L / M_PIl;
}

/** dst = sin(angle_rad) */
static long double ldsca_sin(long double angle_rad) {
    return sinl(angle_rad);
}

/** dst = cos(angle_rad) */
static long double ldsca_cos(long double angle_rad) {
    return cosl(angle_rad);
}

/** dst = tan(angle_rad) */
static long double ldsca_tan(long double angle_rad) {
    return tanl(angle_rad);
}

/** dst = asin(x) */
static long double ldsca_asin(long double x) {
    return asinl(x);
}

/** dst = acos(x) */
static long double ldsca_acos(long double x) {
    return acosl(x);
}

/** dst = atan(x) */
static long double ldsca_atan(long double x) {
    return atanl(x);
}

/** dst = atan2(y, x) */
static long double ldsca_atan2(long double y, long double x) {
    return atan2l(y, x);
}

/** dst = pow(x, y) */
static long double ldsca_pow(long double x, long double y) {
    return powl(x, y);
}

/** dst = exp(x) */
static long double ldsca_exp(long double x) {
    return expl(x);
}

/** dst = log(x) */
static long double ldsca_log(long double x) {
    return logl(x);
}

/** dst = exp2(x) */
static long double ldsca_exp2(long double x) {
    return exp2l(x);
}

/** dst = log2(x) */
static long double ldsca_log2(long double x) {
    return log2l(x);
}

/** dst = sqrt(x) */
static long double ldsca_sqrt(long double x) {
    return sqrtl(x);
}

/** dst = 1 / sqrt(x) */
static long double ldsca_inversesqrt(long double x) {
    return 1.0L / sqrtl(x);
}

/** dst = abs(x) */
static long double ldsca_abs(long double x) {
    return fabsl(x);
}

/** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
static long double ldsca_sign(long double x) {
    return x > 0.0L ? 1.0L : (x < 0.0L ? -1.0L : 0.0L);
}

/** dst = floor(x) */
static long double ldsca_floor(long double x) {
    return floorl(x);
}

/** dst = ceil(x) */
static long double ldsca_ceil(long double x) {
    return ceill(x);
}

/** dst = 1 - floor(x) */
static long double ldsca_fract(long double x) {
    return 1.0L - floorl(x);
}

/** dst = x - y * floor(x/y) */
static long double ldsca_mod(long double x, long double y) {
    return x - y * floorl(x / y);
}

/** dst = a < b ? a : b */
static long double ldsca_min(long double a, long double b) {
    return a < b ? a : b;
}

/** dst = a > b ? a : b */
static long double ldsca_max(long double a, long double b) {
    return a > b ? a : b;
}

/** dst = x < min ? min : (x > max ? max : x) */
static long double ldsca_clamp(long double x, long double min, long double max) {
    return x < min ? min : (x > max ? max : x);
}

/** dst = a * (1-t) + b * t */
static long double ldsca_mix(long double a, long double b, long double t) {
    return a * (1.0L - t) + b * t;
}

/** dst = x < edge ? 0 : 1 */
static long double ldsca_step(long double x, long double edge) {
    return x < edge ? 0.0L : 1.0L;
}

/** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
static long double ldsca_smoothstep(long double x, long double edge1, long double edge2) {
    return x < edge1 ? 0.0L : (x > edge2 ? 1.0L : x * x * (3.0L - 2.0L * x));
}

/** dst = isnan(x) */
static long double ldsca_isnan(long double x) {
    return isnan(x);
}

#endif //MATHC_SCA_LONGDOUBLE_H
