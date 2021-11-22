#ifndef MATHC_VEC_<{VEC}>N_H
#define MATHC_VEC_<{VEC}>N_H

#ifndef MATHC_MAX_SIZE
#ifdef __STDC_NO_VLA__
#define MATHC_MAX_SIZE 16
#endif
#endif

#include <string.h>     // memcmp
#include <stdbool.h>
#include <math.h>
#include <assert.h>


/** macro to cast a vector into a <{float}> vector */
#define <{vec}>N_cast_into(dst_vec, vec, n) \
do { \
    for(int <{vec}>N_cast_into_i_=0; <{vec}>N_cast_into_i_<(n); <{vec}>N_cast_into_i_++) \
        (dst_vec)[<{vec}>N_cast_into_i_] = (<{float}>) (vec)[<{vec}>N_cast_into_i_]; \
} while(0)


<% if real -%>
/** dst = vec / 255 */
static void <{vec}>N_cast_from_uchar_1(<{float}> *dst_vec, const unsigned char *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = (<{float}>) vec[i] / 255<{dotzero}>;
}
<% endif %>


/** vec_a == vec_b */
static bool <{vec}>N_cmp(const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    return memcmp(vec_a, vec_b, n * sizeof(<{float}>)) == 0;
}

/** dst = vec */
static void <{vec}>N_copy(<{float}> *dst_vec, const <{float}> *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec[i];
}

/** dst = scalar */
static void <{vec}>N_set(<{float}> *dst_vec, <{float}> scalar, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = scalar;
}

<% if not unsigned -%>
/** dst = -vec */
static void <{vec}>N_neg(<{float}> *dst_vec, const <{float}> *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = -vec[i];
}
<% endif -%>

/** dst = a + b */
static void <{vec}>N_add_vec(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + vec_b[i];
}

/** dst = a + b */
static void <{vec}>N_add(<{float}> *dst_vec, const <{float}> *vec_a, <{float}> scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] + scalar_b;
}

/** dst = a - b */
static void <{vec}>N_sub_vec(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - vec_b[i];
}

/** dst = a - b */
static void <{vec}>N_sub(<{float}> *dst_vec, const <{float}> *vec_a, <{float}> scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] - scalar_b;
}

/** dst = a * b */
static void <{vec}>N_scale_vec(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * vec_b[i];
}

/** dst = a * b */
static void <{vec}>N_scale(<{float}> *dst_vec, const <{float}> *vec_a, <{float}> scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * scalar_b;
}

/** dst = a / b */
static void <{vec}>N_div_vec(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / vec_b[i];
}

/** dst = a / b */
static void <{vec}>N_div(<{float}> *dst_vec, const <{float}> *vec_a, <{float}> scalar_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] / scalar_b;
}


/** dst = pow(x, y) */
static void <{vec}>N_pow(<{float}> *dst_vec, const <{float}> *vec_x, <{float}> y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{powf}>(vec_x[i], y);
}

/** dst = pow(x, y) */
static void <{vec}>N_pow_vec(<{float}> *dst_vec, const <{float}> *vec_x, const <{float}> *vec_y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{powf}>(vec_x[i], vec_y[i]);
}

<% if not unsigned -%>
/** dst = abs(x) */
static void <{vec}>N_abs(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{fabsf}>(vec_x[i]);
}
<% endif -%>

<% if not unsigned -%>
/** dst = x > 0 ? 1 : (x < 0 ? -1 : 0) */
static void <{vec}>N_sign(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] > 0<{dotzero}> ? 1<{dotzero}> : (vec_x[i] < 0<{dotzero}> ? -1<{dotzero}> : 0.0);
}
<% endif -%>

<% if real -%>
/** dst = x - y * floor(x/y) */
static void <{vec}>N_mod(<{float}> *dst_vec, const <{float}> *vec_x, <{float}> y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] - y * <{floorf}>(vec_x[i] / y);
}
<% else %>
/** dst = x % y */
static void <{vec}>N_mod(<{float}> *dst_vec, const <{float}> *vec_x, <{float}> y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] % y;
}
<% endif %>

<% if real -%>
/** dst = x - y * floor(x/y) */
static void <{vec}>N_mod_vec(<{float}> *dst_vec, const <{float}> *vec_x, const <{float}> *vec_y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] - vec_y[i] * <{floorf}>(vec_x[i] / vec_y[i]);
}
<% else %>
/** dst = x % y  */
static void <{vec}>N_mod_vec(<{float}> *dst_vec, const <{float}> *vec_x, const <{float}> *vec_y, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] % vec_y[i];
}
<% endif %>

/** dst = a < b ? a : b */
static void <{vec}>N_min(<{float}> *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < b ? vec_a[i] : b;
}

/** dst = a < b ? a : b */
static void <{vec}>N_min_vec(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
}

/** dst = a > b ? a : b */
static void <{vec}>N_max(<{float}> *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > b ? vec_a[i] : b;
}

/** dst = a > b ? a : b */
static void <{vec}>N_max_vec(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > vec_b[i] ? vec_a[i] : vec_b[i];
}

/** returns the index of the min vec value */
static int <{vec}>N_min_index(const <{float}> *vec, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i] < vec[idx])
            idx = i;
    }
    return idx;
}

/** returns the index of the max vec value */
static int <{vec}>N_max_index(const <{float}> *vec, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i] > vec[idx])
            idx = i;
    }
    return idx;
}

/** dst = x < min ? min : (x > max ? max : x) */
static void <{vec}>N_clamp(<{float}> *dst_vec, const <{float}> *vec_x, <{float}> min, <{float}> max, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < min ? min : (vec_x[i] > max ? max : vec_x[i]);
}

/** dst = x < min ? min : (x > max ? max : x) */
static void <{vec}>N_clamp_vec(<{float}> *dst_vec, const <{float}> *vec_x, const <{float}> *vec_min, const <{float}> *vec_max, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < vec_min[i] ? vec_min[i] : (vec_x[i] > vec_max[i] ? vec_max[i] : vec_x[i]);
}

/** dst = x < edge ? 0 : 1 */
static void <{vec}>N_step(<{float}> *dst_vec, const <{float}> *vec_x, <{float}> edge, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < edge ? 0<{dotzero}> : 1<{dotzero}>;
}

/** dst = x < edge ? 0 : 1 */
static void <{vec}>N_step_vec(<{float}> *dst_vec, const <{float}> *vec_x, const <{float}> *vec_edge, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] < vec_edge[i] ? 0<{dotzero}> : 1<{dotzero}>;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static <{float}> <{vec}>N_sum(const <{float}> *vec, int n) {
    <{float}> sum = 0;
    for (int i = 0; i < n; i++)
        sum += vec[i];
    return sum;
}

/** returns a dot b */
static <{float}> <{vec}>N_dot(const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    <{float}> dot = 0;
    for (int i = 0; i < n; i++)
        dot += vec_a[i] * vec_b[i];
    return dot;
}

/** returns ||vec||_1 */
static <{float}> <{vec}>N_norm_1(const <{float}> *vec, int n) {
    <{float}> sum = 0;
    for (int i = 0; i < n; i++) {
        sum += <{fabsf}>(vec[i]);
    }
    return sum;
}

/** returns ||vec||_inf */
static <{float}> <{vec}>N_norm_inf(const <{float}> *vec, int n) {
    <{float}> max = 0;
    for (int i = 0; i < n; i++) {
        if (max < <{fabsf}>(vec[i]))
            max = <{fabsf}>(vec[i]);
    }
    return max;
}

<# -#>
<# -#>
<# only for real types -#>
<# -#>
<# -#>

<% if real -%>
/** dst = a * M_PI / 180 */
static void <{vec}>N_radians(<{float}> *dst_vec, const <{float}> *vec_deg, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_deg[i] * (<{float}>) M_PI / 180<{dotzero}>;
}

/** dst = a * 180 / M_PI */
static void <{vec}>N_degrees(<{float}> *dst_vec, const <{float}> *vec_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_rad[i] * 180<{dotzero}> / (<{float}>) M_PI;
}

/** dst = sin(angle_rad) */
static void <{vec}>N_sin(<{float}> *dst_vec, const <{float}> *vec_angle_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{sinf}>(vec_angle_rad[i]);
}

/** dst = cos(angle_rad) */
static void <{vec}>N_cos(<{float}> *dst_vec, const <{float}> *vec_angle_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{cosf}>(vec_angle_rad[i]);
}

/** dst = tan(angle_rad) */
static void <{vec}>N_tan(<{float}> *dst_vec, const <{float}> *vec_angle_rad, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{tanf}>(vec_angle_rad[i]);
}

/** dst = asin(x) */
static void <{vec}>N_asin(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{asinf}>(vec_x[i]);
}

/** dst = acos(x) */
static void <{vec}>N_acos(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{acosf}>(vec_x[i]);
}

/** dst = atan(x) */
static void <{vec}>N_atan(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{atanf}>(vec_x[i]);
}

/** dst = atan2(y, x) */
static void <{vec}>N_atan2(<{float}> *dst_vec, const <{float}> *vec_y, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{atan2f}>(vec_y[i], vec_x[i]);
}

/** dst = exp(x) */
static void <{vec}>N_exp(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{expf}>(vec_x[i]);
}

/** dst = log(x) */
static void <{vec}>N_log(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{logf}>(vec_x[i]);
}

/** dst = exp2(x) */
static void <{vec}>N_exp2(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{exp2f}>(vec_x[i]);
}

/** dst = log2(x) */
static void <{vec}>N_log2(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{log2f}>(vec_x[i]);
}

/** dst = sqrt(x) */
static void <{vec}>N_sqrt(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{sqrtf}>(vec_x[i]);
}

/** dst = 1 / sqrt(x) */
static void <{vec}>N_inversesqrt(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = 1<{dotzero}> / <{sqrtf}>(vec_x[i]);
}

/** dst = floor(x) */
static void <{vec}>N_floor(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{floorf}>(vec_x[i]);
}

/** dst = ceil(x) */
static void <{vec}>N_ceil(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{ceilf}>(vec_x[i]);
}

/** dst = x - floor(x) */
static void <{vec}>N_fract(<{float}> *dst_vec, const <{float}> *vec_x, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_x[i] - <{floorf}>(vec_x[i]);
}

/** dst = a * (1-t) + b * t */
static void <{vec}>N_mix(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, <{float}> t, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * (1<{dotzero}> - t) + vec_b[i] * t;
}

/** dst = a * (1-t) + b * t */
static void <{vec}>N_mix_vec(<{float}> *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, const <{float}> *vec_t, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] * (1<{dotzero}> - vec_t[i]) + vec_b[i] * vec_t[i];
}

/** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
static void <{vec}>N_smoothstep(<{float}> *dst_vec, const <{float}> *vec_x, <{float}> edge1, <{float}> edge2, int n) {
    for (int i = 0; i < n; i++) {
        <{float}> x = vec_x[i];
        dst_vec[i] = x < edge1 ? 0<{dotzero}> : (x > edge2 ? 1<{dotzero}> : x * x * (3<{dotzero}> - 2<{dotzero}> * x));
    }
}

/** dst = x < edge1 ? 0 : (x > edge2 ? 1 : x * x * (3 - 2 * x)) Hermite polynomials */
static void
<{vec}>N_smoothstep_vec(<{float}> *dst_vec, const <{float}> *vec_x, const <{float}> *vec_edge1, const <{float}> *vec_edge2, int n) {
    for (int i = 0; i < n; i++) {
        <{float}> x = vec_x[i];
        dst_vec[i] = x < vec_edge1[i] ? 0<{dotzero}> : (x > vec_edge2[i] ? 1<{dotzero}> : x * x * (3<{dotzero}> - 2<{dotzero}> * x));
    }
}

/** returns ||vec||_2 */
static <{float}> <{vec}>N_norm(const <{float}> *vec, int n) {
    return <{sqrtf}>(<{vec}>N_dot(vec, vec, n));
}

/** returns ||vec||_p */
static <{float}> <{vec}>N_norm_p(const <{float}> *vec, <{float}> p, int n) {
    <{float}> sum = 0;
    for (int i = 0; i < n; i++) {
        sum += <{powf}>(<{fabsf}>(vec[i]), p);
    }
    return <{powf}>(sum, 1<{dotzero}> / p);
}

/** dst = vec / norm(vec) */
static void <{vec}>N_normalize_unsafe(<{float}> *dst_vec, const <{float}> *vec, int n) {
    <{vec}>N_scale(dst_vec, vec, 1<{dotzero}> / <{vec}>N_norm(vec, n), n);
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static void <{vec}>N_normalize(<{float}> *dst_vec, const <{float}> *vec, int n) {
    <{float}> norm = <{vec}>N_norm(vec, n);
    <{vec}>N_scale(dst_vec, vec, 1<{dotzero}> / (norm > 0<{dotzero}> ? norm : 1.0), n);
}

/** returns length of a vector, see <{vec}>N_norm. Just here to match glsl */
static <{float}> <{vec}>N_length(const <{float}> *vec, int n) {
    return <{vec}>N_norm(vec, n);
}

/** returns norm(b-a) */
static <{float}> <{vec}>N_distance(const <{float}> *vec_a, const <{float}> *vec_b, int n) {
#ifdef MATHC_MAX_SIZE
    assert(n <= MATHC_MAX_SIZE);
    <{float}> tmp[MATHC_MAX_SIZE];
#else
    <{float}> tmp[n];
#endif
    <{vec}>N_sub_vec(tmp, vec_b, vec_a, n);
    return <{vec}>N_norm(tmp, n);
}

/** dst = dot(I, Nref) < 0 ? N : -N */
static void <{vec}>N_faceforward(<{float}> *dst_vec, const <{float}> *vec_N, const <{float}> *vec_I, const <{float}> *vec_Nref, int n) {
    if (<{vec}>N_dot(vec_I, vec_Nref, n) < 0)
        <{vec}>N_copy(dst_vec, vec_N, n);
    else
        <{vec}>N_neg(dst_vec, vec_N, n);
}

/** dst = I - 2.0 * N * dot(N,I) */
static void <{vec}>N_reflect(<{float}> *dst_vec, const <{float}> *vec_I, const <{float}> *vec_N, int n) {
    <{vec}>N_scale(dst_vec, vec_N, 2<{dotzero}> * <{vec}>N_dot(vec_N, vec_I, n), n);
    <{vec}>N_sub_vec(dst_vec, vec_I, dst_vec, n);
}

static void <{vec}>N_refract(<{float}> *dst_vec, const <{float}> *vec_I, const <{float}> *vec_N, <{float}> eta, int n) {
    // implementation from example implementation: https://developer.download.nvidia.com/cg/refract.html
    <{vec}>N_neg(dst_vec, vec_I, n);
    <{float}> cosi = <{vec}>N_dot(dst_vec, vec_N, n);
    <{float}> cost2 = 1<{dotzero}> - eta * eta * (1<{dotzero}> - cosi * cosi);
    <{vec}>N_scale(dst_vec, vec_N, eta * cosi - <{sqrtf}>(<{fabsf}>(cost2)), n);
    <{float}> t[3];
    <{vec}>N_scale(t, vec_I, eta, n);
    <{vec}>N_add_vec(t, t, dst_vec, n);
    <{vec}>N_scale(dst_vec, t, cost2 > 0.0, n);
}

/** dst = isnan(vec) */
static void <{vec}>N_isnan(bool *dst_vec, const <{float}> *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = isnan(vec[i]);
}

/** dst = isnan(vec) */
static void <{vec}>N_not_isnan(bool *dst_vec, const <{float}> *vec, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = !isnan(vec[i]);
}
<% endif %>

<# -#>
<# -#>
<# end of only for real types -#>
<# -#>
<# -#>

//
// compere to a bool vec
//


/** dst = a < b */
static void <{vec}>N_less_than(bool *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < b;
}

/** dst = a < b */
static void <{vec}>N_less_than_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] < vec_b[i];
}

/** dst = a <= b */
static void <{vec}>N_less_than_equal(bool *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] <= b;
}

/** dst = a <= b */
static void <{vec}>N_less_than_equal_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] <= vec_b[i];
}

/** dst = a > b */
static void <{vec}>N_greater_than(bool *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > b;
}

/** dst = a > b */
static void <{vec}>N_greater_than_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] > vec_b[i];
}

/** dst = a >= b */
static void <{vec}>N_greater_than_equal(bool *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] >= b;
}

/** dst = a >= b */
static void <{vec}>N_greater_than_equal_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] >= vec_b[i];
}

/** dst = a == b */
static void <{vec}>N_equal(bool *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] == b;
}

/** dst = a == b */
static void <{vec}>N_equal_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] == vec_b[i];
}

/** dst = a != b */
static void <{vec}>N_not_equal(bool *dst_vec, const <{float}> *vec_a, <{float}> b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] != b;
}

/** dst = a != b */
static void <{vec}>N_not_equal_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = vec_a[i] != vec_b[i];
}

<# -#>
<# -#>
<# only for real types -#>
<# -#>
<# -#>

<% if real %>
/** dst = a == b (+-eps) */
static void <{vec}>N_equal_eps(bool *dst_vec, const <{float}> *vec_a, <{float}> b, <{float}> eps, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{fabsf}>(vec_a[i] - b) <= eps;
}

/** dst = a == b (+-eps) */
static void <{vec}>N_equal_eps_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, <{float}> eps, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{fabsf}>(vec_a[i] - vec_b[i]) <= eps;
}

/** dst = a != b (+-eps) */
static void <{vec}>N_not_equal_eps(bool *dst_vec, const <{float}> *vec_a, <{float}> b, <{float}> eps, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{fabsf}>(vec_a[i] - b) > eps;
}

/** dst = a != b (+-eps) */
static void <{vec}>N_not_equal_eps_vec(bool *dst_vec, const <{float}> *vec_a, const <{float}> *vec_b, <{float}> eps, int n) {
    for (int i = 0; i < n; i++)
        dst_vec[i] = <{fabsf}>(vec_a[i] - vec_b[i]) > eps;
}
<% endif %>

<# -#>
<# -#>
<# end of only for real types -#>
<# -#>
<# -#>

#endif //MATHC_VEC_<{VEC}>N_H
