#ifndef MATHC_MAT_GENERIC_H
#define MATHC_MAT_GENERIC_H

#include "typed.h"

//
// this header file has the following content:
// generic macros for each typed function: mat33f_transpose and mat44i_transpose can be accessed with mat_transpose
// generic nested macros for add, sub, scale, div
//

/** vec<n> dst = mat<n*n>[row][:] */
#define mat_get_row(mat, row) _Generic((mat), \
mat22f: mat22f_get_row, \
mat33f: mat33f_get_row, \
mat44f: mat44f_get_row, \
mat22d: mat22d_get_row, \
mat33d: mat33d_get_row, \
mat44d: mat44d_get_row, \
mat22i: mat22i_get_row, \
mat33i: mat33i_get_row, \
mat44i: mat44i_get_row, \
default: "type_error" \
) ((mat), (row))

/** vec<n> dst = mat<n*n>[:][col] */
#define mat_get_col(mat, col) _Generic((mat), \
mat22f: mat22f_get_col, \
mat33f: mat33f_get_col, \
mat44f: mat44f_get_col, \
mat22d: mat22d_get_col, \
mat33d: mat33d_get_col, \
mat44d: mat44d_get_col, \
mat22i: mat22i_get_col, \
mat33i: mat33i_get_col, \
mat44i: mat44i_get_col, \
default: "type_error" \
) ((mat), (col))

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
#define mat_set_row(mat, vec, row) _Generic((mat), \
mat22f: mat22f_set_row, \
mat33f: mat33f_set_row, \
mat44f: mat44f_set_row, \
mat22d: mat22d_set_row, \
mat33d: mat33d_set_row, \
mat44d: mat44d_set_row, \
mat22i: mat22i_set_row, \
mat33i: mat33i_set_row, \
mat44i: mat44i_set_row, \
default: "type_error" \
) ((mat), (vec), (row))

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
#define mat_set_col(mat, vec, col) _Generic((mat), \
mat22f: mat22f_set_col, \
mat33f: mat33f_set_col, \
mat44f: mat44f_set_col, \
mat22d: mat22d_set_col, \
mat33d: mat33d_set_col, \
mat44d: mat44d_set_col, \
mat22i: mat22i_set_col, \
mat33i: mat33i_set_col, \
mat44i: mat44i_set_col, \
default: "type_error" \
) ((mat), (vec), (col))

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
#define mat_row_set_sca(mat, scalar, row) _Generic((mat), \
mat22f: mat22f_row_set_sca, \
mat33f: mat33f_row_set_sca, \
mat44f: mat44f_row_set_sca, \
mat22d: mat22d_row_set_sca, \
mat33d: mat33d_row_set_sca, \
mat44d: mat44d_row_set_sca, \
mat22i: mat22i_row_set_sca, \
mat33i: mat33i_row_set_sca, \
mat44i: mat44i_row_set_sca, \
default: "type_error" \
) ((mat), (scalar), (row))

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
#define mat_col_set_sca(mat, scalar, col) _Generic((mat), \
mat22f: mat22f_col_set_sca, \
mat33f: mat33f_col_set_sca, \
mat44f: mat44f_col_set_sca, \
mat22d: mat22d_col_set_sca, \
mat33d: mat33d_col_set_sca, \
mat44d: mat44d_col_set_sca, \
mat22i: mat22i_col_set_sca, \
mat33i: mat33i_col_set_sca, \
mat44i: mat44i_col_set_sca, \
default: "type_error" \
) ((mat), (scalar), (col))

/** mat<n*n> dst = mat<n*n>^t */
#define mat_transpose(mat) _Generic((mat), \
mat22f: mat22f_transpose, \
mat33f: mat33f_transpose, \
mat44f: mat44f_transpose, \
mat22d: mat22d_transpose, \
mat33d: mat33d_transpose, \
mat44d: mat44d_transpose, \
mat22i: mat22i_transpose, \
mat33i: mat33i_transpose, \
mat44i: mat44i_transpose, \
default: "type_error" \
) ((mat))

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
#define mat_mul_mat(mat_a, mat_b) _Generic((mat_a), \
mat22f: mat22f_mul_mat, \
mat33f: mat33f_mul_mat, \
mat44f: mat44f_mul_mat, \
mat22d: mat22d_mul_mat, \
mat33d: mat33d_mul_mat, \
mat44d: mat44d_mul_mat, \
mat22i: mat22i_mul_mat, \
mat33i: mat33i_mul_mat, \
mat44i: mat44i_mul_mat, \
default: "type_error" \
) ((mat_a), (mat_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define mat_mul_vec(mat_a, vec_b) _Generic((mat_a), \
mat22f: mat22f_mul_vec, \
mat33f: mat33f_mul_vec, \
mat44f: mat44f_mul_vec, \
mat22d: mat22d_mul_vec, \
mat33d: mat33d_mul_vec, \
mat44d: mat44d_mul_vec, \
mat22i: mat22i_mul_vec, \
mat33i: mat33i_mul_vec, \
mat44i: mat44i_mul_vec, \
default: "type_error" \
) ((mat_a), (vec_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define vec_mul_mat(vec_a, mat_b) _Generic((vec_a), \
vec2f: vec2f_mul_mat, \
vec3f: vec3f_mul_mat, \
vec4f: vec4f_mul_mat, \
vec2d: vec2d_mul_mat, \
vec3d: vec3d_mul_mat, \
vec4d: vec4d_mul_mat, \
vec2i: vec2i_mul_mat, \
vec3i: vec3i_mul_mat, \
vec4i: vec4i_mul_mat, \
default: "type_error" \
) ((vec_a), (mat_b))

/** returns = det mat<3*3> mat33 */
#define mat_determinant(mat) _Generic((mat), \
mat22f: mat22f_determinant, \
mat33f: mat33f_determinant, \
mat44f: mat44f_determinant, \
mat22d: mat22d_determinant, \
mat33d: mat33d_determinant, \
mat44d: mat44d_determinant, \
mat22i: mat22i_determinant, \
mat33i: mat33i_determinant, \
mat44i: mat44i_determinant, \
default: "type_error" \
) ((mat))

/** mat<3*3> dst = inv(mat<3*3> mat33) */
#define mat_invert(mat) _Generic((mat), \
mat22f: mat22f_invert, \
mat33f: mat33f_invert, \
mat44f: mat44f_invert, \
mat22d: mat22d_invert, \
mat33d: mat33d_invert, \
mat44d: mat44d_invert, \
mat22i: mat22i_invert, \
mat33i: mat33i_invert, \
mat44i: mat44i_invert, \
default: "type_error" \
) ((mat))

#endif //MATHC_MAT_GENERIC_H
