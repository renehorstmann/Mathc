#ifndef MATHC_VEC_IVECN_H
#define MATHC_VEC_IVECN_H

#include "stdlib.h"     // abs
#include "stdbool.h"
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
static void ivecN_add(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** dst = a - b */
static void ivecN_sub_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** dst = a - b */
static void ivecN_sub(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - scalar_b;
}

/** dst = a * b */
static void ivecN_scale_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** dst = a * b */
static void ivecN_scale(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** dst = a / b */
static void ivecN_div_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / vec_b[i];
}

/** dst = a / b */
static void ivecN_div(int *dst_vec, const int *vec_a, int scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / scalar_b;
}

/** dst = abs(x) */
static void ivecN_abs(int *dst_vec, const int *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = abs(vec_x[i]);
}

/** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
static void ivecN_sign(int *dst_vec, const int *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] > 0 ? 1 : (vec_x[i] < 0 ? -1 : 0);
}

/** dst = x % y */
static void ivecN_mod(int *dst_vec, const int *vec_x, int y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] % y;
}

/** dst = x % y */
static void ivecN_mod_vec(int *dst_vec, const int *vec_x, const int *vec_y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] % vec_y[i];
}

/** dst = a < b ? a : b */
static void ivecN_min(int *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < b ? vec_a[i] : b;
}

/** dst = a < b ? a : b */
static void ivecN_min_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
}

/** dst = a > b ? a : b */
static void ivecN_max(int *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > b ? vec_a[i] : b;
}

/** dst = a > b ? a : b */
static void ivecN_max_vec(int *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > vec_b[i] ? vec_a[i] : vec_b[i];
}

/** dst = x < min ? min : (x > max ? max : x) */
static void ivecN_clamp(int *dst_vec, const int *vec_x, int min, int max, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < min ? min : (vec_x[i] > max ? max : vec_x[i]);
}

/** dst = x < min ? min : (x > max ? max : x) */
static void ivecN_clamp_vec(int *dst_vec, const int *vec_x, const int *vec_min, const int *vec_max, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < vec_min[i] ? vec_min[i] : (vec_x[i] > vec_max[i] ? vec_max[i] : vec_x[i]);
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
        sum += powf(abs(vec[i]), p);
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

/** returns length of a vector, see ivecN_norm. Just here to match glsl */
static float ivecN_length(const int *vec, int n) {
    return ivecN_norm(vec, n);
}

/** returns norm(b-a) */
static float ivecN_distance(const int *vec_a, const int *vec_b, int n) {
    int delta[n];
    ivecN_sub_vec(delta, vec_b, vec_a, n);
    return ivecN_norm(delta, n);
}

/** dst = a < b */
static void ivecN_less_than(bool *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < b;
}

/** dst = a < b */
static void ivecN_less_than_vec(bool *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < vec_b[i];
}

/** dst = a <= b */
static void ivecN_less_than_equal(bool *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] <= b;
}

/** dst = a <= b */
static void ivecN_less_than_equal_vec(bool *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] <= vec_b[i];
}

/** dst = a > b */
static void ivecN_greater_than(bool *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > b;
}

/** dst = a > b */
static void ivecN_greater_than_vec(bool *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > vec_b[i];
}

/** dst = a >= b */
static void ivecN_greater_than_equal(bool *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] >= b;
}

/** dst = a >= b */
static void ivecN_greater_than_equal_vec(bool *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] >= vec_b[i];
}

/** dst = a == b */
static void ivecN_equal(bool *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] == b;
}

/** dst = a == b */
static void ivecN_equal_vec(bool *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] == vec_b[i];
}

/** dst = a != b */
static void ivecN_not_equal(bool *dst_vec, const int *vec_a, int b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] != b;
}

/** dst = a != b */
static void ivecN_not_equal_vec(bool *dst_vec, const int *vec_a, const int *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] != vec_b[i];
}

#endif //MATHC_VEC_IVECN_H
