#ifndef MATHC_VEC_IVEC2_H
#define MATHC_VEC_IVEC2_H

#include "ivecn.h"
#include "../types.h"


/** dst = scalar */
static ivec2 ivec2_set(int scalar) {
    ivec2 res;
    ivecN_set(res.v, scalar, 2);
    return res;
}


/** dst = -vec */
static ivec2 ivec2_neg(ivec2 vec) {
    ivec2 res;
    ivecN_neg(res.v, vec.v, 2);
    return res;
}
/** dst = -vec */
static ivec2 ivec2_neg_v(const int *vec) {
    return ivec2_neg(IVec2(vec));
}


/** dst = a + b */
static ivec2 ivec2_add_vec(ivec2 vec_a, ivec2 vec_b) {
    ivec2 res;
    ivecN_add_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a + b */
static ivec2 ivec2_add_vec_v(const int *vec_a, const int *vec_b) {
    return ivec2_add_vec(IVec2(vec_a), IVec2(vec_b));
}


/** dst = a + b */
static ivec2 ivec2_add_sca(ivec2 vec_a, int scalar_b) {
    ivec2 res;
    ivecN_add_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a + b */
static ivec2 ivec2_add_sca_v(const int *vec_a, int scalar_b) {
    return ivec2_add_sca(IVec2(vec_a), scalar_b);
}


/** dst = a - b */
static ivec2 ivec2_sub_vec(ivec2 vec_a, ivec2 vec_b) {
    ivec2 res;
    ivecN_sub_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a - b */
static ivec2 ivec2_sub_vec_v(const int *vec_a, const int *vec_b) {
    return ivec2_sub_vec(IVec2(vec_a), IVec2(vec_b));
}


/** dst = a - b */
static ivec2 ivec2_sub_sca(ivec2 vec_a, int scalar_b) {
    ivec2 res;
    ivecN_sub_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a - b */
static ivec2 ivec2_sub_sca_v(const int *vec_a, int scalar_b) {
    return ivec2_sub_sca(IVec2(vec_a), scalar_b);
}


/** dst = a * b */
static ivec2 ivec2_scale_vec(ivec2 vec_a, ivec2 vec_b) {
    ivec2 res;
    ivecN_scale_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a * b */
static ivec2 ivec2_scale_vec_v(const int *vec_a, const int *vec_b) {
    return ivec2_scale_vec(IVec2(vec_a), IVec2(vec_b));
}


/** dst = a * b */
static ivec2 ivec2_scale_sca(ivec2 vec_a, int scalar_b) {
    ivec2 res;
    ivecN_scale_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a * b */
static ivec2 ivec2_scale_sca_v(const int *vec_a, int scalar_b) {
    return ivec2_scale_sca(IVec2(vec_a), scalar_b);
}


/** dst = a / b */
static ivec2 ivec2_div_vec(ivec2 vec_a, ivec2 vec_b) {
    ivec2 res;
    ivecN_div_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a / b */
static ivec2 ivec2_div_vec_v(const int *vec_a, const int *vec_b) {
    return ivec2_div_vec(IVec2(vec_a), IVec2(vec_b));
}


/** dst = a / b */
static ivec2 ivec2_div_sca(ivec2 vec_a, int scalar_b) {
    ivec2 res;
    ivecN_div_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a / b */
static ivec2 ivec2_div_sca_v(const int *vec_a, int scalar_b) {
    return ivec2_div_sca(IVec2(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int ivec2_sum(ivec2 vec) {
    return ivecN_sum(vec.v, 2);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int ivec2_sum_v(const int *vec) {
    return ivec2_sum(IVec2(vec));
}


/** returns a dot b */
static int ivec2_dot(ivec2 vec_a, ivec2 vec_b) {
    return ivecN_dot(vec_a.v, vec_b.v, 2);
}
/** returns a dot b */
static int ivec2_dot_v(const int *vec_a, const int *vec_b) {
    return ivec2_dot(IVec2(vec_a), IVec2(vec_b));
}


/** returns ||vec||_2 */
static float ivec2_norm(ivec2 vec) {
    return ivecN_norm(vec.v, 2);
}
/** returns ||vec||_2 */
static float ivec2_norm_v(const int *vec) {
    return ivec2_norm(IVec2(vec));
}


/** returns ||vec||_p */
static float ivec2_norm_p(ivec2 vec, float p) {
    return ivecN_norm_p(vec.v, p, 2);
}
/** returns ||vec||_p */
static float ivec2_norm_p_v(const int *vec, float p) {
    return ivec2_norm_p(IVec2(vec), p);
}


/** returns ||vec||_1 */
static int ivec2_norm_1(ivec2 vec) {
    return ivecN_norm_1(vec.v, 2);
}
/** returns ||vec||_1 */
static int ivec2_norm_1_v(const int *vec) {
    return ivec2_norm_1(IVec2(vec));
}


/** returns ||vec||_inf */
static int ivec2_norm_inf(ivec2 vec) {
    return ivecN_norm_inf(vec.v, 2);
}
/** returns ||vec||_inf */
static int ivec2_norm_inf_v(const int *vec) {
    return ivec2_norm_inf(IVec2(vec));
}


/** dst = from + (to - from) * t */
static ivec2 ivec2_lerp(ivec2 vec_from, ivec2 vec_to, float t) {
    ivec2 res;
    ivecN_lerp(res.v, vec_from.v, vec_to.v, t, 2);
    return res;
}
/** dst = from + (to - from) * t */
static ivec2 ivec2_lerp_v(const int *vec_from, const int *vec_to, float t) {
    return ivec2_lerp(IVec2(vec_from), IVec2(vec_to), t);
}


#endif //MATHC_VEC_IVEC2_H
