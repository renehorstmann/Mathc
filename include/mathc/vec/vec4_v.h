#ifndef MATHC_VEC_VEC4_V_H
#define MATHC_VEC_VEC4_V_H

#include "vec4.h"


/** dst = -vec */
static vec4 vec4_neg_v(const float *vec) {
    vec4 res;
    vecN_neg(res.v, vec, 4);
    return res;
}

/** dst = a + b */
static vec4 vec4_add_vec_v(const float *vec_a, const float *vec_b) {
    vec4 res;
    vecN_add_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** dst = a + b */
static vec4 vec4_add_sca_v(const float *vec_a, float scalar_b) {
    vec4 res;
    vecN_add_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** dst = a - b */
static vec4 vec4_sub_vec_v(const float *vec_a, const float *vec_b) {
    vec4 res;
    vecN_sub_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** dst = a - b */
static vec4 vec4_sub_sca_v(const float *vec_a, float scalar_b) {
    vec4 res;
    vecN_sub_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** dst = a * b */
static vec4 vec4_scale_vec_v(const float *vec_a, const float *vec_b) {
    vec4 res;
    vecN_scale_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** dst = a * b */
static vec4 vec4_scale_sca_v(const float *vec_a, float scalar_b) {
    vec4 res;
    vecN_scale_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** dst = a / b */
static vec4 vec4_div_vec_v(const float *vec_a, const float *vec_b) {
    vec4 res;
    vecN_div_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** dst = a / b */
static vec4 vec4_div_sca_v(const float *vec_a, float scalar_b) {
    vec4 res;
    vecN_div_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec4_sum_v(const float *vec) {
    return vecN_sum(vec, 4);
}

/** returns a dot b */
static float vec4_dot_v(const float *vec_a, const float *vec_b) {
    return vecN_dot(vec_a, vec_b, 4);
}

/** returns ||vec||_2 */
static float vec4_norm_v(const float *vec) {
    return vecN_norm(vec, 4);
}

/** returns ||vec||_p */
static float vec4_norm_p_v(const float *vec, float p) {
    return vecN_norm_p(vec, p, 4);
}

/** returns ||vec||_1 */
static float vec4_norm_1_v(const float *vec) {
    return vecN_norm_1(vec, 4);
}

/** returns ||vec||_inf */
static float vec4_norm_inf_v(const float *vec) {
    return vecN_norm_inf(vec, 4);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4 vec4_normalize_v(const float *vec) {
    vec4 res;
    vecN_normalize(res.v, vec, 4);
    return res;
}

/** dst = from + (to - from) * t */
static vec4 vec4_lerp_v(const float *from, const float *to, float t) {
    vec4 res;
    vecN_lerp(res.v, from, to, t, 4);
    return res;
}

/** dst = a x b , dst.w = 0 */
static vec4 vec4_cross_v(const float *a, const float *b) {
    return vec4_cross(Vec4(a), Vec4(b));
}

#endif //MATHC_VEC_VEC4_V_H
