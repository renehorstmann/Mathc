#ifndef MATHC_MAT_MAT3_H
#define MATHC_MAT_MAT3_H

#include "matn.h"
#include "../types.h"
#include "../vec/vec3.h"


/** dst = r==c ? 1 : 0 (identity)  */
static mat3 mat3_eye() {
    mat3 res;
    matN_eye(res.v, 3);
    return res;
}

/** dst = mat[row][:] */
static vec3 mat3_get_row(mat3 mat, int row) {
    vec3 res;
    matN_get_row(res.v, mat.v, row, 3);
    return res;
}

/** dst = mat[:][col] */
static vec3 mat3_get_col(mat3 mat, int col) {
    vec3 res;
    matN_get_col(res.v, mat.v, col, 3);
    return res;
}

/** dst = mat; dst[row][:] = vec */
static mat3 mat3_set_row(mat3 mat, vec3 vec, int row) {
    matN_set_row(mat.v, vec.v, row, 3);
    return mat;
}

/** dst = mat; dst[:][col] = vec */
static mat3 mat3_set_col(mat3 mat, vec3 vec, int col) {
    matN_set_col(mat.v, vec.v, col, 3);
    return mat;
}

/** dst = mat; dst[row][:] = scalar */
static mat3 mat3_row_set_sca(mat3 mat, float scalar, int row) {
    matN_row_set_sca(mat.v, scalar, row, 3);
    return mat;
}

/** dst = mat; dst[:][col] = scalar */
static mat3 mat3_col_set_sca(mat3 mat, float scalar, int col) {
    matN_col_set_sca(mat.v, scalar, col, 3);
    return mat;
}

/** returns sum of diagonal form upper left to lower right */
static float mat3_trace(mat3 mat) {
    return matN_trace(mat.v, 3);
}

/** dst = mat^t */
static mat3 mat3_transpose(mat3 mat) {
    mat3 res;
    matN_transpose_no_alias(res.v, mat.v, 3);
    return res;
}

/** dst = a @ b */
static mat3 mat3_mul_mat(mat3 mat_a, mat3 mat_b) {
    mat3 res;
    matN_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 3);
    return res;
}

/** dst = a @ b */
static vec3 mat3_mul_vec(mat3 mat_a, vec3 vec_b) {
    vec3 res;
    matN_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 3);
    return res;
}

/** dst = a @ b */
static vec3 vec3_mul_mat(vec3 vec_a, mat3 mat_b) {
    vec3 res;
    vecN_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 3);
    return res;
}

/** returns = determinant mat */
static float mat3_det(mat3 mat) {
    // from cglm/mat3.h/glm_mat3_det
    float a = mat.m[0][0], b = mat.m[0][1], c = mat.m[0][2];
    float d = mat.m[1][0], e = mat.m[1][1], f = mat.m[1][2];
    float g = mat.m[2][0], h = mat.m[2][1], i = mat.m[2][2];

    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
}

/** dst = inverted mat */
static mat3 mat3_inv(mat3 mat) {
    // from cglm/mat3.h/glm_mat3_inv
    float a = mat.m[0][0], b = mat.m[0][1];
    float c = mat.m[1][0], d = mat.m[1][1];
    float det = 1.0f / (a * d - b * c);

    mat3 res;
    res.m[0][0] =  d * det;
    res.m[0][1] = -b * det;
    res.m[1][0] = -c * det;
    res.m[1][1] =  a * det;
    return res;
}

/** dst = mat[col:col+2, row:row+2] */
static mat2 mat3_get_block2(mat3 mat, int row, int col) {
    mat2 res;
    matN_get_block(res.v, mat.v, row, col, 2, 3);
    return res;
}

/** dst = mat; dst[col:col+2, row:row+2] = block */
static mat3 mat3_set_block2(mat3 mat, mat2 block, int row, int col) {
    matN_set_block(mat.v, block.v, row, col, 2, 3);
    return mat;
}

/** dst = mat[:2, :2] */
static mat2 mat3_get_upper_left(mat3 mat) {
    return mat3_get_block2(mat, 0, 0);
}

/** dst = mat; dst[:2, :2] = block */
static mat3 mat3_set_upper_left(mat3 mat, mat2 block) {
    return mat3_set_block2(mat, block, 0, 0);
}

/** angle_axis as xyz = axis and w = angle [rad] */
static mat3 mat3_rotation_from_angle_axis(vec4 angle_axis) {
    // from cglm/affine/glm_rotate_make
    float c = cosf(angle_axis.w);
    float s = sinf(angle_axis.w);

    vec3 axis = vec3_normalize(angle_axis.xyz);
    vec3 v = vec3_scale_sca(axis, 1.0f - c);
    vec3 vs = vec3_scale_sca(axis, s);

    mat3 res;
    res.col[0] = vec3_scale_sca(axis, v.x);
    res.col[1] = vec3_scale_sca(axis, v.y);
    res.col[2] = vec3_scale_sca(axis, v.z);

    res.m[0][0] += c;      res.m[1][0] -= vs.z;   res.m[2][0] += vs.y;
    res.m[0][1] += vs.z;   res.m[1][1] += c;      res.m[2][1] -= vs.x;
    res.m[0][2] -= vs.y;   res.m[1][2] += vs.x;   res.m[2][2] += c;
    return res;
}

#endif //MATHC_MAT_MAT3_H
