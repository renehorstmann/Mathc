#ifndef MATHC_VEC_VECN_H
#define MATHC_VEC_VECN_H

#ifndef MATHC_MAX_SIZE
#ifdef __STDC_NO_VLA__
#define MATHC_MAX_SIZE 16
#endif
#endif

#include <string.h>     // memcmp
#include <stdbool.h>
#include <assert.h>
#include "../sca/float.h"


/** macro to cast a vector into a float vector */
#define vecN_cast_into(dst, from, n) \
do { \
    for(int vecN_cast_into_i_=0; vecN_cast_into_i_<(n); vecN_cast_into_i_++) \
        (dst)[vecN_cast_into_i_] = (float) (from)[vecN_cast_into_i_]; \
} while(0)


/*/ float /*//** dst = v / 255 */
/*/ float /*/static void vecN_cast_from_uchar_1(float *dst, const unsigned char *v, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = (float) v[i] / (float) 255;
/*/ float /*/}


/*/ int /*//** dst = vec * 255 */
/*/ int /*/static void vecN_cast_from_float_1(float *dst_vec, const float *vec, int n) {
/*/ int /*/    for (int i = 0; i < n; i++)
/*/ int /*/        dst_vec[i] = (float) (vec[i] * 255.0f);
/*/ int /*/}

/*/ int /*//** dst = vec * 255 */
/*/ int /*/static void vecN_cast_from_double_1(float *dst_vec, const double *vec, int n) {
/*/ int /*/    for (int i = 0; i < n; i++)
/*/ int /*/        dst_vec[i] = (float) (vec[i] * 255.0);
/*/ int /*/}

/*/ int /*//** dst = vec * 255 */
/*/ int /*/static void vecN_cast_from_longdouble_1(float *dst_vec, const long double *vec, int n) {
/*/ int /*/    for (int i = 0; i < n; i++)
/*/ int /*/        dst_vec[i] = (float) (vec[i] * 255.0);
/*/ int /*/}


/** a == b */
static bool vecN_cmp(const float *a, const float *b, int n) {
    return memcmp(a, b, n * sizeof(float)) == 0;
}

/** dst = v */
static void vecN_copy(float *dst, const float *v, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = v[i];
}

/** dst = s */
static void vecN_set(float *dst, float s, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = s;
}

/*/ signed /*//** dst = -v */
/*/ signed /*/static void vecN_neg(float *dst, const float *v, int n) {
/*/ signed /*/    for (int i = 0; i < n; i++)
/*/ signed /*/        dst[i] = -v[i];
/*/ signed /*/}

/** dst = a + b */
static void vecN_add_vec(float *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] + b[i];
}

/** dst = a + b */
static void vecN_add(float *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] + b;
}

/** dst = a - b */
static void vecN_sub_vec(float *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] - b[i];
}

/** dst = a - b */
static void vecN_sub(float *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] - b;
}

/** dst = a * b */
static void vecN_scale_vec(float *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] * b[i];
}

/** dst = a * b */
static void vecN_scale(float *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] * b;
}

/** dst = a / b */
static void vecN_div_vec(float *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] / b[i];
}

/** dst = a / b */
static void vecN_div(float *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] / b;
}

/*/ float /*//** dst = a * M_PI / 180 */
/*/ float /*/static void vecN_radians(float *dst, const float *deg, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_radians(deg[i]);
/*/ float /*/}

/*/ float /*//** dst = a * 180 / M_PI */
/*/ float /*/static void vecN_degrees(float *dst, const float *rad, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_degrees(rad[i]);
/*/ float /*/}

/*/ float /*//** dst = sin(angle_rad) */
/*/ float /*/static void vecN_sin(float *dst, const float *angle_rad, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_sin(angle_rad[i]);
/*/ float /*/}

/*/ float /*//** dst = cos(angle_rad) */
/*/ float /*/static void vecN_cos(float *dst, const float *angle_rad, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_cos(angle_rad[i]);
/*/ float /*/}

/*/ float /*//** dst = tan(angle_rad) */
/*/ float /*/static void vecN_tan(float *dst, const float *angle_rad, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_tan(angle_rad[i]);
/*/ float /*/}

/*/ float /*//** dst = asin(x) */
/*/ float /*/static void vecN_asin(float *dst, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_asin(x[i]);
/*/ float /*/}

/*/ float /*//** dst = acos(x) */
/*/ float /*/static void vecN_acos(float *dst, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_acos(x[i]);
/*/ float /*/}

/*/ float /*//** dst = atan(x) */
/*/ float /*/static void vecN_atan(float *dst, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_atan(x[i]);
/*/ float /*/}

/*/ float /*//** dst = atan2(y, x) */
/*/ float /*/static void vecN_atan2(float *dst, const float *y, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_atan2(y[i], x[i]);
/*/ float /*/}

/** dst = pow(x, y) */
static void vecN_pow(float *dst, const float *x, float y, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_pow(x[i], y);
}

/** dst = pow(x, y) */
static void vecN_pow_vec(float *dst, const float *x, const float *y, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_pow(x[i], y[i]);
}

/** dst = exp(x) */
static void vecN_exp(float *dst, const float *x, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_exp(x[i]);
}

/** dst = log(x) */
static void vecN_log(float *dst, const float *x, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_log(x[i]);
}

/** dst = exp2(x) */
static void vecN_exp2(float *dst, const float *x, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_exp2(x[i]);
}

/** dst = log2(x) */
static void vecN_log2(float *dst, const float *x, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_log2(x[i]);
}

/** dst = sqrt(x) */
static void vecN_sqrt(float *dst, const float *x, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_sqrt(x[i]);
}

/*/ float /*//** dst = 1 / sqrt(x) */
/*/ float /*/static void vecN_inversesqrt(float *dst, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_inversesqrt(x[i]);
/*/ float /*/}

/*/ signed /*//** dst = abs(x) */
/*/ signed /*/static void vecN_abs(float *dst, const float *x, int n) {
/*/ signed /*/    for (int i = 0; i < n; i++)
/*/ signed /*/        dst[i] = sca_abs(x[i]);
/*/ signed /*/}

/*/ signed /*//** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
/*/ signed /*/static void vecN_sign(float *dst, const float *x, int n) {
/*/ signed /*/    for (int i = 0; i < n; i++)
/*/ signed /*/        dst[i] = sca_sign(x[i]);
/*/ signed /*/}

/*/ float /*//** dst = floor(x) */
/*/ float /*/static void vecN_floor(float *dst, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_floor(x[i]);
/*/ float /*/}

/*/ float /*//** dst = ceil(x) */
/*/ float /*/static void vecN_ceil(float *dst, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_ceil(x[i]);
/*/ float /*/}

/*/ float /*//** dst = x - floor(x) */
/*/ float /*/static void vecN_fract(float *dst, const float *x, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_fract(x[i]);
/*/ float /*/}

/*/ float /*//** dst = x - y * floor(x/y) */
/*/ int /*//** dst = (x % y + y) % y (always positive, if y>0) **/
static void vecN_mod(float *dst, const float *x, float y, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_mod(x[i], y);
}

/*/ float /*//** dst = x - y * floor(x/y) */
/*/ int /*//** dst = (x % y + y) % y (always positive, if y>0) **/
static void vecN_mod_vec(float *dst, const float *x, const float *y, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_mod(x[i], y[i]);
}

/** dst = a < b ? a : b */
static void vecN_min(float *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_min(a[i], b);
}

/** dst = a < b ? a : b */
static void vecN_min_vec(float *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_min(a[i], b[i]);
}

/** dst = a > b ? a : b */
static void vecN_max(float *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_max(a[i], b);
}

/** dst = a > b ? a : b */
static void vecN_max_vec(float *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_max(a[i], b[i]);
}

/** returns the index of the min v value */
static int vecN_min_index(const float *v, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[idx])
            idx = i;
    }
    return idx;
}

/** returns the index of the max v value */
static int vecN_max_index(const float *v, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[idx])
            idx = i;
    }
    return idx;
}

/** dst = x < min ? min : (x > max ? max : x) */
static void vecN_clamp(float *dst, const float *x, float min, float max, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_clamp(x[i], min, max);
}

/** dst = x < min ? min : (x > max ? max : x) */
static void vecN_clamp_vec(float *dst, const float *x, const float *min, const float *max, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_clamp(x[i], min[i], max[i]);
}

/** dst = a * (1-t) + b * t */
static void vecN_mix(float *dst, const float *a, const float *b, float t, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_mix(a[i], b[i], t);
}

/** dst = a * (1-t) + b * t */
static void vecN_mix_vec(float *dst, const float *a, const float *b, const float *t, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_mix(a[i], b[i], t[i]);
}

/** dst = x < edge ? 0 : 1 */
static void vecN_step(float *dst, const float *x, float edge, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_step(x[i], edge);
}

/** dst = x < edge ? 0 : 1 */
static void vecN_step_vec(float *dst, const float *x, const float *edge, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = sca_step(x[i], edge[i]);
}

/*/ float /*//** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
/*/ float /*/static void vecN_smoothstep(float *dst, const float *x, float edge1, float edge2, int n) {
/*/ float /*/    for (int i = 0; i < n; i++) {
/*/ float /*/        dst[i] = sca_smoothstep(x[i], edge1, edge2);
/*/ float /*/    }
/*/ float /*/}

/*/ float /*//** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
/*/ float /*/static void
/*/ float /*/vecN_smoothstep_vec(float *dst, const float *x, const float *edge1, const float *edge2, int n) {
/*/ float /*/    for (int i = 0; i < n; i++) {
/*/ float /*/        dst[i] = sca_smoothstep(x[i], edge1[i], edge2[i]);
/*/ float /*/    }
/*/ float /*/}

/** returns v[0] + v[1] + ... + v[n-1] */
static float vecN_sum(const float *v, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    return sum;
}

/** returns a dot b */
static float vecN_dot(const float *a, const float *b, int n) {
    float dot = 0;
    for (int i = 0; i < n; i++)
        dot += a[i] * b[i];
    return dot;
}

/** assert(n>=3) ; dst = a x b , dst.w... = 0 */
static void vecN_cross(float *dst, const float *a, const float *b, int n) {
    assert(n>=3 && "mathc vec*_cross only in 3D");
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
    for(int i=3; i<n; i++)
        dst[i] = 0;
}

/** returns ||v||_2 */
static float vecN_norm(const float *v, int n) {
    return sca_sqrt(vecN_dot(v, v, n));
}

/*/ signed /*//** returns ||v||_p */
/*/ signed /*/static float vecN_norm_p(const float *v, float p, int n) {
/*/ signed /*/    float sum = 0;
/*/ signed /*/    for (int i = 0; i < n; i++) {
/*/ signed /*/        sum += sca_pow(sca_abs(v[i]), p);
/*/ signed /*/    }
/*/ signed /*/    return sca_pow(sum, (float) 1 / p);
/*/ signed /*/}

/*/ signed /*//** returns ||v||_1 */
/*/ signed /*/static float vecN_norm_1(const float *v, int n) {
/*/ signed /*/    float sum = 0;
/*/ signed /*/    for (int i = 0; i < n; i++) {
/*/ signed /*/        sum += sca_abs(v[i]);
/*/ signed /*/    }
/*/ signed /*/    return sum;
/*/ signed /*/}

/*/ signed /*//** returns ||v||_inf */
/*/ signed /*/static float vecN_norm_inf(const float *v, int n) {
/*/ signed /*/    float max = 0;
/*/ signed /*/    for (int i = 0; i < n; i++) {
/*/ signed /*/        if (max < sca_abs(v[i]))
/*/ signed /*/            max = sca_abs(v[i]);
/*/ signed /*/    }
/*/ signed /*/    return max;
/*/ signed /*/}

/*/ float /*//** dst = v / norm(v) */
/*/ float /*/static void vecN_normalize_unsafe(float *dst, const float *v, int n) {
/*/ float /*/    vecN_scale(dst, v, (float) 1 / vecN_norm(v, n), n);
/*/ float /*/}

/*/ float /*//** dst = v / (norm(v) > 0 ? norm(v) : 1) */
/*/ float /*/static void vecN_normalize(float *dst, const float *v, int n) {
/*/ float /*/    float norm = vecN_norm(v, n);
/*/ float /*/    vecN_scale(dst, v, (float) 1 / (norm > (float) 0 ? norm : (float) 1), n);
/*/ float /*/}

/** returns length of a vector, see vecN_norm. Just here to match glsl */
static float vecN_length(const float *v, int n) {
    return vecN_norm(v, n);
}

/** returns norm(b-a) */
static float vecN_distance(const float *a, const float *b, int n) {
#ifdef MATHC_MAX_SIZE
    assert(n <= MATHC_MAX_SIZE);
    float tmp[MATHC_MAX_SIZE];
#else
    float tmp[n];
#endif
    vecN_sub_vec(tmp, b, a, n);
    return vecN_norm(tmp, n);
}

/** returns dot(b-a) */
static float vecN_sqr_distance(const float *a, const float *b, int n) {
#ifdef MATHC_MAX_SIZE
    assert(n <= MATHC_MAX_SIZE);
    float tmp[MATHC_MAX_SIZE];
#else
    float tmp[n];
#endif
    vecN_sub_vec(tmp, b, a, n);
    return vecN_dot(tmp, tmp, n);
}

/*/ float /*//** dst = dot(i_v, nref_v) < 0 ? n_v : -n_v */
/*/ float /*/static void vecN_faceforward(float *dst, const float *n_v, const float *i_v, const float *nref_v, int n) {
/*/ float /*/    if (vecN_dot(i_v, nref_v, n) < 0)
/*/ float /*/        vecN_copy(dst, n_v, n);
/*/ float /*/    else
/*/ float /*/        vecN_neg(dst, n_v, n);
/*/ float /*/}

/*/ float /*//** dst = i_v - 2.0 * n_v * dot(n_v,i_v) */
/*/ float /*/static void vecN_reflect(float *dst, const float *i_v, const float *n_v, int n) {
/*/ float /*/    vecN_scale(dst, n_v, (float) 2 * vecN_dot(n_v, i_v, n), n);
/*/ float /*/    vecN_sub_vec(dst, i_v, dst, n);
/*/ float /*/}

/*/ float /*/static void vecN_refract(float *dst, const float *i_v, const float *n_v, float eta, int n) {
/*/ float /*/    // implementation from example implementation: https://developer.download.nvidia.com/cg/refract.html
/*/ float /*/    vecN_neg(dst, i_v, n);
/*/ float /*/    float cosi = vecN_dot(dst, n_v, n);
/*/ float /*/    float cost2 = (float) 1 - eta * eta * ((float) 1 - cosi * cosi);
/*/ float /*/    vecN_scale(dst, n_v, eta * cosi - sca_sqrt(sca_abs(cost2)), n);
/*/ float /*/    float t[3];
/*/ float /*/    vecN_scale(t, i_v, eta, n);
/*/ float /*/    vecN_add_vec(t, t, dst, n);
/*/ float /*/    vecN_scale(dst, t, cost2 > (float) 0, n);
/*/ float /*/}

/** dst = a < b */
static void vecN_less_than(bool *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] < b;
}

/** dst = a < b */
static void vecN_less_than_vec(bool *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] < b[i];
}

/** dst = a <= b */
static void vecN_less_than_equal(bool *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] <= b;
}

/** dst = a <= b */
static void vecN_less_than_equal_vec(bool *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] <= b[i];
}

/** dst = a > b */
static void vecN_greater_than(bool *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] > b;
}

/** dst = a > b */
static void vecN_greater_than_vec(bool *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] > b[i];
}

/** dst = a >= b */
static void vecN_greater_than_equal(bool *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] >= b;
}

/** dst = a >= b */
static void vecN_greater_than_equal_vec(bool *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] >= b[i];
}

/** dst = a == b */
static void vecN_equal(bool *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] == b;
}

/** dst = a == b */
static void vecN_equal_vec(bool *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] == b[i];
}

/** dst = a != b */
static void vecN_not_equal(bool *dst, const float *a, float b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] != b;
}

/** dst = a != b */
static void vecN_not_equal_vec(bool *dst, const float *a, const float *b, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = a[i] != b[i];
}

/*/ float /*//** dst = a == b (+-eps) */
/*/ float /*/static void vecN_equal_eps(bool *dst, const float *a, float b, float eps, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_abs(a[i] - b) <= eps;
/*/ float /*/}

/*/ float /*//** dst = a == b (+-eps) */
/*/ float /*/static void vecN_equal_eps_vec(bool *dst, const float *a, const float *b, float eps, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_abs(a[i] - b[i]) <= eps;
/*/ float /*/}

/*/ float /*//** dst = a != b (+-eps) */
/*/ float /*/static void vecN_not_equal_eps(bool *dst, const float *a, float b, float eps, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_abs(a[i] - b) > eps;
/*/ float /*/}

/*/ float /*//** dst = a != b (+-eps) */
/*/ float /*/static void vecN_not_equal_eps_vec(bool *dst, const float *a, const float *b, float eps, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_abs(a[i] - b[i]) > eps;
/*/ float /*/}

/*/ float /*//** dst = isnan(v) */
/*/ float /*/static void vecN_isnan(bool *dst, const float *v, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_isnan(v[i]);
/*/ float /*/}

/*/ float /*//** dst = !isnan(v) */
/*/ float /*/static void vecN_not_isnan(bool *dst, const float *v, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = !sca_isnan(v[i]);
/*/ float /*/}

/*/ float /*//** dst = isinf(v) */
/*/ float /*/static void vecN_isinf(bool *dst, const float *v, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = sca_isinf(v[i]);
/*/ float /*/}

/*/ float /*//** dst = !isinf(v) */
/*/ float /*/static void vecN_not_isinf(bool *dst, const float *v, int n) {
/*/ float /*/    for (int i = 0; i < n; i++)
/*/ float /*/        dst[i] = !sca_isinf(v[i]);
/*/ float /*/}

#endif //MATHC_VEC_VECN_H
