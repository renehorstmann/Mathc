#ifndef MATHC_VEC_TYPED_V_H
#define MATHC_VEC_TYPED_V_H

#include "functions.h"


//
// this header file has the following content:
// 1. typed_v functions for float[2] as vec2f
// 2. typed_v functions for float[3] as vec3f
// 3. typed_v functions for float[4] as vec4f
// 4. typed_v functions for double[2] as vec2d
// 5. typed_v functions for double[3] as vec3d
// 6. typed_v functions for double[4] as vec4d
// 7. typed_v functions for int[2] as vec2i
// 8. typed_v functions for int[3] as vec3i
// 9. typed_v functions for int[4] as vec4i
//


//
// vec2f
//

/** vec<n> dst_i = -vec_i */
static vec2f vec2f_neg_v(const float *vec) {
    vec2f res;
    vecf_neg(res.v, vec, 2);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec2f vec2f_add_vec_v(const float *vec_a, const float *vec_b) {
    vec2f res;
    vecf_add_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec2f vec2f_add_sca_v(const float *vec_a, float scalar_b) {
    vec2f res;
    vecf_add_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec2f vec2f_sub_vec_v(const float *vec_a, const float *vec_b) {
    vec2f res;
    vecf_sub_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec2f vec2f_sub_sca_v(const float *vec_a, float scalar_b) {
    vec2f res;
    vecf_sub_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec2f vec2f_scale_vec_v(const float *vec_a, const float *vec_b) {
    vec2f res;
    vecf_scale_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec2f vec2f_scale_sca_v(const float *vec_a, float scalar_b) {
    vec2f res;
    vecf_scale_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec2f vec2f_div_vec_v(const float *vec_a, const float *vec_b) {
    vec2f res;
    vecf_div_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec2f vec2f_div_sca_v(const float *vec_a, float scalar_b) {
    vec2f res;
    vecf_div_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec2f_sum_v(const float *vec) {
    return vecf_sum(vec, 2);
}

/** returns vec<n> dot vec<n> */
static float vec2f_dot_v(const float *vec_a, const float *vec_b) {
    return vecf_dot(vec_a, vec_b, 2);
}

/** returns norm2 of a float vector */
static float vec2f_norm_v(const float *vec) {
    return vecf_norm(vec, 2);
}

/** dst = vec / norm(vec) */
static vec2f vec2f_normalize_unsafe_v(const float *vec) {
    vec2f res;
    vecf_normalize_unsafe(res.v, vec, 2);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec2f vec2f_normalize_v(const float *vec) {
    vec2f res;
    vecf_normalize(res.v, vec, 2);
    return res;
}

//
// vec3f
//

/** vec<n> dst_i = -vec_i */
static vec3f vec3f_neg_v(const float *vec) {
    vec3f res;
    vecf_neg(res.v, vec, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3f vec3f_add_vec_v(const float *vec_a, const float *vec_b) {
    vec3f res;
    vecf_add_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3f vec3f_add_sca_v(const float *vec_a, float scalar_b) {
    vec3f res;
    vecf_add_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3f vec3f_sub_vec_v(const float *vec_a, const float *vec_b) {
    vec3f res;
    vecf_sub_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3f vec3f_sub_sca_v(const float *vec_a, float scalar_b) {
    vec3f res;
    vecf_sub_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3f vec3f_scale_vec_v(const float *vec_a, const float *vec_b) {
    vec3f res;
    vecf_scale_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3f vec3f_scale_sca_v(const float *vec_a, float scalar_b) {
    vec3f res;
    vecf_scale_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec3f vec3f_div_vec_v(const float *vec_a, const float *vec_b) {
    vec3f res;
    vecf_div_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec3f vec3f_div_sca_v(const float *vec_a, float scalar_b) {
    vec3f res;
    vecf_div_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec3f_sum_v(const float *vec) {
    return vecf_sum(vec, 3);
}

/** returns vec<n> dot vec<n> */
static float vec3f_dot_v(const float *vec_a, const float *vec_b) {
    return vecf_dot(vec_a, vec_b, 3);
}

/** vec3f dst = a cross b */
static vec3f vec3f_cross_v(const float *vec_a, const float *vec_b) {
    vec3f res;
    vecf_cross(res.v, vec_a, vec_b, 3);
    return res;
}

/** returns norm2 of a float vector */
static float vec3f_norm_v(const float *vec) {
    return vecf_norm(vec, 3);
}

/** dst = vec / norm(vec) */
static vec3f vec3f_normalize_unsafe_v(const float *vec) {
    vec3f res;
    vecf_normalize_unsafe(res.v, vec, 3);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3f vec3f_normalize_v(const float *vec) {
    vec3f res;
    vecf_normalize(res.v, vec, 3);
    return res;
}



//
// vec4f
//

/** vec<n> dst_i = -vec_i */
static vec4f vec4f_neg_v(const float *vec) {
    vec4f res;
    vecf_neg(res.v, vec, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4f vec4f_add_vec_v(const float *vec_a, const float *vec_b) {
    vec4f res;
    vecf_add_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4f vec4f_add_sca_v(const float *vec_a, float scalar_b) {
    vec4f res;
    vecf_add_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4f vec4f_sub_vec_v(const float *vec_a, const float *vec_b) {
    vec4f res;
    vecf_sub_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4f vec4f_sub_sca_v(const float *vec_a, float scalar_b) {
    vec4f res;
    vecf_sub_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4f vec4f_scale_vec_v(const float *vec_a, const float *vec_b) {
    vec4f res;
    vecf_scale_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4f vec4f_scale_sca_v(const float *vec_a, float scalar_b) {
    vec4f res;
    vecf_scale_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec4f vec4f_div_vec_v(const float *vec_a, const float *vec_b) {
    vec4f res;
    vecf_div_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec4f vec4f_div_sca_v(const float *vec_a, float scalar_b) {
    vec4f res;
    vecf_div_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static float vec4f_sum_v(const float *vec) {
    return vecf_sum(vec, 4);
}

/** returns vec<n> dot vec<n> */
static float vec4f_dot_v(const float *vec_a, const float *vec_b) {
    return vecf_dot(vec_a, vec_b, 4);
}

/** vec4f dst = a cross b */
static vec4f vec4f_cross_v(const float *vec_a, const float *vec_b) {
    vec4f res;
    vecf_cross(res.v, vec_a, vec_b, 4);
    return res;
}

/** returns norm2 of a float vector */
static float vec4f_norm_v(const float *vec) {
    return vecf_norm(vec, 4);
}

/** dst = vec / norm(vec) */
static vec4f vec4f_normalize_unsafe_v(const float *vec) {
    vec4f res;
    vecf_normalize_unsafe(res.v, vec, 4);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4f vec4f_normalize_v(const float *vec) {
    vec4f res;
    vecf_normalize(res.v, vec, 4);
    return res;
}


//
// vec2d
//

/** vec<n> dst_i = -vec_i */
static vec2d vec2d_neg_v(const double *vec) {
    vec2d res;
    vecd_neg(res.v, vec, 2);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec2d vec2d_add_vec_v(const double *vec_a, const double *vec_b) {
    vec2d res;
    vecd_add_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec2d vec2d_add_sca_v(const double *vec_a, double scalar_b) {
    vec2d res;
    vecd_add_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec2d vec2d_sub_vec_v(const double *vec_a, const double *vec_b) {
    vec2d res;
    vecd_sub_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec2d vec2d_sub_sca_v(const double *vec_a, double scalar_b) {
    vec2d res;
    vecd_sub_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec2d vec2d_scale_vec_v(const double *vec_a, const double *vec_b) {
    vec2d res;
    vecd_scale_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec2d vec2d_scale_sca_v(const double *vec_a, double scalar_b) {
    vec2d res;
    vecd_scale_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec2d vec2d_div_vec_v(const double *vec_a, const double *vec_b) {
    vec2d res;
    vecd_div_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec2d vec2d_div_sca_v(const double *vec_a, double scalar_b) {
    vec2d res;
    vecd_div_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double vec2d_sum_v(const double *vec) {
    return vecd_sum(vec, 2);
}

/** returns vec<n> dot vec<n> */
static double vec2d_dot_v(const double *vec_a, const double *vec_b) {
    return vecd_dot(vec_a, vec_b, 2);
}

/** returns norm2 of a double vector */
static double vec2d_norm_v(const double *vec) {
    return vecd_norm(vec, 2);
}

/** dst = vec / norm(vec) */
static vec2d vec2d_normalize_unsafe_v(const double *vec) {
    vec2d res;
    vecd_normalize_unsafe(res.v, vec, 2);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec2d vec2d_normalize_v(const double *vec) {
    vec2d res;
    vecd_normalize(res.v, vec, 2);
    return res;
}


//
// vec3d
//

/** vec<n> dst_i = -vec_i */
static vec3d vec3d_neg_v(const double *vec) {
    vec3d res;
    vecd_neg(res.v, vec, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3d vec3d_add_vec_v(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_add_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3d vec3d_add_sca_v(const double *vec_a, double scalar_b) {
    vec3d res;
    vecd_add_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3d vec3d_sub_vec_v(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_sub_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3d vec3d_sub_sca_v(const double *vec_a, double scalar_b) {
    vec3d res;
    vecd_sub_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3d vec3d_scale_vec_v(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_scale_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3d vec3d_scale_sca_v(const double *vec_a, double scalar_b) {
    vec3d res;
    vecd_scale_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec3d vec3d_div_vec_v(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_div_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec3d vec3d_div_sca_v(const double *vec_a, double scalar_b) {
    vec3d res;
    vecd_div_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double vec3d_sum_v(const double *vec) {
    return vecd_sum(vec, 3);
}

/** returns vec<n> dot vec<n> */
static double vec3d_dot_v(const double *vec_a, const double *vec_b) {
    return vecd_dot(vec_a, vec_b, 3);
}

/** vec3d dst = a cross b */
static vec3d vec3d_cross_v(const double *vec_a, const double *vec_b) {
    vec3d res;
    vecd_cross(res.v, vec_a, vec_b, 3);
    return res;
}

/** returns norm2 of a double vector */
static double vec3d_norm_v(const double *vec) {
    return vecd_norm(vec, 3);
}

/** dst = vec / norm(vec) */
static vec3d vec3d_normalize_unsafe_v(const double *vec) {
    vec3d res;
    vecd_normalize_unsafe(res.v, vec, 3);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec3d vec3d_normalize_v(const double *vec) {
    vec3d res;
    vecd_normalize(res.v, vec, 3);
    return res;
}



//
// vec4d
//

/** vec<n> dst_i = -vec_i */
static vec4d vec4d_neg_v(const double *vec) {
    vec4d res;
    vecd_neg(res.v, vec, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4d vec4d_add_vec_v(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_add_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4d vec4d_add_sca_v(const double *vec_a, double scalar_b) {
    vec4d res;
    vecd_add_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4d vec4d_sub_vec_v(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_sub_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4d vec4d_sub_sca_v(const double *vec_a, double scalar_b) {
    vec4d res;
    vecd_sub_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4d vec4d_scale_vec_v(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_scale_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4d vec4d_scale_sca_v(const double *vec_a, double scalar_b) {
    vec4d res;
    vecd_scale_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec4d vec4d_div_vec_v(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_div_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec4d vec4d_div_sca_v(const double *vec_a, double scalar_b) {
    vec4d res;
    vecd_div_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static double vec4d_sum_v(const double *vec) {
    return vecd_sum(vec, 4);
}

/** returns vec<n> dot vec<n> */
static double vec4d_dot_v(const double *vec_a, const double *vec_b) {
    return vecd_dot(vec_a, vec_b, 4);
}

/** vec4d dst = a cross b */
static vec4d vec4d_cross_v(const double *vec_a, const double *vec_b) {
    vec4d res;
    vecd_cross(res.v, vec_a, vec_b, 4);
    return res;
}

/** returns norm2 of a double vector */
static double vec4d_norm_v(const double *vec) {
    return vecd_norm(vec, 4);
}

/** dst = vec / norm(vec) */
static vec4d vec4d_normalize_unsafe_v(const double *vec) {
    vec4d res;
    vecd_normalize_unsafe(res.v, vec, 4);
    return res;
}

/** dst = vec / (norm(vec) > 0 ? norm(vec) : 1) */
static vec4d vec4d_normalize_v(const double *vec) {
    vec4d res;
    vecd_normalize(res.v, vec, 4);
    return res;
}


//
// vec2i
//

/** vec<n> dst_i = -vec_i */
static vec2i vec2i_neg_v(const int *vec) {
    vec2i res;
    veci_neg(res.v, vec, 2);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec2i vec2i_add_vec_v(const int *vec_a, const int *vec_b) {
    vec2i res;
    veci_add_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec2i vec2i_add_sca_v(const int *vec_a, int scalar_b) {
    vec2i res;
    veci_add_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec2i vec2i_sub_vec_v(const int *vec_a, const int *vec_b) {
    vec2i res;
    veci_sub_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec2i vec2i_sub_sca_v(const int *vec_a, int scalar_b) {
    vec2i res;
    veci_sub_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec2i vec2i_scale_vec_v(const int *vec_a, const int *vec_b) {
    vec2i res;
    veci_scale_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec2i vec2i_scale_sca_v(const int *vec_a, int scalar_b) {
    vec2i res;
    veci_scale_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec2i vec2i_div_vec_v(const int *vec_a, const int *vec_b) {
    vec2i res;
    veci_div_vec(res.v, vec_a, vec_b, 2);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec2i vec2i_div_sca_v(const int *vec_a, int scalar_b) {
    vec2i res;
    veci_div_sca(res.v, vec_a, scalar_b, 2);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int vec2i_sum_v(const int *vec) {
    return veci_sum(vec, 2);
}

/** returns vec<n> dot vec<n> */
static int vec2i_dot_v(const int *vec_a, const int *vec_b) {
    return veci_dot(vec_a, vec_b, 2);
}

/** returns norm2 of a int vector */
static double vec2i_norm_v(const int *vec) {
    return veci_norm(vec, 2);
}


//
// vec3i
//

/** vec<n> dst_i = -vec_i */
static vec3i vec3i_neg_v(const int *vec) {
    vec3i res;
    veci_neg(res.v, vec, 3);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec3i vec3i_add_vec_v(const int *vec_a, const int *vec_b) {
    vec3i res;
    veci_add_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec3i vec3i_add_sca_v(const int *vec_a, int scalar_b) {
    vec3i res;
    veci_add_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3i vec3i_sub_vec_v(const int *vec_a, const int *vec_b) {
    vec3i res;
    veci_sub_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec3i vec3i_sub_sca_v(const int *vec_a, int scalar_b) {
    vec3i res;
    veci_sub_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec3i vec3i_scale_vec_v(const int *vec_a, const int *vec_b) {
    vec3i res;
    veci_scale_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec3i vec3i_scale_sca_v(const int *vec_a, int scalar_b) {
    vec3i res;
    veci_scale_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec3i vec3i_div_vec_v(const int *vec_a, const int *vec_b) {
    vec3i res;
    veci_div_vec(res.v, vec_a, vec_b, 3);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec3i vec3i_div_sca_v(const int *vec_a, int scalar_b) {
    vec3i res;
    veci_div_sca(res.v, vec_a, scalar_b, 3);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int vec3i_sum_v(const int *vec) {
    return veci_sum(vec, 3);
}

/** returns vec<n> dot vec<n> */
static int vec3i_dot_v(const int *vec_a, const int *vec_b) {
    return veci_dot(vec_a, vec_b, 3);
}

/** vec3i dst = a cross b */
static vec3i vec3i_cross_v(const int *vec_a, const int *vec_b) {
    vec3i res;
    veci_cross(res.v, vec_a, vec_b, 3);
    return res;
}

/** returns norm2 of a int vector */
static double vec3i_norm_v(const int *vec) {
    return veci_norm(vec, 3);
}



//
// vec4i
//

/** vec<n> dst_i = -vec_i */
static vec4i vec4i_neg_v(const int *vec) {
    vec4i res;
    veci_neg(res.v, vec, 4);
    return res;
}

/** vec<n> dst_i = a_i + b_i */
static vec4i vec4i_add_vec_v(const int *vec_a, const int *vec_b) {
    vec4i res;
    veci_add_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i + b */
static vec4i vec4i_add_sca_v(const int *vec_a, int scalar_b) {
    vec4i res;
    veci_add_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4i vec4i_sub_vec_v(const int *vec_a, const int *vec_b) {
    vec4i res;
    veci_sub_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> dst_i = a_i - b_i */
static vec4i vec4i_sub_sca_v(const int *vec_a, int scalar_b) {
    vec4i res;
    veci_sub_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i * b_i */
static vec4i vec4i_scale_vec_v(const int *vec_a, const int *vec_b) {
    vec4i res;
    veci_scale_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i * b */
static vec4i vec4i_scale_sca_v(const int *vec_a, int scalar_b) {
    vec4i res;
    veci_scale_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** vec<n> dst_i = a_i / b_i */
static vec4i vec4i_div_vec_v(const int *vec_a, const int *vec_b) {
    vec4i res;
    veci_div_vec(res.v, vec_a, vec_b, 4);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec4i vec4i_div_sca_v(const int *vec_a, int scalar_b) {
    vec4i res;
    veci_div_sca(res.v, vec_a, scalar_b, 4);
    return res;
}

/** returns vec[0] + vec[1] + ... + vec[n-1] */
static int vec4i_sum_v(const int *vec) {
    return veci_sum(vec, 4);
}

/** returns vec<n> dot vec<n> */
static int vec4i_dot_v(const int *vec_a, const int *vec_b) {
    return veci_dot(vec_a, vec_b, 4);
}

/** vec4i dst = a cross b */
static vec4i vec4i_cross_v(const int *vec_a, const int *vec_b) {
    vec4i res;
    veci_cross(res.v, vec_a, vec_b, 4);
    return res;
}

/** returns norm2 of a int vector */
static double vec4i_norm_v(const int *vec) {
    return veci_norm(vec, 4);
}


#endif //MATHC_VEC_TYPED_V_H
