#ifndef MATHC_MAT_MAT3_V_H
#define MATHC_MAT_MAT3_V_H

#include "mat3.h"


/** dst = mat[row][:] */
static vec3 mat3_get_row_v(const float *mat, int row) {
    vec3 res;
    matN_get_row(res.v, mat, row, 3);
    return res;
}

/** dst = mat[:][col] */
static vec3 mat3_get_col_v(const float *mat, int col) {
    vec3 res;
    matN_get_col(res.v, mat, col, 3);
    return res;
}

/** dst = mat; dst[row][:] = vec */
static mat3 mat3_set_row_v(const float *mat, const float *vec, int row) {
    mat3 dst = Mat3(mat);
    matN_set_row(dst.v, vec, row, 3);
    return dst;
}

/** dst = mat; dst[:][col] = vec */
static mat3 mat3_set_col_v(const float *mat, const float *vec, int col) {
    mat3 dst = Mat3(mat);
    matN_set_col(dst.v, vec, col, 3);
    return dst;
}

/** dst = mat; dst[row][:] = scalar */
static mat3 mat3_row_set_sca_v(const float *mat, float scalar, int row) {
    mat3 dst = Mat3(mat);
    matN_row_set_sca(dst.v, scalar, row, 3);
    return dst;
}

/** dst = mat; dst[:][col] = scalar */
static mat3 mat3_col_set_sca_v(const float *mat, float scalar, int col) {
    mat3 dst = Mat3(mat);
    matN_col_set_sca(dst.v, scalar, col, 3);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static float mat3_trace_v(const float *mat) {
    return matN_trace(mat, 3);
}

/** dst = mat^t */
static mat3 mat3_transpose_v(const float *mat) {
    mat3 res;
    matN_transpose_no_alias(res.v, mat, 3);
    return res;
}

/** dst = a @ b */
static mat3 mat3_mul_mat_v(const float *mat_a, const float *mat_b) {
    mat3 res;
    matN_mul_mat_no_alias(res.v, mat_a, mat_b, 3);
    return res;
}

/** dst = a @ b */
static vec3 mat3_mul_vec_v(const float *mat_a, const float *vec_b) {
    vec3 res;
    matN_mul_vec_no_alias(res.v, mat_a, vec_b, 3);
    return res;
}

/** dst = a @ b */
static vec3 vec3_mul_mat_v(const float *vec_a, const float *mat_b) {
    vec3 res;
    vecN_mul_mat_no_alias(res.v, vec_a, mat_b, 3);
    return res;
}

/** returns = determinant mat */
static float mat3_det_v(const float *mat) {
    return mat3_det(Mat3(mat));
}

/** dst = inverted mat */
static mat3 mat3_inv_v(const float *mat) {
    return mat3_inv(Mat3(mat));
}

/** dst = mat[col:col+2, row:row+2] */
static mat2 mat3_get_block2_v(const float *mat, int row, int col) {
    mat2 res;
    matN_get_block(res.v, mat, row, col, 2, 3);
    return res;
}

/** dst = mat; dst[col:col+2, row:row+2] = block */
static mat3 mat3_set_block2_v(const float *mat, const float *block, int row, int col) {
    mat3 dst = Mat3(mat);
    matN_set_block(dst.v, block, row, col, 2, 3);
    return dst;
}

/** dst = mat[:2, :2] */
static mat2 mat3_get_upper_left_v(const float *mat) {
    return mat3_get_block2_v(mat, 0, 0);
}

/** dst = mat; dst[:2, :2] = block */
static mat3 mat3_set_upper_left_v(const float *mat, const float *block) {
    return mat3_set_block2_v(mat, block, 0, 0);
}

/** angle_axis as xyz = axis and w = angle [rad] */
static mat3 mat3_rotation_from_angle_axis_v(const float *angle_axis) {
    return mat3_rotation_from_angle_axis(Vec4(angle_axis));
}

#endif //MATHC_MAT_MAT3_V_H
