#ifndef MATHC_MAT_TYPED_H
#define MATHC_MAT_TYPED_H

#include "functions.h"


//
// this header file has the following content:
// 1. typed functions for float[2][2] as mat22f
// 2. typed functions for float[3][3] as mat33f
// 3. typed functions for float[4][4] as mat44f
// 4. typed functions for double[2][2] as mat22d
// 5. typed functions for double[3][3] as mat33d
// 6. typed functions for double[4][4] as mat44d
// 7. typed functions for int[2][2] as mat22i
// 8. typed functions for int[3][3] as mat33i
// 9. typed functions for int[4][4] as mat44i
//


//
// mat22f
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat22f mat22f_eye() {
    mat22f res;
    matf_eye(res.v, 2);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec2f mat22f_get_row(mat22f mat, int row) {
    vec2f res;
    matf_get_row(res.v, mat.v, row, 2);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec2f mat22f_get_col(mat22f mat, int col) {
    vec2f res;
    matf_get_col(res.v, mat.v, col, 2);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat22f mat22f_set_row(mat22f mat, vec2f vec, int row) {
    matf_set_row(mat.v, vec.v, row, 2);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat22f mat22f_set_col(mat22f mat, vec2f vec, int col) {
    matf_set_col(mat.v, vec.v, col, 2);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat22f mat22f_row_set_sca(mat22f mat, float scalar, int row) {
    matf_row_set_sca(mat.v, scalar, row, 2);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat22f mat22f_col_set_sca(mat22f mat, float scalar, int col) {
    matf_col_set_sca(mat.v, scalar, col, 2);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat22f mat22f_transpose(mat22f mat) {
    mat22f res;
    matf_transpose_no_alias(res.v, mat.v, 2);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat22f mat22f_mul_mat(mat22f mat_a, mat22f mat_b) {
    mat22f res;
    matf_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 2);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec2f mat22f_mul_vec(mat22f mat_a, vec2f vec_b) {
    vec2f res;
    matf_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 2);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec2f vec2f_mul_mat(vec2f vec_a, mat22f mat_b) {
    vec2f res;
    vecf_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 2);
    return res;
}

/** returns = det mat<2*2> mat22 */
static float mat22f_determinant(mat22f mat) {
    return matf_determinant22(mat.v);
}

/** mat<2*2> dst = inv(mat<2*2> mat22) */
static mat22f mat22f_invert(mat22f mat) {
    mat22f res;
    matf_invert22_no_alias(res.v, mat.v);
    return res;
}


//
// mat33f
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat33f mat33f_eye() {
    mat33f res;
    matf_eye(res.v, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec3f mat33f_get_row(mat33f mat, int row) {
    vec3f res;
    matf_get_row(res.v, mat.v, row, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec3f mat33f_get_col(mat33f mat, int col) {
    vec3f res;
    matf_get_col(res.v, mat.v, col, 3);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat33f mat33f_set_row(mat33f mat, vec3f vec, int row) {
    matf_set_row(mat.v, vec.v, row, 3);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat33f mat33f_set_col(mat33f mat, vec3f vec, int col) {
    matf_set_col(mat.v, vec.v, col, 3);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat33f mat33f_row_set_sca(mat33f mat, float scalar, int row) {
    matf_row_set_sca(mat.v, scalar, row, 3);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat33f mat33f_col_set_sca(mat33f mat, float scalar, int col) {
    matf_col_set_sca(mat.v, scalar, col, 3);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat33f mat33f_transpose(mat33f mat) {
    mat33f res;
    matf_transpose_no_alias(res.v, mat.v, 3);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat33f mat33f_mul_mat(mat33f mat_a, mat33f mat_b) {
    mat33f res;
    matf_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 3);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec3f mat33f_mul_vec(mat33f mat_a, vec3f vec_b) {
    vec3f res;
    matf_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec3f vec3f_mul_mat(vec3f vec_a, mat33f mat_b) {
    vec3f res;
    vecf_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 3);
    return res;
}

/** returns = det mat<3*3> mat33 */
static float mat33f_determinant(mat33f mat) {
    return matf_determinant33(mat.v);
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static mat33f mat33f_invert(mat33f mat) {
    mat33f res;
    matf_invert33_no_alias(res.v, mat.v);
    return res;
}


//
// mat44f
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat44f mat44f_eye() {
    mat44f res;
    matf_eye(res.v, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec4f mat44f_get_row(mat44f mat, int row) {
    vec4f res;
    matf_get_row(res.v, mat.v, row, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec4f mat44f_get_col(mat44f mat, int col) {
    vec4f res;
    matf_get_col(res.v, mat.v, col, 4);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat44f mat44f_set_row(mat44f mat, vec4f vec, int row) {
    matf_set_row(mat.v, vec.v, row, 4);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat44f mat44f_set_col(mat44f mat, vec4f vec, int col) {
    matf_set_col(mat.v, vec.v, col, 4);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat44f mat44f_row_set_sca(mat44f mat, float scalar, int row) {
    matf_row_set_sca(mat.v, scalar, row, 4);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat44f mat44f_col_set_sca(mat44f mat, float scalar, int col) {
    matf_col_set_sca(mat.v, scalar, col, 4);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat44f mat44f_transpose(mat44f mat) {
    mat44f res;
    matf_transpose_no_alias(res.v, mat.v, 4);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat44f mat44f_mul_mat(mat44f mat_a, mat44f mat_b) {
    mat44f res;
    matf_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 4);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec4f mat44f_mul_vec(mat44f mat_a, vec4f vec_b) {
    vec4f res;
    matf_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec4f vec4f_mul_mat(vec4f vec_a, mat44f mat_b) {
    vec4f res;
    vecf_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 4);
    return res;
}

/** returns = det mat<4*4> mat44 */
static float mat44f_determinant(mat44f mat) {
    return matf_determinant44(mat.v);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static mat44f mat44f_invert(mat44f mat) {
    mat44f res;
    matf_invert44_no_alias(res.v, mat.v);
    return res;
}

/** returns the rotation part [:3, :3] */
static mat33f mat44f_get_rotation(mat44f mat) {
    mat33f res;
    for(int c=0; c<3; c++) {
        for(int r=0; r<3; r++) 
            res.m[c][r] = mat.m[c][r];
    }
    return res;
}

/** sets the rotation part [:3, :3] */
static mat44f mat44f_set_rotation(mat44f mat, mat33f rotation) {
    for(int c=0; c<3; c++) {
        for(int r=0; r<3; r++) 
            mat.m[c][r] = rotation.m[c][r];
    }
    return mat;
}



//
// mat22d
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat22d mat22d_eye() {
    mat22d res;
    matd_eye(res.v, 2);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec2d mat22d_get_row(mat22d mat, int row) {
    vec2d res;
    matd_get_row(res.v, mat.v, row, 2);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec2d mat22d_get_col(mat22d mat, int col) {
    vec2d res;
    matd_get_col(res.v, mat.v, col, 2);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat22d mat22d_set_row(mat22d mat, vec2d vec, int row) {
    matd_set_row(mat.v, vec.v, row, 2);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat22d mat22d_set_col(mat22d mat, vec2d vec, int col) {
    matd_set_col(mat.v, vec.v, col, 2);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat22d mat22d_row_set_sca(mat22d mat, double scalar, int row) {
    matd_row_set_sca(mat.v, scalar, row, 2);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat22d mat22d_col_set_sca(mat22d mat, double scalar, int col) {
    matd_col_set_sca(mat.v, scalar, col, 2);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat22d mat22d_transpose(mat22d mat) {
    mat22d res;
    matd_transpose_no_alias(res.v, mat.v, 2);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat22d mat22d_mul_mat(mat22d mat_a, mat22d mat_b) {
    mat22d res;
    matd_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 2);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec2d mat22d_mul_vec(mat22d mat_a, vec2d vec_b) {
    vec2d res;
    matd_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 2);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec2d vec2d_mul_mat(vec2d vec_a, mat22d mat_b) {
    vec2d res;
    vecd_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 2);
    return res;
}

/** returns = det mat<2*2> mat22 */
static double mat22d_determinant(mat22d mat) {
    return matd_determinant22(mat.v);
}

/** mat<2*2> dst = inv(mat<2*2> mat22) */
static mat22d mat22d_invert(mat22d mat) {
    mat22d res;
    matd_invert22_no_alias(res.v, mat.v);
    return res;
}




//
// mat33d
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat33d mat33d_eye() {
    mat33d res;
    matd_eye(res.v, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec3d mat33d_get_row(mat33d mat, int row) {
    vec3d res;
    matd_get_row(res.v, mat.v, row, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec3d mat33d_get_col(mat33d mat, int col) {
    vec3d res;
    matd_get_col(res.v, mat.v, col, 3);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat33d mat33d_set_row(mat33d mat, vec3d vec, int row) {
    matd_set_row(mat.v, vec.v, row, 3);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat33d mat33d_set_col(mat33d mat, vec3d vec, int col) {
    matd_set_col(mat.v, vec.v, col, 3);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat33d mat33d_row_set_sca(mat33d mat, double scalar, int row) {
    matd_row_set_sca(mat.v, scalar, row, 3);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat33d mat33d_col_set_sca(mat33d mat, double scalar, int col) {
    matd_col_set_sca(mat.v, scalar, col, 3);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat33d mat33d_transpose(mat33d mat) {
    mat33d res;
    matd_transpose_no_alias(res.v, mat.v, 3);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat33d mat33d_mul_mat(mat33d mat_a, mat33d mat_b) {
    mat33d res;
    matd_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 3);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec3d mat33d_mul_vec(mat33d mat_a, vec3d vec_b) {
    vec3d res;
    matd_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec3d vec3d_mul_mat(vec3d vec_a, mat33d mat_b) {
    vec3d res;
    vecd_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 3);
    return res;
}

/** returns = det mat<3*3> mat33 */
static double mat33d_determinant(mat33d mat) {
    return matd_determinant33(mat.v);
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static mat33d mat33d_invert(mat33d mat) {
    mat33d res;
    matd_invert33_no_alias(res.v, mat.v);
    return res;
}


//
// mat44d
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat44d mat44d_eye() {
    mat44d res;
    matd_eye(res.v, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec4d mat44d_get_row(mat44d mat, int row) {
    vec4d res;
    matd_get_row(res.v, mat.v, row, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec4d mat44d_get_col(mat44d mat, int col) {
    vec4d res;
    matd_get_col(res.v, mat.v, col, 4);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat44d mat44d_set_row(mat44d mat, vec4d vec, int row) {
    matd_set_row(mat.v, vec.v, row, 4);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat44d mat44d_set_col(mat44d mat, vec4d vec, int col) {
    matd_set_col(mat.v, vec.v, col, 4);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat44d mat44d_row_set_sca(mat44d mat, double scalar, int row) {
    matd_row_set_sca(mat.v, scalar, row, 4);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat44d mat44d_col_set_sca(mat44d mat, double scalar, int col) {
    matd_col_set_sca(mat.v, scalar, col, 4);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat44d mat44d_transpose(mat44d mat) {
    mat44d res;
    matd_transpose_no_alias(res.v, mat.v, 4);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat44d mat44d_mul_mat(mat44d mat_a, mat44d mat_b) {
    mat44d res;
    matd_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 4);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec4d mat44d_mul_vec(mat44d mat_a, vec4d vec_b) {
    vec4d res;
    matd_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec4d vec4d_mul_mat(vec4d vec_a, mat44d mat_b) {
    vec4d res;
    vecd_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 4);
    return res;
}

/** returns = det mat<4*4> mat44 */
static double mat44d_determinant(mat44d mat) {
    return matd_determinant44(mat.v);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static mat44d mat44d_invert(mat44d mat) {
    mat44d res;
    matd_invert44_no_alias(res.v, mat.v);
    return res;
}

/** returns the rotation part [:3, :3] */
static mat33d mat44d_get_rotation(mat44d mat) {
    mat33d res;
    for(int c=0; c<3; c++) {
        for(int r=0; r<3; r++)
            res.m[c][r] = mat.m[c][r];
    }
    return res;
}

/** sets the rotation part [:3, :3] */
static mat44d mat44d_set_rotation(mat44d mat, mat33d rotation) {
    for(int c=0; c<3; c++) {
        for(int r=0; r<3; r++)
            mat.m[c][r] = rotation.m[c][r];
    }
    return mat;
}


//
// mat22i
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat22i mat22i_eye() {
    mat22i res;
    mati_eye(res.v, 2);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec2i mat22i_get_row(mat22i mat, int row) {
    vec2i res;
    mati_get_row(res.v, mat.v, row, 2);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec2i mat22i_get_col(mat22i mat, int col) {
    vec2i res;
    mati_get_col(res.v, mat.v, col, 2);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat22i mat22i_set_row(mat22i mat, vec2i vec, int row) {
    mati_set_row(mat.v, vec.v, row, 2);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat22i mat22i_set_col(mat22i mat, vec2i vec, int col) {
    mati_set_col(mat.v, vec.v, col, 2);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat22i mat22i_row_set_sca(mat22i mat, int scalar, int row) {
    mati_row_set_sca(mat.v, scalar, row, 2);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat22i mat22i_col_set_sca(mat22i mat, int scalar, int col) {
    mati_col_set_sca(mat.v, scalar, col, 2);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat22i mat22i_transpose(mat22i mat) {
    mat22i res;
    mati_transpose_no_alias(res.v, mat.v, 2);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat22i mat22i_mul_mat(mat22i mat_a, mat22i mat_b) {
    mat22i res;
    mati_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 2);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec2i mat22i_mul_vec(mat22i mat_a, vec2i vec_b) {
    vec2i res;
    mati_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 2);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec2i vec2i_mul_mat(vec2i vec_a, mat22i mat_b) {
    vec2i res;
    veci_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 2);
    return res;
}

/** returns = det mat<2*2> mat22 */
static int mat22i_determinant(mat22i mat) {
    return mati_determinant22(mat.v);
}

/** mat<2*2> dst = inv(mat<2*2> mat22) */
static mat22i mat22i_invert(mat22i mat) {
    mat22i res;
    mati_invert22_no_alias(res.v, mat.v);
    return res;
}


//
// mat33i
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat33i mat33i_eye() {
    mat33i res;
    mati_eye(res.v, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec3i mat33i_get_row(mat33i mat, int row) {
    vec3i res;
    mati_get_row(res.v, mat.v, row, 3);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec3i mat33i_get_col(mat33i mat, int col) {
    vec3i res;
    mati_get_col(res.v, mat.v, col, 3);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat33i mat33i_set_row(mat33i mat, vec3i vec, int row) {
    mati_set_row(mat.v, vec.v, row, 3);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat33i mat33i_set_col(mat33i mat, vec3i vec, int col) {
    mati_set_col(mat.v, vec.v, col, 3);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat33i mat33i_row_set_sca(mat33i mat, int scalar, int row) {
    mati_row_set_sca(mat.v, scalar, row, 3);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat33i mat33i_col_set_sca(mat33i mat, int scalar, int col) {
    mati_col_set_sca(mat.v, scalar, col, 3);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat33i mat33i_transpose(mat33i mat) {
    mat33i res;
    mati_transpose_no_alias(res.v, mat.v, 3);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat33i mat33i_mul_mat(mat33i mat_a, mat33i mat_b) {
    mat33i res;
    mati_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 3);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec3i mat33i_mul_vec(mat33i mat_a, vec3i vec_b) {
    vec3i res;
    mati_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 3);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec3i vec3i_mul_mat(vec3i vec_a, mat33i mat_b) {
    vec3i res;
    veci_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 3);
    return res;
}

/** returns = det mat<3*3> mat33 */
static int mat33i_determinant(mat33i mat) {
    return mati_determinant33(mat.v);
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static mat33i mat33i_invert(mat33i mat) {
    mat33i res;
    mati_invert33_no_alias(res.v, mat.v);
    return res;
}


//
// mat44i
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity)  */
static mat44i mat44i_eye() {
    mat44i res;
    mati_eye(res.v, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[row][:] */
static vec4i mat44i_get_row(mat44i mat, int row) {
    vec4i res;
    mati_get_row(res.v, mat.v, row, 4);
    return res;
}

/** vec<n> dst = mat<n*n>[:][col] */
static vec4i mat44i_get_col(mat44i mat, int col) {
    vec4i res;
    mati_get_col(res.v, mat.v, col, 4);
    return res;
}

/** mat<n*n>[row][:] dst = vec<n>, returns mat */
static mat44i mat44i_set_row(mat44i mat, vec4i vec, int row) {
    mati_set_row(mat.v, vec.v, row, 4);
    return mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns mat */
static mat44i mat44i_set_col(mat44i mat, vec4i vec, int col) {
    mati_set_col(mat.v, vec.v, col, 4);
    return mat;
}

/** mat<n*n>[row][:] dst = scalar, returns mat */
static mat44i mat44i_row_set_sca(mat44i mat, int scalar, int row) {
    mati_row_set_sca(mat.v, scalar, row, 4);
    return mat;
}

/** mat<n*n>[:][col] dst = scalar, returns mat */
static mat44i mat44i_col_set_sca(mat44i mat, int scalar, int col) {
    mati_col_set_sca(mat.v, scalar, col, 4);
    return mat;
}

/** mat<n*n> dst = mat<n*n>^t */
static mat44i mat44i_transpose(mat44i mat) {
    mat44i res;
    mati_transpose_no_alias(res.v, mat.v, 4);
    return res;
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static mat44i mat44i_mul_mat(mat44i mat_a, mat44i mat_b) {
    mat44i res;
    mati_mul_mat_no_alias(res.v, mat_a.v, mat_b.v, 4);
    return res;
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static vec4i mat44i_mul_vec(mat44i mat_a, vec4i vec_b) {
    vec4i res;
    mati_mul_vec_no_alias(res.v, mat_a.v, vec_b.v, 4);
    return res;
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static vec4i vec4i_mul_mat(vec4i vec_a, mat44i mat_b) {
    vec4i res;
    veci_mul_mat_no_alias(res.v, vec_a.v, mat_b.v, 4);
    return res;
}

/** returns = det mat<4*4> mat44 */
static int mat44i_determinant(mat44i mat) {
    return mati_determinant44(mat.v);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static mat44i mat44i_invert(mat44i mat) {
    mat44i res;
    mati_invert44_no_alias(res.v, mat.v);
    return res;
}

/** returns the rotation part [:3, :3] */
static mat33i mat44i_get_rotation(mat44i mat) {
    mat33i res;
    for(int c=0; c<3; c++) {
        for(int r=0; r<3; r++)
            res.m[c][r] = mat.m[c][r];
    }
    return res;
}

/** sets the rotation part [:3, :3] */
static mat44i mat44i_set_rotation(mat44i mat, mat33i rotation) {
    for(int c=0; c<3; c++) {
        for(int r=0; r<3; r++)
            mat.m[c][r] = rotation.m[c][r];
    }
    return mat;
}

#endif //MATHC_MAT_TYPED_H
