#ifndef MATHC_MAT_TYPED_V_H
#define MATHC_MAT_TYPED_V_H

#include "functions.h"


//
// this header file has the following content:
// 1. typed_v functions for float[3][3] as mat33f
// 2. typed_v functions for float[4][4] as mat44f
// 3. typed_v functions for double[3][3] as mat33d
// 4. typed_v functions for double[4][4] as mat44d
// 5. typed_v functions for int[3][3] as int33d
// 6. typed_v functions for int[4][4] as int44d
//



//
// mat33f
//

/** vec<n> dst = mat<n*n>[row][:] */
static vec3f mat33f_get_row_v(const float *mat, int row) {
    vec3f res;
    matf_get_row(res.v, mat, row, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec3f mat33f_get_col_v(const float *mat, int col) {
    vec3f res;
    matf_get_col(res.v, mat, col, 3);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat33f mat33f_set_row_v(float *in_out_mat, const float *vec, int row) {
    matf_set_row(in_out_mat, vec, row, 3);
    return Mat33f(in_out_mat);
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat33f mat33f_set_col_v(float *in_out_mat, const float *vec, int col) {
    matf_set_col(in_out_mat, vec, col, 3);
    return Mat33f(in_out_mat);
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat33f mat33f_row_set_sca_v(float *in_out_mat, float scalar, int row) {
    matf_row_set_sca(in_out_mat, scalar, row, 3);
    return Mat33f(in_out_mat);
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat33f mat33f_col_set_sca_v(float *in_out_mat, float scalar, int col) {
    matf_col_set_sca(in_out_mat, scalar, col, 3);
    return Mat33f(in_out_mat);
}

/** mat<n*n> dst = mat<n*n>^t */
static mat33f mat33f_transpose_v(const float *mat) {
    mat33f res;
    matf_transpose_no_alias(res.v, mat, 3);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat33f mat33f_mul_mat_v(const float *mat_a, const float *mat_b) {
    mat33f res;
    matf_mul_mat_no_alias(res.v, mat_a, mat_b, 3);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec3f mat33f_mul_vec_v(const float *mat_a, const float *vec_b) {
    vec3f res;
    matf_mul_vec_no_alias(res.v, mat_a, vec_b, 3);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec3f vec3f_mul_mat_v(const float *vec_a, const float *mat_b) {
    vec3f res;
    vecf_mul_mat_no_alias(res.v, vec_a, mat_b, 3);
    return res;
}

/** returns = det mat<3*3> mat33 */
static float mat33f_determinant_v(const float *mat) {
    return matf_determinant33(mat);
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static mat33f mat33f_invert_v(const float *mat) {
    mat33f res;
    matf_invert33_no_alias(res.v, mat);
    return res;
}


//
// mat44f
//

/** vec<n> dst = mat<n*n>[row][:] */
static vec4f mat44f_get_row_v(const float *mat, int row) {
    vec4f res;
    matf_get_row(res.v, mat, row, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec4f mat44f_get_col_v(const float *mat, int col) {
    vec4f res;
    matf_get_col(res.v, mat, col, 4);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat44f mat44f_set_row_v(float *in_out_mat, const float *vec, int row) {
    matf_set_row(in_out_mat, vec, row, 4);
    return Mat44f(in_out_mat);
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat44f mat44f_set_col_v(float *in_out_mat, const float *vec, int col) {
    matf_set_col(in_out_mat, vec, col, 4);
    return Mat44f(in_out_mat);
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat44f mat44f_row_set_sca_v(float *in_out_mat, float scalar, int row) {
    matf_row_set_sca(in_out_mat, scalar, row, 4);
    return Mat44f(in_out_mat);
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat44f mat44f_col_set_sca_v(float *in_out_mat, float scalar, int col) {
    matf_col_set_sca(in_out_mat, scalar, col, 4);
    return Mat44f(in_out_mat);
}

/** mat<n*n> dst = mat<n*n>^t */
static mat44f mat44f_transpose_v(const float *mat) {
    mat44f res;
    matf_transpose_no_alias(res.v, mat, 4);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat44f mat44f_mul_mat_v(const float *mat_a, const float *mat_b) {
    mat44f res;
    matf_mul_mat_no_alias(res.v, mat_a, mat_b, 4);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec4f mat44f_mul_vec_v(const float *mat_a, const float *vec_b) {
    vec4f res;
    matf_mul_vec_no_alias(res.v, mat_a, vec_b, 4);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec4f vec4f_mul_mat_v(const float *vec_a, const float *mat_b) {
    vec4f res;
    vecf_mul_mat_no_alias(res.v, vec_a, mat_b, 4);
    return res;
}

/** returns = det mat<4*4> mat44 */
static float mat44f_determinant_v(const float *mat) {
    return matf_determinant44(mat);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static mat44f mat44f_invert_v(const float *mat) {
    mat44f res;
    matf_invert44_no_alias(res.v, mat);
    return res;
}




//
// mat33d
//

/** vec<n> dst = mat<n*n>[row][:] */
static vec3d mat33d_get_row_v(const double *mat, int row) {
    vec3d res;
    matd_get_row(res.v, mat, row, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec3d mat33d_get_col_v(const double *mat, int col) {
    vec3d res;
    matd_get_col(res.v, mat, col, 3);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat33d mat33d_set_row_v(double *in_out_mat, const double *vec, int row) {
    matd_set_row(in_out_mat, vec, row, 3);
    return Mat33d(in_out_mat);
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat33d mat33d_set_col_v(double *in_out_mat, const double *vec, int col) {
    matd_set_col(in_out_mat, vec, col, 3);
    return Mat33d(in_out_mat);
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat33d mat33d_row_set_sca_v(double *in_out_mat, double scalar, int row) {
    matd_row_set_sca(in_out_mat, scalar, row, 3);
    return Mat33d(in_out_mat);
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat33d mat33d_col_set_sca_v(double *in_out_mat, double scalar, int col) {
    matd_col_set_sca(in_out_mat, scalar, col, 3);
    return Mat33d(in_out_mat);
}

/** mat<n*n> dst = mat<n*n>^t */
static mat33d mat33d_transpose_v(const double *mat) {
    mat33d res;
    matd_transpose_no_alias(res.v, mat, 3);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat33d mat33d_mul_mat_v(const double *mat_a, const double *mat_b) {
    mat33d res;
    matd_mul_mat_no_alias(res.v, mat_a, mat_b, 3);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec3d mat33d_mul_vec_v(const double *mat_a, const double *vec_b) {
    vec3d res;
    matd_mul_vec_no_alias(res.v, mat_a, vec_b, 3);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec3d vec3d_mul_mat_v(const double *vec_a, const double *mat_b) {
    vec3d res;
    vecd_mul_mat_no_alias(res.v, vec_a, mat_b, 3);
    return res;
}

/** returns = det mat<3*3> mat33 */
static double mat33d_determinant_v(const double *mat) {
    return matd_determinant33(mat);
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static mat33d mat33d_invert_v(const double *mat) {
    mat33d res;
    matd_invert33_no_alias(res.v, mat);
    return res;
}


//
// mat44d
//

/** vec<n> dst = mat<n*n>[row][:] */
static vec4d mat44d_get_row_v(const double *mat, int row) {
    vec4d res;
    matd_get_row(res.v, mat, row, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec4d mat44d_get_col_v(const double *mat, int col) {
    vec4d res;
    matd_get_col(res.v, mat, col, 4);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat44d mat44d_set_row_v(double *in_out_mat, const double *vec, int row) {
    matd_set_row(in_out_mat, vec, row, 4);
    return Mat44d(in_out_mat);
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat44d mat44d_set_col_v(double *in_out_mat, const double *vec, int col) {
    matd_set_col(in_out_mat, vec, col, 4);
    return Mat44d(in_out_mat);
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat44d mat44d_row_set_sca_v(double *in_out_mat, double scalar, int row) {
    matd_row_set_sca(in_out_mat, scalar, row, 4);
    return Mat44d(in_out_mat);
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat44d mat44d_col_set_sca_v(double *in_out_mat, double scalar, int col) {
    matd_col_set_sca(in_out_mat, scalar, col, 4);
    return Mat44d(in_out_mat);
}

/** mat<n*n> dst = mat<n*n>^t */
static mat44d mat44d_transpose_v(const double *mat) {
    mat44d res;
    matd_transpose_no_alias(res.v, mat, 4);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat44d mat44d_mul_mat_v(const double *mat_a, const double *mat_b) {
    mat44d res;
    matd_mul_mat_no_alias(res.v, mat_a, mat_b, 4);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec4d mat44d_mul_vec_v(const double *mat_a, const double *vec_b) {
    vec4d res;
    matd_mul_vec_no_alias(res.v, mat_a, vec_b, 4);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec4d vec4d_mul_mat_v(const double *vec_a, const double *mat_b) {
    vec4d res;
    vecd_mul_mat_no_alias(res.v, vec_a, mat_b, 4);
    return res;
}

/** returns = det mat<4*4> mat44 */
static double mat44d_determinant_v(const double *mat) {
    return matd_determinant44(mat);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static mat44d mat44d_invert_v(const double *mat) {
    mat44d res;
    matd_invert44_no_alias(res.v, mat);
    return res;
}




//
// mat33i
//

/** vec<n> dst = mat<n*n>[row][:] */
static vec3i mat33i_get_row_v(const int *mat, int row) {
    vec3i res;
    mati_get_row(res.v, mat, row, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec3i mat33i_get_col_v(const int *mat, int col) {
    vec3i res;
    mati_get_col(res.v, mat, col, 3);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat33i mat33i_set_row_v(int *in_out_mat, const int *vec, int row) {
    mati_set_row(in_out_mat, vec, row, 3);
    return Mat33i(in_out_mat);
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat33i mat33i_set_col_v(int *in_out_mat, const int *vec, int col) {
    mati_set_col(in_out_mat, vec, col, 3);
    return Mat33i(in_out_mat);
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat33i mat33i_row_set_sca_v(int *in_out_mat, int scalar, int row) {
    mati_row_set_sca(in_out_mat, scalar, row, 3);
    return Mat33i(in_out_mat);
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat33i mat33i_col_set_sca_v(int *in_out_mat, int scalar, int col) {
    mati_col_set_sca(in_out_mat, scalar, col, 3);
    return Mat33i(in_out_mat);
}

/** mat<n*n> dst = mat<n*n>^t */
static mat33i mat33i_transpose_v(const int *mat) {
    mat33i res;
    mati_transpose_no_alias(res.v, mat, 3);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat33i mat33i_mul_mat_v(const int *mat_a, const int *mat_b) {
    mat33i res;
    mati_mul_mat_no_alias(res.v, mat_a, mat_b, 3);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec3i mat33i_mul_vec_v(const int *mat_a, const int *vec_b) {
    vec3i res;
    mati_mul_vec_no_alias(res.v, mat_a, vec_b, 3);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec3i vec3i_mul_mat_v(const int *vec_a, const int *mat_b) {
    vec3i res;
    veci_mul_mat_no_alias(res.v, vec_a, mat_b, 3);
    return res;
}

/** returns = det mat<3*3> mat33 */
static int mat33i_determinant_v(const int *mat) {
    return mati_determinant33(mat);
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static mat33i mat33i_invert_v(const int *mat) {
    mat33i res;
    mati_invert33_no_alias(res.v, mat);
    return res;
}


//
// mat44i
//

/** vec<n> dst = mat<n*n>[row][:] */
static vec4i mat44i_get_row_v(const int *mat, int row) {
    vec4i res;
    mati_get_row(res.v, mat, row, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec4i mat44i_get_col_v(const int *mat, int col) {
    vec4i res;
    mati_get_col(res.v, mat, col, 4);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat44i mat44i_set_row_v(int *in_out_mat, const int *vec, int row) {
    mati_set_row(in_out_mat, vec, row, 4);
    return Mat44i(in_out_mat);
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat44i mat44i_set_col_v(int *in_out_mat, const int *vec, int col) {
    mati_set_col(in_out_mat, vec, col, 4);
    return Mat44i(in_out_mat);
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat44i mat44i_row_set_sca_v(int *in_out_mat, int scalar, int row) {
    mati_row_set_sca(in_out_mat, scalar, row, 4);
    return Mat44i(in_out_mat);
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat44i mat44i_col_set_sca_v(int *in_out_mat, int scalar, int col) {
    mati_col_set_sca(in_out_mat, scalar, col, 4);
    return Mat44i(in_out_mat);
}

/** mat<n*n> dst = mat<n*n>^t */
static mat44i mat44i_transpose_v(const int *mat) {
    mat44i res;
    mati_transpose_no_alias(res.v, mat, 4);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat44i mat44i_mul_mat_v(const int *mat_a, const int *mat_b) {
    mat44i res;
    mati_mul_mat_no_alias(res.v, mat_a, mat_b, 4);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec4i mat44i_mul_vec_v(const int *mat_a, const int *vec_b) {
    vec4i res;
    mati_mul_vec_no_alias(res.v, mat_a, vec_b, 4);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec4i vec4i_mul_mat_v(const int *vec_a, const int *mat_b) {
    vec4i res;
    veci_mul_mat_no_alias(res.v, vec_a, mat_b, 4);
    return res;
}

/** returns = det mat<4*4> mat44 */
static int mat44i_determinant_v(const int *mat) {
    return mati_determinant44(mat);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static mat44i mat44i_invert_v(const int *mat) {
    mat44i res;
    mati_invert44_no_alias(res.v, mat);
    return res;
}


#endif //MATHC_MAT_TYPED_V_H
