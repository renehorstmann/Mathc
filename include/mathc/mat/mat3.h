#ifndef MATHC_MAT_MAT3_H
#define MATHC_MAT_MAT3_H

#include "matn.h"
#include "../types/types.h"
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
/** dst = mat[row][:] */
static vec3 mat3_get_row_v(const float *mat, int row) {
    return mat3_get_row(Mat3(mat), row);
}


/** dst = mat[:][col] */
static vec3 mat3_get_col(mat3 mat, int col) {
    vec3 res;
    matN_get_col(res.v, mat.v, col, 3);
    return res;
}
/** dst = mat[:][col] */
static vec3 mat3_get_col_v(const float *mat, int col) {
    return mat3_get_col(Mat3(mat), col);
}


/** dst = mat; dst[row][:] = vec */
static mat3 mat3_set_row(mat3 mat, vec3 vec, int row) {
    matN_set_row(mat.v, vec.v, row, 3);
    return mat;
}
/** dst = mat; dst[row][:] = vec */
static mat3 mat3_set_row_v(const float *mat, const float *vec, int row) {
    return mat3_set_row(Mat3(mat), Vec3(vec), row);
}


/** dst = mat; dst[:][col] = vec */
static mat3 mat3_set_col(mat3 mat, vec3 vec, int col) {
    matN_set_col(mat.v, vec.v, col, 3);
    return mat;
}
/** dst = mat; dst[:][col] = vec */
static mat3 mat3_set_col_v(const float *mat, const float *vec, int col) {
    return mat3_set_col(Mat3(mat), Vec3(vec), col);
}


/** dst = mat; dst[row][:] = scalar */
static mat3 mat3_row_set_sca(mat3 mat, float scalar, int row) {
    matN_row_set_sca(mat.v, scalar, row, 3);
    return mat;
}
/** dst = mat; dst[row][:] = scalar */
static mat3 mat3_row_set_sca_v(const float *mat, float scalar, int row) {
    return mat3_row_set_sca(Mat3(mat), scalar, row);
}


/** dst = mat; dst[:][col] = scalar */
static mat3 mat3_col_set_sca(mat3 mat, float scalar, int col) {
    matN_col_set_sca(mat.v, scalar, col, 3);
    return mat;
}
/** dst = mat; dst[:][col] = scalar */
static mat3 mat3_col_set_sca_v(const float *mat, float scalar, int col) {
    return mat3_col_set_sca(Mat3(mat), scalar, col);
}


/** returns sum of diagonal form upper left to lower right */
static float mat3_trace(mat3 mat) {
    return matN_trace(mat.v, 3);
}
/** returns sum of diagonal form upper left to lower right */
static float mat3_trace_v(const float *mat) {
    return mat3_trace(Mat3(mat));
}


/** dst = mat^t */
static mat3 mat3_transpose(mat3 mat) {
    mat3 res;
    matN_transpose_no_alias(res.v, mat.v, 3);
    return res;
}
/** dst = mat^t */
static mat3 mat3_transpose_v(const float *mat) {
    return mat3_transpose(Mat3(mat));
}


/** dst = a @ b */
static mat3 mat3_mul_mat(mat3 mat_a, mat3 mat_b) {
    mat3 res;
    matN_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 3);
    return res;
}
/** dst = a @ b */
static mat3 mat3_mul_mat_v(const float *mat_a, const float *mat_b) {
    return mat3_mul_mat(Mat3(mat_a), Mat3(mat_b));
}


/** dst = a @ b */
static vec3 mat3_mul_vec(mat3 mat_a, vec3 vec_b) {
    vec3 res;
    matN_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 3);
    return res;
}
/** dst = a @ b */
static vec3 mat3_mul_vec_v(const float *mat_a, const float *vec_b) {
    return mat3_mul_vec(Mat3(mat_a), Vec3(vec_b));
}


/** dst = a @ b */
static vec3 vec3_mul_mat(vec3 vec_a, mat3 mat_b) {
    vec3 res;
    vecN_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 3);
    return res;
}
/** dst = a @ b */
static vec3 vec3_mul_mat_v(const float *vec_a, const float *mat_b) {
    return vec3_mul_mat(Vec3(vec_a), Mat3(mat_b));
}


/** returns = determinant mat */
static float mat3_det(mat3 mat) {
    // from cglm/mat3.h/glm_mat3_det
    float a = mat.m[0][0], b = mat.m[0][1], c = mat.m[0][2];
    float d = mat.m[1][0], e = mat.m[1][1], f = mat.m[1][2];
    float g = mat.m[2][0], h = mat.m[2][1], i = mat.m[2][2];

    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
}
/** returns = determinant mat */
static float mat3_det_v(const float *mat) {
    return mat3_det(Mat3(mat));
}


/** dst = inverted mat */
static mat3 mat3_inv(mat3 mat) {
    // from cglm/mat3.h/glm_mat3_inv
    float a = mat.m[0][0], b = mat.m[0][1], c = mat.m[0][2];
    float d = mat.m[1][0], e = mat.m[1][1], f = mat.m[1][2];
    float g = mat.m[2][0], h = mat.m[2][1], i = mat.m[2][2];

    mat3 res;
    res.m[0][0] =   e * i - f * h;
    res.m[0][1] = -(b * i - h * c);
    res.m[0][2] =   b * f - e * c;
    res.m[1][0] = -(d * i - g * f);
    res.m[1][1] =   a * i - c * g;
    res.m[1][2] = -(a * f - d * c);
    res.m[2][0] =   d * h - g * e;
    res.m[2][1] = -(a * h - g * b);
    res.m[2][2] =   a * e - b * d;

    float inv_det = 1.0f / (a * res.m[0][0] + b * res.m[1][0] + c * res.m[2][0]);

    vecN_scale_sca(res.v, res.v, inv_det, 9);
    return res;
}
/** dst = inverted mat */
static mat3 mat3_inv_v(const float *mat) {
    return mat3_inv(Mat3(mat));
}


/** dst = mat[col:col+2, row:row+2] */
static mat2 mat3_get_block2(mat3 mat, int row, int col) {
    mat2 res;
    matN_get_block(res.v, mat.v, row, col, 2, 3);
    return res;
}
/** dst = mat[col:col+2, row:row+2] */
static mat2 mat3_get_block2_v(const float *mat, int row, int col) {
    return mat3_get_block2(Mat3(mat), row, col);
}


/** dst = mat; dst[col:col+2, row:row+2] = block */
static mat3 mat3_set_block2(mat3 mat, mat2 block_2, int row, int col) {
    matN_set_block(mat.v, block_2.v, row, col, 2, 3);
    return mat;
}
/** dst = mat; dst[col:col+2, row:row+2] = block */
static mat3 mat3_set_block2_v(const float *mat, const float *block_2, int row, int col) {
    return mat3_set_block2(Mat3(mat), Mat2(block_2), row, col);
}


/** dst = mat[:2, :2] */
static mat2 mat3_get_upper_left(mat3 mat) {
    return mat3_get_block2(mat, 0, 0);
}
/** dst = mat[:2, :2] */
static mat2 mat3_get_upper_left_v(const float *mat) {
    return mat3_get_upper_left(Mat3(mat));
}


/** dst = mat; dst[:2, :2] = block */
static mat3 mat3_set_upper_left(mat3 mat, mat2 block_2) {
    return mat3_set_block2(mat, block_2, 0, 0);
}
/** dst = mat; dst[:2, :2] = block */
static mat3 mat3_set_upper_left_v(const float *mat, const float *block_2) {
    return mat3_set_upper_left(Mat3(mat), Mat2(block_2));
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
/** angle_axis as xyz = axis and w = angle [rad] */
static mat3 mat3_rotation_from_angle_axis_v(const float *angle_axis) {
    return mat3_rotation_from_angle_axis(Vec4(angle_axis));
}


#endif //MATHC_MAT_MAT3_H
