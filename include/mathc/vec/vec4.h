#ifndef MATHC_VEC_VEC4_H
#define MATHC_VEC_VEC4_H

#include "vecn.h"
#include "../types.h"


/** dst = scalar */
static vec4 vec4_set(float scalar) {
    vec4 res;
    vecN_set(res.v, scalar, 4);
    return res;
}


/** dst = -vec */
static vec4 vec4_neg(vec4 vec) {
    vec4 res;
    vecN_neg(res.v, vec.v, 4);
    return res;
}
/** dst = -vec */
static vec4 vec4_neg_v(const float *vec) {
    return vec4_neg(Vec4(vec));
}


/** dst = a + b */
static vec4 vec4_add_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_add_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a + b */
static vec4 vec4_add_vec_v(const float *vec_a, const float *vec_b) {
    return vec4_add_vec(Vec4(vec_a), Vec4(vec_b));
}


/** dst = a + b */
static vec4 vec4_add_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_add_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a + b */
static vec4 vec4_add_sca_v(const float *vec_a, float scalar_b) {
    return vec4_add_sca(Vec4(vec_a), scalar_b);
}


/** dst = a - b */
static vec4 vec4_sub_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_sub_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a - b */
static vec4 vec4_sub_vec_v(const float *vec_a, const float *vec_b) {
    return vec4_sub_vec(Vec4(vec_a), Vec4(vec_b));
}


/** dst = a - b */
static vec4 vec4_sub_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_sub_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a - b */
static vec4 vec4_sub_sca_v(const float *vec_a, float scalar_b) {
    return vec4_sub_sca(Vec4(vec_a), scalar_b);
}


/** dst = a * b */
static vec4 vec4_scale_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_scale_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a * b */
static vec4 vec4_scale_vec_v(const float *vec_a, const float *vec_b) {
    return vec4_scale_vec(Vec4(vec_a), Vec4(vec_b));
}


/** dst = a * b */
static vec4 vec4_scale_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_scale_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a * b */
static vec4 vec4_scale_sca_v(const float *vec_a, float scalar_b) {
    return vec4_scale_sca(Vec4(vec_a), scalar_b);
}


/** dst = a / b */
static vec4 vec4_div_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_div_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a / b */
static vec4 vec4_div_vec_v(const float *vec_a, const float *vec_b) {
    return vec4_div_vec(Vec4(vec_a), Vec4(vec_b));
}


/** dst = a / b */
static vec4 vec4_div_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_div_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a / b */
static vec4 vec4_div_sca_v(const float *vec_a, float scalar_b) {
    return vec4_div_sca(Vec4(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec4_sum(vec4 vec) {
    return vecN_sum(vec.v, 4);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec4_sum_v(const float *vec) {
    return vec4_sum(Vec4(vec));
}


/** returns a dot b */
static float vec4_dot(vec4 vec_a, vec4 vec_b) {
    return vecN_dot(vec_a.v, vec_b.v, 4);
}
/** returns a dot b */
static float vec4_dot_v(const float *vec_a, const float *vec_b) {
    return vec4_dot(Vec4(vec_a), Vec4(vec_b));
}


/** returns ||vec||_4 */
static float vec4_norm(vec4 vec) {
    return vecN_norm(vec.v, 4);
}
/** returns ||vec||_4 */
static float vec4_norm_v(const float *vec) {
    return vec4_norm(Vec4(vec));
}


/** returns ||vec||_p */
static float vec4_norm_p(vec4 vec, float p) {
    return vecN_norm_p(vec.v, p, 4);
}
/** returns ||vec||_p */
static float vec4_norm_p_v(const float *vec, float p) {
    return vec4_norm_p(Vec4(vec), p);
}


/** returns ||vec||_1 */
static float vec4_norm_1(vec4 vec) {
    return vecN_norm_1(vec.v, 4);
}
/** returns ||vec||_1 */
static float vec4_norm_1_v(const float *vec) {
    return vec4_norm_1(Vec4(vec));
}


/** returns ||vec||_inf */
static float vec4_norm_inf(vec4 vec) {
    return vecN_norm_inf(vec.v, 4);
}
/** returns ||vec||_inf */
static float vec4_norm_inf_v(const float *vec) {
    return vec4_norm_inf(Vec4(vec));
}


/** dst = vec / norm(vec) */
static vec4 vec4_normalize_unsafe(vec4 vec) {
    vec4 res;
    vecN_normalize_unsafe(res.v, vec.v, 4);
    return res;
}
/** dst = vec / norm(vec) */
static vec4 vec4_normalize_unsafe_v(const float *vec) {
    return vec4_normalize_unsafe(Vec4(vec));
}


/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4 vec4_normalize(vec4 vec) {
    vec4 res;
    vecN_normalize(res.v, vec.v, 4);
    return res;
}
/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4 vec4_normalize_v(const float *vec) {
    return vec4_normalize(Vec4(vec));
}


/** dst = from + (to - from) * t */
static vec4 vec4_lerp(vec4 vec_from, vec4 vec_to, float t) {
    vec4 res;
    vecN_lerp(res.v, vec_from.v, vec_to.v, t, 4);
    return res;
}
/** dst = from + (to - from) * t */
static vec4 vec4_lerp_v(const float *vec_from, const float *vec_to, float t) {
    return vec4_lerp(Vec4(vec_from), Vec4(vec_to), t);
}


/** dst = a x b , dst.w = 0 */
static vec4 vec4_cross(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    res.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
    res.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
    res.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
    res.w = 0;
    return res;
}
/** dst = a x b , dst.w = 0 */
static vec4 vec4_cross_v(const float *vec_a, const float *vec_b) {
    return vec4_cross(Vec4(vec_a), Vec4(vec_b));
}


#endif //MATHC_VEC_VEC4_H
