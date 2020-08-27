#ifndef MATHC_VEC_VEC3_V_H
#define MATHC_VEC_VEC3_V_H

#include "vec3.h"


/** dst = -vec */
static vec3 vec3_neg_v(const float *vec) {
    vec3 res;
    vecN_neg(res.v, vec, 3);
    return res;
}

/** dst = a + b */
static vec3 vec3_add_vec_v(const float *vec_a, const float *vec_b) {
    vec3 res;
    vecN_add_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** dst = a + b */
static vec3 vec3_add_sca_v(const float *vec_a, float scalar_b) {
    vec3 res;
    vecN_add_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** dst = a - b */
static vec3 vec3_sub_vec_v(const float *vec_a, const float *vec_b) {
    vec3 res;
    vecN_sub_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** dst = a - b */
static vec3 vec3_sub_sca_v(const float *vec_a, float scalar_b) {
    vec3 res;
    vecN_sub_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** dst = a * b */
static vec3 vec3_scale_vec_v(const float *vec_a, const float *vec_b) {
    vec3 res;
    vecN_scale_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** dst = a * b */
static vec3 vec3_scale_sca_v(const float *vec_a, float scalar_b) {
    vec3 res;
    vecN_scale_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** dst = a / b */
static vec3 vec3_div_vec_v(const float *vec_a, const float *vec_b) {
    vec3 res;
    vecN_div_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** dst = a / b */
static vec3 vec3_div_sca_v(const float *vec_a, float scalar_b) {
    vec3 res;
    vecN_div_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec3_sum_v(const float *vec) {
    return vecN_sum(vec, 3);
}

/** returns a dot b */
static float vec3_dot_v(const float *vec_a, const float *vec_b) {
    return vecN_dot(vec_a, vec_b, 3);
}

/** returns ||vec||_2 */
static float vec3_norm_v(const float *vec) {
    return vecN_norm(vec, 3);
}

/** returns ||vec||_p */
static float vec3_norm_p_v(const float *vec, float p) {
    return vecN_norm_p(vec, p, 3);
}

/** returns ||vec||_1 */
static float vec3_norm_1_v(const float *vec) {
    return vecN_norm_1(vec, 3);
}

/** returns ||vec||_inf */
static float vec3_norm_inf_v(const float *vec) {
    return vecN_norm_inf(vec, 3);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3 vec3_normalize_v(const float *vec) {
    vec3 res;
    vecN_normalize(res.v, vec, 3);
    return res;
}

/** dst = from + (to - from) * t */
static vec3 vec3_lerp_v(const float *from, const float *to, float t) {
    vec3 res;
    vecN_lerp(res.v, from, to, t, 3);
    return res;
}

/** dst = a x b */
static vec3 vec3_cross_v(const float *a, const float *b) {
    return vec3_cross(Vec3(a), Vec3(b));
}

#endif //MATHC_VEC_VEC3_V_H
