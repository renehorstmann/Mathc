#ifndef MATHC_VEC_IVEC4_H
#define MATHC_VEC_IVEC4_H

#include "ivecn.h"
#include "../types/int.h"
#include "../types/float.h"   // for mix_vec
#include "../types/bool.h"


/** dst = unit_x */
static ivec4 ivec4_unit_x() {
    return (ivec4) {{1, 0
//X>=3                     , 0
//X>=4                     , 0
                   }};
}

/** dst = unit_y */
static ivec4 ivec4_unit_y() {
    return (ivec4) {{0, 1
//X>=3                     , 0
//X>=4                     , 0
                   }};
}

//X>=3 /** dst = unit_z */
//X>=3 static ivec4 ivec4_unit_z() {
//X>=3     return (ivec4) {{0, 0, 1
//X>=4                     , 0
//X>=3     }};
//X>=3 }

//X>=4 /** dst = unit_w */
//X>=4 static ivec4 ivec4_unit_w() {
//X>=4     return (ivec4) {{0, 0, 0, 1}};
//X>=4 }

/** dst = (ivec4) v */
static ivec4 ivec4_cast_from_float(const float *cast) {
    ivec4 res;
    ivecN_cast_into(res.v, cast, 4);
    return res;
}

/** dst = (ivec4) v */
static ivec4 ivec4_cast_from_double(const double *cast) {
    ivec4 res;
    ivecN_cast_into(res.v, cast, 4);
    return res;
}

/** dst = (ivec4) v */
static ivec4 ivec4_cast_from_int(const int *cast) {
    ivec4 res;
    ivecN_cast_into(res.v, cast, 4);
    return res;
}

/** dst = (ivec4) v */
static ivec4 ivec4_cast_from_uchar(const unsigned char *cast) {
    ivec4 res;
    ivecN_cast_into(res.v, cast, 4);
    return res;
}

/** dst = vec * 255 */
static ivec4 ivec4_cast_from_float_1(const float *cast) {
    ivec4 res;
    ivecN_cast_from_float_1(res.v, cast, 4);
    return res;
}

/** dst = vec * 255 */
static ivec4 ivec4_cast_from_double_1(const double *cast) {
    ivec4 res;
    ivecN_cast_from_double_1(res.v, cast, 4);
    return res;
}

/** a == b */
static bool ivec4_cmp(ivec4 a, ivec4 b) {
    return ivecN_cmp(a.v, b.v, 4);
}

/** dst = s */
static ivec4 ivec4_set(float s) {
    ivec4 res;
    ivecN_set(res.v, s, 4);
    return res;
}


//SIGNED /** dst = -v */
//SIGNED static ivec4 ivec4_neg(ivec4 v) {
//SIGNED     ivec4 res;
//SIGNED     ivecN_neg(res.v, v.v, 4);
//SIGNED     return res;
//SIGNED }


/** dst = a + b */
static ivec4 ivec4_add_vec(ivec4 a, ivec4 b) {
    ivec4 res;
    ivecN_add_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a + b */
static ivec4 ivec4_add(ivec4 a, float b) {
    ivec4 res;
    ivecN_add(res.v, a.v, b, 4);
    return res;
}


/** dst = a - b */
static ivec4 ivec4_sub_vec(ivec4 a, ivec4 b) {
    ivec4 res;
    ivecN_sub_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a - b */
static ivec4 ivec4_sub(ivec4 a, float b) {
    ivec4 res;
    ivecN_sub(res.v, a.v, b, 4);
    return res;
}


/** dst = a * b */
static ivec4 ivec4_scale_vec(ivec4 a, ivec4 b) {
    ivec4 res;
    ivecN_scale_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a * b */
static ivec4 ivec4_scale(ivec4 a, float b) {
    ivec4 res;
    ivecN_scale(res.v, a.v, b, 4);
    return res;
}


/** dst = a / b */
static ivec4 ivec4_div_vec(ivec4 a, ivec4 b) {
    ivec4 res;
    ivecN_div_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a / b */
static ivec4 ivec4_div(ivec4 a, float b) {
    ivec4 res;
    ivecN_div(res.v, a.v, b, 4);
    return res;
}


/** dst = pow(x, y) */
static ivec4 ivec4_pow(ivec4 x, float y) {
    ivec4 res;
    ivecN_pow(res.v, x.v, y, 4);
    return res;
}


/** dst = pow(x, y) */
static ivec4 ivec4_pow_vec(ivec4 x, ivec4 y) {
    ivec4 res;
    ivecN_pow_vec(res.v, x.v, y.v, 4);
    return res;
}


/** dst = exp(x) */
static ivec4 ivec4_exp(ivec4 x) {
    ivec4 res;
    ivecN_exp(res.v, x.v, 4);
    return res;
}


/** dst = log(x) */
static ivec4 ivec4_log(ivec4 x) {
    ivec4 res;
    ivecN_log(res.v, x.v, 4);
    return res;
}


/** dst = exp2(x) */
static ivec4 ivec4_exp2(ivec4 x) {
    ivec4 res;
    ivecN_exp2(res.v, x.v, 4);
    return res;
}


/** dst = log2(x) */
static ivec4 ivec4_log2(ivec4 x) {
    ivec4 res;
    ivecN_log2(res.v, x.v, 4);
    return res;
}


/** dst = sqrt(x) */
static ivec4 ivec4_sqrt(ivec4 x) {
    ivec4 res;
    ivecN_sqrt(res.v, x.v, 4);
    return res;
}


//SIGNED /** dst = abs(x) */
//SIGNED static ivec4 ivec4_abs(ivec4 x) {
//SIGNED     ivec4 res;
//SIGNED     ivecN_abs(res.v, x.v, 4);
//SIGNED     return res;
//SIGNED }


//SIGNED /** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
//SIGNED static ivec4 ivec4_sign(ivec4 x) {
//SIGNED     ivec4 res;
//SIGNED     ivecN_sign(res.v, x.v, 4);
//SIGNED     return res;
//SIGNED }


//SIGNED /** dst = x % y (always positive) **/
//SIGNED static ivec4 ivec4_mod_positive(ivec4 x, float y) {
//SIGNED     ivec4 res;
//SIGNED     ivecN_mod_positive(res.v, x.v, y, 4);
//SIGNED     return res;
//SIGNED }


//SIGNED /** dst = x % y (always positive) **/
//SIGNED static ivec4 ivec4_mod_positive_vec(ivec4 x, ivec4 y) {
//SIGNED     ivec4 res;
//SIGNED     ivecN_mod_positive_vec(res.v, x.v, y.v, 4);
//SIGNED     return res;
//SIGNED }


/** dst = a < b ? a : b */
static ivec4 ivec4_min(ivec4 x, float y) {
    ivec4 res;
    ivecN_min(res.v, x.v, y, 4);
    return res;
}


/** dst = a < b ? a : b */
static ivec4 ivec4_min_vec(ivec4 x, ivec4 y) {
    ivec4 res;
    ivecN_min_vec(res.v, x.v, y.v, 4);
    return res;
}


/** dst = a > b ? a : b */
static ivec4 ivec4_max(ivec4 x, float y) {
    ivec4 res;
    ivecN_max(res.v, x.v, y, 4);
    return res;
}


/** dst = a > b ? a : b */
static ivec4 ivec4_max_vec(ivec4 x, ivec4 y) {
    ivec4 res;
    ivecN_max_vec(res.v, x.v, y.v, 4);
    return res;
}


/** returns the index of the min v value */
static int ivec4_min_index(ivec4 ivec) {
    return ivecN_min_index(ivec.v, 4);
}

/** returns the index of the max v value */
static int ivec4_max_index(ivec4 ivec) {
    return ivecN_max_index(ivec.v, 4);
}

/** dst = x < min ? min : (x > max ? max : x) */
static ivec4 ivec4_clamp(ivec4 x, float min, float max) {
    ivec4 res;
    ivecN_clamp(res.v, x.v, min, max, 4);
    return res;
}


/** dst = x < min ? min : (x > max ? max : x) */
static ivec4 ivec4_clamp_vec(ivec4 x, ivec4 min, ivec4 max) {
    ivec4 res;
    ivecN_clamp_vec(res.v, x.v, min.v, max.v, 4);
    return res;
}


/** dst = a * (1-t) + b * t */
static ivec4 ivec4_mix(ivec4 a, ivec4 b, float t) {
    ivec4 res;
    ivecN_mix(res.v, a.v, b.v, t, 4);
    return res;
}


/** dst = a * (1-t) + b * t */
static ivec4 ivec4_mix_vec(ivec4 a, ivec4 b, vec4 t) {
    ivec4 res;
    ivecN_mix_vec(res.v, a.v, b.v, t.v, 4);
    return res;
}


/** dst = x < edge ? 0 : 1 */
static ivec4 ivec4_step(ivec4 x, float edge) {
    ivec4 res;
    ivecN_step(res.v, x.v, edge, 4);
    return res;
}


/** dst = x < edge ? 0 : 1 */
static ivec4 ivec4_step_vec(ivec4 x, ivec4 edge) {
    ivec4 res;
    ivecN_step_vec(res.v, x.v, edge.v, 4);
    return res;
}


/** returns v[0] + v[1] + ... + v[n-1] */
static float ivec4_sum(ivec4 v) {
    return ivecN_sum(v.v, 4);
}


/** returns a dot b */
static float ivec4_dot(ivec4 a, ivec4 b) {
    return ivecN_dot(a.v, b.v, 4);
}


/** returns ||v||_4 */
static float ivec4_norm(ivec4 v) {
    return ivecN_norm(v.v, 4);
}


//SIGNED /** returns ||v||_p */
//SIGNED static float ivec4_norm_p(ivec4 v, float p) {
//SIGNED     return ivecN_norm_p(v.v, p, 4);
//SIGNED }


//SIGNED /** returns ||v||_1 */
//SIGNED static float ivec4_norm_1(ivec4 v) {
//SIGNED     return ivecN_norm_1(v.v, 4);
//SIGNED }


//SIGNED /** returns ||v||_inf */
//SIGNED static float ivec4_norm_inf(ivec4 v) {
//SIGNED     return ivecN_norm_inf(v.v, 4);
//SIGNED }


/** returns length of a vector, see ivecN_norm. Just here to match glsl */
static float ivec4_length(ivec4 v) {
    return ivecN_length(v.v, 4);
}


/** returns norm(b-a) */
static float ivec4_distance(ivec4 a, ivec4 b) {
    return ivecN_distance(a.v, b.v, 4);
}


/** returns dot(b-a) */
static float ivec4_sqr_distance(ivec4 a, ivec4 b) {
    return ivecN_sqr_distance(a.v, b.v, 4);
}


/** dst = a < b */
static bvec4 ivec4_less_than(ivec4 a, float b) {
    bvec4 res;
    ivecN_less_than(res.v, a.v, b, 4);
    return res;
}


/** dst = a < b */
static bvec4 ivec4_less_than_vec(ivec4 a, ivec4 b) {
    bvec4 res;
    ivecN_less_than_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a <= b */
static bvec4 ivec4_less_than_equal(ivec4 a, float b) {
    bvec4 res;
    ivecN_less_than_equal(res.v, a.v, b, 4);
    return res;
}


/** dst = a <= b */
static bvec4 ivec4_less_than_equal_vec(ivec4 a, ivec4 b) {
    bvec4 res;
    ivecN_less_than_equal_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a > b */
static bvec4 ivec4_greater_than(ivec4 a, float b) {
    bvec4 res;
    ivecN_greater_than(res.v, a.v, b, 4);
    return res;
}


/** dst = a > b */
static bvec4 ivec4_greater_than_vec(ivec4 a, ivec4 b) {
    bvec4 res;
    ivecN_greater_than_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a >= b */
static bvec4 ivec4_greater_than_equal(ivec4 a, float b) {
    bvec4 res;
    ivecN_greater_than_equal(res.v, a.v, b, 4);
    return res;
}


/** dst = a >= b */
static bvec4 ivec4_greater_than_equal_vec(ivec4 a, ivec4 b) {
    bvec4 res;
    ivecN_greater_than_equal_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a == b */
static bvec4 ivec4_equal(ivec4 a, float b) {
    bvec4 res;
    ivecN_equal(res.v, a.v, b, 4);
    return res;
}


/** dst = a == b */
static bvec4 ivec4_equal_vec(ivec4 a, ivec4 b) {
    bvec4 res;
    ivecN_equal_vec(res.v, a.v, b.v, 4);
    return res;
}


/** dst = a != b */
static bvec4 ivec4_not_equal(ivec4 a, float b) {
    bvec4 res;
    ivecN_not_equal(res.v, a.v, b, 4);
    return res;
}


/** dst = a != b */
static bvec4 ivec4_not_equal_vec(ivec4 a, ivec4 b) {
    bvec4 res;
    ivecN_not_equal_vec(res.v, a.v, b.v, 4);
    return res;
}


//X>=3 /** dst = a x b , dst.w = 0 */
//X>=3 static ivec4 ivec4_cross(ivec4 a, ivec4 b) {
//X>=3     ivec4 res;
//X>=3     res.x = a.y * b.z - a.z * b.y;
//X>=3     res.y = a.z * b.x - a.x * b.z;
//X>=3     res.z = a.x * b.y - a.y * b.x;
//X>=4     res.w = 0;
//X>=3     return res;
//X>=3 }


#endif //MATHC_VEC_IVEC4_H
