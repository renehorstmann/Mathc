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
/** dst = -vec */
static vec3 vec3_neg_v(const float *vec) {
    return vec3_neg(Vec3(vec));
}


/** dst = a + b */
static vec3 vec3_add_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_add_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a + b */
static vec3 vec3_add_vec_v(const float *vec_a, const float *vec_b) {
    return vec3_add_vec(Vec3(vec_a), Vec3(vec_b));
}


/** dst = a + b */
static vec3 vec3_add_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_add_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a + b */
static vec3 vec3_add_sca_v(const float *vec_a, float scalar_b) {
    return vec3_add_sca(Vec3(vec_a), scalar_b);
}


/** dst = a - b */
static vec3 vec3_sub_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_sub_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a - b */
static vec3 vec3_sub_vec_v(const float *vec_a, const float *vec_b) {
    return vec3_sub_vec(Vec3(vec_a), Vec3(vec_b));
}


/** dst = a - b */
static vec3 vec3_sub_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_sub_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a - b */
static vec3 vec3_sub_sca_v(const float *vec_a, float scalar_b) {
    return vec3_sub_sca(Vec3(vec_a), scalar_b);
}


/** dst = a * b */
static vec3 vec3_scale_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_scale_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a * b */
static vec3 vec3_scale_vec_v(const float *vec_a, const float *vec_b) {
    return vec3_scale_vec(Vec3(vec_a), Vec3(vec_b));
}


/** dst = a * b */
static vec3 vec3_scale_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_scale_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a * b */
static vec3 vec3_scale_sca_v(const float *vec_a, float scalar_b) {
    return vec3_scale_sca(Vec3(vec_a), scalar_b);
}


/** dst = a / b */
static vec3 vec3_div_vec(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    vecN_div_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a / b */
static vec3 vec3_div_vec_v(const float *vec_a, const float *vec_b) {
    return vec3_div_vec(Vec3(vec_a), Vec3(vec_b));
}


/** dst = a / b */
static vec3 vec3_div_sca(vec3 vec_a, float scalar_b) {
    vec3 res;
    vecN_div_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a / b */
static vec3 vec3_div_sca_v(const float *vec_a, float scalar_b) {
    return vec3_div_sca(Vec3(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec3_sum(vec3 vec) {
    return vecN_sum(vec.v, 3);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec3_sum_v(const float *vec) {
    return vec3_sum(Vec3(vec));
}


/** returns a dot b */
static float vec3_dot(vec3 vec_a, vec3 vec_b) {
    return vecN_dot(vec_a.v, vec_b.v, 3);
}
/** returns a dot b */
static float vec3_dot_v(const float *vec_a, const float *vec_b) {
    return vec3_dot(Vec3(vec_a), Vec3(vec_b));
}


/** returns ||vec||_3 */
static float vec3_norm(vec3 vec) {
    return vecN_norm(vec.v, 3);
}
/** returns ||vec||_3 */
static float vec3_norm_v(const float *vec) {
    return vec3_norm(Vec3(vec));
}


/** returns ||vec||_p */
static float vec3_norm_p(vec3 vec, float p) {
    return vecN_norm_p(vec.v, p, 3);
}
/** returns ||vec||_p */
static float vec3_norm_p_v(const float *vec, float p) {
    return vec3_norm_p(Vec3(vec), p);
}


/** returns ||vec||_1 */
static float vec3_norm_1(vec3 vec) {
    return vecN_norm_1(vec.v, 3);
}
/** returns ||vec||_1 */
static float vec3_norm_1_v(const float *vec) {
    return vec3_norm_1(Vec3(vec));
}


/** returns ||vec||_inf */
static float vec3_norm_inf(vec3 vec) {
    return vecN_norm_inf(vec.v, 3);
}
/** returns ||vec||_inf */
static float vec3_norm_inf_v(const float *vec) {
    return vec3_norm_inf(Vec3(vec));
}


/** dst = vec / norm(vec) */
static vec3 vec3_normalize_unsafe(vec3 vec) {
    vec3 res;
    vecN_normalize_unsafe(res.v, vec.v, 3);
    return res;
}
/** dst = vec / norm(vec) */
static vec3 vec3_normalize_unsafe_v(const float *vec) {
    return vec3_normalize_unsafe(Vec3(vec));
}


/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3 vec3_normalize(vec3 vec) {
    vec3 res;
    vecN_normalize(res.v, vec.v, 3);
    return res;
}
/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3 vec3_normalize_v(const float *vec) {
    return vec3_normalize(Vec3(vec));
}


/** dst = from + (to - from) * t */
static vec3 vec3_lerp(vec3 vec_from, vec3 vec_to, float t) {
    vec3 res;
    vecN_lerp(res.v, vec_from.v, vec_to.v, t, 3);
    return res;
}
/** dst = from + (to - from) * t */
static vec3 vec3_lerp_v(const float *vec_from, const float *vec_to, float t) {
    return vec3_lerp(Vec3(vec_from), Vec3(vec_to), t);
}


/** dst = a x b */
static vec3 vec3_cross(vec3 vec_a, vec3 vec_b) {
    vec3 res;
    res.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
    res.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
    res.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
    return res;
}
/** dst = a x b */
static vec3 vec3_cross_v(const float *vec_a, const float *vec_b) {
    return vec3_cross(Vec3(vec_a), Vec3(vec_b));
}


#endif //MATHC_VEC_VEC3_H
