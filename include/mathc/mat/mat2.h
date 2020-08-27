#ifndef MATHC_MAT_MAT2_H
#define MATHC_MAT_MAT2_H

#include "matn.h"
#include "../types.h"


/** dst = r==c ? 1 : 0 (identity)  */
static mat2 mat2_eye() {
    mat2 res;
    matN_eye(res.v, 2);
    return res;
}

/** dst = mat[row][:] */
static vec2 mat2_get_row(mat2 mat, int row) {
    vec2 res;
    matN_get_row(res.v, mat.v, row, 2);
    return res;
}

/** dst = mat[:][col] */
static vec2 mat2_get_col(mat2 mat, int col) {
    vec2 res;
    matN_get_col(res.v, mat.v, col, 2);
    return res;
}

/** dst = mat; dst[row][:] = vec */
static mat2 mat2_set_row(mat2 mat, vec2 vec, int row) {
    matN_set_row(mat.v, vec.v, row, 2);
    return mat;
}

/** dst = mat; dst[:][col] = vec */
static mat2 mat2_set_col(mat2 mat, vec2 vec, int col) {
    matN_set_col(mat.v, vec.v, col, 2);
    return mat;
}

/** dst = mat; dst[row][:] = scalar */
static mat2 mat2_row_set_sca(mat2 mat, float scalar, int row) {
    matN_row_set_sca(mat.v, scalar, row, 2);
    return mat;
}

/** dst = mat; dst[:][col] = scalar */
static mat2 mat2_col_set_sca(mat2 mat, float scalar, int col) {
    matN_col_set_sca(mat.v, scalar, col, 2);
    return mat;
}

/** returns sum of diagonal form upper left to lower right */
static float mat2_trace(mat2 mat) {
    return matN_trace(mat.v, 2);
}

/** dst = mat^t */
static mat2 mat2_transpose(mat2 mat) {
    mat2 res;
    matN_transpose_no_alias(res.v, mat.v, 2);
    return res;
}

/** dst = a @ b */
static mat2 mat2_mul_mat(mat2 mat_a, mat2 mat_b) {
    mat2 res;
    matN_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 2);
    return res;
}

/** dst = a @ b */
static vec2 mat2_mul_vec(mat2 mat_a, vec2 vec_b) {
    vec2 res;
    matN_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 2);
    return res;
}

/** dst = a @ b */
static vec2 vec2_mul_mat(vec2 vec_a, mat2 mat_b) {
    vec2 res;
    vecN_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 2);
    return res;
}

/** returns = determinant mat */
static float mat2_det(mat2 mat) {
    // from cglm/mat2.h/glm_mat2_det
    return mat.m[0][0] * mat.m[1][1] - mat.m[1][0] * mat.m[0][1];
}

/** dst = inverted mat */
static mat2 mat2_inv(mat2 mat) {
    // from cglm/mat2.h/glm_mat2_inv
    float a = mat.m[0][0], b = mat.m[0][1];
    float c = mat.m[1][0], d = mat.m[1][1];
    float det = 1.0f / (a * d - b * c);

    mat2 res;
    res.m[0][0] =  d * det;
    res.m[0][1] = -b * det;
    res.m[1][0] = -c * det;
    res.m[1][1] =  a * det;
    return res;
}

#endif //MATHC_MAT_MAT2_H
