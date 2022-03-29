#ifndef MATHC_MAT_MAT__X___H
#define MATHC_MAT_MAT__X___H

/*/ 0 /*/   // template file!
/*/ 0 /*/   //
/*/ 0 /*/   // __X__ will be replaced by X=[2, 3, 4, ...]
/*/ 0 /*/   //
/*/ 0 /*/   // all lines starting with "/*/ cond /*/[//]" may be removed
/*/ 0 /*/   // if cond is true:
/*/ 0 /*/   //      only the condition comment will be removed "/*/ cond /*/)"
/*/ 0 /*/   // if cond is false:
/*/ 0 /*/   //      the whole line will be removed
/*/ 0 /*/
/*/ 0 /*/   // the following setup is just here to pleasure an ide
/*/ 0 /*/ #include "../../out/mathc/types/vec2.h"
/*/ 0 /*/ #include "../../out/mathc/types/mat2.h"
/*/ 0 /*/ #include "../../out/mathc/types/vec3.h"
/*/ 0 /*/ #include "../../out/mathc/types/mat3.h"
/*/ 0 /*/ #include "../../out/mathc/types/vec4.h"
/*/ 0 /*/ #include "../../out/mathc/types/mat4.h"
/*/ 0 /*/ typedef vec4 vec__X__;
/*/ 0 /*/ typedef mat4 mat__X__;
/*/ 0 /*/ #define __X__ 4

#include "matn.h"
/*/ 1 /*///#include "../types/mat__X__.h"
/*/ X==3 /*///#include "../types/mat2.h"
/*/ X==4 /*///#include "../types/mat2.h"
/*/ X==4 /*///#include "../types/mat3.h"
#include "../vec/vecn.h"


/** dst = r==c ? 1 : 0 (identity)  */
static mat__X__ mat__X___eye() {
    mat__X__ res;
    matN_eye(res.v, __X__);
    return res;
}

/** a == b */
static bool mat__X___cmp(mat__X__ a, mat__X__ b) {
    return vecN_cmp(a.v, b.v, __X__ * __X__);
}


/** dst = m[row][:] */
static vec__X__ mat__X___get_row(mat__X__ m, int row) {
    vec__X__ res;
    matN_get_row(res.v, m.v, row, __X__);
    return res;
}


/** dst = m[:][col] */
static vec__X__ mat__X___get_col(mat__X__ m, int col) {
    vec__X__ res;
    matN_get_col(res.v, m.v, col, __X__);
    return res;
}


/** dst = m; dst[row][:] = v */
static mat__X__ mat__X___set_row(mat__X__ m, vec__X__ v, int row) {
    matN_set_row(m.v, v.v, row, __X__);
    return m;
}

/** m[row][:] = v; dst = m */
static mat__X__ mat__X___set_this_row(mat__X__ *m, vec__X__ v, int row) {
    matN_set_row(m->v, v.v, row, __X__);
    return *m;
}

/** dst = m; dst[:][col] = v */
static mat__X__ mat__X___set_col(mat__X__ m, vec__X__ v, int col) {
    matN_set_col(m.v, v.v, col, __X__);
    return m;
}

/** mat[:][col] = v; dst = m */
static mat__X__ mat__X___set_this_col(mat__X__ *mat, vec__X__ v, int col) {
    matN_set_col(mat->v, v.v, col, __X__);
    return *mat;
}


/** dst = m; dst[row][:] = s */
static mat__X__ mat__X___set_row_sca(mat__X__ m, float s, int row) {
    matN_set_row_sca(m.v, s, row, __X__);
    return m;
}

/** m[row][:] = s; dst = m */
static mat__X__ mat__X___set_this_row_sca(mat__X__ *m, float s, int row) {
    matN_set_row_sca(m->v, s, row, __X__);
    return *m;
}


/** dst = m; dst[:][col] = s */
static mat__X__ mat__X___set_col_sca(mat__X__ m, float s, int col) {
    matN_set_col_sca(m.v, s, col, __X__);
    return m;
}

/** m[:][col] = s; dst = m */
static mat__X__ mat__X___set_this_col_sca(mat__X__ *m, float s, int col) {
    matN_set_col_sca(m->v, s, col, __X__);
    return *m;
}


/** returns sum of diagonal form upper left to lower right */
static float mat__X___trace(mat__X__ m) {
    return matN_trace(m.v, __X__);
}


/** dst = m^t */
static mat__X__ mat__X___transpose(mat__X__ m) {
    mat__X__ res;
    matN_transpose_no_alias(res.v, m.v, __X__);
    return res;
}


/** dst = a @ b */
static mat__X__ mat__X___mul_mat(mat__X__ a, mat__X__ b) {
    mat__X__ res;
    matN_mul_mat_no_alias(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a @ b */
static vec__X__ mat__X___mul_vec(mat__X__ a, vec__X__ b) {
    vec__X__ res;
    matN_mul_vec_no_alias(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a @ b */
static vec__X__ vec__X___mul_mat(vec__X__ a, mat__X__ b) {
    vec__X__ res;
    vecN_mul_mat_no_alias(res.v, a.v, b.v, __X__);
    return res;
}

/*/ X==2 /*//** returns = determinant m */
/*/ X==2 /*/static float mat2_det(mat2 m) {
/*/ X==2 /*/    // from cglm/mat2.h/glm_mat2_det
/*/ X==2 /*/    return m.m[0][0] * m.m[1][1] - m.m[1][0] * m.m[0][1];
/*/ X==2 /*/}
/*/ X==2 /*/
/*/ X==2 /*/
/*/ X==2 /*//** dst = inverted m */
/*/ X==2 /*/static mat2 mat2_inv(mat2 m) {
/*/ X==2 /*/    // from cglm/mat2.h/glm_mat2_inv
/*/ X==2 /*/    float a = m.m[0][0], b = m.m[0][1];
/*/ X==2 /*/    float c = m.m[1][0], d = m.m[1][1];
/*/ X==2 /*/
/*/ X==2 /*/    mat2 res;
/*/ X==2 /*/    res.m[0][0] = d;
/*/ X==2 /*/    res.m[0][1] = -b;
/*/ X==2 /*/    res.m[1][0] = -c;
/*/ X==2 /*/    res.m[1][1] = a;
/*/ X==2 /*/
/*/ X==2 /*/    float det = a * d - b * c;
/*/ X==2 /*/    vecN_div(res.v, res.v, det, 4);
/*/ X==2 /*/
/*/ X==2 /*/    return res;
/*/ X==2 /*/}

/*/ X==3 /*//** returns = determinant m */
/*/ X==3 /*/static float mat3_det(mat3 m) {
/*/ X==3 /*/    // from cglm/mat3.h/glm_mat3_det
/*/ X==3 /*/    float a = m.m[0][0], b = m.m[0][1], c = m.m[0][2];
/*/ X==3 /*/    float d = m.m[1][0], e = m.m[1][1], f = m.m[1][2];
/*/ X==3 /*/    float g = m.m[2][0], h = m.m[2][1], i = m.m[2][2];
/*/ X==3 /*/
/*/ X==3 /*/    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = inverted m */
/*/ X==3 /*/static mat3 mat3_inv(mat3 m) {
/*/ X==3 /*/    // from cglm/mat3.h/glm_mat3_inv
/*/ X==3 /*/    float a = m.m[0][0], b = m.m[0][1], c = m.m[0][2];
/*/ X==3 /*/    float d = m.m[1][0], e = m.m[1][1], f = m.m[1][2];
/*/ X==3 /*/    float g = m.m[2][0], h = m.m[2][1], i = m.m[2][2];
/*/ X==3 /*/
/*/ X==3 /*/    mat3 res;
/*/ X==3 /*/    res.m[0][0] = e * i - f * h;
/*/ X==3 /*/    res.m[0][1] = -(b * i - h * c);
/*/ X==3 /*/    res.m[0][2] = b * f - e * c;
/*/ X==3 /*/    res.m[1][0] = -(d * i - g * f);
/*/ X==3 /*/    res.m[1][1] = a * i - c * g;
/*/ X==3 /*/    res.m[1][2] = -(a * f - d * c);
/*/ X==3 /*/    res.m[2][0] = d * h - g * e;
/*/ X==3 /*/    res.m[2][1] = -(a * h - g * b);
/*/ X==3 /*/    res.m[2][2] = a * e - b * d;
/*/ X==3 /*/
/*/ X==3 /*/    float det = a * res.m[0][0] + b * res.m[1][0] + c * res.m[2][0];
/*/ X==3 /*/    vecN_div(res.v, res.v, det, 9);
/*/ X==3 /*/
/*/ X==3 /*/    return res;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m[col:col+2, row:row+2] */
/*/ X==3 /*/static mat2 mat3_get_block2(mat3 m, int row, int col) {
/*/ X==3 /*/    mat2 res;
/*/ X==3 /*/    matN_get_block(res.v, m.v, row, col, 2, 3);
/*/ X==3 /*/    return res;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m; dst[col:col+2, row:row+2] = block */
/*/ X==3 /*/static mat3 mat3_set_block2(mat3 m, mat2 block_2, int row, int col) {
/*/ X==3 /*/    matN_set_block(m.v, block_2.v, row, col, 2, 3);
/*/ X==3 /*/    return m;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*//** m[col:col+2, row:row+2] = block; dst = m */
/*/ X==3 /*/static mat3 mat3_set_this_block2(mat3 *m, mat2 block_2, int row, int col) {
/*/ X==3 /*/    matN_set_block(m->v, block_2.v, row, col, 2, 3);
/*/ X==3 /*/    return *m;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m[:2, :2] */
/*/ X==3 /*/static mat2 mat3_get_upper_left(mat3 m) {
/*/ X==3 /*/    return mat3_get_block2(m, 0, 0);
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m; dst[:2, :2] = block */
/*/ X==3 /*/static mat3 mat3_set_upper_left(mat3 m, mat2 block_2) {
/*/ X==3 /*/    return mat3_set_block2(m, block_2, 0, 0);
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** m[:2, :2] = block; dst = m */
/*/ X==3 /*/static mat3 mat3_set_this_upper_left(mat3 *m, mat2 block_2) {
/*/ X==3 /*/    return mat3_set_this_block2(m, block_2, 0, 0);
/*/ X==3 /*/}

/*/ X==4 /*//** returns = determinant mm */
/*/ X==4 /*/static float mat4_det(mat4 mm) {
/*/ X==4 /*/    // from cglm/mat4.h/glm_mat4_det
/*/ X==4 /*/    /* [square] det(A) = det(At) */
/*/ X==4 /*/    float t[6];
/*/ X==4 /*/    float a = mm.m[0][0], b = mm.m[0][1], c = mm.m[0][2], d = mm.m[0][3],
/*/ X==4 /*/            e = mm.m[1][0], f = mm.m[1][1], g = mm.m[1][2], h = mm.m[1][3],
/*/ X==4 /*/            i = mm.m[2][0], j = mm.m[2][1], k = mm.m[2][2], l = mm.m[2][3],
/*/ X==4 /*/            m = mm.m[3][0], n = mm.m[3][1], o = mm.m[3][2], p = mm.m[3][3];
/*/ X==4 /*/
/*/ X==4 /*/    t[0] = k * p - o * l;
/*/ X==4 /*/    t[1] = j * p - n * l;
/*/ X==4 /*/    t[2] = j * o - n * k;
/*/ X==4 /*/    t[3] = i * p - m * l;
/*/ X==4 /*/    t[4] = i * o - m * k;
/*/ X==4 /*/    t[5] = i * n - m * j;
/*/ X==4 /*/
/*/ X==4 /*/    return a * (f * t[0] - g * t[1] + h * t[2])
/*/ X==4 /*/           - b * (e * t[0] - g * t[3] + h * t[4])
/*/ X==4 /*/           + c * (e * t[1] - f * t[3] + h * t[5])
/*/ X==4 /*/           - d * (e * t[2] - f * t[4] + g * t[5]);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = inverted mm */
/*/ X==4 /*/static mat4 mat4_inv(mat4 mm) {
/*/ X==4 /*/    // from cglm/mat4.h/glm_mat4_inv
/*/ X==4 /*/    float t[6];
/*/ X==4 /*/    float a = mm.m[0][0], b = mm.m[0][1], c = mm.m[0][2], d = mm.m[0][3];
/*/ X==4 /*/    float e = mm.m[1][0], f = mm.m[1][1], g = mm.m[1][2], h = mm.m[1][3];
/*/ X==4 /*/    float i = mm.m[2][0], j = mm.m[2][1], k = mm.m[2][2], l = mm.m[2][3];
/*/ X==4 /*/    float m = mm.m[3][0], n = mm.m[3][1], o = mm.m[3][2], p = mm.m[3][3];
/*/ X==4 /*/
/*/ X==4 /*/    t[0] = k * p - o * l;
/*/ X==4 /*/    t[1] = j * p - n * l;
/*/ X==4 /*/    t[2] = j * o - n * k;
/*/ X==4 /*/    t[3] = i * p - m * l;
/*/ X==4 /*/    t[4] = i * o - m * k;
/*/ X==4 /*/    t[5] = i * n - m * j;
/*/ X==4 /*/
/*/ X==4 /*/    mat4 res;
/*/ X==4 /*/    res.m[0][0] = f * t[0] - g * t[1] + h * t[2];
/*/ X==4 /*/    res.m[1][0] = -(e * t[0] - g * t[3] + h * t[4]);
/*/ X==4 /*/    res.m[2][0] = e * t[1] - f * t[3] + h * t[5];
/*/ X==4 /*/    res.m[3][0] = -(e * t[2] - f * t[4] + g * t[5]);
/*/ X==4 /*/
/*/ X==4 /*/    res.m[0][1] = -(b * t[0] - c * t[1] + d * t[2]);
/*/ X==4 /*/    res.m[1][1] = a * t[0] - c * t[3] + d * t[4];
/*/ X==4 /*/    res.m[2][1] = -(a * t[1] - b * t[3] + d * t[5]);
/*/ X==4 /*/    res.m[3][1] = a * t[2] - b * t[4] + c * t[5];
/*/ X==4 /*/
/*/ X==4 /*/    t[0] = g * p - o * h;
/*/ X==4 /*/    t[1] = f * p - n * h;
/*/ X==4 /*/    t[2] = f * o - n * g;
/*/ X==4 /*/    t[3] = e * p - m * h;
/*/ X==4 /*/    t[4] = e * o - m * g;
/*/ X==4 /*/    t[5] = e * n - m * f;
/*/ X==4 /*/
/*/ X==4 /*/    res.m[0][2] = b * t[0] - c * t[1] + d * t[2];
/*/ X==4 /*/    res.m[1][2] = -(a * t[0] - c * t[3] + d * t[4]);
/*/ X==4 /*/    res.m[2][2] = a * t[1] - b * t[3] + d * t[5];
/*/ X==4 /*/    res.m[3][2] = -(a * t[2] - b * t[4] + c * t[5]);
/*/ X==4 /*/
/*/ X==4 /*/    t[0] = g * l - k * h;
/*/ X==4 /*/    t[1] = f * l - j * h;
/*/ X==4 /*/    t[2] = f * k - j * g;
/*/ X==4 /*/    t[3] = e * l - i * h;
/*/ X==4 /*/    t[4] = e * k - i * g;
/*/ X==4 /*/    t[5] = e * j - i * f;
/*/ X==4 /*/
/*/ X==4 /*/    res.m[0][3] = -(b * t[0] - c * t[1] + d * t[2]);
/*/ X==4 /*/    res.m[1][3] = a * t[0] - c * t[3] + d * t[4];
/*/ X==4 /*/    res.m[2][3] = -(a * t[1] - b * t[3] + d * t[5]);
/*/ X==4 /*/    res.m[3][3] = a * t[2] - b * t[4] + c * t[5];
/*/ X==4 /*/
/*/ X==4 /*/    float det = a * res.m[0][0] + b * res.m[1][0] + c * res.m[2][0] + d * res.m[3][0];
/*/ X==4 /*/    vecN_div(res.v, res.v, det, 16);
/*/ X==4 /*/
/*/ X==4 /*/    return res;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[col:col+2, row:row+2] */
/*/ X==4 /*/static mat2 mat4_get_block2(mat4 m, int row, int col) {
/*/ X==4 /*/    mat2 res;
/*/ X==4 /*/    matN_get_block(res.v, m.v, row, col, 2, 4);
/*/ X==4 /*/    return res;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[col:col+2, row:row+2] = block */
/*/ X==4 /*/static mat4 mat4_set_block2(mat4 m, mat2 block_2, int row, int col) {
/*/ X==4 /*/    matN_set_block(m.v, block_2.v, row, col, 2, 4);
/*/ X==4 /*/    return m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** m[col:col+2, row:row+2] = block; dst = m */
/*/ X==4 /*/static mat4 mat4_set_this_block2(mat4 *m, mat2 block_2, int row, int col) {
/*/ X==4 /*/    matN_set_block(m->v, block_2.v, row, col, 2, 4);
/*/ X==4 /*/    return *m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[col:col+2, row:row+2] */
/*/ X==4 /*/static mat3 mat4_get_block3(mat4 m, int row, int col) {
/*/ X==4 /*/    mat3 res;
/*/ X==4 /*/    matN_get_block(res.v, m.v, row, col, 3, 4);
/*/ X==4 /*/    return res;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[col:col+2, row:row+2] = block */
/*/ X==4 /*/static mat4 mat4_set_block3(mat4 m, mat3 block_3, int row, int col) {
/*/ X==4 /*/    matN_set_block(m.v, block_3.v, row, col, 3, 4);
/*/ X==4 /*/    return m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** m[col:col+2, row:row+2] = block; dst = m */
/*/ X==4 /*/static mat4 mat4_set_this_block3(mat4 *m, mat3 block_3, int row, int col) {
/*/ X==4 /*/    matN_set_block(m->v, block_3.v, row, col, 3, 4);
/*/ X==4 /*/    return *m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[:2, :2] */
/*/ X==4 /*/static mat2 mat4_get_upper_left2(mat4 m) {
/*/ X==4 /*/    return mat4_get_block2(m, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[:2, :2] = block */
/*/ X==4 /*/static mat4 mat4_set_upper_left2(mat4 m, mat2 block_2) {
/*/ X==4 /*/    return mat4_set_block2(m, block_2, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** m[:2, :2] = block; dst = m */
/*/ X==4 /*/static mat4 mat4_set_this_upper_left2(mat4 *m, mat2 block_2) {
/*/ X==4 /*/    return mat4_set_this_block2(m, block_2, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[:3, :3] */
/*/ X==4 /*/static mat3 mat4_get_upper_left3(mat4 m) {
/*/ X==4 /*/    return mat4_get_block3(m, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[:3, :3] = block */
/*/ X==4 /*/static mat4 mat4_set_upper_left3(mat4 m, mat3 block_3) {
/*/ X==4 /*/    return mat4_set_block3(m, block_3, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** m[:3, :3] = block; dst = m */
/*/ X==4 /*/static mat4 mat4_set_this_upper_left3(mat4 *m, mat3 block_3) {
/*/ X==4 /*/    return mat4_set_this_block3(m, block_3, 0, 0);
/*/ X==4 /*/}

#endif //MATHC_MAT_MAT__X___H
