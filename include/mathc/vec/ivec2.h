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

/** dst = -ivec */
static ivec2 ivec2_neg(ivec2 ivec) {
    ivec2 res;
    ivecN_neg(res.v, ivec.v, 2);
    return res;
}

/** dst = a + b */
static ivec2 ivec2_add_ivec(ivec2 ivec_a, ivec2 ivec_b) {
    ivec2 res;
    ivecN_add_ivec(res.v, ivec_a.v, ivec_b.v, 2);
    return res;
}

/** dst = a + b */
static ivec2 ivec2_add_sca(ivec2 ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_add_sca(res.v, ivec_a.v, scalar_b, 2);
    return res;
}

/** dst = a - b */
static ivec2 ivec2_sub_ivec(ivec2 ivec_a, ivec2 ivec_b) {
    ivec2 res;
    ivecN_sub_ivec(res.v, ivec_a.v, ivec_b.v, 2);
    return res;
}

/** dst = a - b */
static ivec2 ivec2_sub_sca(ivec2 ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_sub_sca(res.v, ivec_a.v, scalar_b, 2);
    return res;
}

/** dst = a * b */
static ivec2 ivec2_scale_ivec(ivec2 ivec_a, ivec2 ivec_b) {
    ivec2 res;
    ivecN_scale_ivec(res.v, ivec_a.v, ivec_b.v, 2);
    return res;
}

/** dst = a * b */
static ivec2 ivec2_scale_sca(ivec2 ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_scale_sca(res.v, ivec_a.v, scalar_b, 2);
    return res;
}

/** dst = a / b */
static ivec2 ivec2_div_ivec(ivec2 ivec_a, ivec2 ivec_b) {
    ivec2 res;
    ivecN_div_ivec(res.v, ivec_a.v, ivec_b.v, 2);
    return res;
}

/** dst = a / b */
static ivec2 ivec2_div_sca(ivec2 ivec_a, int scalar_b) {
    ivec2 res;
    ivecN_div_sca(res.v, ivec_a.v, scalar_b, 2);
    return res;
}

/** returns ivec[0] + ivec[1] + ... + ivec[n-1] */
static int ivec2_sum(ivec2 ivec) {
    return ivecN_sum(ivec.v, 2);
}

/** returns a dot b */
static int ivec2_dot(ivec2 ivec_a, ivec2 ivec_b) {
    return ivecN_dot(ivec_a.v, ivec_b.v, 2);
}

/** returns ||ivec||_2 */
static float ivec2_norm(ivec2 ivec) {
    return ivecN_norm(ivec.v, 2);
}

/** returns ||ivec||_p */
static float ivec2_norm_p(ivec2 ivec, float p) {
    return ivecN_norm_p(ivec.v, p, 2);
}

/** returns ||ivec||_1 */
static int ivec2_norm_1(ivec2 ivec) {
    return ivecN_norm_1(ivec.v, 2);
}

/** returns ||ivec||_inf */
static int ivec2_norm_inf(ivec2 ivec) {
    return ivecN_norm_inf(ivec.v, 2);
}

/** dst = from + (to - from) * t */
static ivec2 ivec2_lerp(ivec2 from, ivec2 to, float t) {
    ivec2 res;
    ivecN_lerp(res.v, from.v, to.v, t, 2);
    return res;
}

#endif //MATHC_VEC_IVEC2_H
