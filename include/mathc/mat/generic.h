#ifndef MATHC_MAT_GENERIC_H
#define MATHC_MAT_GENERIC_H

#include "typed.h"

//
// this header file has the following content:
// generic macros for each typed function: mat33f_transpose and mat44i_transpose can be accessed with mat_transpose
// generic nested macros for add, sub, scale, div
//

/** casts a float, double, into <const> mat33<x> */
#define Mat33(mat) _Generic((mat), \
float *: Mat33f(mat), \
const float *: ConstMat33f(mat), \
double *: Mat33d(mat), \
const double *: ConstMat33d(mat), \
int *: Mat33i(mat), \
const int *: ConstMat33i(mat), \
default: "type_error" \
)

/** casts a float, double, into <const> mat44<x> */
#define Mat44(mat) _Generic((mat), \
float *: Mat44f(mat), \
const float *: ConstMat44f(mat), \
double *: Mat44d(mat), \
const double *: ConstMat44d(mat), \
int *: Mat44i(mat), \
const int *: ConstMat44i(mat), \
default: "type_error" \
)

/** casts a float, double, into <const> vec3<x> */
#define Vec3(vec) _Generic((vec), \
float *: Vec3f(vec), \
const float *: ConstVec3f(vec), \
double *: Vec3d(vec), \
const double *: ConstVec3d(vec), \
int *: Vec3i(vec), \
const int *: ConstVec3i(vec), \
default: "type_error" \
)

/** casts a float, double, into <const> vec4<x> */
#define Vec4(vec) _Generic((vec), \
float *: Vec4f(vec), \
const float *: ConstVec4f(vec), \
double *: Vec4d(vec), \
const double *: ConstVec4d(vec), \
int *: Vec4i(vec), \
const int *: ConstVec4i(vec), \
default: "type_error" \
)

/** vec<n> dst = mat<n*n>[row][:] */
#define mat_get_row(mat, row) _Generic((mat), \
mat33f: mat33f_get_row, \
mat44f: mat44f_get_row, \
mat33d: mat33d_get_row, \
mat44d: mat44d_get_row, \
mat33i: mat33i_get_row, \
mat44i: mat44i_get_row, \
default: "type_error" \
) ((mat), (row))

/** vec<n> dst = mat<n*n>[:][col] */
#define mat_get_col(mat, col) _Generic((mat), \
mat33f: mat33f_get_col, \
mat44f: mat44f_get_col, \
mat33d: mat33d_get_col, \
mat44d: mat44d_get_col, \
mat33i: mat33i_get_col, \
mat44i: mat44i_get_col, \
default: "type_error" \
) ((mat), (col))

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
#define mat_set_row(mat, vec, row) _Generic((mat), \
mat33f: mat33f_set_row, \
mat44f: mat44f_set_row, \
mat33d: mat33d_set_row, \
mat44d: mat44d_set_row, \
mat33i: mat33i_set_row, \
mat44i: mat44i_set_row, \
default: "type_error" \
) ((mat), (vec), (row))

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
#define mat_set_col(mat, vec, col) _Generic((mat), \
mat33f: mat33f_set_col, \
mat44f: mat44f_set_col, \
mat33d: mat33d_set_col, \
mat44d: mat44d_set_col, \
mat33i: mat33i_set_col, \
mat44i: mat44i_set_col, \
default: "type_error" \
) ((mat), (vec), (col))

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
#define mat_row_set_sca(mat, scalar, row) _Generic((mat), \
mat33f: mat33f_row_set_sca, \
mat44f: mat44f_row_set_sca, \
mat33d: mat33d_row_set_sca, \
mat44d: mat44d_row_set_sca, \
mat33i: mat33i_row_set_sca, \
mat44i: mat44i_row_set_sca, \
default: "type_error" \
) ((mat), (scalar), (row))

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
#define mat_col_set_sca(mat, scalar, col) _Generic((mat), \
mat33f: mat33f_col_set_sca, \
mat44f: mat44f_col_set_sca, \
mat33d: mat33d_col_set_sca, \
mat44d: mat44d_col_set_sca, \
mat33i: mat33i_col_set_sca, \
mat44i: mat44i_col_set_sca, \
default: "type_error" \
) ((mat), (scalar), (col))

/** mat<n*n> dst = mat<n*n>^t */
#define mat_transpose(mat) _Generic((mat), \
mat33f: mat33f_transpose, \
mat44f: mat44f_transpose, \
mat33d: mat33d_transpose, \
mat44d: mat44d_transpose, \
mat33i: mat33i_transpose, \
mat44i: mat44i_transpose, \
default: "type_error" \
) ((mat))

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
#define mat_mul_mat(mat_a, mat_b) _Generic((mat_a), \
mat33f: mat33f_mul_mat, \
mat44f: mat44f_mul_mat, \
mat33d: mat33d_mul_mat, \
mat44d: mat44d_mul_mat, \
mat33i: mat33i_mul_mat, \
mat44i: mat44i_mul_mat, \
default: "type_error" \
) ((mat_a), (mat_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define mat_mul_vec(mat_a, vec_b) _Generic((mat_a), \
mat33f: mat33f_mul_vec, \
mat44f: mat44f_mul_vec, \
mat33d: mat33d_mul_vec, \
mat44d: mat44d_mul_vec, \
mat33i: mat33i_mul_vec, \
mat44i: mat44i_mul_vec, \
default: "type_error" \
) ((mat_a), (vec_b))

/** vec<n> dst = mat<n*n> a * vec<n> b */
#define vec_mul_mat(vec_a, mat_b) _Generic((vec_a), \
vec3f: vec3f_mul_mat, \
vec4f: vec4f_mul_mat, \
vec3d: vec3d_mul_mat, \
vec4d: vec4d_mul_mat, \
vec3i: vec3i_mul_mat, \
vec4i: vec4i_mul_mat, \
default: "type_error" \
) ((vec_a), (mat_b))

/** returns = det mat<3*3> mat33 */
#define mat_determinant(mat) _Generic((mat), \
mat33f: mat33f_determinant, \
mat44f: mat44f_determinant, \
mat33d: mat33d_determinant, \
mat44d: mat44d_determinant, \
mat33i: mat33i_determinant, \
mat44i: mat44i_determinant, \
default: "type_error" \
) ((mat))

/** mat<3*3> dst = inv(mat<3*3> mat33) */
#define mat_invert(mat) _Generic((mat), \
mat33f: mat33f_invert, \
mat44f: mat44f_invert, \
mat33d: mat33d_invert, \
mat44d: mat44d_invert, \
mat33i: mat33i_invert, \
mat44i: mat44i_invert, \
default: "type_error" \
) ((mat))

#endif //MATHC_MAT_GENERIC_H
