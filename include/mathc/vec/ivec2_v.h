#ifndef MATHC_VEC_IVEC2_V_H
#define MATHC_VEC_IVEC2_V_H

#include "ivec2.h"


/** dst = -ivec */
static ivec2 ivec2_neg_v(const int *ivec) {
    ivec2 res;
    ivecN_neg(res.v, ivec, 2);
    return res;
}

/** dst = a + b */
static ivec2 ivec2_add_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec2 res;
    ivecN_add_ivec(res.v, ivec_a, ivec_b, 2);
    return res;
}

/** dst = a + b */
static ivec2 ivec2_add_sca_v(const int *ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_add_sca(res.v, ivec_a, scalar_b, 2);
    return res;
}

/** dst = a - b */
static ivec2 ivec2_sub_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec2 res;
    ivecN_sub_ivec(res.v, ivec_a, ivec_b, 2);
    return res;
}

/** dst = a - b */
static ivec2 ivec2_sub_sca_v(const int *ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_sub_sca(res.v, ivec_a, scalar_b, 2);
    return res;
}

/** dst = a * b */
static ivec2 ivec2_scale_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec2 res;
    ivecN_scale_ivec(res.v, ivec_a, ivec_b, 2);
    return res;
}

/** dst = a * b */
static ivec2 ivec2_scale_sca_v(const int *ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_scale_sca(res.v, ivec_a, scalar_b, 2);
    return res;
}

/** dst = a / b */
static ivec2 ivec2_div_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec2 res;
    ivecN_div_ivec(res.v, ivec_a, ivec_b, 2);
    return res;
}

/** dst = a / b */
static ivec2 ivec2_div_sca_v(const int *ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_div_sca(res.v, ivec_a, scalar_b, 2);
    return res;
}

/** returns ivec[0] + ivec[1] + ... + ivec[n-1] */
static int ivec2_sum_v(const int *ivec) {
    return ivecN_sum(ivec, 2);
}

/** returns a dot b */
static int ivec2_dot_v(const int *ivec_a, const int *ivec_b) {
    return ivecN_dot(ivec_a, ivec_b, 2);
}

/** returns ||ivec||_2 */
static float ivec2_norm_v(const int *ivec) {
    return ivecN_norm(ivec, 2);
}

/** returns ||ivec||_p */
static float ivec2_norm_p_v(const int *ivec, float p) {
    return ivecN_norm_p(ivec, p, 2);
}

/** returns ||ivec||_1 */
static int ivec2_norm_1_v(const int *ivec) {
    return ivecN_norm_1(ivec, 2);
}

/** returns ||ivec||_inf */
static int ivec2_norm_inf_v(const int *ivec) {
    return ivecN_norm_inf(ivec, 2);
}

/** dst = from + (to - from) * t */
static ivec2 ivec2_lerp_v(const int *from, const int *to,  t) {
    ivec2 res;
    ivecN_lerp(res.v, from, to, t, 2);
    return res;
}

#endif //MATHC_VEC_IVEC2_V_H
