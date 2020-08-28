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


/** dst = -vec */
static dvec2 dvec2_neg(dvec2 vec) {
    dvec2 res;
    dvecN_neg(res.v, vec.v, 2);
    return res;
}
/** dst = -vec */
static dvec2 dvec2_neg_v(const double *vec) {
    return dvec2_neg(DVec2(vec));
}


/** dst = a + b */
static dvec2 dvec2_add_vec(dvec2 vec_a, dvec2 vec_b) {
    dvec2 res;
    dvecN_add_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a + b */
static dvec2 dvec2_add_vec_v(const double *vec_a, const double *vec_b) {
    return dvec2_add_vec(DVec2(vec_a), DVec2(vec_b));
}


/** dst = a + b */
static dvec2 dvec2_add_sca(dvec2 vec_a, double scalar_b) {
    dvec2 res;
    dvecN_add_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a + b */
static dvec2 dvec2_add_sca_v(const double *vec_a, double scalar_b) {
    return dvec2_add_sca(DVec2(vec_a), scalar_b);
}


/** dst = a - b */
static dvec2 dvec2_sub_vec(dvec2 vec_a, dvec2 vec_b) {
    dvec2 res;
    dvecN_sub_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a - b */
static dvec2 dvec2_sub_vec_v(const double *vec_a, const double *vec_b) {
    return dvec2_sub_vec(DVec2(vec_a), DVec2(vec_b));
}


/** dst = a - b */
static dvec2 dvec2_sub_sca(dvec2 vec_a, double scalar_b) {
    dvec2 res;
    dvecN_sub_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a - b */
static dvec2 dvec2_sub_sca_v(const double *vec_a, double scalar_b) {
    return dvec2_sub_sca(DVec2(vec_a), scalar_b);
}


/** dst = a * b */
static dvec2 dvec2_scale_vec(dvec2 vec_a, dvec2 vec_b) {
    dvec2 res;
    dvecN_scale_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a * b */
static dvec2 dvec2_scale_vec_v(const double *vec_a, const double *vec_b) {
    return dvec2_scale_vec(DVec2(vec_a), DVec2(vec_b));
}


/** dst = a * b */
static dvec2 dvec2_scale_sca(dvec2 vec_a, double scalar_b) {
    dvec2 res;
    dvecN_scale_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a * b */
static dvec2 dvec2_scale_sca_v(const double *vec_a, double scalar_b) {
    return dvec2_scale_sca(DVec2(vec_a), scalar_b);
}


/** dst = a / b */
static dvec2 dvec2_div_vec(dvec2 vec_a, dvec2 vec_b) {
    dvec2 res;
    dvecN_div_vec(res.v, vec_a.v, vec_b.v, 2);
    return res;
}
/** dst = a / b */
static dvec2 dvec2_div_vec_v(const double *vec_a, const double *vec_b) {
    return dvec2_div_vec(DVec2(vec_a), DVec2(vec_b));
}


/** dst = a / b */
static dvec2 dvec2_div_sca(dvec2 vec_a, double scalar_b) {
    dvec2 res;
    dvecN_div_sca(res.v, vec_a.v, scalar_b, 2);
    return res;
}
/** dst = a / b */
static dvec2 dvec2_div_sca_v(const double *vec_a, double scalar_b) {
    return dvec2_div_sca(DVec2(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double dvec2_sum(dvec2 vec) {
    return dvecN_sum(vec.v, 2);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double dvec2_sum_v(const double *vec) {
    return dvec2_sum(DVec2(vec));
}


/** returns a dot b */
static double dvec2_dot(dvec2 vec_a, dvec2 vec_b) {
    return dvecN_dot(vec_a.v, vec_b.v, 2);
}
/** returns a dot b */
static double dvec2_dot_v(const double *vec_a, const double *vec_b) {
    return dvec2_dot(DVec2(vec_a), DVec2(vec_b));
}


/** returns ||vec||_2 */
static double dvec2_norm(dvec2 vec) {
    return dvecN_norm(vec.v, 2);
}
/** returns ||vec||_2 */
static double dvec2_norm_v(const double *vec) {
    return dvec2_norm(DVec2(vec));
}


/** returns ||vec||_p */
static double dvec2_norm_p(dvec2 vec, double p) {
    return dvecN_norm_p(vec.v, p, 2);
}
/** returns ||vec||_p */
static double dvec2_norm_p_v(const double *vec, double p) {
    return dvec2_norm_p(DVec2(vec), p);
}


/** returns ||vec||_1 */
static double dvec2_norm_1(dvec2 vec) {
    return dvecN_norm_1(vec.v, 2);
}
/** returns ||vec||_1 */
static double dvec2_norm_1_v(const double *vec) {
    return dvec2_norm_1(DVec2(vec));
}


/** returns ||vec||_inf */
static double dvec2_norm_inf(dvec2 vec) {
    return dvecN_norm_inf(vec.v, 2);
}
/** returns ||vec||_inf */
static double dvec2_norm_inf_v(const double *vec) {
    return dvec2_norm_inf(DVec2(vec));
}


/** dst = vec / norm(vec) */
static dvec2 dvec2_normalize_unsafe(dvec2 vec) {
    dvec2 res;
    dvecN_normalize_unsafe(res.v, vec.v, 2);
    return res;
}
/** dst = vec / norm(vec) */
static dvec2 dvec2_normalize_unsafe_v(const double *vec) {
    return dvec2_normalize_unsafe(DVec2(vec));
}


/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static dvec2 dvec2_normalize(dvec2 vec) {
    dvec2 res;
    dvecN_normalize(res.v, vec.v, 2);
    return res;
}
/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static dvec2 dvec2_normalize_v(const double *vec) {
    return dvec2_normalize(DVec2(vec));
}


/** dst = from + (to - from) * t */
static dvec2 dvec2_lerp(dvec2 vec_from, dvec2 vec_to, double t) {
    dvec2 res;
    dvecN_lerp(res.v, vec_from.v, vec_to.v, t, 2);
    return res;
}
/** dst = from + (to - from) * t */
static dvec2 dvec2_lerp_v(const double *vec_from, const double *vec_to, double t) {
    return dvec2_lerp(DVec2(vec_from), DVec2(vec_to), t);
}


#endif //MATHC_VEC_DVEC2_H
