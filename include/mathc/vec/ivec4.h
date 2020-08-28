#ifndef MATHC_VEC_IVEC4_H
#define MATHC_VEC_IVEC4_H

#include "ivecn.h"
#include "../types.h"


/** dst = scalar */
static ivec4 ivec4_set(int scalar) {
    ivec4 res;
    ivecN_set(res.v, scalar, 4);
    return res;
}


/** dst = -vec */
static ivec4 ivec4_neg(ivec4 vec) {
    ivec4 res;
    ivecN_neg(res.v, vec.v, 4);
    return res;
}
/** dst = -vec */
static ivec4 ivec4_neg_v(const int *vec) {
    return ivec4_neg(IVec4(vec));
}


/** dst = a + b */
static ivec4 ivec4_add_vec(ivec4 vec_a, ivec4 vec_b) {
    ivec4 res;
    ivecN_add_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a + b */
static ivec4 ivec4_add_vec_v(const int *vec_a, const int *vec_b) {
    return ivec4_add_vec(IVec4(vec_a), IVec4(vec_b));
}


/** dst = a + b */
static ivec4 ivec4_add_sca(ivec4 vec_a, int scalar_b) {
    ivec4 res;
    ivecN_add_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a + b */
static ivec4 ivec4_add_sca_v(const int *vec_a, int scalar_b) {
    return ivec4_add_sca(IVec4(vec_a), scalar_b);
}


/** dst = a - b */
static ivec4 ivec4_sub_vec(ivec4 vec_a, ivec4 vec_b) {
    ivec4 res;
    ivecN_sub_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a - b */
static ivec4 ivec4_sub_vec_v(const int *vec_a, const int *vec_b) {
    return ivec4_sub_vec(IVec4(vec_a), IVec4(vec_b));
}


/** dst = a - b */
static ivec4 ivec4_sub_sca(ivec4 vec_a, int scalar_b) {
    ivec4 res;
    ivecN_sub_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a - b */
static ivec4 ivec4_sub_sca_v(const int *vec_a, int scalar_b) {
    return ivec4_sub_sca(IVec4(vec_a), scalar_b);
}


/** dst = a * b */
static ivec4 ivec4_scale_vec(ivec4 vec_a, ivec4 vec_b) {
    ivec4 res;
    ivecN_scale_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a * b */
static ivec4 ivec4_scale_vec_v(const int *vec_a, const int *vec_b) {
    return ivec4_scale_vec(IVec4(vec_a), IVec4(vec_b));
}


/** dst = a * b */
static ivec4 ivec4_scale_sca(ivec4 vec_a, int scalar_b) {
    ivec4 res;
    ivecN_scale_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a * b */
static ivec4 ivec4_scale_sca_v(const int *vec_a, int scalar_b) {
    return ivec4_scale_sca(IVec4(vec_a), scalar_b);
}


/** dst = a / b */
static ivec4 ivec4_div_vec(ivec4 vec_a, ivec4 vec_b) {
    ivec4 res;
    ivecN_div_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a / b */
static ivec4 ivec4_div_vec_v(const int *vec_a, const int *vec_b) {
    return ivec4_div_vec(IVec4(vec_a), IVec4(vec_b));
}


/** dst = a / b */
static ivec4 ivec4_div_sca(ivec4 vec_a, int scalar_b) {
    ivec4 res;
    ivecN_div_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a / b */
static ivec4 ivec4_div_sca_v(const int *vec_a, int scalar_b) {
    return ivec4_div_sca(IVec4(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int ivec4_sum(ivec4 vec) {
    return ivecN_sum(vec.v, 4);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int ivec4_sum_v(const int *vec) {
    return ivec4_sum(IVec4(vec));
}


/** returns a dot b */
static int ivec4_dot(ivec4 vec_a, ivec4 vec_b) {
    return ivecN_dot(vec_a.v, vec_b.v, 4);
}
/** returns a dot b */
static int ivec4_dot_v(const int *vec_a, const int *vec_b) {
    return ivec4_dot(IVec4(vec_a), IVec4(vec_b));
}


/** returns ||vec||_4 */
static float ivec4_norm(ivec4 vec) {
    return ivecN_norm(vec.v, 4);
}
/** returns ||vec||_4 */
static float ivec4_norm_v(const int *vec) {
    return ivec4_norm(IVec4(vec));
}


/** returns ||vec||_p */
static float ivec4_norm_p(ivec4 vec, float p) {
    return ivecN_norm_p(vec.v, p, 4);
}
/** returns ||vec||_p */
static float ivec4_norm_p_v(const int *vec, float p) {
    return ivec4_norm_p(IVec4(vec), p);
}


/** returns ||vec||_1 */
static int ivec4_norm_1(ivec4 vec) {
    return ivecN_norm_1(vec.v, 4);
}
/** returns ||vec||_1 */
static int ivec4_norm_1_v(const int *vec) {
    return ivec4_norm_1(IVec4(vec));
}


/** returns ||vec||_inf */
static int ivec4_norm_inf(ivec4 vec) {
    return ivecN_norm_inf(vec.v, 4);
}
/** returns ||vec||_inf */
static int ivec4_norm_inf_v(const int *vec) {
    return ivec4_norm_inf(IVec4(vec));
}


/** dst = from + (to - from) * t */
static ivec4 ivec4_lerp(ivec4 vec_from, ivec4 vec_to, float t) {
    ivec4 res;
    ivecN_lerp(res.v, vec_from.v, vec_to.v, t, 4);
    return res;
}
/** dst = from + (to - from) * t */
static ivec4 ivec4_lerp_v(const int *vec_from, const int *vec_to, float t) {
    return ivec4_lerp(IVec4(vec_from), IVec4(vec_to), t);
}


/** dst = a x b , dst.w = 0 */
static ivec4 ivec4_cross(ivec4 vec_a, ivec4 vec_b) {
    ivec4 res;
    res.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
    res.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
    res.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
    res.w = 0;
    return res;
}
/** dst = a x b , dst.w = 0 */
static ivec4 ivec4_cross_v(const int *vec_a, const int *vec_b) {
    return ivec4_cross(IVec4(vec_a), IVec4(vec_b));
}


#endif //MATHC_VEC_IVEC4_H
