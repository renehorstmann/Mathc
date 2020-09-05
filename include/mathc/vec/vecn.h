#ifndef MATHC_VEC_VECN_H
#define MATHC_VEC_VECN_H

#include "stdbool.h"
#include "math.h"


/** macro to cast a vector into a float vector */
#define vecN_cast_into(dst_vec, vec, n) \
{ \
    for(int i=0; i<(n); i++) \
        (dst_vec)[i] = (float) (vec)[i]; \
}


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

/** dst = a * M_PI / 180 */
static void vecN_radians(float *dst_vec, const float *vec_deg, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_deg[i] * M_PI / 180.0f;
}

/** dst = a * 180 / M_PI */
static void vecN_degrees(float *dst_vec, const float *vec_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_rad[i] * 180.0f / M_PI;
}

/** dst = sin(angle_rad) */
static void vecN_sin(float *dst_vec, const float *vec_angle_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = sinf(vec_angle_rad[i]);
}

/** dst = cos(angle_rad) */
static void vecN_cos(float *dst_vec, const float *vec_angle_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = cosf(vec_angle_rad[i]);
}

/** dst = tan(angle_rad) */
static void vecN_tan(float *dst_vec, const float *vec_angle_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = tanf(vec_angle_rad[i]);
}

/** dst = asin(x) */
static void vecN_asin(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = asinf(vec_x[i]);
}

/** dst = acos(x) */
static void vecN_acos(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = acosf(vec_x[i]);
}

/** dst = atan(x) */
static void vecN_atan(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = atanf(vec_x[i]);
}

/** dst = atan2(y, x) */
static void vecN_atan2(float *dst_vec, const float *vec_y, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = atan2f(vec_y[i], vec_x[i]);
}

/** dst = pow(x, y) */
static void vecN_pow(float *dst_vec, const float *vec_x, float y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = powf(vec_x[i], y);
}

/** dst = pow(x, y) */
static void vecN_powv(float *dst_vec, const float *vec_x, const float *vec_y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = powf(vec_x[i], vec_y[i]);
}

/** dst = exp(x) */
static void vecN_exp(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = expf(vec_x[i]);
}

/** dst = log(x) */
static void vecN_log(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = logf(vec_x[i]);
}

/** dst = exp2(x) */
static void vecN_exp2(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = exp2f(vec_x[i]);
}

/** dst = log2(x) */
static void vecN_log2(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = log2f(vec_x[i]);
}

/** dst = sqrt(x) */
static void vecN_sqrt(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = sqrtf(vec_x[i]);
}

/** dst = 1 / sqrt(x) */
static void vecN_inversesqrt(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = 1.0f / sqrtf(vec_x[i]);
}

/** dst = abs(x) */
static void vecN_abs(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = fabsf(vec_x[i]);
}

/** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
static void vecN_sign(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] > 0 ? 1 : (vec_x[i] < 0 ? -1 : 0);
}

/** dst = floor(x) */
static void vecN_floor(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = floorf(vec_x[i]);
}

/** dst = ceil(x) */
static void vecN_ceil(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = ceilf(vec_x[i]);
}

/** dst = x - floor(x) */
static void vecN_fract(float *dst_vec, const float *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] - floorf(vec_x[i]);
}

/** dst = x - y * floor(x/y) */
static void vecN_mod(float *dst_vec, const float *vec_x, float y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] - y * floorf(vec_x[i] / y);
}

/** dst = x - y * floor(x/y) */
static void vecN_modv(float *dst_vec, const float *vec_x, const float *vec_y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] - vec_y[i] * floorf(vec_x[i] / vec_y[i]);
}

/** dst = a < b ? a : b */
static void vecN_min(float *dst_vec, const float *vec_a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < b ? vec_a[i] : b;
}

/** dst = a < b ? a : b */
static void vecN_minv(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
}

/** dst = a > b ? a : b */
static void vecN_max(float *dst_vec, const float *vec_a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > b ? vec_a[i] : b;
}

/** dst = a > b ? a : b */
static void vecN_maxv(float *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > vec_b[i] ? vec_a[i] : vec_b[i];
}

/** dst = x < min ? min : (x > max ? max : x) */
static void vecN_clamp(float *dst_vec, const float *vec_x, float min, float max, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < min ? min : (vec_x[i] > max ? max : vec_x[i]);
}

/** dst = x < min ? min : (x > max ? max : x) */
static void vecN_clampv(float *dst_vec, const float *vec_x, const float *vec_min, const float *vec_max, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < vec_min[i] ? vec_min[i] : (vec_x[i] > vec_max[i] ? vec_max[i] : vec_x[i]);
}

/** dst = a * (1-t) + b * t */
static void vecN_mix(float *dst_vec, const float *vec_a, const float *vec_b, float t, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * (1.0f - t) + vec_b[i] * t;
}

/** dst = a * (1-t) + b * t */
static void vecN_mixv(float *dst_vec, const float *vec_a, const float *vec_b, const float *vec_t, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * (1.0f - vec_t[i]) + vec_b[i] * vec_t[i];
}

/** dst = x < edge ? 0 : 1 */
static void vecN_step(float *dst_vec, const float *vec_x, float edge, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < edge ? 0.0f : 1.0f;
}

/** dst = x < edge ? 0 : 1 */
static void vecN_stepv(float *dst_vec, const float *vec_x, const float *vec_edge, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < vec_edge[i] ? 0.0f : 1.0f;
}

/** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
static void vecN_smoothstep(float *dst_vec, const float *vec_x, float edge1, float edge2, int n) {
    for (int i = 0; i < n; i++) {
        float x = vec_x[i];
        dst_vec[i] = x < edge1 ? 0.0f : (x > edge2 ? 1.0f : x * x * (3 - 2 * x));
    }
}

/** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
static void
vecN_smoothstepv(float *dst_vec, const float *vec_x, const float *vec_edge1, const float *vec_edge2, int n) {
    for (int i = 0; i < n; i++) {
        float x = vec_x[i];
        dst_vec[i] = x < vec_edge1[i] ? 0.0f : (x > vec_edge2[i] ? 1.0f : x * x * (3 - 2 * x));
    }
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

/** returns length of a vector, see vecN_norm. Just here to match glsl */
static float vecN_length(const float *vec, int n) {
    return vecN_norm(vec, n);
}

/** returns norm(b-a) */
static float vecN_distance(const float *vec_a, const float *vec_b, int n) {
    float delta[n];
    vecN_sub_vec(delta, vec_b, vec_a, n);
    return vecN_norm(delta, n);
}

/** dst = dot(I, Nref) < 0 ? N : -N */
static void vecN_faceforward(float *dst_vec, const float *vec_N, const float *vec_I, const float *vec_Nref, int n) {
    if (vecN_dot(vec_I, vec_Nref, n) < 0)
        vecN_copy(dst_vec, vec_N, n);
    else
        vecN_neg(dst_vec, vec_N, n);
}

/** dst = I - 2.0 * N * dot(N,I) */
static void vecN_reflect(float *dst_vec, const float *vec_I, const float *vec_N, int n) {
    vecN_scale_sca(dst_vec, vec_N, 2.0f * vecN_dot(vec_N, vec_I, n), n);
    vecN_sub_vec(dst_vec, vec_I, dst_vec, n);
}

static void vecN_refract(float *dst_vec, const float *vec_I, const float *vec_N, float eta, int n) {
    // implementation from example implementation: https://developer.download.nvidia.com/cg/refract.html
    vecN_neg(dst_vec, vec_I, n);
    float cosi = vecN_dot(dst_vec, vec_N, n);
    float cost2 = 1.0f - eta * eta * (1.0f - cosi * cosi);
    vecN_scale_sca(dst_vec, vec_N, eta * cosi - sqrtf(fabsf(cost2)), n);
    float t[3];
    vecN_scale_sca(t, vec_I, eta, n);
    vecN_add_vec(t, t, dst_vec, n);
    vecN_scale_sca(dst_vec, t, cost2 > 0, n);
}

/** dst = a < b */
static void vecN_less_than(bool *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < vec_b[i];
}

/** dst = a <= b */
static void vecN_less_than_equal(bool *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] <= vec_b[i];
}

/** dst = a > b */
static void vecN_greater_than(bool *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > vec_b[i];
}

/** dst = a >= b */
static void vecN_greater_than_equal(bool *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] >= vec_b[i];
}

/** dst = a == b */
static void vecN_equal(bool *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] == vec_b[i];
}

/** dst = a != b */
static void vecN_not_equal(bool *dst_vec, const float *vec_a, const float *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] != vec_b[i];
}

#endif //MATHC_VEC_VECN_H
