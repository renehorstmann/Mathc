#ifndef MATHC_VEC_IVEC__X___H
#define MATHC_VEC_IVEC__X___H

#include "ivecn.h"
#include "../types/int.h"
#include "../types/float.h"   // for mix_vec
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
/*/ 0 /*/ typedef ivec4 ivec__X__;
/*/ 0 /*/ typedef bvec4 bvec__X__;
/*/ 0 /*/ int __X__ = 4;
/*/ 0 /*/ typedef int really_an_int;


/** dst = unit_x */
static ivec__X__ ivec__X___unit_x() {
    return (ivec__X__) {{1, 0
/*/ X>=3 /*/                     , 0
/*/ X>=4 /*/                     , 0
                   }};
}

/** dst = unit_y */
static ivec__X__ ivec__X___unit_y() {
    return (ivec__X__) {{0, 1
/*/ X>=3 /*/                     , 0
/*/ X>=4 /*/                     , 0
                   }};
}

/*/ X>=3 /*//** dst = unit_z */
/*/ X>=3 /*/static ivec__X__ ivec__X___unit_z() {
/*/ X>=3 /*/    return (ivec__X__) {{0, 0, 1
/*/ X>=4 /*/                    , 0
/*/ X>=3 /*/    }};
/*/ X>=3 /*/}

/*/ X>=4 /*//** dst = unit_w */
/*/ X>=4 /*/static ivec__X__ ivec__X___unit_w() {
/*/ X>=4 /*/    return (ivec__X__) {{0, 0, 0, 1}};
/*/ X>=4 /*/}

/** dst = (ivec__X__) v */
static ivec__X__ ivec__X___cast_from_float(const float *cast) {
    ivec__X__ res;
    ivecN_cast_into(res.v, cast, __X__);
    return res;
}

/** dst = (ivec__X__) v */
static ivec__X__ ivec__X___cast_from_double(const double *cast) {
    ivec__X__ res;
    ivecN_cast_into(res.v, cast, __X__);
    return res;
}

/** dst = (ivec__X__) v */
static ivec__X__ ivec__X___cast_from_int(const really_an_int *cast) {
    ivec__X__ res;
    ivecN_cast_into(res.v, cast, __X__);
    return res;
}

/** dst = (ivec__X__) v */
static ivec__X__ ivec__X___cast_from_uchar(const unsigned char *cast) {
    ivec__X__ res;
    ivecN_cast_into(res.v, cast, __X__);
    return res;
}

/** dst = vec * 255 */
static ivec__X__ ivec__X___cast_from_float_1(const float *cast) {
    ivec__X__ res;
    ivecN_cast_from_float_1(res.v, cast, __X__);
    return res;
}

/** dst = vec * 255 */
static ivec__X__ ivec__X___cast_from_double_1(const double *cast) {
    ivec__X__ res;
    ivecN_cast_from_double_1(res.v, cast, __X__);
    return res;
}

/** a == b */
static bool ivec__X___cmp(ivec__X__ a, ivec__X__ b) {
    return ivecN_cmp(a.v, b.v, __X__);
}

/** dst = s */
static ivec__X__ ivec__X___set(float s) {
    ivec__X__ res;
    ivecN_set(res.v, s, __X__);
    return res;
}


/*/ signed /*//** dst = -v */
/*/ signed /*/static ivec__X__ ivec__X___neg(ivec__X__ v) {
/*/ signed /*/    ivec__X__ res;
/*/ signed /*/    ivecN_neg(res.v, v.v, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/** dst = a + b */
static ivec__X__ ivec__X___add_vec(ivec__X__ a, ivec__X__ b) {
    ivec__X__ res;
    ivecN_add_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a + b */
static ivec__X__ ivec__X___add(ivec__X__ a, float b) {
    ivec__X__ res;
    ivecN_add(res.v, a.v, b, __X__);
    return res;
}


/** dst = a - b */
static ivec__X__ ivec__X___sub_vec(ivec__X__ a, ivec__X__ b) {
    ivec__X__ res;
    ivecN_sub_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a - b */
static ivec__X__ ivec__X___sub(ivec__X__ a, float b) {
    ivec__X__ res;
    ivecN_sub(res.v, a.v, b, __X__);
    return res;
}


/** dst = a * b */
static ivec__X__ ivec__X___scale_vec(ivec__X__ a, ivec__X__ b) {
    ivec__X__ res;
    ivecN_scale_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a * b */
static ivec__X__ ivec__X___scale(ivec__X__ a, float b) {
    ivec__X__ res;
    ivecN_scale(res.v, a.v, b, __X__);
    return res;
}


/** dst = a / b */
static ivec__X__ ivec__X___div_vec(ivec__X__ a, ivec__X__ b) {
    ivec__X__ res;
    ivecN_div_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a / b */
static ivec__X__ ivec__X___div(ivec__X__ a, float b) {
    ivec__X__ res;
    ivecN_div(res.v, a.v, b, __X__);
    return res;
}


/** dst = pow(x, y) */
static ivec__X__ ivec__X___pow(ivec__X__ x, float y) {
    ivec__X__ res;
    ivecN_pow(res.v, x.v, y, __X__);
    return res;
}


/** dst = pow(x, y) */
static ivec__X__ ivec__X___pow_vec(ivec__X__ x, ivec__X__ y) {
    ivec__X__ res;
    ivecN_pow_vec(res.v, x.v, y.v, __X__);
    return res;
}


/** dst = exp(x) */
static ivec__X__ ivec__X___exp(ivec__X__ x) {
    ivec__X__ res;
    ivecN_exp(res.v, x.v, __X__);
    return res;
}


/** dst = log(x) */
static ivec__X__ ivec__X___log(ivec__X__ x) {
    ivec__X__ res;
    ivecN_log(res.v, x.v, __X__);
    return res;
}


/** dst = exp2(x) */
static ivec__X__ ivec__X___exp2(ivec__X__ x) {
    ivec__X__ res;
    ivecN_exp2(res.v, x.v, __X__);
    return res;
}


/** dst = log2(x) */
static ivec__X__ ivec__X___log2(ivec__X__ x) {
    ivec__X__ res;
    ivecN_log2(res.v, x.v, __X__);
    return res;
}


/** dst = sqrt(x) */
static ivec__X__ ivec__X___sqrt(ivec__X__ x) {
    ivec__X__ res;
    ivecN_sqrt(res.v, x.v, __X__);
    return res;
}


/*/ signed /*//** dst = abs(x) */
/*/ signed /*/static ivec__X__ ivec__X___abs(ivec__X__ x) {
/*/ signed /*/    ivec__X__ res;
/*/ signed /*/    ivecN_abs(res.v, x.v, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/*/ signed /*//** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
/*/ signed /*/static ivec__X__ ivec__X___sign(ivec__X__ x) {
/*/ signed /*/    ivec__X__ res;
/*/ signed /*/    ivecN_sign(res.v, x.v, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/*/ signed /*//** dst = x % y (always positive) **/
/*/ signed /*/static ivec__X__ ivec__X___mod_positive(ivec__X__ x, float y) {
/*/ signed /*/    ivec__X__ res;
/*/ signed /*/    ivecN_mod_positive(res.v, x.v, y, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/*/ signed /*//** dst = x % y (always positive) **/
/*/ signed /*/static ivec__X__ ivec__X___mod_positive_vec(ivec__X__ x, ivec__X__ y) {
/*/ signed /*/    ivec__X__ res;
/*/ signed /*/    ivecN_mod_positive_vec(res.v, x.v, y.v, __X__);
/*/ signed /*/    return res;
/*/ signed /*/}


/** dst = a < b ? a : b */
static ivec__X__ ivec__X___min(ivec__X__ x, float y) {
    ivec__X__ res;
    ivecN_min(res.v, x.v, y, __X__);
    return res;
}


/** dst = a < b ? a : b */
static ivec__X__ ivec__X___min_vec(ivec__X__ x, ivec__X__ y) {
    ivec__X__ res;
    ivecN_min_vec(res.v, x.v, y.v, __X__);
    return res;
}


/** dst = a > b ? a : b */
static ivec__X__ ivec__X___max(ivec__X__ x, float y) {
    ivec__X__ res;
    ivecN_max(res.v, x.v, y, __X__);
    return res;
}


/** dst = a > b ? a : b */
static ivec__X__ ivec__X___max_vec(ivec__X__ x, ivec__X__ y) {
    ivec__X__ res;
    ivecN_max_vec(res.v, x.v, y.v, __X__);
    return res;
}


/** returns the index of the min v value */
static int ivec__X___min_index(ivec__X__ ivec) {
    return ivecN_min_index(ivec.v, __X__);
}

/** returns the index of the max v value */
static int ivec__X___max_index(ivec__X__ ivec) {
    return ivecN_max_index(ivec.v, __X__);
}

/** dst = x < min ? min : (x > max ? max : x) */
static ivec__X__ ivec__X___clamp(ivec__X__ x, float min, float max) {
    ivec__X__ res;
    ivecN_clamp(res.v, x.v, min, max, __X__);
    return res;
}


/** dst = x < min ? min : (x > max ? max : x) */
static ivec__X__ ivec__X___clamp_vec(ivec__X__ x, ivec__X__ min, ivec__X__ max) {
    ivec__X__ res;
    ivecN_clamp_vec(res.v, x.v, min.v, max.v, __X__);
    return res;
}


/** dst = a * (1-t) + b * t */
static ivec__X__ ivec__X___mix(ivec__X__ a, ivec__X__ b, float t) {
    ivec__X__ res;
    ivecN_mix(res.v, a.v, b.v, t, __X__);
    return res;
}


/** dst = a * (1-t) + b * t */
static ivec__X__ ivec__X___mix_vec(ivec__X__ a, ivec__X__ b, vec__X__ t) {
    ivec__X__ res;
    ivecN_mix_vec(res.v, a.v, b.v, t.v, __X__);
    return res;
}


/** dst = x < edge ? 0 : 1 */
static ivec__X__ ivec__X___step(ivec__X__ x, float edge) {
    ivec__X__ res;
    ivecN_step(res.v, x.v, edge, __X__);
    return res;
}


/** dst = x < edge ? 0 : 1 */
static ivec__X__ ivec__X___step_vec(ivec__X__ x, ivec__X__ edge) {
    ivec__X__ res;
    ivecN_step_vec(res.v, x.v, edge.v, __X__);
    return res;
}


/** returns v[0] + v[1] + ... + v[n-1] */
static float ivec__X___sum(ivec__X__ v) {
    return ivecN_sum(v.v, __X__);
}


/** returns a dot b */
static float ivec__X___dot(ivec__X__ a, ivec__X__ b) {
    return ivecN_dot(a.v, b.v, __X__);
}


/** returns ||v||___X__ */
static float ivec__X___norm(ivec__X__ v) {
    return ivecN_norm(v.v, __X__);
}


/*/ signed /*//** returns ||v||_p */
/*/ signed /*/static float ivec__X___norm_p(ivec__X__ v, float p) {
/*/ signed /*/    return ivecN_norm_p(v.v, p, __X__);
/*/ signed /*/}


/*/ signed /*//** returns ||v||_1 */
/*/ signed /*/static float ivec__X___norm_1(ivec__X__ v) {
/*/ signed /*/    return ivecN_norm_1(v.v, __X__);
/*/ signed /*/}


/*/ signed /*//** returns ||v||_inf */
/*/ signed /*/static float ivec__X___norm_inf(ivec__X__ v) {
/*/ signed /*/    return ivecN_norm_inf(v.v, __X__);
/*/ signed /*/}


/** returns length of a vector, see ivecN_norm. Just here to match glsl */
static float ivec__X___length(ivec__X__ v) {
    return ivecN_length(v.v, __X__);
}


/** returns norm(b-a) */
static float ivec__X___distance(ivec__X__ a, ivec__X__ b) {
    return ivecN_distance(a.v, b.v, __X__);
}


/** returns dot(b-a) */
static float ivec__X___sqr_distance(ivec__X__ a, ivec__X__ b) {
    return ivecN_sqr_distance(a.v, b.v, __X__);
}


/** dst = a < b */
static bvec__X__ ivec__X___less_than(ivec__X__ a, float b) {
    bvec__X__ res;
    ivecN_less_than(res.v, a.v, b, __X__);
    return res;
}


/** dst = a < b */
static bvec__X__ ivec__X___less_than_vec(ivec__X__ a, ivec__X__ b) {
    bvec__X__ res;
    ivecN_less_than_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a <= b */
static bvec__X__ ivec__X___less_than_equal(ivec__X__ a, float b) {
    bvec__X__ res;
    ivecN_less_than_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a <= b */
static bvec__X__ ivec__X___less_than_equal_vec(ivec__X__ a, ivec__X__ b) {
    bvec__X__ res;
    ivecN_less_than_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a > b */
static bvec__X__ ivec__X___greater_than(ivec__X__ a, float b) {
    bvec__X__ res;
    ivecN_greater_than(res.v, a.v, b, __X__);
    return res;
}


/** dst = a > b */
static bvec__X__ ivec__X___greater_than_vec(ivec__X__ a, ivec__X__ b) {
    bvec__X__ res;
    ivecN_greater_than_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a >= b */
static bvec__X__ ivec__X___greater_than_equal(ivec__X__ a, float b) {
    bvec__X__ res;
    ivecN_greater_than_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a >= b */
static bvec__X__ ivec__X___greater_than_equal_vec(ivec__X__ a, ivec__X__ b) {
    bvec__X__ res;
    ivecN_greater_than_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a == b */
static bvec__X__ ivec__X___equal(ivec__X__ a, float b) {
    bvec__X__ res;
    ivecN_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a == b */
static bvec__X__ ivec__X___equal_vec(ivec__X__ a, ivec__X__ b) {
    bvec__X__ res;
    ivecN_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a != b */
static bvec__X__ ivec__X___not_equal(ivec__X__ a, float b) {
    bvec__X__ res;
    ivecN_not_equal(res.v, a.v, b, __X__);
    return res;
}


/** dst = a != b */
static bvec__X__ ivec__X___not_equal_vec(ivec__X__ a, ivec__X__ b) {
    bvec__X__ res;
    ivecN_not_equal_vec(res.v, a.v, b.v, __X__);
    return res;
}


/*/ X>=3 /*//** dst = a x b , dst.w = 0 */
/*/ X>=3 /*/static ivec__X__ ivec__X___cross(ivec__X__ a, ivec__X__ b) {
/*/ X>=3 /*/    ivec__X__ res;
/*/ X>=3 /*/    res.x = a.y * b.z - a.z * b.y;
/*/ X>=3 /*/    res.y = a.z * b.x - a.x * b.z;
/*/ X>=3 /*/    res.z = a.x * b.y - a.y * b.x;
/*/ X>=4 /*/    res.w = 0;
/*/ X>=3 /*/    return res;
/*/ X>=3 /*/}


#endif //MATHC_VEC_IVEC__X___H
