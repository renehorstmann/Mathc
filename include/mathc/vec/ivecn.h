#ifndef MATHC_VEC_IVECN_H
#define MATHC_VEC_IVECN_H

#include "stdlib.h"     //abs
#include "math.h"


/** macro to cast a vector into a int vector */
#define ivecN_cast_into(dst_vec, vec, n) \
{ \
    for(int i=0; i<(n); i++) \
        (dst_vec)[i] = (int) (vec)[i]; \
}


/** dst = vec */
static void ivecN_copy(int *dst_vec, const int *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** dst = scalar */
static void ivecN_set(int *dst_vec, int scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

/** dst = -vec */
static void ivecN_neg(int *dst_vec, const int *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}

/** dst = a + b */
static void ivecN_add_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** dst = a + b */
static void ivecN_add_sca(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** dst = a - b */
static void ivecN_sub_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** dst = a - b */
static void ivecN_sub_sca(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - scalar_b;
}

/** dst = a * b */
static void ivecN_scale_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** dst = a * b */
static void ivecN_scale_sca(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** dst = a / b */
static void ivecN_div_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / vec_b[i];
}

/** dst = a / b */
static void ivecN_div_sca(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / scalar_b;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int ivecN_sum(const int *vec, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns a dot b */
static int ivecN_dot(const int *vec_a, const int *vec_b, int n) {
    int dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** returns ||vec||_2 */
static float ivecN_norm(const int *vec, int n) {
    return sqrtf(ivecN_dot(vec, vec, n));
}

/** returns ||vec||_p */
static float ivecN_norm_p(const int *vec, float p, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += powf(fabsf((float) vec[i]), p);
    }
    return powf(sum, 1.0f / p);
}

/** returns ||vec||_1 */
static int ivecN_norm_1(const int *vec, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(vec[i]);
    }
    return sum;
}

/** returns ||vec||_inf */
static int ivecN_norm_inf(const int *vec, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < abs(vec[i]))
            max = abs(vec[i]);
    }
    return max;
}

/** dst = from + (to - from) * t */
static void ivecN_lerp(int *dst_vec, const int *vec_from, const int *vec_to, float t, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = (int) (vec_from[i] + (vec_to[i] - vec_from[i]) * t);
}

#endif //MATHC_VEC_IVECN_H
