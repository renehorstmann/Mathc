#ifndef MATHC_MAT_MAT4_V_H
#define MATHC_MAT_MAT4_V_H

#include "mat4.h"


/** dst = mat[row][:] */
static vec4 mat4_get_row_v(const float *mat, int row) {
    vec4 res;
    matN_get_row(res.v, mat, row, 4);
    return res;
}

/** dst = mat[:][col] */
static vec4 mat4_get_col_v(const float *mat, int col) {
    vec4 res;
    matN_get_col(res.v, mat, col, 4);
    return res;
}

/** dst = mat; dst[row][:] = vec */
static mat4 mat4_set_row_v(const float *mat, const float *vec, int row) {
    mat4 dst = Mat4(mat);
    matN_set_row(dst.v, vec, row, 4);
    return dst;
}

/** dst = mat; dst[:][col] = vec */
static mat4 mat4_set_col_v(const float *mat, const float *vec, int col) {
    mat4 dst = Mat4(mat);
    matN_set_col(dst.v, vec, col, 4);
    return dst;
}

/** dst = mat; dst[row][:] = scalar */
static mat4 mat4_row_set_sca_v(const float *mat, float scalar, int row) {
    mat4 dst = Mat4(mat);
    matN_row_set_sca(dst.v, scalar, row, 4);
    return dst;
}

/** dst = mat; dst[:][col] = scalar */
static mat4 mat4_col_set_sca_v(const float *mat, float scalar, int col) {
    mat4 dst = Mat4(mat);
    matN_col_set_sca(dst.v, scalar, col, 4);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static float mat4_trace_v(const float *mat) {
    return matN_trace(mat, 4);
}

/** dst = mat^t */
static mat4 mat4_transpose_v(const float *mat) {
    mat4 res;
    matN_transpose_no_alias(res.v, mat, 4);
    return res;
}

/** dst = a @ b */
static mat4 mat4_mul_mat_v(const float *mat_a, const float *mat_b) {
    mat4 res;
    matN_mul_mat_no_alias(res.v, mat_a, mat_b, 4);
    return res;
}

/** dst = a @ b */
static vec4 mat4_mul_vec_v(const float *mat_a, const float *vec_b) {
    vec4 res;
    matN_mul_vec_no_alias(res.v, mat_a, vec_b, 4);
    return res;
}

/** dst = a @ b */
static vec4 vec4_mul_mat_v(const float *vec_a, const float *mat_b) {
    vec4 res;
    vecN_mul_mat_no_alias(res.v, vec_a, mat_b, 4);
    return res;
}

/** returns = determinant mat */
static float mat4_det_v(const float *mat) {
    return mat4_det(Mat4(mat));
}

/** dst = inverted mat */
static mat4 mat4_inv_v(const float *mat) {
    return mat4_inv(Mat4(mat));
}


/** dst = mat[col:col+2, row:row+2] */
static mat2 mat4_get_block2_v(const float *mat, int row, int col) {
    mat2 res;
    matN_get_block(res.v, mat, row, col, 2, 4);
    return res;
}

/** dst = mat; dst[col:col+2, row:row+2] = block */
static mat4 mat4_set_block2_v(const float *mat, const float *block, int row, int col) {
    mat4 dst = Mat4(mat);
    matN_set_block(dst.v, block, row, col, 2, 4);
    return dst;
}

/** dst = mat[col:col+2, row:row+2] */
static mat3 mat4_get_block3_v(const float *mat, int row, int col) {
    mat3 res;
    matN_get_block(res.v, mat, row, col, 3, 4);
    return res;
}

/** dst = mat; dst[col:col+2, row:row+2] = block */
static mat4 mat4_set_block3_v(const float *mat, const float *block, int row, int col) {
    mat4 dst = Mat4(mat);
    matN_set_block(dst.v, block, row, col, 3, 4);
    return dst;
}

/** dst = mat[:2, :2] */
static mat2 mat4_get_upper_left2_v(const float *mat) {
    return mat4_get_block2_v(mat, 0, 0);
}

/** dst = mat; dst[:2, :2] = block */
static mat4 mat4_set_upper_left2_v(const float *mat, const float *block) {
    return mat4_set_block2_v(mat, block, 0, 0);
}

/** dst = mat[:3, :3] */
static mat3 mat4_get_upper_left3_v(const float *mat) {
    return mat4_get_block3_v(mat, 0, 0);
}

/** dst = mat; dst[:3, :3] = block */
static mat4 mat4_set_upper_left3_v(const float *mat, const float *block) {
    return mat4_set_block3_v(mat, block, 0, 0);
}

#endif //MATHC_MAT_MAT4_V_H
