#ifndef MATHC_VEC_VEC__X___H
#define MATHC_VEC_VEC__X___H

#include "vecn.h"
#include "../types/float.h"
#include "../types/bool.h"

/*/ 0 /*/   // template file!
/*/ 0 /*/   //
/*/ 0 /*/   // __X__ will be replaced by X=[2, 3, 4]
/*/ 0 /*/   //
/*/ 0 /*/   // all lines starting with "/*/ cond /*/" may be removed
/*/ 0 /*/   // if cond is true:
/*/ 0 /*/   //      only the condition comment will be removed "/*/ cond /*/)"
/*/ 0 /*/   // if cond is false:
/*/ 0 /*/   //      the whole line will be removed
/*/ 0 /*/
/*/ 0 /*/   // the following setup is just here to pleasure an ide
/*/ 0 /*/ typedef vec4 vec__X__;
/*/ 0 /*/ typedef bvec4 bvec__X__;
/*/ 0 /*/ int __X__ = 4;
/*/ 0 /*/ typedef float really_a_float;

/** dst = unit_x */
static vec__X__ vec__X___unit_x() {
    return (vec__X__) {{1, 0
/*/ X>=3 /*/                     , 0
/*/ X>=4 /*/                     , 0
                       }};
}

/** dst = unit_y */
static vec__X__ vec__X___unit_y() {
    return (vec__X__) {{0, 1
/*/ X>=3 /*/                     , 0
/*/ X>=4 /*/                     , 0
                       }};
}

/*/ X>=3 /*//** dst = unit_z */
/*/ X>=3 /*/static vec__X__ vec__X___unit_z() {
/*/ X>=3 /*/    return (vec__X__) {{0, 0, 1
/*/ X>=4 /*/                    , 0
/*/ X>=3 /*/    }};
/*/ X>=3 /*/}

/*/ X>=4 /*//** dst = unit_w */
/*/ X>=4 /*/static vec__X__ vec__X___unit_w() {
/*/ X>=4 /*/    return (vec__X__) {{0, 0, 0, 1}};
/*/ X>=4 /*/}

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

/** dst = v / 255 */
static vec__X__ vec__X___cast_from_uchar_1(const unsigned char *cast) {
    vec__X__ res;
    vecN_cast_from_uchar_1(res.v, cast, __X__);
    return res;
}

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


/** dst = -v */
static vec__X__ vec__X___neg(vec__X__ v) {
    vec__X__ res;
    vecN_neg(res.v, v.v, __X__);
    return res;
}


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


/** dst = a * M_PI / 180 */
static vec__X__ vec__X___radians(vec__X__ deg) {
    vec__X__ res;
    vecN_radians(res.v, deg.v, __X__);
    return res;
}


/** dst = a * 180 / M_PI */
static vec__X__ vec__X___degrees(vec__X__ rad) {
    vec__X__ res;
    vecN_degrees(res.v, rad.v, __X__);
    return res;
}


/** dst = sin(angle_rad) */
static vec__X__ vec__X___sin(vec__X__ angle_rad) {
    vec__X__ res;
    vecN_sin(res.v, angle_rad.v, __X__);
    return res;
}


/** dst = cos(angle_rad) */
static vec__X__ vec__X___cos(vec__X__ angle_rad) {
    vec__X__ res;
    vecN_cos(res.v, angle_rad.v, __X__);
    return res;
}


/** dst = tan(angle_rad) */
static vec__X__ vec__X___tan(vec__X__ angle_rad) {
    vec__X__ res;
    vecN_tan(res.v, angle_rad.v, __X__);
    return res;
}


/** dst = asin(x) */
static vec__X__ vec__X___asin(vec__X__ x) {
    vec__X__ res;
    vecN_asin(res.v, x.v, __X__);
    return res;
}


/** dst = acos(x) */
static vec__X__ vec__X___acos(vec__X__ x) {
    vec__X__ res;
    vecN_acos(res.v, x.v, __X__);
    return res;
}


/** dst = atan(x) */
static vec__X__ vec__X___atan(vec__X__ x) {
    vec__X__ res;
    vecN_atan(res.v, x.v, __X__);
    return res;
}


/** dst = atan2(y, x) */
static vec__X__ vec__X___atan2(vec__X__ y, vec__X__ x) {
    vec__X__ res;
    vecN_atan2(res.v, y.v, x.v, __X__);
    return res;
}


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


/** dst = 1 / sqrt(x) */
static vec__X__ vec__X___inversesqrt(vec__X__ x) {
    vec__X__ res;
    vecN_inversesqrt(res.v, x.v, __X__);
    return res;
}


/** dst = abs(x) */
static vec__X__ vec__X___abs(vec__X__ x) {
    vec__X__ res;
    vecN_abs(res.v, x.v, __X__);
    return res;
}


/** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
static vec__X__ vec__X___sign(vec__X__ x) {
    vec__X__ res;
    vecN_sign(res.v, x.v, __X__);
    return res;
}


/** dst = floor(x) */
static vec__X__ vec__X___floor(vec__X__ x) {
    vec__X__ res;
    vecN_floor(res.v, x.v, __X__);
    return res;
}


/** dst = ceil(x) */
static vec__X__ vec__X___ceil(vec__X__ x) {
    vec__X__ res;
    vecN_ceil(res.v, x.v, __X__);
    return res;
}


/** dst = x - floor(x) */
static vec__X__ vec__X___fract(vec__X__ x) {
    vec__X__ res;
    vecN_fract(res.v, x.v, __X__);
    return res;
}


/** dst = x - y * floor(x/y) */
static vec__X__ vec__X___mod(vec__X__ x, float y) {
    vec__X__ res;
    vecN_mod(res.v, x.v, y, __X__);
    return res;
}


/** dst = x - y * floor(x/y) */
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
static vec__X__ vec__X___mix(vec__X__ a, vec__X__ b, float t) {
    vec__X__ res;
    vecN_mix(res.v, a.v, b.v, t, __X__);
    return res;
}


/** dst = a * (1-t) + b * t */
static vec__X__ vec__X___mix_vec(vec__X__ a, vec__X__ b, vec__X__ t) {
    vec__X__ res;
    vecN_mix_vec(res.v, a.v, b.v, t.v, __X__);
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


/** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
static vec__X__ vec__X___smoothstep(vec__X__ x, float edge1, float edge2) {
    vec__X__ res;
    vecN_smoothstep(res.v, x.v, edge1, edge2, __X__);
    return res;
}


/** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
static vec__X__ vec__X___smoothstep_vec(vec__X__ x, vec__X__ edge1, vec__X__ edge2) {
    vec__X__ res;
    vecN_smoothstep_vec(res.v, x.v, edge1.v, edge2.v, __X__);
    return res;
}


/** returns v[0] + v[1] + ... + v[n-1] */
static float vec__X___sum(vec__X__ v) {
    return vecN_sum(v.v, __X__);
}


/** returns a dot b */
static float vec__X___dot(vec__X__ a, vec__X__ b) {
    return vecN_dot(a.v, b.v, __X__);
}


/** returns ||v||___X__ */
static float vec__X___norm(vec__X__ v) {
    return vecN_norm(v.v, __X__);
}


/** returns ||v||_p */
static float vec__X___norm_p(vec__X__ v, float p) {
    return vecN_norm_p(v.v, p, __X__);
}


/** returns ||v||_1 */
static float vec__X___norm_1(vec__X__ v) {
    return vecN_norm_1(v.v, __X__);
}


/** returns ||v||_inf */
static float vec__X___norm_inf(vec__X__ v) {
    return vecN_norm_inf(v.v, __X__);
}


/** dst = v / norm(v) */
static vec__X__ vec__X___normalize_unsafe(vec__X__ v) {
    vec__X__ res;
    vecN_normalize_unsafe(res.v, v.v, __X__);
    return res;
}


/** dst = v / (norm(v) > 0 ? norm(v) : 1) */
static vec__X__ vec__X___normalize(vec__X__ v) {
    vec__X__ res;
    vecN_normalize(res.v, v.v, __X__);
    return res;
}


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


/** dst = dot(i, nref) < 0 ? N : -N */
static vec__X__ vec__X___faceforward(vec__X__ n, vec__X__ i, vec__X__ nref) {
    vec__X__ res;
    vecN_faceforward(res.v, n.v, i.v, nref.v, __X__);
    return res;
}


/** dst = i - 2.0 * n * dot(n,i) */
static vec__X__ vec__X___reflect(vec__X__ i, vec__X__ n) {
    vec__X__ res;
    vecN_reflect(res.v, i.v, n.v, __X__);
    return res;
}


static vec__X__ vec__X___refract(vec__X__ i, vec__X__ n, float eta) {
    vec__X__ res;
    vecN_refract(res.v, i.v, n.v, eta, __X__);
    return res;
}


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


/** dst = a == b (+-eps) */
static bvec__X__ vec__X___equal_eps(vec__X__ a, float b, float eps) {
    bvec__X__ res;
    vecN_equal_eps(res.v, a.v, b, eps, __X__);
    return res;
}


/** dst = a == b (+-eps) */
static bvec__X__ vec__X___equal_eps_vec(vec__X__ a, vec__X__ b, float eps) {
    bvec__X__ res;
    vecN_equal_eps_vec(res.v, a.v, b.v, eps, __X__);
    return res;
}


/** dst = a != b (+-eps) */
static bvec__X__ vec__X___not_equal_eps(vec__X__ a, float b, float eps) {
    bvec__X__ res;
    vecN_not_equal_eps(res.v, a.v, b, eps, __X__);
    return res;
}


/** dst = a != b (+-eps) */
static bvec__X__ vec__X___not_equal_eps_vec(vec__X__ a, vec__X__ b, float eps) {
    bvec__X__ res;
    vecN_not_equal_eps_vec(res.v, a.v, b.v, eps, __X__);
    return res;
}

/** dst = isnan(a) */
static bvec__X__ vec__X___isnan(vec__X__ v) {
    bvec__X__ res;
    vecN_isnan(res.v, v.v, __X__);
    return res;
}

/** dst = isnan(a) */
static bvec__X__ vec__X___not_isnan(vec__X__ v) {
    bvec__X__ res;
    vecN_not_isnan(res.v, v.v, __X__);
    return res;
}

/*/ X>=3 /*//** dst = a x b , dst.w = 0 */
/*/ X>=3 /*/static vec__X__ vec__X___cross(vec__X__ a, vec__X__ b) {
/*/ X>=3 /*/    vec__X__ res;
/*/ X>=3 /*/    res.x = a.y * b.z - a.z * b.y;
/*/ X>=3 /*/    res.y = a.z * b.x - a.x * b.z;
/*/ X>=3 /*/    res.z = a.x * b.y - a.y * b.x;
/*/ X>=4 /*/    res.w = 0;
/*/ X>=3 /*/    return res;
/*/ X>=3 /*/}

#endif //MATHC_VEC_VEC__X___H
