#ifndef MATHC_VEC_DVEC3_H
#define MATHC_VEC_DVEC3_H

#include "dvecn.h"
#include "../types.h"


/** dst = scalar */
static dvec3 dvec3_set(double scalar) {
    dvec3 res;
    dvecN_set(res.v, scalar, 3);
    return res;
}

/** dst = -dvec */
static dvec3 dvec3_neg(dvec3 dvec) {
    dvec3 res;
    dvecN_neg(res.v, dvec.v, 3);
    return res;
}

/** dst = a + b */
static dvec3 dvec3_add_dvec(dvec3 dvec_a, dvec3 dvec_b) {
    dvec3 res;
    dvecN_add_dvec(res.v, dvec_a.v, dvec_b.v, 3);
    return res;
}

/** dst = a + b */
static dvec3 dvec3_add_sca(dvec3 dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_add_sca(res.v, dvec_a.v, scalar_b, 3);
    return res;
}

/** dst = a - b */
static dvec3 dvec3_sub_dvec(dvec3 dvec_a, dvec3 dvec_b) {
    dvec3 res;
    dvecN_sub_dvec(res.v, dvec_a.v, dvec_b.v, 3);
    return res;
}

/** dst = a - b */
static dvec3 dvec3_sub_sca(dvec3 dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_sub_sca(res.v, dvec_a.v, scalar_b, 3);
    return res;
}

/** dst = a * b */
static dvec3 dvec3_scale_dvec(dvec3 dvec_a, dvec3 dvec_b) {
    dvec3 res;
    dvecN_scale_dvec(res.v, dvec_a.v, dvec_b.v, 3);
    return res;
}

/** dst = a * b */
static dvec3 dvec3_scale_sca(dvec3 dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_scale_sca(res.v, dvec_a.v, scalar_b, 3);
    return res;
}

/** dst = a / b */
static dvec3 dvec3_div_dvec(dvec3 dvec_a, dvec3 dvec_b) {
    dvec3 res;
    dvecN_div_dvec(res.v, dvec_a.v, dvec_b.v, 3);
    return res;
}

/** dst = a / b */
static dvec3 dvec3_div_sca(dvec3 dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_div_sca(res.v, dvec_a.v, scalar_b, 3);
    return res;
}

/** returns dvec[0] + dvec[1] + ... + dvec[n-1] */
static double dvec3_sum(dvec3 dvec) {
    return dvecN_sum(dvec.v, 3);
}

/** returns a dot b */
static double dvec3_dot(dvec3 dvec_a, dvec3 dvec_b) {
    return dvecN_dot(dvec_a.v, dvec_b.v, 3);
}

/** returns ||dvec||_2 */
static double dvec3_norm(dvec3 dvec) {
    return dvecN_norm(dvec.v, 3);
}

/** returns ||dvec||_p */
static double dvec3_norm_p(dvec3 dvec, double p) {
    return dvecN_norm_p(dvec.v, p, 3);
}

/** returns ||dvec||_1 */
static double dvec3_norm_1(dvec3 dvec) {
    return dvecN_norm_1(dvec.v, 3);
}

/** returns ||dvec||_inf */
static double dvec3_norm_inf(dvec3 dvec) {
    return dvecN_norm_inf(dvec.v, 3);
}

/** dst = dvec / (norm(dvec) > 0 ? norm(dvec) : 1) */
static dvec3 dvec3_normalize(dvec3 dvec) {
    dvec3 res;
    dvecN_normalize(res.v, dvec.v, 3);
    return res;
}

/** dst = from + (to - from) * t */
static dvec3 dvec3_lerp(dvec3 from, dvec3 to, double t) {
    dvec3 res;
    dvecN_lerp(res.v, from.v, to.v, t, 3);
    return res;
}

/** dst = a x b */
static dvec3 dvec3_cross(dvec3 a, dvec3 b) {
    dvec3 res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    return res;
}

#endif //MATHC_VEC_DVEC3_H
