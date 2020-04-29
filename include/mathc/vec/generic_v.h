#ifndef MATHC_VEC_GENERIC_V_H
#define MATHC_VEC_GENERIC_V_H

#include "typed_v.h"

//
// this header file has the following content:
// generic macros for each typed_v function: vec3f_add_vec_v and vec4i_add_vec_v can be accessed with vec3_add_vec_v
// generic nested macros for add_v, sub_v, scale_v, div_v
//


//
// vec3
//

/** vec<n> dst_i = -vec_i */
#define vec3_neg_v(vec) _Generic((vec), \
float *: vec3f_neg_v, \
const float *: vec3f_neg_v, \
double *: vec3d_neg_v, \
const double *: vec3d_neg_v, \
int *: vec3i_neg_v, \
const int *: vec3i_neg_v, \
default: "type_error" \
) ((vec))

/** vec<n> dst_i = a_i + b_i */
#define vec3_add_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec3f_add_vec_v, \
const float *: vec3f_add_vec_v, \
double *: vec3d_add_vec_v, \
const double *: vec3d_add_vec_v, \
int *: vec3i_add_vec_v, \
const int *: vec3i_add_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> dst_i = a_i + b */
#define vec3_add_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec3f_add_sca_v, \
const float *: vec3f_add_sca_v, \
double *: vec3d_add_sca_v, \
const double *: vec3d_add_sca_v, \
int *: vec3i_add_sca_v, \
const int *: vec3i_add_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec3_add_vec_v and vec3_add_sca_: vec<n> dst_i = a_i + b */
#define vec3_add_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec3f_add_vec_v, const float *: vec3f_add_vec_v, default: vec3f_add_sca_v), \
const float *: _Generic((b), float *: vec3f_add_vec_v, const float *: vec3f_add_vec_v, default: vec3f_add_sca_v), \
double *: _Generic((b), double *: vec3d_add_vec_v, const double *: vec3d_add_vec_v, default: vec3d_add_sca_v), \
const double *: _Generic((b), double *: vec3d_add_vec_v, const double *: vec3d_add_vec_v, default: vec3d_add_sca_v), \
int *: _Generic((b), int *: vec3i_add_vec_v, const int *: vec3i_add_vec_v, default: vec3i_add_sca_v), \
const int *: _Generic((b), int *: vec3i_add_vec_v, const int *: vec3i_add_vec_v, default: vec3i_add_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** vec<n> dst_i = a_i - b_i */
#define vec3_sub_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec3f_sub_vec_v, \
const float *: vec3f_sub_vec_v, \
double *: vec3d_sub_vec_v, \
const double *: vec3d_sub_vec_v, \
int *: vec3i_sub_vec_v, \
const int *: vec3i_sub_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> dst_i = a_i - b_i */
#define vec3_sub_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec3f_sub_sca_v, \
const float *: vec3f_sub_sca_v, \
double *: vec3d_sub_sca_v, \
const double *: vec3d_sub_sca_v, \
int *: vec3i_sub_sca_v, \
const int *: vec3i_sub_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec3_sub_vec_v and vec3_sub_sca_v: vec<n> dst_i = a_i - b */
#define vec3_sub_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec3f_sub_vec_v, const float *: vec3f_sub_vec_v, default: vec3f_sub_sca_v), \
const float *: _Generic((b), float *: vec3f_sub_vec_v, const float *: vec3f_sub_vec_v, default: vec3f_sub_sca_v), \
double *: _Generic((b), double *: vec3d_sub_vec_v, const double *: vec3d_sub_vec_v, default: vec3d_sub_sca_v), \
const double *: _Generic((b), double *: vec3d_sub_vec_v, const double *: vec3d_sub_vec_v, default: vec3d_sub_sca_v), \
int *: _Generic((b), int *: vec3i_sub_vec_v, const int *: vec3i_sub_vec_v, default: vec3i_sub_sca_v), \
const int *: _Generic((b), int *: vec3i_sub_vec_v, const int *: vec3i_sub_vec_v, default: vec3i_sub_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** vec<n> dst_i = a_i * b_i */
#define vec3_scale_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec3f_scale_vec_v, \
const float *: vec3f_scale_vec_v, \
double *: vec3d_scale_vec_v, \
const double *: vec3d_scale_vec_v, \
int *: vec3i_scale_vec_v, \
const int *: vec3i_scale_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> res_i = a_i * b */
#define vec3_scale_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec3f_scale_sca_v, \
const float *: vec3f_scale_sca_v, \
double *: vec3d_scale_sca_v, \
const double *: vec3d_scale_sca_v, \
int *: vec3i_scale_sca_v, \
const int *: vec3i_scale_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec3_scale_vec_v and vec3_scale_sca_v: vec<n> dst_i = a_i * b */
#define vec3_scale_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec3f_scale_vec_v, const float *: vec3f_scale_vec_v, default: vec3f_scale_sca_v), \
const float *: _Generic((b), float *: vec3f_scale_vec_v, const float *: vec3f_scale_vec_v, default: vec3f_scale_sca_v), \
double *: _Generic((b), double *: vec3d_scale_vec_v, const double *: vec3d_scale_vec_v, default: vec3d_scale_sca_v), \
const double *: _Generic((b), double *: vec3d_scale_vec_v, const double *: vec3d_scale_vec_v, default: vec3d_scale_sca_v), \
int *: _Generic((b), int *: vec3i_scale_vec_v, const int *: vec3i_scale_vec_v, default: vec3i_scale_sca_v), \
const int *: _Generic((b), int *: vec3i_scale_vec_v, const int *: vec3i_scale_vec_v, default: vec3i_scale_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** vec<n> dst_i = a_i / b_i */
#define vec3_div_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec3f_div_vec_v, \
const float *: vec3f_div_vec_v, \
double *: vec3d_div_vec_v, \
const double *: vec3d_div_vec_v, \
int *: vec3i_div_vec_v, \
const int *: vec3i_div_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> res_i = a_i / b */
#define vec3_div_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec3f_div_sca_v, \
const float *: vec3f_div_sca_v, \
double *: vec3d_div_sca_v, \
const double *: vec3d_div_sca_v, \
int *: vec3i_div_sca_v, \
const int *: vec3i_div_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec3_div_vec_v and vec3_div_sca_v: vec<n> dst_i = a_i / b */
#define vec3_div_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec3f_div_vec_v, const float *: vec3f_div_vec_v, default: vec3f_div_sca_v), \
const float *: _Generic((b), float *: vec3f_div_vec_v, const float *: vec3f_div_vec_v, default: vec3f_div_sca_v), \
double *: _Generic((b), double *: vec3d_div_vec_v, const double *: vec3d_div_vec_v, default: vec3d_div_sca_v), \
const double *: _Generic((b), double *: vec3d_div_vec_v, const double *: vec3d_div_vec_v, default: vec3d_div_sca_v), \
int *: _Generic((b), int *: vec3i_div_vec_v, const int *: vec3i_div_vec_v, default: vec3i_div_sca_v), \
const int *: _Generic((b), int *: vec3i_div_vec_v, const int *: vec3i_div_vec_v, default: vec3i_div_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** returns vec[0] + vec[1] + ... + vec[n-1] */
#define vec3_sum_v(vec) _Generic((vec), \
float *: vec3f_sum_v, \
const float *: vec3f_sum_v, \
double *: vec3d_sum_v, \
const double *: vec3d_sum_v, \
int *: vec3i_sum_v, \
const int *: vec3i_sum_v, \
default: "type_error" \
) ((vec))

/** returns vec<n> dot vec<n> */
#define vec3_dot_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec3f_dot_v, \
const float *: vec3f_dot_v, \
double *: vec3d_dot_v, \
const double *: vec3d_dot_v, \
int *: vec3i_dot_v, \
const int *: vec3i_dot_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec3f dst = a cross b */
#define vec3_cross_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec3f_cross_v, \
const float *: vec3f_cross_v, \
double *: vec3d_cross_v, \
const double *: vec3d_cross_v, \
int *: vec3i_cross_v, \
const int *: vec3i_cross_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** returns norm2 of a float vector */
#define vec3_norm_v(vec) _Generic((vec), \
float *: vec3f_norm_v, \
const float *: vec3f_norm_v, \
double *: vec3d_norm_v, \
const double *: vec3d_norm_v, \
int *: vec3i_norm_v, \
const int *: vec3i_norm_v, \
default: "type_error" \
) ((vec))

/** dst = vec / norm(vec) */
#define vec3_normalize_unsafe_v(vec) _Generic((vec), \
float *: vec3f_normalize_unsafe_v, \
const float *: vec3f_normalize_unsafe_v, \
double *: vec3d_normalize_unsafe_v, \
const double *: vec3d_normalize_unsafe_v, \
default: "type_error" \
) ((vec))

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
#define vec3_normalize_v(vec) _Generic((vec), \
float *: vec3f_normalize_v, \
const float *: vec3f_normalize_v, \
double *: vec3d_normalize_v, \
const double *: vec3d_normalize_v, \
default: "type_error" \
) ((vec))




//
// vec4
//

/** vec<n> dst_i = -vec_i */
#define vec4_neg_v(vec) _Generic((vec), \
float *: vec4f_neg_v, \
const float *: vec4f_neg_v, \
double *: vec4d_neg_v, \
const double *: vec4d_neg_v, \
int *: vec4i_neg_v, \
const int *: vec4i_neg_v, \
default: "type_error" \
) ((vec))

/** vec<n> dst_i = a_i + b_i */
#define vec4_add_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec4f_add_vec_v, \
const float *: vec4f_add_vec_v, \
double *: vec4d_add_vec_v, \
const double *: vec4d_add_vec_v, \
int *: vec4i_add_vec_v, \
const int *: vec4i_add_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> dst_i = a_i + b */
#define vec4_add_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec4f_add_sca_v, \
const float *: vec4f_add_sca_v, \
double *: vec4d_add_sca_v, \
const double *: vec4d_add_sca_v, \
int *: vec4i_add_sca_v, \
const int *: vec4i_add_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec4_add_vec_v and vec4_add_sca_: vec<n> dst_i = a_i + b */
#define vec4_add_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec4f_add_vec_v, const float *: vec4f_add_vec_v default: vec4f_add_sca_v), \
const float *: _Generic((b), float *: vec4f_add_vec_v, const float *: vec4f_add_vec_v default: vec4f_add_sca_v), \
double *: _Generic((b), double *: vec4d_add_vec_v, const double *: vec4d_add_vec_v default: vec4d_add_sca_v), \
const double *: _Generic((b), double *: vec4d_add_vec_v, const double *: vec4d_add_vec_v default: vec4d_add_sca_v), \
int *: _Generic((b), int *: vec4i_add_vec_v, const int *: vec4i_add_vec_v default: vec4i_add_sca_v), \
const int *: _Generic((b), int *: vec4i_add_vec_v, const int *: vec4i_add_vec_v default: vec4i_add_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** vec<n> dst_i = a_i - b_i */
#define vec4_sub_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec4f_sub_vec_v, \
const float *: vec4f_sub_vec_v, \
double *: vec4d_sub_vec_v, \
const double *: vec4d_sub_vec_v, \
int *: vec4i_sub_vec_v, \
const int *: vec4i_sub_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> dst_i = a_i - b_i */
#define vec4_sub_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec4f_sub_sca_v, \
const float *: vec4f_sub_sca_v, \
double *: vec4d_sub_sca_v, \
const double *: vec4d_sub_sca_v, \
int *: vec4i_sub_sca_v, \
const int *: vec4i_sub_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec4_sub_vec_v and vec4_sub_sca_v: vec<n> dst_i = a_i - b */
#define vec4_sub_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec4f_sub_vec_v, const float *: vec4f_sub_vec_v, default: vec4f_sub_sca_v), \
const float *: _Generic((b), float *: vec4f_sub_vec_v, const float *: vec4f_sub_vec_v, default: vec4f_sub_sca_v), \
double *: _Generic((b), double *: vec4d_sub_vec_v, const double *: vec4d_sub_vec_v, default: vec4d_sub_sca_v), \
const double *: _Generic((b), double *: vec4d_sub_vec_v, const double *: vec4d_sub_vec_v, default: vec4d_sub_sca_v), \
int *: _Generic((b), int *: vec4i_sub_vec_v, const int *: vec4i_sub_vec_v, default: vec4i_sub_sca_v), \
const int *: _Generic((b), int *: vec4i_sub_vec_v, const int *: vec4i_sub_vec_v, default: vec4i_sub_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** vec<n> dst_i = a_i * b_i */
#define vec4_scale_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec4f_scale_vec_v, \
const float *: vec4f_scale_vec_v, \
double *: vec4d_scale_vec_v, \
const double *: vec4d_scale_vec_v, \
int *: vec4i_scale_vec_v, \
const int *: vec4i_scale_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> res_i = a_i * b */
#define vec4_scale_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec4f_scale_sca_v, \
const float *: vec4f_scale_sca_v, \
double *: vec4d_scale_sca_v, \
const double *: vec4d_scale_sca_v, \
int *: vec4i_scale_sca_v, \
const int *: vec4i_scale_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec4_scale_vec_v and vec4_scale_sca_v: vec<n> dst_i = a_i * b */
#define vec4_scale_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec4f_scale_vec_v, const float *: vec4f_scale_vec_v, default: vec4f_scale_sca_v), \
const float *: _Generic((b), float *: vec4f_scale_vec_v, const float *: vec4f_scale_vec_v, default: vec4f_scale_sca_v), \
double *: _Generic((b), double *: vec4d_scale_vec_v, const double *: vec4d_scale_vec_v, default: vec4d_scale_sca_v), \
const double *: _Generic((b), double *: vec4d_scale_vec_v, const double *: vec4d_scale_vec_v, default: vec4d_scale_sca_v), \
int *: _Generic((b), int *: vec4i_scale_vec_v, const int *: vec4i_scale_vec_v, default: vec4i_scale_sca_v), \
const int *: _Generic((b), int *: vec4i_scale_vec_v, const int *: vec4i_scale_vec_v, default: vec4i_scale_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** vec<n> dst_i = a_i / b_i */
#define vec4_div_vec_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec4f_div_vec_v, \
const float *: vec4f_div_vec_v, \
double *: vec4d_div_vec_v, \
const double *: vec4d_div_vec_v, \
int *: vec4i_div_vec_v, \
const int *: vec4i_div_vec_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec<n> res_i = a_i / b */
#define vec4_div_sca_v(vec_a, scalar_b) _Generic((vec_a), \
float *: vec4f_div_sca_v, \
const float *: vec4f_div_sca_v, \
double *: vec4d_div_sca_v, \
const double *: vec4d_div_sca_v, \
int *: vec4i_div_sca_v, \
const int *: vec4i_div_sca_v, \
default: "type_error" \
) ((vec_a), (scalar_b))

/** nested generic for both vec4_div_vec_v and vec4_div_sca_v: vec<n> dst_i = a_i / b */
#define vec4_div_v(vec_a, b) _Generic((vec_a), \
float *: _Generic((b), float *: vec4f_div_vec_v, const float *: vec4f_div_vec_v, default: vec4f_div_sca_v), \
const float *: _Generic((b), float *: vec4f_div_vec_v, const float *: vec4f_div_vec_v, default: vec4f_div_sca_v), \
double *: _Generic((b), double *: vec4d_div_vec_v, const double *: vec4d_div_vec_v, default: vec4d_div_sca_v), \
const double *: _Generic((b), double *: vec4d_div_vec_v, const double *: vec4d_div_vec_v, default: vec4d_div_sca_v), \
int *: _Generic((b), int *: vec4i_div_vec_v, const int *: vec4i_div_vec_v, default: vec4i_div_sca_v), \
const int *: _Generic((b), int *: vec4i_div_vec_v, const int *: vec4i_div_vec_v, default: vec4i_div_sca_v), \
default: "type_error"\
) ((vec_a), (b))

/** returns vec[0] + vec[1] + ... + vec[n-1] */
#define vec4_sum_v(vec) _Generic((vec), \
float *: vec4f_sum_v, \
const float *: vec4f_sum_v, \
double *: vec4d_sum_v, \
const double *: vec4d_sum_v, \
int *: vec4i_sum_v, \
const int *: vec4i_sum_v, \
default: "type_error" \
) ((vec))

/** returns vec<n> dot vec<n> */
#define vec4_dot_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec4f_dot_v, \
const float *: vec4f_dot_v, \
double *: vec4d_dot_v, \
const double *: vec4d_dot_v, \
int *: vec4i_dot_v, \
const int *: vec4i_dot_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** vec4f dst = a cross b */
#define vec4_cross_v(vec_a, vec_b) _Generic((vec_a), \
float *: vec4f_cross_v, \
const float *: vec4f_cross_v, \
double *: vec4d_cross_v, \
const double *: vec4d_cross_v, \
int *: vec4i_cross_v, \
const int *: vec4i_cross_v, \
default: "type_error" \
) ((vec_a), (vec_b))

/** returns norm2 of a float vector */
#define vec4_norm_v(vec) _Generic((vec), \
float *: vec4f_norm_v, \
const float *: vec4f_norm_v, \
double *: vec4d_norm_v, \
const double *: vec4d_norm_v, \
int *: vec4i_norm_v, \
const int *: vec4i_norm_v, \
default: "type_error" \
) ((vec))

/** dst = vec / norm(vec) */
#define vec4_normalize_unsafe_v(vec) _Generic((vec), \
float *: vec4f_normalize_unsafe_v, \
const float *: vec4f_normalize_unsafe_v, \
double *: vec4d_normalize_unsafe_v, \
const double *: vec4d_normalize_unsafe_v, \
default: "type_error" \
) ((vec))

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
#define vec4_normalize_v(vec) _Generic((vec), \
float *: vec4f_normalize_v, \
const float *: vec4f_normalize_v, \
double *: vec4d_normalize_v, \
const double *: vec4d_normalize_v, \
default: "type_error" \
) ((vec))



#endif //MATHC_VEC_GENERIC_V_H
