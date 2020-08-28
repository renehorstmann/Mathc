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


/** dst = -vec */
static dvec3 dvec3_neg(dvec3 vec) {
    dvec3 res;
    dvecN_neg(res.v, vec.v, 3);
    return res;
}
/** dst = -vec */
static dvec3 dvec3_neg_v(const double *vec) {
    return dvec3_neg(DVec3(vec));
}


/** dst = a + b */
static dvec3 dvec3_add_vec(dvec3 vec_a, dvec3 vec_b) {
    dvec3 res;
    dvecN_add_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a + b */
static dvec3 dvec3_add_vec_v(const double *vec_a, const double *vec_b) {
    return dvec3_add_vec(DVec3(vec_a), DVec3(vec_b));
}


/** dst = a + b */
static dvec3 dvec3_add_sca(dvec3 vec_a, double scalar_b) {
    dvec3 res;
    dvecN_add_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a + b */
static dvec3 dvec3_add_sca_v(const double *vec_a, double scalar_b) {
    return dvec3_add_sca(DVec3(vec_a), scalar_b);
}


/** dst = a - b */
static dvec3 dvec3_sub_vec(dvec3 vec_a, dvec3 vec_b) {
    dvec3 res;
    dvecN_sub_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a - b */
static dvec3 dvec3_sub_vec_v(const double *vec_a, const double *vec_b) {
    return dvec3_sub_vec(DVec3(vec_a), DVec3(vec_b));
}


/** dst = a - b */
static dvec3 dvec3_sub_sca(dvec3 vec_a, double scalar_b) {
    dvec3 res;
    dvecN_sub_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a - b */
static dvec3 dvec3_sub_sca_v(const double *vec_a, double scalar_b) {
    return dvec3_sub_sca(DVec3(vec_a), scalar_b);
}


/** dst = a * b */
static dvec3 dvec3_scale_vec(dvec3 vec_a, dvec3 vec_b) {
    dvec3 res;
    dvecN_scale_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a * b */
static dvec3 dvec3_scale_vec_v(const double *vec_a, const double *vec_b) {
    return dvec3_scale_vec(DVec3(vec_a), DVec3(vec_b));
}


/** dst = a * b */
static dvec3 dvec3_scale_sca(dvec3 vec_a, double scalar_b) {
    dvec3 res;
    dvecN_scale_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a * b */
static dvec3 dvec3_scale_sca_v(const double *vec_a, double scalar_b) {
    return dvec3_scale_sca(DVec3(vec_a), scalar_b);
}


/** dst = a / b */
static dvec3 dvec3_div_vec(dvec3 vec_a, dvec3 vec_b) {
    dvec3 res;
    dvecN_div_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}
/** dst = a / b */
static dvec3 dvec3_div_vec_v(const double *vec_a, const double *vec_b) {
    return dvec3_div_vec(DVec3(vec_a), DVec3(vec_b));
}


/** dst = a / b */
static dvec3 dvec3_div_sca(dvec3 vec_a, double scalar_b) {
    dvec3 res;
    dvecN_div_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}
/** dst = a / b */
static dvec3 dvec3_div_sca_v(const double *vec_a, double scalar_b) {
    return dvec3_div_sca(DVec3(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double dvec3_sum(dvec3 vec) {
    return dvecN_sum(vec.v, 3);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double dvec3_sum_v(const double *vec) {
    return dvec3_sum(DVec3(vec));
}


/** returns a dot b */
static double dvec3_dot(dvec3 vec_a, dvec3 vec_b) {
    return dvecN_dot(vec_a.v, vec_b.v, 3);
}
/** returns a dot b */
static double dvec3_dot_v(const double *vec_a, const double *vec_b) {
    return dvec3_dot(DVec3(vec_a), DVec3(vec_b));
}


/** returns ||vec||_3 */
static double dvec3_norm(dvec3 vec) {
    return dvecN_norm(vec.v, 3);
}
/** returns ||vec||_3 */
static double dvec3_norm_v(const double *vec) {
    return dvec3_norm(DVec3(vec));
}


/** returns ||vec||_p */
static double dvec3_norm_p(dvec3 vec, double p) {
    return dvecN_norm_p(vec.v, p, 3);
}
/** returns ||vec||_p */
static double dvec3_norm_p_v(const double *vec, double p) {
    return dvec3_norm_p(DVec3(vec), p);
}


/** returns ||vec||_1 */
static double dvec3_norm_1(dvec3 vec) {
    return dvecN_norm_1(vec.v, 3);
}
/** returns ||vec||_1 */
static double dvec3_norm_1_v(const double *vec) {
    return dvec3_norm_1(DVec3(vec));
}


/** returns ||vec||_inf */
static double dvec3_norm_inf(dvec3 vec) {
    return dvecN_norm_inf(vec.v, 3);
}
/** returns ||vec||_inf */
static double dvec3_norm_inf_v(const double *vec) {
    return dvec3_norm_inf(DVec3(vec));
}


/** dst = vec / norm(vec) */
static dvec3 dvec3_normalize_unsafe(dvec3 vec) {
    dvec3 res;
    dvecN_normalize_unsafe(res.v, vec.v, 3);
    return res;
}
/** dst = vec / norm(vec) */
static dvec3 dvec3_normalize_unsafe_v(const double *vec) {
    return dvec3_normalize_unsafe(DVec3(vec));
}


/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static dvec3 dvec3_normalize(dvec3 vec) {
    dvec3 res;
    dvecN_normalize(res.v, vec.v, 3);
    return res;
}
/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static dvec3 dvec3_normalize_v(const double *vec) {
    return dvec3_normalize(DVec3(vec));
}


/** dst = from + (to - from) * t */
static dvec3 dvec3_lerp(dvec3 vec_from, dvec3 vec_to, double t) {
    dvec3 res;
    dvecN_lerp(res.v, vec_from.v, vec_to.v, t, 3);
    return res;
}
/** dst = from + (to - from) * t */
static dvec3 dvec3_lerp_v(const double *vec_from, const double *vec_to, double t) {
    return dvec3_lerp(DVec3(vec_from), DVec3(vec_to), t);
}


/** dst = a x b */
static dvec3 dvec3_cross(dvec3 vec_a, dvec3 vec_b) {
    dvec3 res;
    res.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
    res.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
    res.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
    return res;
}
/** dst = a x b */
static dvec3 dvec3_cross_v(const double *vec_a, const double *vec_b) {
    return dvec3_cross(DVec3(vec_a), DVec3(vec_b));
}


#endif //MATHC_VEC_DVEC3_H
