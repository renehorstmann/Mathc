#ifndef MATHC_VEC_DVEC4_H
#define MATHC_VEC_DVEC4_H

#include "dvecn.h"
#include "../types.h"


/** dst = scalar */
static dvec4 dvec4_set(double scalar) {
    dvec4 res;
    dvecN_set(res.v, scalar, 4);
    return res;
}

/** dst = -dvec */
static dvec4 dvec4_neg(dvec4 dvec) {
    dvec4 res;
    dvecN_neg(res.v, dvec.v, 4);
    return res;
}

/** dst = a + b */
static dvec4 dvec4_add_dvec(dvec4 dvec_a, dvec4 dvec_b) {
    dvec4 res;
    dvecN_add_dvec(res.v, dvec_a.v, dvec_b.v, 4);
    return res;
}

/** dst = a + b */
static dvec4 dvec4_add_sca(dvec4 dvec_a, double scalar_b) {
    dvec4 res;
    dvecN_add_sca(res.v, dvec_a.v, scalar_b, 4);
    return res;
}

/** dst = a - b */
static dvec4 dvec4_sub_dvec(dvec4 dvec_a, dvec4 dvec_b) {
    dvec4 res;
    dvecN_sub_dvec(res.v, dvec_a.v, dvec_b.v, 4);
    return res;
}

/** dst = a - b */
static dvec4 dvec4_sub_sca(dvec4 dvec_a, double scalar_b) {
    dvec4 res;
    dvecN_sub_sca(res.v, dvec_a.v, scalar_b, 4);
    return res;
}

/** dst = a * b */
static dvec4 dvec4_scale_dvec(dvec4 dvec_a, dvec4 dvec_b) {
    dvec4 res;
    dvecN_scale_dvec(res.v, dvec_a.v, dvec_b.v, 4);
    return res;
}

/** dst = a * b */
static dvec4 dvec4_scale_sca(dvec4 dvec_a, double scalar_b) {
    dvec4 res;
    dvecN_scale_sca(res.v, dvec_a.v, scalar_b, 4);
    return res;
}

/** dst = a / b */
static dvec4 dvec4_div_dvec(dvec4 dvec_a, dvec4 dvec_b) {
    dvec4 res;
    dvecN_div_dvec(res.v, dvec_a.v, dvec_b.v, 4);
    return res;
}

/** dst = a / b */
static dvec4 dvec4_div_sca(dvec4 dvec_a, double scalar_b) {
    dvec4 res;
    dvecN_div_sca(res.v, dvec_a.v, scalar_b, 4);
    return res;
}

/** returns dvec[0] + dvec[1] + ... + dvec[n-1] */
static double dvec4_sum(dvec4 dvec) {
    return dvecN_sum(dvec.v, 4);
}

/** returns a dot b */
static double dvec4_dot(dvec4 dvec_a, dvec4 dvec_b) {
    return dvecN_dot(dvec_a.v, dvec_b.v, 4);
}

/** returns ||dvec||_2 */
static double dvec4_norm(dvec4 dvec) {
    return dvecN_norm(dvec.v, 4);
}

/** returns ||dvec||_p */
static double dvec4_norm_p(dvec4 dvec, double p) {
    return dvecN_norm_p(dvec.v, p, 4);
}

/** returns ||dvec||_1 */
static double dvec4_norm_1(dvec4 dvec) {
    return dvecN_norm_1(dvec.v, 4);
}

/** returns ||dvec||_inf */
static double dvec4_norm_inf(dvec4 dvec) {
    return dvecN_norm_inf(dvec.v, 4);
}

/** dst = dvec / (norm(dvec) > 0 ? norm(dvec) : 1) */
static dvec4 dvec4_normalize(dvec4 dvec) {
    dvec4 res;
    dvecN_normalize(res.v, dvec.v, 4);
    return res;
}

/** dst = from + (to - from) * t */
static dvec4 dvec4_lerp(dvec4 from, dvec4 to, double t) {
    dvec4 res;
    dvecN_lerp(res.v, from.v, to.v, t, 4);
    return res;
}

/** dst = a x b , dst.w = 0 */
static dvec4 dvec4_cross(dvec4 a, dvec4 b) {
    dvec4 res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    res.w = 0;
    return res;
}

#endif //MATHC_VEC_DVEC4_H
