#ifndef MATHC_VEC_VEC3_H
#define MATHC_VEC_VEC3_H

#include "vecn.h"
#include "../types.h"


/** dst = scalar */
static vec3 vec3_set(float scalar) {
    vec3 res;
    vecN_set(res.v, scalar, 3);
    return res;
}

/** dst = -vec */
static vec3 vec3_neg(vec3 vec) {
    vec3 res;
    vecN_neg(res.v, vec.v, 3);
    return res;
}

/** dst = a + b */
static vec3 vec3_add_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_add_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** dst = a + b */
static vec3 vec3_add_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_add_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** dst = a - b */
static vec3 vec3_sub_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_sub_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** dst = a - b */
static vec3 vec3_sub_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_sub_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** dst = a * b */
static vec3 vec3_scale_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_scale_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** dst = a * b */
static vec3 vec3_scale_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_scale_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** dst = a / b */
static vec3 vec3_div_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_div_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** dst = a / b */
static vec3 vec3_div_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_div_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec3_sum(vec3 vec) {
    return vecN_sum(vec.v, 3);
}

/** returns a dot b */
static float vec3_dot(vec3 vec_a, vec3 vec_b) {
    return vecN_dot(vec_a.v, vec_b.v, 3);
}

/** returns ||vec||_2 */
static float vec3_norm(vec3 vec) {
    return vecN_norm(vec.v, 3);
}

/** returns ||vec||_p */
static float vec3_norm_p(vec3 vec, float p) {
    return vecN_norm_p(vec.v, p, 3);
}

/** returns ||vec||_1 */
static float vec3_norm_1(vec3 vec) {
    return vecN_norm_1(vec.v, 3);
}

/** returns ||vec||_inf */
static float vec3_norm_inf(vec3 vec) {
    return vecN_norm_inf(vec.v, 3);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3 vec3_normalize(vec3 vec) {
    vec3 res;
    vecN_normalize(res.v, vec.v, 3);
    return res;
}

/** dst = from + (to - from) * t */
static vec3 vec3_lerp(vec3 from, vec3 to, float t) {
    vec3 res;
    vecN_lerp(res.v, from.v, to.v, t, 3);
    return res;
}

/** dst = a x b */
static vec3 vec3_cross(vec3 a, vec3 b) {
    vec3 res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    return res;
}

#endif //MATHC_VEC_VEC3_H
