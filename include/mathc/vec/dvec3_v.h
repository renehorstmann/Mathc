#ifndef MATHC_VEC_DVEC3_V_H
#define MATHC_VEC_DVEC3_V_H

#include "dvec3.h"


/** dst = -dvec */
static dvec3 dvec3_neg_v(const double *dvec) {
    dvec3 res;
    dvecN_neg(res.v, dvec, 3);
    return res;
}

/** dst = a + b */
static dvec3 dvec3_add_dvec_v(const double *dvec_a, const double *dvec_b) {
    dvec3 res;
    dvecN_add_dvec(res.v, dvec_a, dvec_b, 3);
    return res;
}

/** dst = a + b */
static dvec3 dvec3_add_sca_v(const double *dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_add_sca(res.v, dvec_a, scalar_b, 3);
    return res;
}

/** dst = a - b */
static dvec3 dvec3_sub_dvec_v(const double *dvec_a, const double *dvec_b) {
    dvec3 res;
    dvecN_sub_dvec(res.v, dvec_a, dvec_b, 3);
    return res;
}

/** dst = a - b */
static dvec3 dvec3_sub_sca_v(const double *dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_sub_sca(res.v, dvec_a, scalar_b, 3);
    return res;
}

/** dst = a * b */
static dvec3 dvec3_scale_dvec_v(const double *dvec_a, const double *dvec_b) {
    dvec3 res;
    dvecN_scale_dvec(res.v, dvec_a, dvec_b, 3);
    return res;
}

/** dst = a * b */
static dvec3 dvec3_scale_sca_v(const double *dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_scale_sca(res.v, dvec_a, scalar_b, 3);
    return res;
}

/** dst = a / b */
static dvec3 dvec3_div_dvec_v(const double *dvec_a, const double *dvec_b) {
    dvec3 res;
    dvecN_div_dvec(res.v, dvec_a, dvec_b, 3);
    return res;
}

/** dst = a / b */
static dvec3 dvec3_div_sca_v(const double *dvec_a, double scalar_b) {
    dvec3 res;
    dvecN_div_sca(res.v, dvec_a, scalar_b, 3);
    return res;
}

/** returns dvec[0] + dvec[1] + ... + dvec[n-1] */
static double dvec3_sum_v(const double *dvec) {
    return dvecN_sum(dvec, 3);
}

/** returns a dot b */
static double dvec3_dot_v(const double *dvec_a, const double *dvec_b) {
    return dvecN_dot(dvec_a, dvec_b, 3);
}

/** returns ||dvec||_2 */
static double dvec3_norm_v(const double *dvec) {
    return dvecN_norm(dvec, 3);
}

/** returns ||dvec||_p */
static double dvec3_norm_p_v(const double *dvec, double p) {
    return dvecN_norm_p(dvec, p, 3);
}

/** returns ||dvec||_1 */
static double dvec3_norm_1_v(const double *dvec) {
    return dvecN_norm_1(dvec, 3);
}

/** returns ||dvec||_inf */
static double dvec3_norm_inf_v(const double *dvec) {
    return dvecN_norm_inf(dvec, 3);
}

/** dst = dvec / (norm(dvec) > 0 ? norm(dvec) : 1) */
static dvec3 dvec3_normalize_v(const double *dvec) {
    dvec3 res;
    dvecN_normalize(res.v, dvec, 3);
    return res;
}

/** dst = from + (to - from) * t */
static dvec3 dvec3_lerp_v(const double *from, const double *to, double t) {
    dvec3 res;
    dvecN_lerp(res.v, from, to, t, 3);
    return res;
}

/** dst = a x b */
static dvec3 dvec3_cross_v(const double *a, const double *b) {
    return dvec3_cross(DVec3(a), DVec3(b));
}

#endif //MATHC_VEC_DVEC3_V_H
