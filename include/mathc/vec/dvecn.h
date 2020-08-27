#ifndef MATHC_VEC_DVECN_H
#define MATHC_VEC_DVECN_H

#include "math.h"


/** dst = dvec */
static void dvecN_copy(double *dst_dvec, const double *dvec, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec[i];
}

/** dst = scalar */
static void dvecN_set(double *dst_dvec, double scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = scalar;
}

/** dst = -dvec */
static void dvecN_neg(double *dst_dvec, const double *dvec, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = -dvec[i];
}

/** dst = a + b */
static void dvecN_add_dvec(double *dst_dvec, const double *dvec_a, const double *dvec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] + dvec_b[i];
}

/** dst = a + b */
static void dvecN_add_sca(double *dst_dvec, const double *dvec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] + scalar_b;
}

/** dst = a - b */
static void dvecN_sub_dvec(double *dst_dvec, const double *dvec_a, const double *dvec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] - dvec_b[i];
}

/** dst = a - b */
static void dvecN_sub_sca(double *dst_dvec, const double *dvec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] - scalar_b;
}

/** dst = a * b */
static void dvecN_scale_dvec(double *dst_dvec, const double *dvec_a, const double *dvec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] * dvec_b[i];
}

/** dst = a * b */
static void dvecN_scale_sca(double *dst_dvec, const double *dvec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] * scalar_b;
}

/** dst = a / b */
static void dvecN_div_dvec(double *dst_dvec, const double *dvec_a, const double *dvec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] / dvec_b[i];
}

/** dst = a / b */
static void dvecN_div_sca(double *dst_dvec, const double *dvec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_a[i] / scalar_b;
}

/** returns dvec[0] + dvec[1] + ... + dvec[n-1] */
static double dvecN_sum(const double *dvec, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += dvec[i];
    return sum;
}

/** returns a dot b */
static double dvecN_dot(const double *dvec_a, const double *dvec_b, int n) {
    double dot = 0;
    for (int i = 0; i < n; i++)
        dot += dvec_a[i] * dvec_b[i];
    return dot;
}

/** returns ||dvec||_2 */
static double dvecN_norm(const double *dvec, int n) {
    return sqrtf(dvecN_dot(dvec, dvec, n));
}

/** returns ||dvec||_p */
static double dvecN_norm_p(const double *dvec, double p, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += powf(fabs(dvec[i]), p);
    }
    return powf(sum, 1.0 / p);
}

/** returns ||dvec||_1 */
static double dvecN_norm_1(const double *dvec, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fabs(dvec[i]);
    }
    return sum;
}

/** returns ||dvec||_inf */
static double dvecN_norm_inf(const double *dvec, int n) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        if (max < fabs(dvec[i]))
            max = fabs(dvec[i]);
    }
    return max;
}

/** dst = dvec / norm(dvec) */
static void dvecN_normalize_unsafe(double *dst_dvec, const double *dvec, int n) {
    dvecN_scale_sca(dst_dvec, dvec, 1.0 / dvecN_norm(dvec, n), n);
}

/** dst = dvec / (norm(dvec) > 0 ? norm(dvec) : 1) */
static void dvecN_normalize(double *dst_dvec, const double *dvec, int n) {
    double norm = dvecN_norm(dvec, n);
    dvecN_scale_sca(dst_dvec, dvec, 1.0 / (norm > 0 ? norm : 1), n);
}

/** dst = from + (to - from) * t */
static void dvecN_lerp(double *dst_dvec, const double *dvec_from, const double *dvec_to, double t, int n) {
    for (int i = 0; i < n; i++)
        dst_dvec[i] = dvec_from[i] + (dvec_to[i] - dvec_from[i]) * t;
}

#endif //MATHC_VEC_DVECN_H
