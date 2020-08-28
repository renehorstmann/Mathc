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


/** dst = -vec */
static dvec4 dvec4_neg(dvec4 vec) {
    dvec4 res;
    dvecN_neg(res.v, vec.v, 4);
    return res;
}
/** dst = -vec */
static dvec4 dvec4_neg_v(const double *vec) {
    return dvec4_neg(DVec4(vec));
}


/** dst = a + b */
static dvec4 dvec4_add_vec(dvec4 vec_a, dvec4 vec_b) {
    dvec4 res;
    dvecN_add_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a + b */
static dvec4 dvec4_add_vec_v(const double *vec_a, const double *vec_b) {
    return dvec4_add_vec(DVec4(vec_a), DVec4(vec_b));
}


/** dst = a + b */
static dvec4 dvec4_add_sca(dvec4 vec_a, double scalar_b) {
    dvec4 res;
    dvecN_add_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a + b */
static dvec4 dvec4_add_sca_v(const double *vec_a, double scalar_b) {
    return dvec4_add_sca(DVec4(vec_a), scalar_b);
}


/** dst = a - b */
static dvec4 dvec4_sub_vec(dvec4 vec_a, dvec4 vec_b) {
    dvec4 res;
    dvecN_sub_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a - b */
static dvec4 dvec4_sub_vec_v(const double *vec_a, const double *vec_b) {
    return dvec4_sub_vec(DVec4(vec_a), DVec4(vec_b));
}


/** dst = a - b */
static dvec4 dvec4_sub_sca(dvec4 vec_a, double scalar_b) {
    dvec4 res;
    dvecN_sub_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a - b */
static dvec4 dvec4_sub_sca_v(const double *vec_a, double scalar_b) {
    return dvec4_sub_sca(DVec4(vec_a), scalar_b);
}


/** dst = a * b */
static dvec4 dvec4_scale_vec(dvec4 vec_a, dvec4 vec_b) {
    dvec4 res;
    dvecN_scale_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a * b */
static dvec4 dvec4_scale_vec_v(const double *vec_a, const double *vec_b) {
    return dvec4_scale_vec(DVec4(vec_a), DVec4(vec_b));
}


/** dst = a * b */
static dvec4 dvec4_scale_sca(dvec4 vec_a, double scalar_b) {
    dvec4 res;
    dvecN_scale_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a * b */
static dvec4 dvec4_scale_sca_v(const double *vec_a, double scalar_b) {
    return dvec4_scale_sca(DVec4(vec_a), scalar_b);
}


/** dst = a / b */
static dvec4 dvec4_div_vec(dvec4 vec_a, dvec4 vec_b) {
    dvec4 res;
    dvecN_div_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}
/** dst = a / b */
static dvec4 dvec4_div_vec_v(const double *vec_a, const double *vec_b) {
    return dvec4_div_vec(DVec4(vec_a), DVec4(vec_b));
}


/** dst = a / b */
static dvec4 dvec4_div_sca(dvec4 vec_a, double scalar_b) {
    dvec4 res;
    dvecN_div_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}
/** dst = a / b */
static dvec4 dvec4_div_sca_v(const double *vec_a, double scalar_b) {
    return dvec4_div_sca(DVec4(vec_a), scalar_b);
}


/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double dvec4_sum(dvec4 vec) {
    return dvecN_sum(vec.v, 4);
}
/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double dvec4_sum_v(const double *vec) {
    return dvec4_sum(DVec4(vec));
}


/** returns a dot b */
static double dvec4_dot(dvec4 vec_a, dvec4 vec_b) {
    return dvecN_dot(vec_a.v, vec_b.v, 4);
}
/** returns a dot b */
static double dvec4_dot_v(const double *vec_a, const double *vec_b) {
    return dvec4_dot(DVec4(vec_a), DVec4(vec_b));
}


/** returns ||vec||_4 */
static double dvec4_norm(dvec4 vec) {
    return dvecN_norm(vec.v, 4);
}
/** returns ||vec||_4 */
static double dvec4_norm_v(const double *vec) {
    return dvec4_norm(DVec4(vec));
}


/** returns ||vec||_p */
static double dvec4_norm_p(dvec4 vec, double p) {
    return dvecN_norm_p(vec.v, p, 4);
}
/** returns ||vec||_p */
static double dvec4_norm_p_v(const double *vec, double p) {
    return dvec4_norm_p(DVec4(vec), p);
}


/** returns ||vec||_1 */
static double dvec4_norm_1(dvec4 vec) {
    return dvecN_norm_1(vec.v, 4);
}
/** returns ||vec||_1 */
static double dvec4_norm_1_v(const double *vec) {
    return dvec4_norm_1(DVec4(vec));
}


/** returns ||vec||_inf */
static double dvec4_norm_inf(dvec4 vec) {
    return dvecN_norm_inf(vec.v, 4);
}
/** returns ||vec||_inf */
static double dvec4_norm_inf_v(const double *vec) {
    return dvec4_norm_inf(DVec4(vec));
}


/** dst = vec / norm(vec) */
static dvec4 dvec4_normalize_unsafe(dvec4 vec) {
    dvec4 res;
    dvecN_normalize_unsafe(res.v, vec.v, 4);
    return res;
}
/** dst = vec / norm(vec) */
static dvec4 dvec4_normalize_unsafe_v(const double *vec) {
    return dvec4_normalize_unsafe(DVec4(vec));
}


/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static dvec4 dvec4_normalize(dvec4 vec) {
    dvec4 res;
    dvecN_normalize(res.v, vec.v, 4);
    return res;
}
/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static dvec4 dvec4_normalize_v(const double *vec) {
    return dvec4_normalize(DVec4(vec));
}


/** dst = from + (to - from) * t */
static dvec4 dvec4_lerp(dvec4 vec_from, dvec4 vec_to, double t) {
    dvec4 res;
    dvecN_lerp(res.v, vec_from.v, vec_to.v, t, 4);
    return res;
}
/** dst = from + (to - from) * t */
static dvec4 dvec4_lerp_v(const double *vec_from, const double *vec_to, double t) {
    return dvec4_lerp(DVec4(vec_from), DVec4(vec_to), t);
}


/** dst = a x b , dst.w = 0 */
static dvec4 dvec4_cross(dvec4 vec_a, dvec4 vec_b) {
    dvec4 res;
    res.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
    res.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
    res.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
    res.w = 0;
    return res;
}
/** dst = a x b , dst.w = 0 */
static dvec4 dvec4_cross_v(const double *vec_a, const double *vec_b) {
    return dvec4_cross(DVec4(vec_a), DVec4(vec_b));
}


#endif //MATHC_VEC_DVEC4_H
