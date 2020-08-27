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

/** dst = a + b */
static vec4 vec4_add_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_add_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** dst = a + b */
static vec4 vec4_add_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_add_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** dst = a - b */
static vec4 vec4_sub_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_sub_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** dst = a - b */
static vec4 vec4_sub_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_sub_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** dst = a * b */
static vec4 vec4_scale_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_scale_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** dst = a * b */
static vec4 vec4_scale_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_scale_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** dst = a / b */
static vec4 vec4_div_vec(vec4 vec_a, vec4 vec_b) {
    vec4 res;
    vecN_div_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** dst = a / b */
static vec4 vec4_div_sca(vec4 vec_a, float scalar_b) {
    vec4 res;
    vecN_div_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec4_sum(vec4 vec) {
    return vecN_sum(vec.v, 4);
}

/** returns a dot b */
static float vec4_dot(vec4 vec_a, vec4 vec_b) {
    return vecN_dot(vec_a.v, vec_b.v, 4);
}

/** returns ||vec||_2 */
static float vec4_norm(vec4 vec) {
    return vecN_norm(vec.v, 4);
}

/** returns ||vec||_p */
static float vec4_norm_p(vec4 vec, float p) {
    return vecN_norm_p(vec.v, p, 4);
}

/** returns ||vec||_1 */
static float vec4_norm_1(vec4 vec) {
    return vecN_norm_1(vec.v, 4);
}

/** returns ||vec||_inf */
static float vec4_norm_inf(vec4 vec) {
    return vecN_norm_inf(vec.v, 4);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4 vec4_normalize(vec4 vec) {
    vec4 res;
    vecN_normalize(res.v, vec.v, 4);
    return res;
}

/** dst = from + (to - from) * t */
static vec4 vec4_lerp(vec4 from, vec4 to, float t) {
    vec4 res;
    vecN_lerp(res.v, from.v, to.v, t, 4);
    return res;
}

/** dst = a x b , dst.w = 0 */
static vec4 vec4_cross(vec4 a, vec4 b) {
    vec4 res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    res.w = 0;
    return res;
}

#endif //MATHC_VEC_VEC4_H
