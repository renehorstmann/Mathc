#ifndef MATHC_VEC_VECN_H
#define MATHC_VEC_VECN_H

#include "math.h"


/** dst = vec */
static void vecN_copy(float *dst_vec, const float *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** dst = scalar */
static void vecN_set(float *dst_vec, float scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

/** dst = -vec */
static void vecN_neg(float *dst_vec, const float *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}

/** dst = a + b */
static void vecN_add_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** dst = a + b */
static void vecN_add_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** dst = a - b */
static void vecN_sub_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** dst = a - b */
static void vecN_sub_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - scalar_b;
}

/** dst = a * b */
static void vecN_scale_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** dst = a * b */
static void vecN_scale_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** dst = a / b */
static void vecN_div_vec(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / vec_b[i];
}

/** dst = a / b */
static void vecN_div_sca(float *dst_vec, const float *vec_a, float scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / scalar_b;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vecN_sum(const float *vec, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns a dot b */
static float vecN_dot(const float *vec_a, const float *vec_b, int n) {
    float dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** returns ||vec||_2 */
static float vecN_norm(const float *vec, int n) {
    return sqrtf(vecN_dot(vec, vec, n));
}

/** returns ||vec||_p */
static float vecN_norm_p(const float *vec, float p, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += powf(fabsf(vec[i]), p);
    }
    return powf(sum, 1.0f / p);
}

/** returns ||vec||_1 */
static float vecN_norm_1(const float *vec, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fabsf(vec[i]);
    }
    return sum;
}

/** returns ||vec||_inf */
static float vecN_norm_inf(const float *vec, int n) {
    float max = 0;
    for (int i = 0; i < n; i++) {
        if (max < fabsf(vec[i]))
            max = fabsf(vec[i]);
    }
    return max;
}

/** dst = vec / norm(vec) */
static void vecN_normalize_unsafe(float *dst_vec, const float *vec, int n) {
    vecN_scale_sca(dst_vec, vec, 1.0f / vecN_norm(vec, n), n);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static void vecN_normalize(float *dst_vec, const float *vec, int n) {
    float norm = vecN_norm(vec, n);
    vecN_scale_sca(dst_vec, vec, 1.0f / (norm > 0 ? norm : 1), n);
}

/** dst = from + (to - from) * t */
static void vecN_lerp(float *dst_vec, const float *vec_from, const float *vec_to, float t, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_from[i] + (vec_to[i] - vec_from[i]) * t;
}

#endif //MATHC_VEC_VECN_H
