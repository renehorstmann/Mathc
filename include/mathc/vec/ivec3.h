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

/** dst = -ivec */
static ivec3 ivec3_neg(ivec3 ivec) {
    ivec3 res;
    ivecN_neg(res.v, ivec.v, 3);
    return res;
}

/** dst = a + b */
static ivec3 ivec3_add_ivec(ivec3 ivec_a, ivec3 ivec_b) {
    ivec3 res;
    ivecN_add_ivec(res.v, ivec_a.v, ivec_b.v, 3);
    return res;
}

/** dst = a + b */
static ivec3 ivec3_add_sca(ivec3 ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_add_sca(res.v, ivec_a.v, scalar_b, 3);
    return res;
}

/** dst = a - b */
static ivec3 ivec3_sub_ivec(ivec3 ivec_a, ivec3 ivec_b) {
    ivec3 res;
    ivecN_sub_ivec(res.v, ivec_a.v, ivec_b.v, 3);
    return res;
}

/** dst = a - b */
static ivec3 ivec3_sub_sca(ivec3 ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_sub_sca(res.v, ivec_a.v, scalar_b, 3);
    return res;
}

/** dst = a * b */
static ivec3 ivec3_scale_ivec(ivec3 ivec_a, ivec3 ivec_b) {
    ivec3 res;
    ivecN_scale_ivec(res.v, ivec_a.v, ivec_b.v, 3);
    return res;
}

/** dst = a * b */
static ivec3 ivec3_scale_sca(ivec3 ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_scale_sca(res.v, ivec_a.v, scalar_b, 3);
    return res;
}

/** dst = a / b */
static ivec3 ivec3_div_ivec(ivec3 ivec_a, ivec3 ivec_b) {
    ivec3 res;
    ivecN_div_ivec(res.v, ivec_a.v, ivec_b.v, 3);
    return res;
}

/** dst = a / b */
static ivec3 ivec3_div_sca(ivec3 ivec_a, int scalar_b) {
    ivec3 res;
    ivecN_div_sca(res.v, ivec_a.v, scalar_b, 3);
    return res;
}

/** returns ivec[0] + ivec[1] + ... + ivec[n-1] */
static int ivec3_sum(ivec3 ivec) {
    return ivecN_sum(ivec.v, 3);
}

/** returns a dot b */
static int ivec3_dot(ivec3 ivec_a, ivec3 ivec_b) {
    return ivecN_dot(ivec_a.v, ivec_b.v, 3);
}

/** returns ||ivec||_2 */
static float ivec3_norm(ivec3 ivec) {
    return ivecN_norm(ivec.v, 3);
}

/** returns ||ivec||_p */
static float ivec3_norm_p(ivec3 ivec, float p) {
    return ivecN_norm_p(ivec.v, p, 3);
}

/** returns ||ivec||_1 */
static int ivec3_norm_1(ivec3 ivec) {
    return ivecN_norm_1(ivec.v, 3);
}

/** returns ||ivec||_inf */
static int ivec3_norm_inf(ivec3 ivec) {
    return ivecN_norm_inf(ivec.v, 3);
}

/** dst = from + (to - from) * t */
static ivec3 ivec3_lerp(ivec3 from, ivec3 to, float t) {
    ivec3 res;
    ivecN_lerp(res.v, from.v, to.v, t, 3);
    return res;
}

/** dst = a x b */
static ivec3 ivec3_cross(ivec3 a, ivec3 b) {
    ivec3 res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    return res;
}

#endif //MATHC_VEC_IVEC3_H
