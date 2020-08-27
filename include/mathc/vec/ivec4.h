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

/** dst = -ivec */
static ivec4 ivec4_neg(ivec4 ivec) {
    ivec4 res;
    ivecN_neg(res.v, ivec.v, 4);
    return res;
}

/** dst = a + b */
static ivec4 ivec4_add_ivec(ivec4 ivec_a, ivec4 ivec_b) {
    ivec4 res;
    ivecN_add_ivec(res.v, ivec_a.v, ivec_b.v, 4);
    return res;
}

/** dst = a + b */
static ivec4 ivec4_add_sca(ivec4 ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_add_sca(res.v, ivec_a.v, scalar_b, 4);
    return res;
}

/** dst = a - b */
static ivec4 ivec4_sub_ivec(ivec4 ivec_a, ivec4 ivec_b) {
    ivec4 res;
    ivecN_sub_ivec(res.v, ivec_a.v, ivec_b.v, 4);
    return res;
}

/** dst = a - b */
static ivec4 ivec4_sub_sca(ivec4 ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_sub_sca(res.v, ivec_a.v, scalar_b, 4);
    return res;
}

/** dst = a * b */
static ivec4 ivec4_scale_ivec(ivec4 ivec_a, ivec4 ivec_b) {
    ivec4 res;
    ivecN_scale_ivec(res.v, ivec_a.v, ivec_b.v, 4);
    return res;
}

/** dst = a * b */
static ivec4 ivec4_scale_sca(ivec4 ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_scale_sca(res.v, ivec_a.v, scalar_b, 4);
    return res;
}

/** dst = a / b */
static ivec4 ivec4_div_ivec(ivec4 ivec_a, ivec4 ivec_b) {
    ivec4 res;
    ivecN_div_ivec(res.v, ivec_a.v, ivec_b.v, 4);
    return res;
}

/** dst = a / b */
static ivec4 ivec4_div_sca(ivec4 ivec_a, int scalar_b) {
    ivec4 res;
    ivecN_div_sca(res.v, ivec_a.v, scalar_b, 4);
    return res;
}

/** returns ivec[0] + ivec[1] + ... + ivec[n-1] */
static int ivec4_sum(ivec4 ivec) {
    return ivecN_sum(ivec.v, 4);
}

/** returns a dot b */
static int ivec4_dot(ivec4 ivec_a, ivec4 ivec_b) {
    return ivecN_dot(ivec_a.v, ivec_b.v, 4);
}

/** returns ||ivec||_2 */
static float ivec4_norm(ivec4 ivec) {
    return ivecN_norm(ivec.v, 4);
}

/** returns ||ivec||_p */
static float ivec4_norm_p(ivec4 ivec, float p) {
    return ivecN_norm_p(ivec.v, p, 4);
}

/** returns ||ivec||_1 */
static int ivec4_norm_1(ivec4 ivec) {
    return ivecN_norm_1(ivec.v, 4);
}

/** returns ||ivec||_inf */
static int ivec4_norm_inf(ivec4 ivec) {
    return ivecN_norm_inf(ivec.v, 4);
}

/** dst = from + (to - from) * t */
static ivec4 ivec4_lerp(ivec4 from, ivec4 to, float t) {
    ivec4 res;
    ivecN_lerp(res.v, from.v, to.v, t, 4);
    return res;
}

/** dst = a x b , dst.w = 0 */
static ivec4 ivec4_cross(ivec4 a, ivec4 b) {
    ivec4 res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    res.w = 0;
    return res;
}

#endif //MATHC_VEC_IVEC4_H
