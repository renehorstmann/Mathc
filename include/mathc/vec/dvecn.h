#ifndef MATHC_VEC_DVECN_H
#define MATHC_VEC_DVECN_H

#include "math.h"


/** macro to cast a vector into a double vector */
#define dvecN_cast_into(dst_vec, vec, n) \
{ \
    for(int i=0; i<(n); i++) \
        (dst_vec)[i] = (double) (vec)[i]; \
}


/** dst = vec */
static void dvecN_copy(double *dst_vec, const double *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** dst = scalar */
static void dvecN_set(double *dst_vec, double scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

/** dst = -vec */
static void dvecN_neg(double *dst_vec, const double *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}

/** dst = a + b */
static void dvecN_add_vec(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** dst = a + b */
static void dvecN_add_sca(double *dst_vec, const double *vec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** dst = a - b */
static void dvecN_sub_vec(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** dst = a - b */
static void dvecN_sub_sca(double *dst_vec, const double *vec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - scalar_b;
}

/** dst = a * b */
static void dvecN_scale_vec(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** dst = a * b */
static void dvecN_scale_sca(double *dst_vec, const double *vec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** dst = a / b */
static void dvecN_div_vec(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / vec_b[i];
}

/** dst = a / b */
static void dvecN_div_sca(double *dst_vec, const double *vec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / scalar_b;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double dvecN_sum(const double *vec, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns a dot b */
static double dvecN_dot(const double *vec_a, const double *vec_b, int n) {
    double dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** returns ||vec||_2 */
static double dvecN_norm(const double *vec, int n) {
    return sqrtf(dvecN_dot(vec, vec, n));
}

/** returns ||vec||_p */
static double dvecN_norm_p(const double *vec, double p, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(fabs(vec[i]), p);
    }
    return pow(sum, 1.0 / p);
}

/** returns ||vec||_1 */
static double dvecN_norm_1(const double *vec, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fabs(vec[i]);
    }
    return sum;
}

/** returns ||vec||_inf */
static double dvecN_norm_inf(const double *vec, int n) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        if (max < fabs(vec[i]))
            max = fabs(vec[i]);
    }
    return max;
}

/** dst = vec / norm(vec) */
static void dvecN_normalize_unsafe(double *dst_vec, const double *vec, int n) {
    dvecN_scale_sca(dst_vec, vec, 1.0f / dvecN_norm(vec, n), n);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static void dvecN_normalize(double *dst_vec, const double *vec, int n) {
    double norm = dvecN_norm(vec, n);
    dvecN_scale_sca(dst_vec, vec, 1.0f / (norm > 0 ? norm : 1), n);
}

/** dst = from + (to - from) * t */
static void dvecN_lerp(double *dst_vec, const double *vec_from, const double *vec_to, double t, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_from[i] + (vec_to[i] - vec_from[i]) * t;
}

#endif //MATHC_VEC_DVECN_H
