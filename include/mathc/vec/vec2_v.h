#ifndef MATHC_VEC_VEC2_V_H
#define MATHC_VEC_VEC2_V_H

#include "vec2.h"


/** dst = -vec */
static vec2 vec2_neg_v(const float *vec) {
    vec2 res;
    vecN_neg(res.v, vec, 2);
    return res;
}

/** dst = a + b */
static vec2 vec2_add_vec_v(const float *vec_a, const float *vec_b) {
    vec2 res;
    vecN_add_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** dst = a + b */
static vec2 vec2_add_sca_v(const float *vec_a, float scalar_b) {
    vec2 res;
    vecN_add_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** dst = a - b */
static vec2 vec2_sub_vec_v(const float *vec_a, const float *vec_b) {
    vec2 res;
    vecN_sub_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** dst = a - b */
static vec2 vec2_sub_sca_v(const float *vec_a, float scalar_b) {
    vec2 res;
    vecN_sub_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** dst = a * b */
static vec2 vec2_scale_vec_v(const float *vec_a, const float *vec_b) {
    vec2 res;
    vecN_scale_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** dst = a * b */
static vec2 vec2_scale_sca_v(const float *vec_a, float scalar_b) {
    vec2 res;
    vecN_scale_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** dst = a / b */
static vec2 vec2_div_vec_v(const float *vec_a, const float *vec_b) {
    vec2 res;
    vecN_div_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** dst = a / b */
static vec2 vec2_div_sca_v(const float *vec_a, float scalar_b) {
    vec2 res;
    vecN_div_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec2_sum_v(const float *vec) {
    return vecN_sum(vec, 2);
}

/** returns a dot b */
static float vec2_dot_v(const float *vec_a, const float *vec_b) {
    return vecN_dot(vec_a, vec_b, 2);
}

/** returns ||vec||_2 */
static float vec2_norm_v(const float *vec) {
    return vecN_norm(vec, 2);
}

/** returns ||vec||_p */
static float vec2_norm_p_v(const float *vec, float p) {
    return vecN_norm_p(vec, p, 2);
}

/** returns ||vec||_1 */
static float vec2_norm_1_v(const float *vec) {
    return vecN_norm_1(vec, 2);
}

/** returns ||vec||_inf */
static float vec2_norm_inf_v(const float *vec) {
    return vecN_norm_inf(vec, 2);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec2 vec2_normalize_v(const float *vec) {
    vec2 res;
    vecN_normalize(res.v, vec, 2);
    return res;
}

/** dst = from + (to - from) * t */
static vec2 vec2_lerp_v(const float *from, const float *to, float t) {
    vec2 res;
    vecN_lerp(res.v, from, to, t, 2);
    return res;
}

#endif //MATHC_VEC_VEC2_V_H
