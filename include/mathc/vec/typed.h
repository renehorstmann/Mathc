#ifndef MATHC_VEC_TYPED_H
#define MATHC_VEC_TYPED_H

#include "../types.h"
#include "functions.h"


//
// this header file has the following content:
// 1. typed functions for float[3] as vec3f
// 2. typed functions for float[4] as vec4f
// 3. typed functions for double[3] as vec3d
// 4. typed functions for double[4] as vec4d
// 5. typed functions for int[3] as vec3i
// 6. typed functions for int[4] as vec4i
//


//
// vec3f
//

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

/** vec<n> dst_i = a_i - b_i */
static vec3f vec3f_sub_sca(vec3f vec_a, float scalar_b) {
    vec3f res;
    vecf_sub_sca(res.v, vec_a.v, scalar_b, 3);
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

/** vec<n> dst_i = a_i / b_i */
static vec3f vec3f_div_vec(vec3f vec_a, vec3f vec_b) {
    vec3f res;
    vecf_div_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec3f vec3f_div_sca(vec3f vec_a, float scalar_b) {
    vec3f res;
    vecf_div_sca(res.v, vec_a.v, scalar_b, 3);
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

/** vec<n> dst_i = a_i - b_i */
static vec4f vec4f_sub_sca(vec4f vec_a, float scalar_b) {
    vec4f res;
    vecf_sub_sca(res.v, vec_a.v, scalar_b, 4);
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

/** vec<n> dst_i = a_i / b_i */
static vec4f vec4f_div_vec(vec4f vec_a, vec4f vec_b) {
    vec4f res;
    vecf_div_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec4f vec4f_div_sca(vec4f vec_a, float scalar_b) {
    vec4f res;
    vecf_div_sca(res.v, vec_a.v, scalar_b, 4);
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

/** vec<n> dst_i = a_i - b_i */
static vec3d vec3d_sub_sca(vec3d vec_a, double scalar_b) {
    vec3d res;
    vecd_sub_sca(res.v, vec_a.v, scalar_b, 3);
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

/** vec<n> dst_i = a_i / b_i */
static vec3d vec3d_div_vec(vec3d vec_a, vec3d vec_b) {
    vec3d res;
    vecd_div_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec3d vec3d_div_sca(vec3d vec_a, double scalar_b) {
    vec3d res;
    vecd_div_sca(res.v, vec_a.v, scalar_b, 3);
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

/** vec<n> dst_i = a_i - b_i */
static vec4d vec4d_sub_sca(vec4d vec_a, double scalar_b) {
    vec4d res;
    vecd_sub_sca(res.v, vec_a.v, scalar_b, 4);
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

/** vec<n> dst_i = a_i / b_i */
static vec4d vec4d_div_vec(vec4d vec_a, vec4d vec_b) {
    vec4d res;
    vecd_div_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec4d vec4d_div_sca(vec4d vec_a, double scalar_b) {
    vec4d res;
    vecd_div_sca(res.v, vec_a.v, scalar_b, 4);
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

/** vec<n> dst_i = a_i - b_i */
static vec3i vec3i_sub_sca(vec3i vec_a, int scalar_b) {
    vec3i res;
    veci_sub_sca(res.v, vec_a.v, scalar_b, 3);
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

/** vec<n> dst_i = a_i / b_i */
static vec3i vec3i_div_vec(vec3i vec_a, vec3i vec_b) {
    vec3i res;
    veci_div_vec(res.v, vec_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec3i vec3i_div_sca(vec3i vec_a, int scalar_b) {
    vec3i res;
    veci_div_sca(res.v, vec_a.v, scalar_b, 3);
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

/** vec<n> dst_i = a_i - b_i */
static vec4i vec4i_sub_sca(vec4i vec_a, int scalar_b) {
    vec4i res;
    veci_sub_sca(res.v, vec_a.v, scalar_b, 4);
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

/** vec<n> dst_i = a_i / b_i */
static vec4i vec4i_div_vec(vec4i vec_a, vec4i vec_b) {
    vec4i res;
    veci_div_vec(res.v, vec_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> res_i = a_i / b */
static vec4i vec4i_div_sca(vec4i vec_a, int scalar_b) {
    vec4i res;
    veci_div_sca(res.v, vec_a.v, scalar_b, 4);
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



#endif //MATHC_VEC_TYPED_H
