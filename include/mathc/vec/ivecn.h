#ifndef MATHC_IVEC_VECN_H
#define MATHC_IVEC_VECN_H

#include "stdlib.h" // abs
#include "math.h"


/** dst = ivec */
static void ivecN_copy(int *dst_ivec, const int *ivec, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec[i];
}

/** dst = scalar */
static void ivecN_set(int *dst_ivec, int scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = scalar;
}

/** dst = -ivec */
static void ivecN_neg(int *dst_ivec, const int *ivec, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = -ivec[i];
}

/** dst = a + b */
static void ivecN_add_ivec(int *dst_ivec, const int *ivec_a, const int *ivec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] + ivec_b[i];
}

/** dst = a + b */
static void ivecN_add_sca(int *dst_ivec, const int *ivec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] + scalar_b;
}

/** dst = a - b */
static void ivecN_sub_ivec(int *dst_ivec, const int *ivec_a, const int *ivec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] - ivec_b[i];
}

/** dst = a - b */
static void ivecN_sub_sca(int *dst_ivec, const int *ivec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] - scalar_b;
}

/** dst = a * b */
static void ivecN_scale_ivec(int *dst_ivec, const int *ivec_a, const int *ivec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] * ivec_b[i];
}

/** dst = a * b */
static void ivecN_scale_sca(int *dst_ivec, const int *ivec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] * scalar_b;
}

/** dst = a / b */
static void ivecN_div_ivec(int *dst_ivec, const int *ivec_a, const int *ivec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] / ivec_b[i];
}

/** dst = a / b */
static void ivecN_div_sca(int *dst_ivec, const int *ivec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = ivec_a[i] / scalar_b;
}

/** returns ivec[0] + ivec[1] + ... + ivec[n-1] */
static int ivecN_sum(const int *ivec, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += ivec[i];
    return sum;
}

/** returns a dot b */
static int ivecN_dot(const int *ivec_a, const int *ivec_b, int n) {
    int dot = 0;
    for (int i = 0; i < n; i++)
        dot += ivec_a[i] * ivec_b[i];
    return dot;
}

/** returns ||ivec||_2 */
static float ivecN_norm(const int *ivec, int n) {
    return sqrtf(ivecN_dot(ivec, ivec, n));
}

/** returns ||ivec||_p */
static float ivecN_norm_p(const int *ivec, float p, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += powf(fabsf((float) ivec[i]), p);
    }
    return powf(sum, 1.0f / p);
}

/** returns ||ivec||_1 */
static int ivecN_norm_1(const int *ivec, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(ivec[i]);
    }
    return sum;
}

/** returns ||ivec||_inf */
static int ivecN_norm_inf(const int *ivec, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < abs(ivec[i]))
            max = abs(ivec[i]);
    }
    return max;
}

/** dst = from + (to - from) * t */
static void ivecN_lerp(int *dst_ivec, const int *ivec_from, const int *ivec_to, float t, int n) {
    for (int i = 0; i < n; i++)
        dst_ivec[i] = (int) (ivec_from[i] + (ivec_to[i] - ivec_from[i]) * t);
}

#endif //MATHC_VEC_IVECN_H
