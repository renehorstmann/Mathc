#ifndef UTILC_VECMATH_H
#define UTILC_VECMATH_H

// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

#include <math.h>   //sqrt(f)

//
// this header file has the following content:
//
// 1. macros for vector math
// 2. functions for vector math
// 3. functions for specific sized vector
//

//
// 1. macros
//

/** vec<n> res_i = vec_i */
#define VecCopy(out_set, vec, n)\
for (int i = 0; i < (n); i++) {\
    (out_set)[i] = (vec)[i];\
}

/** vec<n> res_i = scalar */
#define VecSet(out_set, scalar, n)\
for (int i = 0; i < (n); i++) {\
    (out_set)[i] = (scalar);\
}

/** vec<n> res_i = -vec_i */
#define VecNeg(out_neg, vec, n)\
for (int i = 0; i < (n), i++) {\
    (out_neg)[i] = -(vec);\
}

/** vec<n> res_i = a_i + b_i */
#define VecAddVec(out_vec, vec_a, vec_b, n)\
for (int i = 0; i < (n); i++) {\
    (out_vec)[i] = (vec_a)[i] + (vec_b)[i];\
}

/** vec<n> res_i = a_i + b */
#define VecAddSca(out_vec, vec_a, sca_b, n)\
for (int i = 0; i < (n); i++) {\
    (out_vec)[i] = (vec_a=[i] + (sca_b);\
}

/** vec<n> res_i = a_i - b_i */
#define VecSubVec(out_vec, vec_a, vec_b, n)\
for (int i = 0; i < (n); i++) {\
    (out_vec)[i] = (vec_a)[i] - (vec_b)[i];\
}

/** vec<n> res_i = a_i * b_i */
#define VecScaleVec(out_vec, vec_a, vec_b, n)\
for (int i = 0; i < (n); i++) {\
    (out_vec)[i] = (vec_a)[i] * (vec_b)[i];\
}

/** * vec<n> res_i = a_i * b */
#define VecScaleSca(out_vec, vec_a, sca_b, n)\
for (int i = 0; i < (n); i++) {\
    (out_vec)[i] = (vec_a)[i] * (sca_b);\
}


/** sca = vec[0] + vec[1] + ... + vec[n-1] */
#define VecSum(out_sca, vec, n)\
{\
    (out_sca) = 0;\
    for (int i = 0; i < (n); i++) {\
        (out_sca) += (vec)[i]; \
    }\
}

/** sca = vec<n> dot vec<n> */
#define VecDot(out_sca, vec_a, vec_b, n)\
{\
    (out_sca) = 0;\
    for (int i = 0; i < (n); i++) {\
        (out_sca) += (vec_a)[i] * (vec_b)[i];\
    }\
}

/** vec3 res = a cross b, all values after the third will be set to 1 */
#define VecCross(out_vec, vec_a, vec_b, n)\
{\
    (out_vec)[0] = (vec_a)[1] * (vec_b)[2] - (vec_a)[2] * (vec_b)[1];\
    (out_vec)[1] = (vec_a)[2] * (vec_b)[0] - (vec_a)[0] * (vec_b)[2];\
    (out_vec)[2] = (vec_a)[0] * (vec_b)[1] - (vec_a)[1] * (vec_b)[0];\
    for (int i=3; i<n; i++) {\
        (out_vec)[i] = 1;\
    }\
}

//
// 2. functions
//


//
// vec = float
//
/** vec<n> dst_i = vec_i */
static void vec_copy(float *dst_vec, const float *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** vec<n> dst_i = scalar */
static void vec_set(float *dst_vec, float scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

/** vec<n> dst_i = -vec_i */
static void vec_neg(float *dst_vec, const float *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}

/** vec<n> dst_i = a_i + b_i */
static void vec_add_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** vec<n> dst_i = a_i + b */
static void vec_add_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** vec<n> dst_i = a_i - b_i */
static void vec_sub_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** vec<n> dst_i = a_i * b_i */
static void vec_scale_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** vec<n> res_i = a_i * b */
static void vec_scale_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec_sum(const float *vec, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns vec<n> dot vec<n> */
static float vec_dot(const float *vec_a, const float *vec_b, int n) {
    float dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** vec3 dst = a cross b, all values after the third will be set to 0 */
static void vec_cross(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    dst_vec[0] = vec_a[1] * vec_b[2] - vec_a[2] * vec_b[1];
    dst_vec[1] = vec_a[2] * vec_b[0] - vec_a[0] * vec_b[2];
    dst_vec[2] = vec_a[0] * vec_b[1] - vec_a[1] * vec_b[0];
    for (int i = 3; i < n; i++)
        dst_vec[i] = 0;
}

/** returns norm2 of a float vector */
static float vec_norm(const float *vec, int n) {
    return sqrtf(vec_dot(vec, vec, n));
}

/** dst = vec / norm(vec) */
static void vec_normalize_unsafe(float *dst_vec, const float *vec, int n) {
    vec_scale_sca(dst_vec, vec, 1.0f / vec_norm(vec, n), n);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static void vec_normalize(float *dst_vec, const float *vec, int n) {
    float norm = vec_norm(vec, n);
    vec_scale_sca(dst_vec, vec, 1.0f / (norm > 0 ? norm : 1), n);
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
// 3. specific size functions
//

//
// vec3
//
typedef struct vec3 {
    float v[3];
} vec3;

/** vec<n> dst_i = vec_i */
static vec3 vec3_copy(const float *vec) {
    vec3 res;
    vec_copy(res.v, vec, 3);
    return res;
}

/** vec<n> dst_i = scalar */
static vec3 vec3_set(float scalar) {
    vec3 res;
    vec_set(res.v, scalar, 3);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec3 vec3_neg(const float *vec) {
    vec3 res;
    vec_neg(res.v, vec, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3 vec3_add_vec(const float *vec_a, const float *vec_b) {
    vec3 res;
    vec_add_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3 vec3_add_sca(const float *vec_a, float scalar_b) {
    vec3 res;
    vec_add_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3 vec3_sub_vec(const float *vec_a, const float *vec_b) {
    vec3 res;
    vec_sub_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3 vec3_scale_vec(const float *vec_a, const float *vec_b) {
    vec3 res;
    vec_scale_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3 vec3_scale_sca(const float *vec_a, float scalar_b) {
    vec3 res;
    vec_scale_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec3 dst = a cross b */
static vec3 vec3_cross(const float *vec_a, const float *vec_b) {
    vec3 res;
    vec_cross(res.v, vec_a, vec_b, 3);
    return res;
}

/** dst = vec / norm(vec) */
static vec3 vec3_normalize_unsafe(const float *vec) {
    return vec3_scale_sca(vec, 1.0f / vec_norm(vec, 3));
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3 vec3_normalize(const float *vec) {
    float norm = vec_norm(vec, 3);
    return vec3_scale_sca(vec, 1.0f / (norm > 0 ? norm : 1));
}


//
// vec3d
//
typedef struct vec3d {
    double v[3];
} vec3d;

/** vec<n> dst_i = vec_i */
static vec3d vec3d_copy(const double *vec) {
    vec3d res;
    vecd_copy(res.v, vec, 3);
    return res;
}

/** vec<n> dst_i = scalar */
static vec3d vec3d_set(double scalar) {
    vec3d res;
    vecd_set(res.v, scalar, 3);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec3d vec3d_neg(const double *vec) {
    vec3d res;
    vecd_neg(res.v, vec, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3d vec3d_add_vec(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_add_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3d vec3d_add_sca(const double *vec_a, double scalar_b) {
    vec3d res;
    vecd_add_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3d vec3d_sub_vec(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_sub_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3d vec3d_scale_vec(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_scale_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3d vec3d_scale_sca(const double *vec_a, double scalar_b) {
    vec3d res;
    vecd_scale_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec3 dst = a cross b */
static vec3d vec3d_cross(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_cross(res.v, vec_a, vec_b, 3);
    return res;
}

/** dst = vec / norm(vec) */
static vec3d vec3d_normalize_unsafe(const double *vec) {
    return vec3d_scale_sca(vec, 1.0f / vecd_norm(vec, 3));
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3d vec3d_normalize(const double *vec) {
    double norm = vecd_norm(vec, 3);
    return vec3d_scale_sca(vec, 1.0 / (norm > 0 ? norm : 1));
}


//
// vec4
//
typedef struct vec4 {
    float v[4];
} vec4;

/** vec<n> dst_i = vec_i */
static vec4 vec4_copy(const float *vec) {
    vec4 res;
    vec_copy(res.v, vec, 4);
    return res;
}

/** vec<n> dst_i = scalar */
static vec4 vec4_set(float scalar) {
    vec4 res;
    vec_set(res.v, scalar, 4);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec4 vec4_neg(const float *vec) {
    vec4 res;
    vec_neg(res.v, vec, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4 vec4_add_vec(const float *vec_a, const float *vec_b) {
    vec4 res;
    vec_add_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4 vec4_add_sca(const float *vec_a, float scalar_b) {
    vec4 res;
    vec_add_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4 vec4_sub_vec(const float *vec_a, const float *vec_b) {
    vec4 res;
    vec_sub_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4 vec4_scale_vec(const float *vec_a, const float *vec_b) {
    vec4 res;
    vec_scale_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4 vec4_scale_sca(const float *vec_a, float scalar_b) {
    vec4 res;
    vec_scale_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec4 dst = a cross b, the fourth component (w) will be set to 1 */
static vec4 vec4_cross(const float *vec_a, const float *vec_b) {
    vec4 res;
    vec_cross(res.v, vec_a, vec_b, 4);
    return res;
}

/** dst = vec / norm(vec) */
static vec4 vec4_normalize_unsafe(const float *vec) {
    return vec4_scale_sca(vec, 1.0f / vec_norm(vec, 4));
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4 vec4_normalize(const float *vec) {
    float norm = vec_norm(vec, 4);
    return vec4_scale_sca(vec, 1.0f / (norm > 0 ? norm : 1));
}


//
// vec4d
//
typedef struct vec4d {
    double v[4];
} vec4d;

/** vec<n> dst_i = vec_i */
static vec4d vec4d_copy(const double *vec) {
    vec4d res;
    vecd_copy(res.v, vec, 4);
    return res;
}

/** vec<n> dst_i = scalar */
static vec4d vec4d_set(double scalar) {
    vec4d res;
    vecd_set(res.v, scalar, 4);
    return res;
}

/** vec<n> dst_i = -vec_i */
static vec4d vec4d_neg(const double_t *vec) {
    vec4d res;
    vecd_neg(res.v, vec, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4d vec4d_add_vec(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_add_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4d vec4d_add_sca(const double *vec_a, double scalar_b) {
    vec4d res;
    vecd_add_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4d vec4d_sub_vec(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_sub_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4d vec4d_scale_vec(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_scale_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4d vec4d_scale_sca(const double *vec_a, double scalar_b) {
    vec4d res;
    vecd_scale_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec4 dst = a cross b, the fourth component (w) will be set to 1 */
static vec4d vec4d_cross(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_cross(res.v, vec_a, vec_b, 4);
    return res;
}

/** dst = vec / norm(vec) */
static vec4d vec4d_normalize_unsafe(const double *vec) {
    return vec4d_scale_sca(vec, 1.0f / vecd_norm(vec, 4));
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4d vec4d_normalize(const double *vec) {
    double norm = vecd_norm(vec, 4);
    return vec4d_scale_sca(vec, 1.0 / (norm > 0 ? norm : 1));
}

#endif //UTILC_VECMATH_H

