#ifndef MATHC_MAT_TYPED_H
#define MATHC_MAT_TYPED_H

#include "functions.h"


//
// this header file has the following content:
// 1. typed functions for float[3][3] as mat33f
// 2. typed functions for float[4][4] as mat44f
// 3. typed functions for double[3][3] as mat33d
// 4. typed functions for double[4][4] as mat44d
// 5. typed functions for int[3][3] as int33d
// 6. typed functions for int[4][4] as int44d
//


//
// vec3f (as in vec/typed.h)
//
#ifndef VEC3F_DEFINED
#define VEC3F_DEFINED
typedef struct vec3f {
    float v[3];
} vec3f;
#endif

/** casts a float * to a dereferenced vec3f */
#define Vec3f(vec) (*(vec3f *) (vec))

/** casts a float * to a dereferenced const vec3f */
#define ConstVec3f(vec) (*(const vec3f *) (vec))

//
// mat33f
//
typedef union mat33f {
    float v[9];
    float m[3][3];
    vec3f rows[3];
} mat33f;

/** casts a float * to a dereferenced mat33f */
#define Mat33f(mat) (*(mat33f *) (mat))

/** casts a float * to a dereferenced const mat33f */
#define ConstMat33f(mat) (*(const mat33f *) (mat))

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

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat33f mat33f_set_row(mat33f in_out_mat, vec3f vec, int row) {
    matf_set_row(in_out_mat.v, vec.v, row, 3);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat33f mat33f_set_col(mat33f in_out_mat, vec3f vec, int col) {
    matf_set_col(in_out_mat.v, vec.v, col, 3);
    return in_out_mat;
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat33f mat33f_row_set_sca(mat33f in_out_mat, float scalar, int row) {
    matf_row_set_sca(in_out_mat.v, scalar, row, 3);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat33f mat33f_col_set_sca(mat33f in_out_mat, float scalar, int col) {
    matf_col_set_sca(in_out_mat.v, scalar, col, 3);
    return in_out_mat;
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
// vec4f (as in vec/typed.h)
//
#ifndef VEC4F_DEFINED
#define VEC4F_DEFINED
typedef struct vec4f {
    float v[4];
} vec4f;
#endif

/** casts a float * to a dereferenced vec4f */
#define Vec4f(vec) (*(vec4f *) (vec))

/** casts a float * to a dereferenced const vec4f */
#define ConstVec4f(vec) (*(const vec4f *) (vec))


//
// mat44f
//
typedef union mat44f {
    float v[16];
    float m[4][4];
    vec4f rows[4];
} mat44f;

/** casts a float * to a dereferenced mat44f */
#define Mat44f(mat) (*(mat44f *) (mat))

/** casts a float * to a dereferenced const mat44f */
#define ConstMat44f(mat) (*(const mat44f *) (mat))

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

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat44f mat44f_set_row(mat44f in_out_mat, vec4f vec, int row) {
    matf_set_row(in_out_mat.v, vec.v, row, 4);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat44f mat44f_set_col(mat44f in_out_mat, vec4f vec, int col) {
    matf_set_col(in_out_mat.v, vec.v, col, 4);
    return in_out_mat;
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat44f mat44f_row_set_sca(mat44f in_out_mat, float scalar, int row) {
    matf_row_set_sca(in_out_mat.v, scalar, row, 4);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat44f mat44f_col_set_sca(mat44f in_out_mat, float scalar, int col) {
    matf_col_set_sca(in_out_mat.v, scalar, col, 4);
    return in_out_mat;
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


//
// vec3d (as in vec/typed.h)
//
#ifndef VEC3D_DEFINED
#define VEC3D_DEFINED
typedef struct vec3d {
    double v[3];
} vec3d;
#endif

/** casts a double * to a dereferenced vec3d */
#define Vec3d(vec) (*(vec3d *) (vec))

/** casts a double * to a dereferenced const vec3d */
#define ConstVec3d(vec) (*(const vec3d *) (vec))

//
// mat33d
//
typedef union mat33d {
    double v[9];
    double m[3][3];
    vec3d rows[3];
} mat33d;

/** casts a double * to a dereferenced mat33d */
#define Mat33d(mat) (*(mat33d *) (mat))

/** casts a double * to a dereferenced const mat33d */
#define ConstMat33d(mat) (*(const mat33d *) (mat))

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

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat33d mat33d_set_row(mat33d in_out_mat, vec3d vec, int row) {
    matd_set_row(in_out_mat.v, vec.v, row, 3);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat33d mat33d_set_col(mat33d in_out_mat, vec3d vec, int col) {
    matd_set_col(in_out_mat.v, vec.v, col, 3);
    return in_out_mat;
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat33d mat33d_row_set_sca(mat33d in_out_mat, double scalar, int row) {
    matd_row_set_sca(in_out_mat.v, scalar, row, 3);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat33d mat33d_col_set_sca(mat33d in_out_mat, double scalar, int col) {
    matd_col_set_sca(in_out_mat.v, scalar, col, 3);
    return in_out_mat;
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
// vec4d (as in vec/typed.h)
//
#ifndef VEC4D_DEFINED
#define VEC4D_DEFINED
typedef struct vec4d {
    double v[4];
} vec4d;
#endif

/** casts a double * to a dereferenced vec4d */
#define Vec4d(vec) (*(vec4d *) (vec))

/** casts a double * to a dereferenced const vec4d */
#define ConstVec4d(vec) (*(const vec4d *) (vec))

//
// mat44d
//
typedef union mat44d {
    double v[16];
    double m[4][4];
    vec4d rows[4];
} mat44d;

/** casts a double * to a dereferenced mat44d */
#define Mat44d(mat) (*(mat44d *) (mat))

/** casts a double * to a dereferenced const mat44d */
#define ConstMat44d(mat) (*(const mat44d *) (mat))


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

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat44d mat44d_set_row(mat44d in_out_mat, vec4d vec, int row) {
    matd_set_row(in_out_mat.v, vec.v, row, 4);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat44d mat44d_set_col(mat44d in_out_mat, vec4d vec, int col) {
    matd_set_col(in_out_mat.v, vec.v, col, 4);
    return in_out_mat;
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat44d mat44d_row_set_sca(mat44d in_out_mat, double scalar, int row) {
    matd_row_set_sca(in_out_mat.v, scalar, row, 4);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat44d mat44d_col_set_sca(mat44d in_out_mat, double scalar, int col) {
    matd_col_set_sca(in_out_mat.v, scalar, col, 4);
    return in_out_mat;
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

//
// vec3i (as in vec/typed.h)
//
#ifndef VEC3I_DEFINED
#define VEC3I_DEFINED
typedef struct vec3i {
    int v[3];
} vec3i;
#endif

/** casts a int * to a dereferenced vec3i */
#define Vec3i(vec) (*(vec3i *) (vec))

/** casts a int * to a dereferenced const vec3i */
#define ConstVec3i(vec) (*(const vec3i *) (vec))

//
// mat33i
//
typedef union mat33i {
    int v[9];
    int m[3][3];
    vec3i rows[3];
} mat33i;

/** casts a int * to a dereferenced mat33i */
#define Mat33i(mat) (*(mat33i *) (mat))

/** casts a int * to a dereferenced const mat33i */
#define ConstMat33i(mat) (*(const mat33i *) (mat))


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

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat33i mat33i_set_row(mat33i in_out_mat, vec3i vec, int row) {
    mati_set_row(in_out_mat.v, vec.v, row, 3);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat33i mat33i_set_col(mat33i in_out_mat, vec3i vec, int col) {
    mati_set_col(in_out_mat.v, vec.v, col, 3);
    return in_out_mat;
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat33i mat33i_row_set_sca(mat33i in_out_mat, int scalar, int row) {
    mati_row_set_sca(in_out_mat.v, scalar, row, 3);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat33i mat33i_col_set_sca(mat33i in_out_mat, int scalar, int col) {
    mati_col_set_sca(in_out_mat.v, scalar, col, 3);
    return in_out_mat;
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
// vec4i (as in vec/typed.h)
//
#ifndef VEC4I_DEFINED
#define VEC4I_DEFINED
typedef struct vec4i {
    int v[4];
} vec4i;
#endif

/** casts a int * to a dereferenced vec4i */
#define Vec4i(vec) (*(vec4i *) (vec))

/** casts a int * to a dereferenced const vec4i */
#define ConstVec4i(vec) (*(const vec4i *) (vec))

//
// mat44i
//
typedef union mat44i {
    int v[16];
    int m[4][4];
    vec4i rows[4];
} mat44i;

/** casts a int * to a dereferenced mat44i */
#define Mat44i(mat) (*(mat44i *) (mat))

/** casts a int * to a dereferenced const mat44i */
#define ConstMat44i(mat) (*(const mat44i *) (mat))


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

/** mat<n*n>[row][:] dst = vec<n>, returns in_out_mat */
static mat44i mat44i_set_row(mat44i in_out_mat, vec4i vec, int row) {
    mati_set_row(in_out_mat.v, vec.v, row, 4);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = vec<n>, returns in_out_mat */
static mat44i mat44i_set_col(mat44i in_out_mat, vec4i vec, int col) {
    mati_set_col(in_out_mat.v, vec.v, col, 4);
    return in_out_mat;
}

/** mat<n*n>[row][:] dst = scalar, returns in_out_mat */
static mat44i mat44i_row_set_sca(mat44i in_out_mat, int scalar, int row) {
    mati_row_set_sca(in_out_mat.v, scalar, row, 4);
    return in_out_mat;
}

/** mat<n*n>[:][col] dst = scalar, returns in_out_mat */
static mat44i mat44i_col_set_sca(mat44i in_out_mat, int scalar, int col) {
    mati_col_set_sca(in_out_mat.v, scalar, col, 4);
    return in_out_mat;
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

#endif //MATHC_MAT_TYPED_H
