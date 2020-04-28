#ifndef MATHC_MAT_GENERIC_V_H
#define MATHC_MAT_GENERIC_V_H

#include "typed_v.h"

//
// this header file has the following content:
// generic macros for each typed_v function: mat33f_transpose_v and mat44i_transpose_v can be accessed with mat3_transpose_v
// generic nested macros for add_v, sub_v, scale_v, div_v
//


//
// mat33
//

/** vec<n> dst = mat<n*n>[row][:] */
#define mat33_get_row_v(mat, row) _Generic((mat), \
float *: mat33f_get_row_v, \
const float *: mat33f_get_row_v, \
double *: mat33d_get_row_v, \
const double *: mat33d_get_row_v, \
int *: mat33i_get_row_v, \
const int *: mat33i_get_row_v, \
default: "type_error" \
) ((mat), (row))

/** vec<n> dst = mat<n*n>[:][col] */
#define mat33_get_col_v(mat, col) _Generic((mat), \
float *: mat33f_get_col_v, \
const float *: mat33f_get_col_v, \
double *: mat33d_get_col_v, \
const double *: mat33d_get_col_v, \
int *: mat33i_get_col_v, \
const int *: mat33i_get_col_v, \
default: "type_error" \
) ((mat), (col))

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
#define mat33_set_row_v(mat, vec, row) _Generic((mat), \
float *: mat33f_set_row_v, \
const float *: mat33f_set_row_v, \
double *: mat33d_set_row_v, \
const double *: mat33d_set_row_v, \
int *: mat33i_set_row_v, \
const int *: mat33i_set_row_v, \
default: "type_error" \
) ((mat), (vec), (row))

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
#define mat33_set_col_v(mat, vec, col) _Generic((mat), \
float *: mat33f_set_col_v, \
const float *: mat33f_set_col_v, \
double *: mat33d_set_col_v, \
const double *: mat33d_set_col_v, \
int *: mat33i_set_col_v, \
const int *: mat33i_set_col_v, \
default: "type_error" \
) ((mat), (vec), (col))

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
#define mat33_row_set_sca_v(mat, scalar, row) _Generic((mat), \
float *: mat33f_row_set_sca_v, \
const float *: mat33f_row_set_sca_v, \
double *: mat33d_row_set_sca_v, \
const double *: mat33d_row_set_sca_v, \
int *: mat33i_row_set_sca_v, \
const int *: mat33i_row_set_sca_v, \
default: "type_error" \
) ((mat), (scalar), (row))

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
#define mat33_col_set_sca_v(mat, scalar, col) _Generic((mat), \
float *: mat33f_col_set_sca_v, \
const float *: mat33f_col_set_sca_v, \
double *: mat33d_col_set_sca_v, \
const double *: mat33d_col_set_sca_v, \
int *: mat33i_col_set_sca_v, \
const int *: mat33i_col_set_sca_v, \
default: "type_error" \
) ((mat), (scalar), (col))

/** mat<n*n> dst = mat<n*n>^t */
#define mat33_transpose_v(mat) _Generic((mat), \
float *: mat33f_transpose_v, \
const float *: mat33f_transpose_v, \
double *: mat33d_transpose_v, \
const double *: mat33d_transpose_v, \
int *: mat33i_transpose_v, \
const int *: mat33i_transpose_v, \
default: "type_error" \
) ((mat))

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
#define mat33_mul_mat_v(mat_a, mat_b) _Generic((mat_a), \
float *: mat33f_mul_mat_v, \
const float *: mat33f_mul_mat_v, \
double *: mat33d_mul_mat_v, \
const double *: mat33d_mul_mat_v, \
int *: mat33i_mul_mat_v, \
const int *: mat33i_mul_mat_v, \
default: "type_error" \
) ((mat_a), (mat_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define mat33_mul_vec_v(mat_a, vec_b) _Generic((mat_a), \
float *: mat33f_mul_vec_v, \
const float *: mat33f_mul_vec_v, \
double *: mat33d_mul_vec_v, \
const double *: mat33d_mul_vec_v, \
int *: mat33i_mul_vec_v, \
const int *: mat33i_mul_vec_v, \
default: "type_error" \
) ((mat_a), (vec_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define vec3_mul_mat_v(vec_a, mat_b) _Generic((vec_a), \
float *: vec3f_mul_mat_v, \
const float *: vec3f_mul_mat_v, \
double *: vec3d_mul_mat_v, \
const double *: vec3d_mul_mat_v, \
int *: vec3i_mul_mat_v, \
const int *: vec3i_mul_mat_v, \
default: "type_error" \
) ((vec_a), (mat_b))

/** returns = det mat<3*3> mat33 */
#define mat33_determinant_v(mat) _Generic((mat), \
float *: mat33f_determinant_v, \
const float *: mat33f_determinant_v, \
double *: mat33d_determinant_v, \
const double *: mat33d_determinant_v, \
int *: mat33i_determinant_v, \
const int *: mat33i_determinant_v, \
default: "type_error" \
) ((mat))

/** mat<3*3> dst = inv(mat<3*3> mat33) */
#define mat33_invert_v(mat) _Generic((mat), \
float *: mat33f_invert_v, \
const float *: mat33f_invert_v, \
double *: mat33d_invert_v, \
const double *: mat33d_invert_v, \
int *: mat33i_invert_v, \
const int *: mat33i_invert_v, \
default: "type_error" \
) ((mat))



//
// mat44
//

/** vec<n> dst = mat<n*n>[row][:] */
#define mat44_get_row_v(mat, row) _Generic((mat), \
float *: mat44f_get_row_v, \
const float *: mat44f_get_row_v, \
double *: mat44d_get_row_v, \
const double *: mat44d_get_row_v, \
int *: mat44i_get_row_v, \
const int *: mat44i_get_row_v, \
default: "type_error" \
) ((mat), (row))

/** vec<n> dst = mat<n*n>[:][col] */
#define mat44_get_col_v(mat, col) _Generic((mat), \
float *: mat44f_get_col_v, \
const float *: mat44f_get_col_v, \
double *: mat44d_get_col_v, \
const double *: mat44d_get_col_v, \
int *: mat44i_get_col_v, \
const int *: mat44i_get_col_v, \
default: "type_error" \
) ((mat), (col))

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
#define mat44_set_row_v(mat, vec, row) _Generic((mat), \
float *: mat44f_set_row_v, \
const float *: mat44f_set_row_v, \
double *: mat44d_set_row_v, \
const double *: mat44d_set_row_v, \
int *: mat44i_set_row_v, \
const int *: mat44i_set_row_v, \
default: "type_error" \
) ((mat), (vec), (row))

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
#define mat44_set_col_v(mat, vec, col) _Generic((mat), \
float *: mat44f_set_col_v, \
const float *: mat44f_set_col_v, \
double *: mat44d_set_col_v, \
const double *: mat44d_set_col_v, \
int *: mat44i_set_col_v, \
const int *: mat44i_set_col_v, \
default: "type_error" \
) ((mat), (vec), (col))

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
#define mat44_row_set_sca_v(mat, scalar, row) _Generic((mat), \
float *: mat44f_row_set_sca_v, \
const float *: mat44f_row_set_sca_v, \
double *: mat44d_row_set_sca_v, \
const double *: mat44d_row_set_sca_v, \
int *: mat44i_row_set_sca_v, \
const int *: mat44i_row_set_sca_v, \
default: "type_error" \
) ((mat), (scalar), (row))

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
#define mat44_col_set_sca_v(mat, scalar, col) _Generic((mat), \
float *: mat44f_col_set_sca_v, \
const float *: mat44f_col_set_sca_v, \
double *: mat44d_col_set_sca_v, \
const double *: mat44d_col_set_sca_v, \
int *: mat44i_col_set_sca_v, \
const int *: mat44i_col_set_sca_v, \
default: "type_error" \
) ((mat), (scalar), (col))

/** mat<n*n> dst = mat<n*n>^t */
#define mat44_transpose_v(mat) _Generic((mat), \
float *: mat44f_transpose_v, \
const float *: mat44f_transpose_v, \
double *: mat44d_transpose_v, \
const double *: mat44d_transpose_v, \
int *: mat44i_transpose_v, \
const int *: mat44i_transpose_v, \
default: "type_error" \
) ((mat))

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
#define mat44_mul_mat_v(mat_a, mat_b) _Generic((mat_a), \
float *: mat44f_mul_mat_v, \
const float *: mat44f_mul_mat_v, \
double *: mat44d_mul_mat_v, \
const double *: mat44d_mul_mat_v, \
int *: mat44i_mul_mat_v, \
const int *: mat44i_mul_mat_v, \
default: "type_error" \
) ((mat_a), (mat_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define mat44_mul_vec_v(mat_a, vec_b) _Generic((mat_a), \
float *: mat44f_mul_vec_v, \
const float *: mat44f_mul_vec_v, \
double *: mat44d_mul_vec_v, \
const double *: mat44d_mul_vec_v, \
int *: mat44i_mul_vec_v, \
const int *: mat44i_mul_vec_v, \
default: "type_error" \
) ((mat_a), (vec_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define vec4_mul_mat_v(vec_a, mat_b) _Generic((vec_a), \
float *: vec4f_mul_mat_v, \
const float *: vec4f_mul_mat_v, \
double *: vec4d_mul_mat_v, \
const double *: vec4d_mul_mat_v, \
int *: vec4i_mul_mat_v, \
const int *: vec4i_mul_mat_v, \
default: "type_error" \
) ((vec_a), (mat_b))

/** returns = det mat<4*4> mat44 */
#define mat44_determinant_v(mat) _Generic((mat), \
float *: mat44f_determinant_v, \
const float *: mat44f_determinant_v, \
double *: mat44d_determinant_v, \
const double *: mat44d_determinant_v, \
int *: mat44i_determinant_v, \
const int *: mat44i_determinant_v, \
default: "type_error" \
) ((mat))

/** mat<4*4> dst = inv(mat<4*4> mat44) */
#define mat44_invert_v(mat) _Generic((mat), \
float *: mat44f_invert_v, \
const float *: mat44f_invert_v, \
double *: mat44d_invert_v, \
const double *: mat44d_invert_v, \
int *: mat44i_invert_v, \
const int *: mat44i_invert_v, \
default: "type_error" \
) ((mat))

#endif //MATHC_MAT_GENERIC_V_H
