#ifndef MATHC_VEC_IVEC3_V_H
#define MATHC_VEC_IVEC3_V_H

#include "ivec3.h"


/** dst = -ivec */
static ivec3 ivec3_neg_v(const int *ivec) {
    ivec3 res;
    ivecN_neg(res.v, ivec, 3);
    return res;
}

/** dst = a + b */
static ivec3 ivec3_add_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec3 res;
    ivecN_add_ivec(res.v, ivec_a, ivec_b, 3);
    return res;
}

/** dst = a + b */
static ivec3 ivec3_add_sca_v(const int *ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_add_sca(res.v, ivec_a, scalar_b, 3);
    return res;
}

/** dst = a - b */
static ivec3 ivec3_sub_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec3 res;
    ivecN_sub_ivec(res.v, ivec_a, ivec_b, 3);
    return res;
}

/** dst = a - b */
static ivec3 ivec3_sub_sca_v(const int *ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_sub_sca(res.v, ivec_a, scalar_b, 3);
    return res;
}

/** dst = a * b */
static ivec3 ivec3_scale_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec3 res;
    ivecN_scale_ivec(res.v, ivec_a, ivec_b, 3);
    return res;
}

/** dst = a * b */
static ivec3 ivec3_scale_sca_v(const int *ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_scale_sca(res.v, ivec_a, scalar_b, 3);
    return res;
}

/** dst = a / b */
static ivec3 ivec3_div_ivec_v(const int *ivec_a, const int *ivec_b) {
    ivec3 res;
    ivecN_div_ivec(res.v, ivec_a, ivec_b, 3);
    return res;
}

/** dst = a / b */
static ivec3 ivec3_div_sca_v(const int *ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_div_sca(res.v, ivec_a, scalar_b, 3);
    return res;
}

/** returns ivec[0] + ivec[1] + ... + ivec[n-1] */
static int ivec3_sum_v(const int *ivec) {
    return ivecN_sum(ivec, 3);
}

/** returns a dot b */
static int ivec3_dot_v(const int *ivec_a, const int *ivec_b) {
    return ivecN_dot(ivec_a, ivec_b, 3);
}

/** returns ||ivec||_2 */
static float ivec3_norm_v(const int *ivec) {
    return ivecN_norm(ivec, 3);
}

/** returns ||ivec||_p */
static float ivec3_norm_p_v(const int *ivec, float p) {
    return ivecN_norm_p(ivec, p, 3);
}

/** returns ||ivec||_1 */
static int ivec3_norm_1_v(const int *ivec) {
    return ivecN_norm_1(ivec, 3);
}

/** returns ||ivec||_inf */
static int ivec3_norm_inf_v(const int *ivec) {
    return ivecN_norm_inf(ivec, 3);
}

/** dst = from + (to - from) * t */
static ivec3 ivec3_lerp_v(const int *from, const int *to, float t) {
    ivec3 res;
    ivecN_lerp(res.v, from, to, t, 3);
    return res;
}

/** dst = a x b */
static ivec3 ivec3_cross_v(const int *a, const int *b) {
    return ivec3_cross(IVec3(a), IVec3(b));
}

#endif //MATHC_VEC_IVEC3_V_H
