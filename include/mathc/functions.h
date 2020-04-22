#ifndef MATHC_FUNCTIONS_H
#define MATHC_FUNCTIONS_H


// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

#include <math.h>   //sqrt(f)

//
// this header file has the following content:
// 1. functions for float vector math vecf_
// 2. functions for double vector math vecd_
// 3. functions for int vector math veci_
//


//
// vecf = float
//
/** vec<n> dst_i = vec_i */
static void vecf_copy(float *dst_vec, const float *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** vec<n> dst_i = scalar */
static void vecf_set(float *dst_vec, float scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

/** vec<n> dst_i = -vec_i */
static void vecf_neg(float *dst_vec, const float *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}

/** vec<n> dst_i = a_i + b_i */
static void vecf_add_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** vec<n> dst_i = a_i + b */
static void vecf_add_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** vec<n> dst_i = a_i - b_i */
static void vecf_sub_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** vec<n> dst_i = a_i * b_i */
static void vecf_scale_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** vec<n> res_i = a_i * b */
static void vecf_scale_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vecf_sum(const float *vec, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns vec<n> dot vec<n> */
static float vecf_dot(const float *vec_a, const float *vec_b, int n) {
    float dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** vec3 dst = a cross b, all values after the third will be set to 0 */
static void vecf_cross(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    dst_vec[0] = vec_a[1] * vec_b[2] - vec_a[2] * vec_b[1];
    dst_vec[1] = vec_a[2] * vec_b[0] - vec_a[0] * vec_b[2];
    dst_vec[2] = vec_a[0] * vec_b[1] - vec_a[1] * vec_b[0];
    for (int i = 3; i < n; i++)
        dst_vec[i] = 0;
}

/** returns norm2 of a float vector */
static float vecf_norm(const float *vec, int n) {
    return sqrtf(vecf_dot(vec, vec, n));
}

/** dst = vec / norm(vec) */
static void vecf_normalize_unsafe(float *dst_vec, const float *vec, int n) {
    vecf_scale_sca(dst_vec, vec, 1.0f / vecf_norm(vec, n), n);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static void vecf_normalize(float *dst_vec, const float *vec, int n) {
    float norm = vecf_norm(vec, n);
    vecf_scale_sca(dst_vec, vec, 1.0f / (norm > 0 ? norm : 1), n);
}


//
// vecd = double
//
/** vec<n> dst_i = vec_i */
static void vecd_copy(double *dst_vec, const double *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** vec<n> dst_i = scalar */
static void vecd_set(double *dst_vec, double scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

/** vec<n> dst_i = -vec_i */
static void vecd_neg(double *dst_vec, const double *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}

/** vec<n> dst_i = a_i + b_i */
static void vecd_add_vec(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** vec<n> dst_i = a_i + b */
static void vecd_add_sca(double *dst_vec, const double *vec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** vec<n> dst_i = a_i - b_i */
static void vecd_sub_vec(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** vec<n> dst_i = a_i * b_i */
static void vecd_scale_vec(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** vec<n> res_i = a_i * b */
static void vecd_scale_sca(double *dst_vec, const double *vec_a, double scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double vecd_sum(const double *vec, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns vec<n> dot vec<n> */
static double vecd_dot(const double *vec_a, const double *vec_b, int n) {
    double dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** vec3 dst = a cross b, all values after the third will be set to 0 */
static void vecd_cross(double *dst_vec, const double *vec_a, const double *vec_b, int n) {
    dst_vec[0] = vec_a[1] * vec_b[2] - vec_a[2] * vec_b[1];
    dst_vec[1] = vec_a[2] * vec_b[0] - vec_a[0] * vec_b[2];
    dst_vec[2] = vec_a[0] * vec_b[1] - vec_a[1] * vec_b[0];
    for (int i = 3; i < n; i++)
        dst_vec[i] = 0;
}

/** returns norm2 of a double vector */
static double vecd_norm(const double *vec, int n) {
    return sqrt(vecd_dot(vec, vec, n));
}

/** dst = vec / norm(vec) */
static void vecd_normalize_unsafe(double *dst_vec, const double *vec, int n) {
    vecd_scale_sca(dst_vec, vec, 1.0 / vecd_norm(vec, n), n);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static void vecd_normalize(double *dst_vec, const double *vec, int n) {
    double norm = vecd_norm(vec, n);
    vecd_scale_sca(dst_vec, vec, 1.0 / (norm > 0 ? norm : 1), n);
}


//
// veci = int
//
/** vec<n> dst_i = vec_i */
static void veci_copy(int *dst_vec, const int *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** vec<n> dst_i = scalar */
static void veci_set(int *dst_vec, int scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

/** vec<n> dst_i = -vec_i */
static void veci_neg(int *dst_vec, const int *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}

/** vec<n> dst_i = a_i + b_i */
static void veci_add_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** vec<n> dst_i = a_i + b */
static void veci_add_sca(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** vec<n> dst_i = a_i - b_i */
static void veci_sub_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** vec<n> dst_i = a_i * b_i */
static void veci_scale_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** vec<n> res_i = a_i * b */
static void veci_scale_sca(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int veci_sum(const int *vec, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns vec<n> dot vec<n> */
static int veci_dot(const int *vec_a, const int *vec_b, int n) {
    int dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** vec3 dst = a cross b, all values after the third will be set to 0 */
static void veci_cross(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    dst_vec[0] = vec_a[1] * vec_b[2] - vec_a[2] * vec_b[1];
    dst_vec[1] = vec_a[2] * vec_b[0] - vec_a[0] * vec_b[2];
    dst_vec[2] = vec_a[0] * vec_b[1] - vec_a[1] * vec_b[0];
    for (int i = 3; i < n; i++)
        dst_vec[i] = 0;
}

/** returns norm2 of an int vector */
static double veci_norm(const int *vec, int n) {
    return sqrt(veci_dot(vec, vec, n));
}


#endif //MATHC_FUNCTIONS_H
