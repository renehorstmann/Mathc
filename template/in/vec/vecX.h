#ifndef MATHC_VEC_VEC__X___H
#define MATHC_VEC_VEC__X___H

/*/ 0 /*/   // template file!
/*/ 0 /*/   //
/*/ 0 /*/   // __X__ will be replaced by X=[2, 3, 4, ...]
/*/ 0 /*/   //
/*/ 0 /*/   // all lines starting with "/*/ cond /*/[//]" may be removed
/*/ 0 /*/   // if cond is true:
/*/ 0 /*/   //      only the condition comment will be removed "/*/ cond /*/)"
/*/ 0 /*/   // if cond is false:
/*/ 0 /*/   //      the whole line will be removed
/*/ 0 /*/
/*/ 0 /*/   // the following setup is just here to pleasure an ide
/*/ 0 /*/ #include "../../out/mathc/types/vec4.h"
/*/ 0 /*/ #include "../../out/mathc/types/bvec4.h"
/*/ 0 /*/ typedef vec4 vec__X__;
/*/ 0 /*/ typedef bvec4 bvec__X__;
/*/ 0 /*/ #define __X__ 4
/*/ 0 /*/ typedef float really_a_float;

#include "vecn.h"
/*/ 1 /*///#include "../types/vec__X__.h"
/*/ 1 /*///#include "../types/bvec__X__.h"


/** dst = (vec__X__) v */
static vec__X__ vec__X___cast_from_float(const really_a_float *cast) {
    vec__X__ res;
    vecN_cast_into(res.v, cast, __X__);
    return res;
}

/** dst = (vec__X__) v */
static vec__X__ vec__X___cast_from_double(const double *cast) {
    vec__X__ res;
    vecN_cast_into(res.v, cast, __X__);
    return res;
}

/** dst = (vec__X__) v */
static vec__X__ vec__X___cast_from_int(const int *cast) {
    vec__X__ res;
    vecN_cast_into(res.v, cast, __X__);
    return res;
}

/** dst = (vec__X__) v */
static vec__X__ vec__X___cast_from_uchar(const unsigned char *cast) {
    vec__X__ res;
    vecN_cast_into(res.v, cast, __X__);
    return res;
}

/*/ float /*//** dst = v / 255 */
/*/ float /*/static vec__X__ vec__X___cast_from_uchar_1(const unsigned char *cast) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_cast_from_uchar_1(res.v, cast, __X__);
/*/ float /*/    return res;
/*/ float /*/}

/*/ int /*//** dst = vec * 255 */
/*/ int /*/static vec__X__ vec__X___cast_from_float_1(const really_a_float *cast) {
/*/ int /*/    vec__X__ res;
/*/ int /*/    vecN_cast_from_float_1(res.v, cast, __X__);
/*/ int /*/    return res;
/*/ int /*/}

/*/ int /*//** dst = vec * 255 */
/*/ int /*/static vec__X__ vec__X___cast_from_double_1(const double *cast) {
/*/ int /*/    vec__X__ res;
/*/ int /*/    vecN_cast_from_double_1(res.v, cast, __X__);
/*/ int /*/    return res;
/*/ int /*/}

/*/ int /*//** dst = vec * 255 */
/*/ int /*/static vec__X__ vec__X___cast_from_longdouble_1(const long double *cast) {
/*/ int /*/    vec__X__ res;
/*/ int /*/    vecN_cast_from_longdouble_1(res.v, cast, __X__);
/*/ int /*/    return res;
/*/ int /*/}

/** a == b */
static bool vec__X___cmp(vec__X__ a, vec__X__ b) {
    return vecN_cmp(a.v, b.v, __X__);
}


/** dst = s */
static vec__X__ vec__X___set(float s) {
    vec__X__ res;
    vecN_set(res.v, s, __X__);
    return res;
}

/*/ X<5 /*//** dst = v0, v1, ... */
/*/ X<5 /*/static vec__X__ vec__X___new(float v0, float v1
/*/ X<5 /*//*/ X>=3 /*/         , float v2
/*/ X<5 /*//*/ X>=4 /*/         , float v3
/*/ X<5 /*/) {
/*/ X<5 /*/    vec__X__ self;
/*/ X<5 /*/    self.v0 = v0;
/*/ X<5 /*/    self.v1 = v1;
/*/ X<5 /*//*/ X>=3 /*/    self.v2 = v2;
/*/ X<5 /*//*/ X>=4 /*/    self.v3 = v3;
/*/ X<5 /*/    return self;
/*/ X<5 /*/}

/** dst = unit_x */
static vec__X__ vec__X___unit_x() {
    vec__X__ res;
    vecN_unit_x(res.v, __X__);
    return res;
}


/** dst = unit_y */
static vec__X__ vec__X___unit_y() {
    vec__X__ res;
    vecN_unit_y(res.v, __X__);
    return res;
}


/*/ X>=3 /*//** dst = unit_z */
/*/ X>=3 /*/static vec__X__ vec__X___unit_z() {
/*/ X>=3 /*/    vec__X__ res;
/*/ X>=3 /*/    vecN_unit_z(res.v, __X__);
/*/ X>=3 /*/    return res;
/*/ X>=3 /*/}


/*/ X>=4 /*//** dst = unit_w */
/*/ X>=4 /*/static vec__X__ vec__X___unit_w() {
/*/ X>=4 /*/    vec__X__ res;
/*/ X>=4 /*/    vecN_unit_w(res.v, __X__);
/*/ X>=4 /*/    return res;
/*/ X>=4 /*/}


/*/ signed /*//** dst = -v */
/*/ signed /*/static vec__X__ vec__X___neg(vec__X__ v) {
/*/ signed /*/    vec__X__ res;
/*/ signed /*/    vecN_neg(res.v, v.v, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/** dst = a + b */
static vec__X__ vec__X___add_vec(vec__X__ a, vec__X__ b) {
    vec__X__ res;
    vecN_add_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a + b */
static vec__X__ vec__X___add(vec__X__ a, float b) {
    vec__X__ res;
    vecN_add(res.v, a.v, b, __X__);
    return res;
}


/** dst = a - b */
static vec__X__ vec__X___sub_vec(vec__X__ a, vec__X__ b) {
    vec__X__ res;
    vecN_sub_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a - b */
static vec__X__ vec__X___sub(vec__X__ a, float b) {
    vec__X__ res;
    vecN_sub(res.v, a.v, b, __X__);
    return res;
}


/** dst = a * b */
static vec__X__ vec__X___scale_vec(vec__X__ a, vec__X__ b) {
    vec__X__ res;
    vecN_scale_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a * b */
static vec__X__ vec__X___scale(vec__X__ a, float b) {
    vec__X__ res;
    vecN_scale(res.v, a.v, b, __X__);
    return res;
}


/** dst = a / b */
static vec__X__ vec__X___div_vec(vec__X__ a, vec__X__ b) {
    vec__X__ res;
    vecN_div_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a / b */
static vec__X__ vec__X___div(vec__X__ a, float b) {
    vec__X__ res;
    vecN_div(res.v, a.v, b, __X__);
    return res;
}

/** dst = a + b * c */
static vec__X__ vec__X___add_scaled_vec(vec__X__ a, vec__X__ b, vec__X__ c) {
    vec__X__ res;
    vecN_add_scaled_vec(res.v, a.v, b.v, c.v, __X__);
    return res;
}

/** dst = a + b * c */
static vec__X__ vec__X___add_scaled(vec__X__ a, vec__X__ b, float c) {
    vec__X__ res;
    vecN_add_scaled(res.v, a.v, b.v, c, __X__);
    return res;
}


/*/ float /*//** dst = a * M_PI / 180 */
/*/ float /*/static vec__X__ vec__X___radians(vec__X__ deg) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_radians(res.v, deg.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = a * 180 / M_PI */
/*/ float /*/static vec__X__ vec__X___degrees(vec__X__ rad) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_degrees(res.v, rad.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = sin(angle_rad) */
/*/ float /*/static vec__X__ vec__X___sin(vec__X__ angle_rad) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_sin(res.v, angle_rad.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = cos(angle_rad) */
/*/ float /*/static vec__X__ vec__X___cos(vec__X__ angle_rad) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_cos(res.v, angle_rad.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = tan(angle_rad) */
/*/ float /*/static vec__X__ vec__X___tan(vec__X__ angle_rad) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_tan(res.v, angle_rad.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = asin(x) */
/*/ float /*/static vec__X__ vec__X___asin(vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_asin(res.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = acos(x) */
/*/ float /*/static vec__X__ vec__X___acos(vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_acos(res.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = atan(x) */
/*/ float /*/static vec__X__ vec__X___atan(vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_atan(res.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = atan2(y, x) */
/*/ float /*/static vec__X__ vec__X___atan2(vec__X__ y, vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_atan2(res.v, y.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/** dst = pow(x, y) */
static vec__X__ vec__X___pow(vec__X__ x, float y) {
    vec__X__ res;
    vecN_pow(res.v, x.v, y, __X__);
    return res;
}


/** dst = pow(x, y) */
static vec__X__ vec__X___pow_vec(vec__X__ x, vec__X__ y) {
    vec__X__ res;
    vecN_pow_vec(res.v, x.v, y.v, __X__);
    return res;
}


/** dst = exp(x) */
static vec__X__ vec__X___exp(vec__X__ x) {
    vec__X__ res;
    vecN_exp(res.v, x.v, __X__);
    return res;
}


/** dst = log(x) */
static vec__X__ vec__X___log(vec__X__ x) {
    vec__X__ res;
    vecN_log(res.v, x.v, __X__);
    return res;
}


/** dst = exp2(x) */
static vec__X__ vec__X___exp2(vec__X__ x) {
    vec__X__ res;
    vecN_exp2(res.v, x.v, __X__);
    return res;
}


/** dst = log2(x) */
static vec__X__ vec__X___log2(vec__X__ x) {
    vec__X__ res;
    vecN_log2(res.v, x.v, __X__);
    return res;
}


/** dst = sqrt(x) */
static vec__X__ vec__X___sqrt(vec__X__ x) {
    vec__X__ res;
    vecN_sqrt(res.v, x.v, __X__);
    return res;
}


/*/ float /*//** dst = 1 / sqrt(x) */
/*/ float /*/static vec__X__ vec__X___inversesqrt(vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_inversesqrt(res.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ signed /*//** dst = abs(x) */
/*/ signed /*/static vec__X__ vec__X___abs(vec__X__ x) {
/*/ signed /*/    vec__X__ res;
/*/ signed /*/    vecN_abs(res.v, x.v, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/*/ signed /*//** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
/*/ signed /*/static vec__X__ vec__X___sign(vec__X__ x) {
/*/ signed /*/    vec__X__ res;
/*/ signed /*/    vecN_sign(res.v, x.v, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/*/ float /*//** dst = floor(x) */
/*/ float /*/static vec__X__ vec__X___floor(vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_floor(res.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = ceil(x) */
/*/ float /*/static vec__X__ vec__X___ceil(vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_ceil(res.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = x - floor(x) */
/*/ float /*/static vec__X__ vec__X___fract(vec__X__ x) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_fract(res.v, x.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = x - y * floor(x/y) */
/*/ int /*//** dst = (x % y + y) % y (always positive, if y>0) **/
static vec__X__ vec__X___mod(vec__X__ x, float y) {
    vec__X__ res;
    vecN_mod(res.v, x.v, y, __X__);
    return res;
}


/*/ float /*//** dst = x - y * floor(x/y) */
/*/ int /*//** dst = (x % y + y) % y (always positive, if y>0) **/
static vec__X__ vec__X___mod_vec(vec__X__ x, vec__X__ y) {
    vec__X__ res;
    vecN_mod_vec(res.v, x.v, y.v, __X__);
    return res;
}


/** dst = a < b ? a : b */
static vec__X__ vec__X___min(vec__X__ x, float y) {
    vec__X__ res;
    vecN_min(res.v, x.v, y, __X__);
    return res;
}


/** dst = a < b ? a : b */
static vec__X__ vec__X___min_vec(vec__X__ x, vec__X__ y) {
    vec__X__ res;
    vecN_min_vec(res.v, x.v, y.v, __X__);
    return res;
}


/** dst = a > b ? a : b */
static vec__X__ vec__X___max(vec__X__ x, float y) {
    vec__X__ res;
    vecN_max(res.v, x.v, y, __X__);
    return res;
}


/** dst = a > b ? a : b */
static vec__X__ vec__X___max_vec(vec__X__ x, vec__X__ y) {
    vec__X__ res;
    vecN_max_vec(res.v, x.v, y.v, __X__);
    return res;
}


/** returns the index of the min v value */
static int vec__X___min_index(vec__X__ vec) {
    return vecN_min_index(vec.v, __X__);
}


/** returns the index of the max v value */
static int vec__X___max_index(vec__X__ vec) {
    return vecN_max_index(vec.v, __X__);
}

/** dst = x < min ? min : (x > max ? max : x) */
static vec__X__ vec__X___clamp(vec__X__ x, float min, float max) {
    vec__X__ res;
    vecN_clamp(res.v, x.v, min, max, __X__);
    return res;
}


/** dst = x < min ? min : (x > max ? max : x) */
static vec__X__ vec__X___clamp_vec(vec__X__ x, vec__X__ min, vec__X__ max) {
    vec__X__ res;
    vecN_clamp_vec(res.v, x.v, min.v, max.v, __X__);
    return res;
}


/** dst = a * (1-t) + b * t */
static vec__X__ vec__X___mix(vec__X__ a, vec__X__ b, really_a_float t) {
    vec__X__ res;
    vecN_mix(res.v, a.v, b.v, t, __X__);
    return res;
}


/** dst = x < edge ? 0 : 1 */
static vec__X__ vec__X___step(vec__X__ x, float edge) {
    vec__X__ res;
    vecN_step(res.v, x.v, edge, __X__);
    return res;
}


/** dst = x < edge ? 0 : 1 */
static vec__X__ vec__X___step_vec(vec__X__ x, vec__X__ edge) {
    vec__X__ res;
    vecN_step_vec(res.v, x.v, edge.v, __X__);
    return res;
}


/*/ float /*//** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
/*/ float /*/static vec__X__ vec__X___smoothstep(vec__X__ x, float edge1, float edge2) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_smoothstep(res.v, x.v, edge1, edge2, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
/*/ float /*/static vec__X__ vec__X___smoothstep_vec(vec__X__ x, vec__X__ edge1, vec__X__ edge2) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_smoothstep_vec(res.v, x.v, edge1.v, edge2.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/** returns v[0] + v[1] + ... + v[n-1] */
static float vec__X___sum(vec__X__ v) {
    return vecN_sum(v.v, __X__);
}


/** returns a dot b */
static float vec__X___dot(vec__X__ a, vec__X__ b) {
    return vecN_dot(a.v, b.v, __X__);
}


/** dst = a x b , dst.w... = 0 */
static vec__X__ vec__X___cross(vec__X__ a, vec__X__ b) {
    vec__X__ res;
    vecN_cross(res.v, a.v, b.v, __X__);
    return res;
}


/** returns ||v||___X__ */
static float vec__X___norm(vec__X__ v) {
    return vecN_norm(v.v, __X__);
}


/*/ signed /*//** returns ||v||_p */
/*/ signed /*/static float vec__X___norm_p(vec__X__ v, float p) {
/*/ signed /*/    return vecN_norm_p(v.v, p, __X__);
/*/ signed /*/}


/*/ signed /*//** returns ||v||_1 */
/*/ signed /*/static float vec__X___norm_1(vec__X__ v) {
/*/ signed /*/    return vecN_norm_1(v.v, __X__);
/*/ signed /*/}


/*/ signed /*//** returns ||v||_inf */
/*/ signed /*/static float vec__X___norm_inf(vec__X__ v) {
/*/ signed /*/    return vecN_norm_inf(v.v, __X__);
/*/ signed /*/}


/*/ float /*//** dst = v / norm(v) */
/*/ float /*/static vec__X__ vec__X___normalize_unsafe(vec__X__ v) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_normalize_unsafe(res.v, v.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = v / (norm(v) > 0 ? norm(v) : 1) */
/*/ float /*/static vec__X__ vec__X___normalize(vec__X__ v) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_normalize(res.v, v.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}

/*/ float /*//** dst = normalize(cross(a, b)) */
/*/ float /*/static vec__X__ vec__X___cross_normalized(vec__X__ a, vec__X__ b) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_cross_normalized(res.v, a.v, b.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/** returns length of a vector, see vecN_norm. Just here to match glsl */
static float vec__X___length(vec__X__ v) {
    return vecN_length(v.v, __X__);
}


/** returns norm(b-a) */
static float vec__X___distance(vec__X__ a, vec__X__ b) {
    return vecN_distance(a.v, b.v, __X__);
}


/** returns dot(b-a) */
static float vec__X___sqr_distance(vec__X__ a, vec__X__ b) {
    return vecN_sqr_distance(a.v, b.v, __X__);
}


/*/ float /*//** dst = dot(i, nref) < 0 ? N : -N */
/*/ float /*/static vec__X__ vec__X___faceforward(vec__X__ n, vec__X__ i, vec__X__ nref) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_faceforward(res.v, n.v, i.v, nref.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = i - 2.0 * n * dot(n,i) */
/*/ float /*/static vec__X__ vec__X___reflect(vec__X__ i, vec__X__ n) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_reflect(res.v, i.v, n.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*/static vec__X__ vec__X___refract(vec__X__ i, vec__X__ n, float eta) {
/*/ float /*/    vec__X__ res;
/*/ float /*/    vecN_refract(res.v, i.v, n.v, eta, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/** dst = a < b */
static bvec__X__ vec__X___less_than(vec__X__ a, float b) {
    bvec__X__ res;
    vecN_less_than(res.v, a.v, b, __X__);
    return res;
}


/** dst = a < b */
static bvec__X__ vec__X___less_than_vec(vec__X__ a, vec__X__ b) {
    bvec__X__ res;
    vecN_less_than_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a <= b */
static bvec__X__ vec__X___less_than_equal(vec__X__ a, float b) {
    bvec__X__ res;
    vecN_less_than_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a <= b */
static bvec__X__ vec__X___less_than_equal_vec(vec__X__ a, vec__X__ b) {
    bvec__X__ res;
    vecN_less_than_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a > b */
static bvec__X__ vec__X___greater_than(vec__X__ a, float b) {
    bvec__X__ res;
    vecN_greater_than(res.v, a.v, b, __X__);
    return res;
}


/** dst = a > b */
static bvec__X__ vec__X___greater_than_vec(vec__X__ a, vec__X__ b) {
    bvec__X__ res;
    vecN_greater_than_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a >= b */
static bvec__X__ vec__X___greater_than_equal(vec__X__ a, float b) {
    bvec__X__ res;
    vecN_greater_than_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a >= b */
static bvec__X__ vec__X___greater_than_equal_vec(vec__X__ a, vec__X__ b) {
    bvec__X__ res;
    vecN_greater_than_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a == b */
static bvec__X__ vec__X___equal(vec__X__ a, float b) {
    bvec__X__ res;
    vecN_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a == b */
static bvec__X__ vec__X___equal_vec(vec__X__ a, vec__X__ b) {
    bvec__X__ res;
    vecN_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a != b */
static bvec__X__ vec__X___not_equal(vec__X__ a, float b) {
    bvec__X__ res;
    vecN_not_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a != b */
static bvec__X__ vec__X___not_equal_vec(vec__X__ a, vec__X__ b) {
    bvec__X__ res;
    vecN_not_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/*/ float /*//** dst = a == b (+-eps) */
/*/ float /*/static bvec__X__ vec__X___equal_eps(vec__X__ a, float b, float eps) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_equal_eps(res.v, a.v, b, eps, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = a == b (+-eps) */
/*/ float /*/static bvec__X__ vec__X___equal_eps_vec(vec__X__ a, vec__X__ b, float eps) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_equal_eps_vec(res.v, a.v, b.v, eps, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = a != b (+-eps) */
/*/ float /*/static bvec__X__ vec__X___not_equal_eps(vec__X__ a, float b, float eps) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_not_equal_eps(res.v, a.v, b, eps, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = a != b (+-eps) */
/*/ float /*/static bvec__X__ vec__X___not_equal_eps_vec(vec__X__ a, vec__X__ b, float eps) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_not_equal_eps_vec(res.v, a.v, b.v, eps, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = isnan(v) */
/*/ float /*/static bvec__X__ vec__X___isnan(vec__X__ v) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_isnan(res.v, v.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = !isnan(v) */
/*/ float /*/static bvec__X__ vec__X___not_isnan(vec__X__ v) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_not_isnan(res.v, v.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = isinf(v) */
/*/ float /*/static bvec__X__ vec__X___isinf(vec__X__ v) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_isinf(res.v, v.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}


/*/ float /*//** dst = !isinf(v) */
/*/ float /*/static bvec__X__ vec__X___not_isinf(vec__X__ v) {
/*/ float /*/    bvec__X__ res;
/*/ float /*/    vecN_not_isinf(res.v, v.v, __X__);
/*/ float /*/    return res;
/*/ float /*/}

#endif //MATHC_VEC_VEC__X___H
