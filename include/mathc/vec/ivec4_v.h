#ifndef MATHC_VEC_IVEC4_V_H
#define MATHC_VEC_IVEC4_V_H

#include "ivec4.h"


/** dst = -ivec */
static ivec4 ivec4_neg_v(const int *ivec) {
    ivec4 res;
    ivecN_neg(res.v, ivec, 4);
    return res;
}

/** dst = a + b */
static ivec4 ivec4_add_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec4 res;
    ivecN_add_ivec(res.v, ivec_a, ivec_b, 4);
    return res;
}

/** dst = a + b */
static ivec4 ivec4_add_sca_v(const int *ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_add_sca(res.v, ivec_a, scalar_b, 4);
    return res;
}

/** dst = a - b */
static ivec4 ivec4_sub_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec4 res;
    ivecN_sub_ivec(res.v, ivec_a, ivec_b, 4);
    return res;
}

/** dst = a - b */
static ivec4 ivec4_sub_sca_v(const int *ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_sub_sca(res.v, ivec_a, scalar_b, 4);
    return res;
}

/** dst = a * b */
static ivec4 ivec4_scale_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec4 res;
    ivecN_scale_ivec(res.v, ivec_a, ivec_b, 4);
    return res;
}

/** dst = a * b */
static ivec4 ivec4_scale_sca_v(const int *ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_scale_sca(res.v, ivec_a, scalar_b, 4);
    return res;
}

/** dst = a / b */
static ivec4 ivec4_div_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec4 res;
    ivecN_div_ivec(res.v, ivec_a, ivec_b, 4);
    return res;
}

/** dst = a / b */
static ivec4 ivec4_div_sca_v(const int *ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_div_sca(res.v, ivec_a, scalar_b, 4);
    return res;
}

/** returns ivec[0] + ivec[1] + ... + ivec[n-1] */
static int ivec4_sum_v(const int *ivec) {
    return ivecN_sum(ivec, 4);
}

/** returns a dot b */
static int ivec4_dot_v(const int *ivec_a, const int *ivec_b) {
    return ivecN_dot(ivec_a, ivec_b, 4);
}

/** returns ||ivec||_2 */
static float ivec4_norm_v(const int *ivec) {
    return ivecN_norm(ivec, 4);
}

/** returns ||ivec||_p */
static float ivec4_norm_p_v(const int *ivec, float p) {
    return ivecN_norm_p(ivec, p, 4);
}

/** returns ||ivec||_1 */
static int ivec4_norm_1_v(const int *ivec) {
    return ivecN_norm_1(ivec, 4);
}

/** returns ||ivec||_inf */
static int ivec4_norm_inf_v(const int *ivec) {
    return ivecN_norm_inf(ivec, 4);
}

/** dst = from + (to - from) * t */
static ivec4 ivec4_lerp_v(const int *from, const int *to, float t) {
    ivec4 res;
    ivecN_lerp(res.v, from, to, t, 4);
    return res;
}

/** dst = a x b , dst.w = 0 */
static ivec4 ivec4_cross_v(const int *a, const int *b) {
    return ivec4_cross(IVec4(a), IVec4(b));
}

#endif //MATHC_VEC_IVEC4_V_H
