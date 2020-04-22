#ifndef MATHC_VEC_H
#define MATHC_VEC_H

// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

#include <math.h>   //sqrt(f)

//
// this header file has the following content:
// 1. functions for vector math with size parameter
// 2. functions for vector math with fixed size such as vec3f
//


//
// 1. functions for vector math with size parameter
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

//
// 2. functions for vector math with fixed size such as vec3f
//

//
// vec3f
//
typedef struct vec3f {
    float v[3];
} vec3f;

/** vec<n> dst_i = scalar */
static vec3f vec3f_set(float scalar) {
    vec3f res;
    vecf_set(res.v, scalar, 3);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec3f vec3f_neg(vec3f vec) {
    vec3f res;
    vecf_neg(res.v, vec.v, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3f vec3f_add_vec(vec3f vec_a, vec3f vec_b) {
    vec3f res;
    vecf_add_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3f vec3f_add_sca(vec3f vec_a, float scalar_b) {
    vec3f res;
    vecf_add_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3f vec3f_sub_vec(vec3f vec_a, vec3f vec_b) {
    vec3f res;
    vecf_sub_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3f vec3f_scale_vec(vec3f vec_a, vec3f vec_b) {
    vec3f res;
    vecf_scale_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3f vec3f_scale_sca(vec3f vec_a, float scalar_b) {
    vec3f res;
    vecf_scale_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec3f_sum(vec3f vec) {
    return vecf_sum(vec.v, 3);
}

/** returns vec<n> dot vec<n> */
static float vec3f_dot(vec3f vec_a, vec3f vec_b) {
    return vecf_dot(vec_a.v, vec_b.v, 3);
}

/** vec3f dst = a cross b */
static vec3f vec3f_cross(vec3f vec_a, vec3f vec_b) {
    vec3f res;
    vecf_cross(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** returns norm2 of a float vector */
static float vec3f_norm(vec3f vec) {
    return vecf_norm(vec.v, 3);
}

/** dst = vec / norm(vec) */
static vec3f vec3f_normalize_unsafe(vec3f vec) {
    vec3f res;
    vecf_normalize_unsafe(res.v, vec.v, 3);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3f vec3f_normalize(vec3f vec) {
    vec3f res;
    vecf_normalize(res.v, vec.v, 3);
    return res;
}


//
// vec4f
//
typedef struct vec4f {
    float v[4];
} vec4f;

/** vec<n> dst_i = scalar */
static vec4f vec4f_set(float scalar) {
    vec4f res;
    vecf_set(res.v, scalar, 4);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec4f vec4f_neg(vec4f vec) {
    vec4f res;
    vecf_neg(res.v, vec.v, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4f vec4f_add_vec(vec4f vec_a, vec4f vec_b) {
    vec4f res;
    vecf_add_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4f vec4f_add_sca(vec4f vec_a, float scalar_b) {
    vec4f res;
    vecf_add_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4f vec4f_sub_vec(vec4f vec_a, vec4f vec_b) {
    vec4f res;
    vecf_sub_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4f vec4f_scale_vec(vec4f vec_a, vec4f vec_b) {
    vec4f res;
    vecf_scale_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4f vec4f_scale_sca(vec4f vec_a, float scalar_b) {
    vec4f res;
    vecf_scale_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec4f_sum(vec4f vec) {
    return vecf_sum(vec.v, 4);
}

/** returns vec<n> dot vec<n> */
static float vec4f_dot(vec4f vec_a, vec4f vec_b) {
    return vecf_dot(vec_a.v, vec_b.v, 4);
}

/** vec4f dst = a cross b */
static vec4f vec4f_cross(vec4f vec_a, vec4f vec_b) {
    vec4f res;
    vecf_cross(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** returns norm2 of a float vector */
static float vec4f_norm(vec4f vec) {
    return vecf_norm(vec.v, 4);
}

/** dst = vec / norm(vec) */
static vec4f vec4f_normalize_unsafe(vec4f vec) {
    vec4f res;
    vecf_normalize_unsafe(res.v, vec.v, 4);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4f vec4f_normalize(vec4f vec) {
    vec4f res;
    vecf_normalize(res.v, vec.v, 4);
    return res;
}



//
// vec3d
//
typedef struct vec3d {
    double v[3];
} vec3d;

/** vec<n> dst_i = scalar */
static vec3d vec3d_set(double scalar) {
    vec3d res;
    vecd_set(res.v, scalar, 3);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec3d vec3d_neg(vec3d vec) {
    vec3d res;
    vecd_neg(res.v, vec.v, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3d vec3d_add_vec(vec3d vec_a, vec3d vec_b) {
    vec3d res;
    vecd_add_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3d vec3d_add_sca(vec3d vec_a, double scalar_b) {
    vec3d res;
    vecd_add_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3d vec3d_sub_vec(vec3d vec_a, vec3d vec_b) {
    vec3d res;
    vecd_sub_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3d vec3d_scale_vec(vec3d vec_a, vec3d vec_b) {
    vec3d res;
    vecd_scale_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3d vec3d_scale_sca(vec3d vec_a, double scalar_b) {
    vec3d res;
    vecd_scale_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double vec3d_sum(vec3d vec) {
    return vecd_sum(vec.v, 3);
}

/** returns vec<n> dot vec<n> */
static double vec3d_dot(vec3d vec_a, vec3d vec_b) {
    return vecd_dot(vec_a.v, vec_b.v, 3);
}

/** vec3d dst = a cross b */
static vec3d vec3d_cross(vec3d vec_a, vec3d vec_b) {
    vec3d res;
    vecd_cross(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** returns norm2 of a double vector */
static double vec3d_norm(vec3d vec) {
    return vecd_norm(vec.v, 3);
}

/** dst = vec / norm(vec) */
static vec3d vec3d_normalize_unsafe(vec3d vec) {
    vec3d res;
    vecd_normalize_unsafe(res.v, vec.v, 3);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3d vec3d_normalize(vec3d vec) {
    vec3d res;
    vecd_normalize(res.v, vec.v, 3);
    return res;
}



//
// vec4d
//
typedef struct vec4d {
    double v[4];
} vec4d;

/** vec<n> dst_i = scalar */
static vec4d vec4d_set(double scalar) {
    vec4d res;
    vecd_set(res.v, scalar, 4);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec4d vec4d_neg(vec4d vec) {
    vec4d res;
    vecd_neg(res.v, vec.v, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4d vec4d_add_vec(vec4d vec_a, vec4d vec_b) {
    vec4d res;
    vecd_add_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4d vec4d_add_sca(vec4d vec_a, double scalar_b) {
    vec4d res;
    vecd_add_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4d vec4d_sub_vec(vec4d vec_a, vec4d vec_b) {
    vec4d res;
    vecd_sub_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4d vec4d_scale_vec(vec4d vec_a, vec4d vec_b) {
    vec4d res;
    vecd_scale_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4d vec4d_scale_sca(vec4d vec_a, double scalar_b) {
    vec4d res;
    vecd_scale_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double vec4d_sum(vec4d vec) {
    return vecd_sum(vec.v, 4);
}

/** returns vec<n> dot vec<n> */
static double vec4d_dot(vec4d vec_a, vec4d vec_b) {
    return vecd_dot(vec_a.v, vec_b.v, 4);
}

/** vec4d dst = a cross b */
static vec4d vec4d_cross(vec4d vec_a, vec4d vec_b) {
    vec4d res;
    vecd_cross(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** returns norm2 of a double vector */
static double vec4d_norm(vec4d vec) {
    return vecd_norm(vec.v, 4);
}

/** dst = vec / norm(vec) */
static vec4d vec4d_normalize_unsafe(vec4d vec) {
    vec4d res;
    vecd_normalize_unsafe(res.v, vec.v, 4);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4d vec4d_normalize(vec4d vec) {
    vec4d res;
    vecd_normalize(res.v, vec.v, 4);
    return res;
}

//
// vec3i
//
typedef struct vec3i {
    int v[3];
} vec3i;

/** vec<n> dst_i = scalar */
static vec3i vec3i_set(int scalar) {
    vec3i res;
    veci_set(res.v, scalar, 3);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec3i vec3i_neg(vec3i vec) {
    vec3i res;
    veci_neg(res.v, vec.v, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3i vec3i_add_vec(vec3i vec_a, vec3i vec_b) {
    vec3i res;
    veci_add_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3i vec3i_add_sca(vec3i vec_a, int scalar_b) {
    vec3i res;
    veci_add_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3i vec3i_sub_vec(vec3i vec_a, vec3i vec_b) {
    vec3i res;
    veci_sub_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3i vec3i_scale_vec(vec3i vec_a, vec3i vec_b) {
    vec3i res;
    veci_scale_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3i vec3i_scale_sca(vec3i vec_a, int scalar_b) {
    vec3i res;
    veci_scale_sca(res.v, vec_a.v, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int vec3i_sum(vec3i vec) {
    return veci_sum(vec.v, 3);
}

/** returns vec<n> dot vec<n> */
static int vec3i_dot(vec3i vec_a, vec3i vec_b) {
    return veci_dot(vec_a.v, vec_b.v, 3);
}

/** vec3i dst = a cross b */
static vec3i vec3i_cross(vec3i vec_a, vec3i vec_b) {
    vec3i res;
    veci_cross(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** returns norm2 of a int vector */
static double vec3i_norm(vec3i vec) {
    return veci_norm(vec.v, 3);
}

//
// vec4i
//
typedef struct vec4i {
    int v[4];
} vec4i;

/** vec<n> dst_i = scalar */
static vec4i vec4i_set(int scalar) {
    vec4i res;
    veci_set(res.v, scalar, 4);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec4i vec4i_neg(vec4i vec) {
    vec4i res;
    veci_neg(res.v, vec.v, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4i vec4i_add_vec(vec4i vec_a, vec4i vec_b) {
    vec4i res;
    veci_add_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4i vec4i_add_sca(vec4i vec_a, int scalar_b) {
    vec4i res;
    veci_add_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4i vec4i_sub_vec(vec4i vec_a, vec4i vec_b) {
    vec4i res;
    veci_sub_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4i vec4i_scale_vec(vec4i vec_a, vec4i vec_b) {
    vec4i res;
    veci_scale_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4i vec4i_scale_sca(vec4i vec_a, int scalar_b) {
    vec4i res;
    veci_scale_sca(res.v, vec_a.v, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int vec4i_sum(vec4i vec) {
    return veci_sum(vec.v, 4);
}

/** returns vec<n> dot vec<n> */
static int vec4i_dot(vec4i vec_a, vec4i vec_b) {
    return veci_dot(vec_a.v, vec_b.v, 4);
}

/** vec4i dst = a cross b */
static vec4i vec4i_cross(vec4i vec_a, vec4i vec_b) {
    vec4i res;
    veci_cross(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** returns norm2 of a int vector */
static double vec4i_norm(vec4i vec) {
    return veci_norm(vec.v, 4);
}




#endif //MATHC_VEC_H
