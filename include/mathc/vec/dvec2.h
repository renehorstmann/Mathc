#ifndef MATHC_VEC_DVEC2_H
#define MATHC_VEC_DVEC2_H

#include "dvecn.h"
#include "../types.h"


/** dst = scalar */
static dvec2 dvec2_set(double scalar) {
    dvec2 res;
    dvecN_set(res.v, scalar, 2);
    return res;
}

/** dst = -dvec */
static dvec2 dvec2_neg(dvec2 dvec) {
    dvec2 res;
    dvecN_neg(res.v, dvec.v, 2);
    return res;
}

/** dst = a + b */
static dvec2 dvec2_add_dvec(dvec2 dvec_a, dvec2 dvec_b) {
    dvec2 res;
    dvecN_add_dvec(res.v, dvec_a.v, dvec_b.v, 2);
    return res;
}

/** dst = a + b */
static dvec2 dvec2_add_sca(dvec2 dvec_a, double scalar_b) {
    dvec2 res;
    dvecN_add_sca(res.v, dvec_a.v, scalar_b, 2);
    return res;
}

/** dst = a - b */
static dvec2 dvec2_sub_dvec(dvec2 dvec_a, dvec2 dvec_b) {
    dvec2 res;
    dvecN_sub_dvec(res.v, dvec_a.v, dvec_b.v, 2);
    return res;
}

/** dst = a - b */
static dvec2 dvec2_sub_sca(dvec2 dvec_a, double scalar_b) {
    dvec2 res;
    dvecN_sub_sca(res.v, dvec_a.v, scalar_b, 2);
    return res;
}

/** dst = a * b */
static dvec2 dvec2_scale_dvec(dvec2 dvec_a, dvec2 dvec_b) {
    dvec2 res;
    dvecN_scale_dvec(res.v, dvec_a.v, dvec_b.v, 2);
    return res;
}

/** dst = a * b */
static dvec2 dvec2_scale_sca(dvec2 dvec_a, double scalar_b) {
    dvec2 res;
    dvecN_scale_sca(res.v, dvec_a.v, scalar_b, 2);
    return res;
}

/** dst = a / b */
static dvec2 dvec2_div_dvec(dvec2 dvec_a, dvec2 dvec_b) {
    dvec2 res;
    dvecN_div_dvec(res.v, dvec_a.v, dvec_b.v, 2);
    return res;
}

/** dst = a / b */
static dvec2 dvec2_div_sca(dvec2 dvec_a, double scalar_b) {
    dvec2 res;
    dvecN_div_sca(res.v, dvec_a.v, scalar_b, 2);
    return res;
}

/** returns dvec[0] + dvec[1] + ... + dvec[n-1] */
static double dvec2_sum(dvec2 dvec) {
    return dvecN_sum(dvec.v, 2);
}

/** returns a dot b */
static double dvec2_dot(dvec2 dvec_a, dvec2 dvec_b) {
    return dvecN_dot(dvec_a.v, dvec_b.v, 2);
}

/** returns ||dvec||_2 */
static double dvec2_norm(dvec2 dvec) {
    return dvecN_norm(dvec.v, 2);
}

/** returns ||dvec||_p */
static double dvec2_norm_p(dvec2 dvec, double p) {
    return dvecN_norm_p(dvec.v, p, 2);
}

/** returns ||dvec||_1 */
static double dvec2_norm_1(dvec2 dvec) {
    return dvecN_norm_1(dvec.v, 2);
}

/** returns ||dvec||_inf */
static double dvec2_norm_inf(dvec2 dvec) {
    return dvecN_norm_inf(dvec.v, 2);
}

/** dst = dvec / (norm(dvec) > 0 ? norm(dvec) : 1) */
static dvec2 dvec2_normalize(dvec2 dvec) {
    dvec2 res;
    dvecN_normalize(res.v, dvec.v, 2);
    return res;
}

/** dst = from + (to - from) * t */
static dvec2 dvec2_lerp(dvec2 from, dvec2 to, double t) {
    dvec2 res;
    dvecN_lerp(res.v, from.v, to.v, t, 2);
    return res;
}

#endif //MATHC_VEC_DVEC2_H
