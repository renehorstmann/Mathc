#ifndef MATHC_MAT_MAT2_V_H
#define MATHC_MAT_MAT2_V_H

#include "mat2.h"


/** dst = mat[row][:] */
static vec2 mat2_get_row_v(const float *mat, int row) {
    vec2 res;
    matN_get_row(res.v, mat, row, 2);
    return res;
}

/** dst = mat[:][col] */
static vec2 mat2_get_col_v(const float *mat, int col) {
    vec2 res;
    matN_get_col(res.v, mat, col, 2);
    return res;
}

/** dst = mat; dst[row][:] = vec */
static mat2 mat2_set_row_v(const float *mat, const float *vec, int row) {
    mat2 dst = Mat2(mat);
    matN_set_row(dst.v, vec, row, 2);
    return dst;
}

/** dst = mat; dst[:][col] = vec */
static mat2 mat2_set_col_v(const float *mat, const float *vec, int col) {
    mat2 dst = Mat2(mat);
    matN_set_col(dst.v, vec, col, 2);
    return dst;
}

/** dst = mat; dst[row][:] = scalar */
static mat2 mat2_row_set_sca_v(const float *mat, float scalar, int row) {
    mat2 dst = Mat2(mat);
    matN_row_set_sca(dst.v, scalar, row, 2);
    return dst;
}

/** dst = mat; dst[:][col] = scalar */
static mat2 mat2_col_set_sca_v(const float *mat, float scalar, int col) {
    mat2 dst = Mat2(mat);
    matN_col_set_sca(dst.v, scalar, col, 2);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static float mat2_trace_v(const float *mat) {
    return matN_trace(mat, 2);
}

/** dst = mat^t */
static mat2 mat2_transpose_v(const float *mat) {
    mat2 res;
    matN_transpose_no_alias(res.v, mat, 2);
    return res;
}

/** dst = a @ b */
static mat2 mat2_mul_mat_v(const float *mat_a, const float *mat_b) {
    mat2 res;
    matN_mul_mat_no_alias(res.v, mat_a, mat_b, 2);
    return res;
}

/** dst = a @ b */
static vec2 mat2_mul_vec_v(const float *mat_a, const float *vec_b) {
    vec2 res;
    matN_mul_vec_no_alias(res.v, mat_a, vec_b, 2);
    return res;
}

/** dst = a @ b */
static vec2 vec2_mul_mat_v(const float *vec_a, const float *mat_b) {
    vec2 res;
    vecN_mul_mat_no_alias(res.v, vec_a, mat_b, 2);
    return res;
}

/** returns = determinant mat */
static float mat2_det_v(const float *mat) {
    return mat2_det(Mat2(mat));
}

/** dst = inverted mat */
static mat2 mat2_inv_v(const float *mat) {
    return mat2_inv(Mat2(mat));
}

#endif //MATHC_MAT_MAT2_V_H
