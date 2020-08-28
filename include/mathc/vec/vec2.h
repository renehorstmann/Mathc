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
/** dst = -vec */
static vec2 vec2_neg_v(const float *vec) {
    return vec2_neg(Vec2(vec));
}


/** dst = a + b */
static vec2 vec2_add_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_add_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a + b */
static vec2 vec2_add_vec_v(const float *vec_a, const float *vec_b) {
    return vec2_add_vec(Vec2(vec_a), Vec2(vec_b));
}


/** dst = a + b */
static vec2 vec2_add_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_add_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a + b */
static vec2 vec2_add_sca_v(const float *vec_a, float scalar_b) {
    return vec2_add_sca(Vec2(vec_a), scalar_b);
}


/** dst = a - b */
static vec2 vec2_sub_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_sub_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a - b */
static vec2 vec2_sub_vec_v(const float *vec_a, const float *vec_b) {
    return vec2_sub_vec(Vec2(vec_a), Vec2(vec_b));
}


/** dst = a - b */
static vec2 vec2_sub_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_sub_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a - b */
static vec2 vec2_sub_sca_v(const float *vec_a, float scalar_b) {
    return vec2_sub_sca(Vec2(vec_a), scalar_b);
}


/** dst = a * b */
static vec2 vec2_scale_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_scale_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a * b */
static vec2 vec2_scale_vec_v(const float *vec_a, const float *vec_b) {
    return vec2_scale_vec(Vec2(vec_a), Vec2(vec_b));
}


/** dst = a * b */
static vec2 vec2_scale_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_scale_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a * b */
static vec2 vec2_scale_sca_v(const float *vec_a, float scalar_b) {
    return vec2_scale_sca(Vec2(vec_a), scalar_b);
}


/** dst = a / b */
static vec2 vec2_div_vec(vec2 vec_a, vec2 vec_b) {
    vec2 res;
    vecN_div_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a / b */
static vec2 vec2_div_vec_v(const float *vec_a, const float *vec_b) {
    return vec2_div_vec(Vec2(vec_a), Vec2(vec_b));
}


/** dst = a / b */
static vec2 vec2_div_sca(vec2 vec_a, float scalar_b) {
    vec2 res;
    vecN_div_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a / b */
static vec2 vec2_div_sca_v(const float *vec_a, float scalar_b) {
    return vec2_div_sca(Vec2(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec2_sum(vec2 vec) {
    return vecN_sum(vec.v, 2);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec2_sum_v(const float *vec) {
    return vec2_sum(Vec2(vec));
}


/** returns a dot b */
static float vec2_dot(vec2 vec_a, vec2 vec_b) {
    return vecN_dot(vec_a.v, vec_b.v, 2);
}
/** returns a dot b */
static float vec2_dot_v(const float *vec_a, const float *vec_b) {
    return vec2_dot(Vec2(vec_a), Vec2(vec_b));
}


/** returns ||vec||_2 */
static float vec2_norm(vec2 vec) {
    return vecN_norm(vec.v, 2);
}
/** returns ||vec||_2 */
static float vec2_norm_v(const float *vec) {
    return vec2_norm(Vec2(vec));
}


/** returns ||vec||_p */
static float vec2_norm_p(vec2 vec, float p) {
    return vecN_norm_p(vec.v, p, 2);
}
/** returns ||vec||_p */
static float vec2_norm_p_v(const float *vec, float p) {
    return vec2_norm_p(Vec2(vec), p);
}


/** returns ||vec||_1 */
static float vec2_norm_1(vec2 vec) {
    return vecN_norm_1(vec.v, 2);
}
/** returns ||vec||_1 */
static float vec2_norm_1_v(const float *vec) {
    return vec2_norm_1(Vec2(vec));
}


/** returns ||vec||_inf */
static float vec2_norm_inf(vec2 vec) {
    return vecN_norm_inf(vec.v, 2);
}
/** returns ||vec||_inf */
static float vec2_norm_inf_v(const float *vec) {
    return vec2_norm_inf(Vec2(vec));
}


/** dst = vec / norm(vec) */
static vec2 vec2_normalize_unsafe(vec2 vec) {
    vec2 res;
    vecN_normalize_unsafe(res.v, vec.v, 2);
    return res;
}
/** dst = vec / norm(vec) */
static vec2 vec2_normalize_unsafe_v(const float *vec) {
    return vec2_normalize_unsafe(Vec2(vec));
}


/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec2 vec2_normalize(vec2 vec) {
    vec2 res;
    vecN_normalize(res.v, vec.v, 2);
    return res;
}
/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec2 vec2_normalize_v(const float *vec) {
    return vec2_normalize(Vec2(vec));
}


/** dst = from + (to - from) * t */
static vec2 vec2_lerp(vec2 vec_from, vec2 vec_to, float t) {
    vec2 res;
    vecN_lerp(res.v, vec_from.v, vec_to.v, t, 2);
    return res;
}
/** dst = from + (to - from) * t */
static vec2 vec2_lerp_v(const float *vec_from, const float *vec_to, float t) {
    return vec2_lerp(Vec2(vec_from), Vec2(vec_to), t);
}


#endif //MATHC_VEC_VEC2_H
