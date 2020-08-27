#ifndef MATHC_VEC_VEC2_H
#define MATHC_VEC_VEC2_H

#include "vecn.h"
#include "../types.h"


/** dst = scalar */
static vec2 vec2_set(float scalar) {
    vec2 res;
    vecN_set(res.v, scalar, 2);
    return res;
}

/** dst = -vec */
static vec2 vec2_neg(vec2 vec) {
    vec2 res;
    vecN_neg(res.v, vec.v, 2);
    return res;
}

/** dst = a + b */
static vec2 vec2_add_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_add_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}

/** dst = a + b */
static vec2 vec2_add_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_add_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}

/** dst = a - b */
static vec2 vec2_sub_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_sub_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}

/** dst = a - b */
static vec2 vec2_sub_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_sub_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}

/** dst = a * b */
static vec2 vec2_scale_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_scale_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}

/** dst = a * b */
static vec2 vec2_scale_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_scale_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}

/** dst = a / b */
static vec2 vec2_div_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_div_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}

/** dst = a / b */
static vec2 vec2_div_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_div_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec2_sum(vec2 vec) {
    return vecN_sum(vec.v, 2);
}

/** returns a dot b */
static float vec2_dot(vec2 vec_a, vec2 vec_b) {
    return vecN_dot(vec_a.v, vec_b.v, 2);
}

/** returns ||vec||_2 */
static float vec2_norm(vec2 vec) {
    return vecN_norm(vec.v, 2);
}

/** returns ||vec||_p */
static float vec2_norm_p(vec2 vec, float p) {
    return vecN_norm_p(vec.v, p, 2);
}

/** returns ||vec||_1 */
static float vec2_norm_1(vec2 vec) {
    return vecN_norm_1(vec.v, 2);
}

/** returns ||vec||_inf */
static float vec2_norm_inf(vec2 vec) {
    return vecN_norm_inf(vec.v, 2);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec2 vec2_normalize(vec2 vec) {
    vec2 res;
    vecN_normalize(res.v, vec.v, 2);
    return res;
}

/** dst = from + (to - from) * t */
static vec2 vec2_lerp(vec2 from, vec2 to, float t) {
    vec2 res;
    vecN_lerp(res.v, from.v, to.v, t, 2);
    return res;
}

#endif //MATHC_VEC_VEC2_H
