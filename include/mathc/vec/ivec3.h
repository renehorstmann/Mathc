#ifndef MATHC_VEC_IVEC3_H
#define MATHC_VEC_IVEC3_H

#include "ivecn.h"
#include "../types.h"


/** dst = scalar */
static ivec3 ivec3_set(int scalar) {
    ivec3 res;
    ivecN_set(res.v, scalar, 3);
    return res;
}


/** dst = -vec */
static ivec3 ivec3_neg(ivec3 vec) {
    ivec3 res;
    ivecN_neg(res.v, vec.v, 3);
    return res;
}
/** dst = -vec */
static ivec3 ivec3_neg_v(const int *vec) {
    return ivec3_neg(IVec3(vec));
}


/** dst = a + b */
static ivec3 ivec3_add_vec(ivec3 vec_a, ivec3 vec_b) {
    ivec3 res;
    ivecN_add_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a + b */
static ivec3 ivec3_add_vec_v(const int *vec_a, const int *vec_b) {
    return ivec3_add_vec(IVec3(vec_a), IVec3(vec_b));
}


/** dst = a + b */
static ivec3 ivec3_add_sca(ivec3 vec_a, int scalar_b) {
    ivec3 res;
    ivecN_add_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a + b */
static ivec3 ivec3_add_sca_v(const int *vec_a, int scalar_b) {
    return ivec3_add_sca(IVec3(vec_a), scalar_b);
}


/** dst = a - b */
static ivec3 ivec3_sub_vec(ivec3 vec_a, ivec3 vec_b) {
    ivec3 res;
    ivecN_sub_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a - b */
static ivec3 ivec3_sub_vec_v(const int *vec_a, const int *vec_b) {
    return ivec3_sub_vec(IVec3(vec_a), IVec3(vec_b));
}


/** dst = a - b */
static ivec3 ivec3_sub_sca(ivec3 vec_a, int scalar_b) {
    ivec3 res;
    ivecN_sub_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a - b */
static ivec3 ivec3_sub_sca_v(const int *vec_a, int scalar_b) {
    return ivec3_sub_sca(IVec3(vec_a), scalar_b);
}


/** dst = a * b */
static ivec3 ivec3_scale_vec(ivec3 vec_a, ivec3 vec_b) {
    ivec3 res;
    ivecN_scale_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a * b */
static ivec3 ivec3_scale_vec_v(const int *vec_a, const int *vec_b) {
    return ivec3_scale_vec(IVec3(vec_a), IVec3(vec_b));
}


/** dst = a * b */
static ivec3 ivec3_scale_sca(ivec3 vec_a, int scalar_b) {
    ivec3 res;
    ivecN_scale_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a * b */
static ivec3 ivec3_scale_sca_v(const int *vec_a, int scalar_b) {
    return ivec3_scale_sca(IVec3(vec_a), scalar_b);
}


/** dst = a / b */
static ivec3 ivec3_div_vec(ivec3 vec_a, ivec3 vec_b) {
    ivec3 res;
    ivecN_div_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a / b */
static ivec3 ivec3_div_vec_v(const int *vec_a, const int *vec_b) {
    return ivec3_div_vec(IVec3(vec_a), IVec3(vec_b));
}


/** dst = a / b */
static ivec3 ivec3_div_sca(ivec3 vec_a, int scalar_b) {
    ivec3 res;
    ivecN_div_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a / b */
static ivec3 ivec3_div_sca_v(const int *vec_a, int scalar_b) {
    return ivec3_div_sca(IVec3(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int ivec3_sum(ivec3 vec) {
    return ivecN_sum(vec.v, 3);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int ivec3_sum_v(const int *vec) {
    return ivec3_sum(IVec3(vec));
}


/** returns a dot b */
static int ivec3_dot(ivec3 vec_a, ivec3 vec_b) {
    return ivecN_dot(vec_a.v, vec_b.v, 3);
}
/** returns a dot b */
static int ivec3_dot_v(const int *vec_a, const int *vec_b) {
    return ivec3_dot(IVec3(vec_a), IVec3(vec_b));
}


/** returns ||vec||_3 */
static float ivec3_norm(ivec3 vec) {
    return ivecN_norm(vec.v, 3);
}
/** returns ||vec||_3 */
static float ivec3_norm_v(const int *vec) {
    return ivec3_norm(IVec3(vec));
}


/** returns ||vec||_p */
static float ivec3_norm_p(ivec3 vec, float p) {
    return ivecN_norm_p(vec.v, p, 3);
}
/** returns ||vec||_p */
static float ivec3_norm_p_v(const int *vec, float p) {
    return ivec3_norm_p(IVec3(vec), p);
}


/** returns ||vec||_1 */
static int ivec3_norm_1(ivec3 vec) {
    return ivecN_norm_1(vec.v, 3);
}
/** returns ||vec||_1 */
static int ivec3_norm_1_v(const int *vec) {
    return ivec3_norm_1(IVec3(vec));
}


/** returns ||vec||_inf */
static int ivec3_norm_inf(ivec3 vec) {
    return ivecN_norm_inf(vec.v, 3);
}
/** returns ||vec||_inf */
static int ivec3_norm_inf_v(const int *vec) {
    return ivec3_norm_inf(IVec3(vec));
}


/** dst = from + (to - from) * t */
static ivec3 ivec3_lerp(ivec3 vec_from, ivec3 vec_to, float t) {
    ivec3 res;
    ivecN_lerp(res.v, vec_from.v, vec_to.v, t, 3);
    return res;
}
/** dst = from + (to - from) * t */
static ivec3 ivec3_lerp_v(const int *vec_from, const int *vec_to, float t) {
    return ivec3_lerp(IVec3(vec_from), IVec3(vec_to), t);
}


/** dst = a x b */
static ivec3 ivec3_cross(ivec3 vec_a, ivec3 vec_b) {
    ivec3 res;
    res.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
    res.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
    res.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
    return res;
}
/** dst = a x b */
static ivec3 ivec3_cross_v(const int *vec_a, const int *vec_b) {
    return ivec3_cross(IVec3(vec_a), IVec3(vec_b));
}


#endif //MATHC_VEC_IVEC3_H
