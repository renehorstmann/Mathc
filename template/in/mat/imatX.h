#ifndef MATHC_MAT_IMAT__X___H
#define MATHC_MAT_IMAT__X___H

#include "imatn.h"
#include "../types/int.h"
#include "../vec/ivecn.h"

/*/ 0 /*/   // template file!
/*/ 0 /*/   //
/*/ 0 /*/   // __X__ will be replaced by X=[2, 3, 4]
/*/ 0 /*/   //
/*/ 0 /*/   // all lines starting with "/*/ cond /*/" may be removed
/*/ 0 /*/   // if cond is true:
/*/ 0 /*/   //      only the condition comment will be removed "/*/ cond /*/)"
/*/ 0 /*/   // if cond is false:
/*/ 0 /*/   //      the whole line will be removed
/*/ 0 /*/
/*/ 0 /*/   // the following setup is just here to pleasure an ide
/*/ 0 /*/ typedef ivec4 ivec__X__;
/*/ 0 /*/ typedef imat4 imat__X__;
/*/ 0 /*/ int __X__ = 4;


/** dst = r==c ? 1 : 0 (identity)  */
static imat__X__ imat__X___eye() {
    imat__X__ res;
    imatN_eye(res.v, __X__);
    return res;
}

/** a == b */
static bool imat__X___cmp(imat__X__ a, imat__X__ b) {
    return ivecN_cmp(a.v, b.v, __X__ * __X__);
}


/** dst = m[row][:] */
static ivec__X__ imat__X___get_row(imat__X__ m, int row) {
    ivec__X__ res;
    imatN_get_row(res.v, m.v, row, __X__);
    return res;
}


/** dst = m[:][col] */
static ivec__X__ imat__X___get_col(imat__X__ m, int col) {
    ivec__X__ res;
    imatN_get_col(res.v, m.v, col, __X__);
    return res;
}


/** dst = m; dst[row][:] = v */
static imat__X__ imat__X___set_row(imat__X__ m, ivec__X__ v, int row) {
    imatN_set_row(m.v, v.v, row, __X__);
    return m;
}

/** m[row][:] = v; dst = m */
static imat__X__ imat__X___set_this_row(imat__X__ *m, ivec__X__ v, int row) {
    imatN_set_row(m->v, v.v, row, __X__);
    return *m;
}

/** dst = m; dst[:][col] = v */
static imat__X__ imat__X___set_col(imat__X__ m, ivec__X__ v, int col) {
    imatN_set_col(m.v, v.v, col, __X__);
    return m;
}

/** imat[:][col] = v; dst = m */
static imat__X__ imat__X___set_this_col(imat__X__ *imat, ivec__X__ v, int col) {
    imatN_set_col(imat->v, v.v, col, __X__);
    return *imat;
}


/** dst = m; dst[row][:] = s */
static imat__X__ imat__X___set_row_sca(imat__X__ m, float s, int row) {
    imatN_set_row_sca(m.v, s, row, __X__);
    return m;
}

/** m[row][:] = s; dst = m */
static imat__X__ imat__X___set_this_row_sca(imat__X__ *m, float s, int row) {
    imatN_set_row_sca(m->v, s, row, __X__);
    return *m;
}


/** dst = m; dst[:][col] = s */
static imat__X__ imat__X___set_col_sca(imat__X__ m, float s, int col) {
    imatN_set_col_sca(m.v, s, col, __X__);
    return m;
}

/** m[:][col] = s; dst = m */
static imat__X__ imat__X___set_this_col_sca(imat__X__ *m, float s, int col) {
    imatN_set_col_sca(m->v, s, col, __X__);
    return *m;
}


/** returns sum of diagonal form upper left to lower right */
static float imat__X___trace(imat__X__ m) {
    return imatN_trace(m.v, __X__);
}


/** dst = m^t */
static imat__X__ imat__X___transpose(imat__X__ m) {
    imat__X__ res;
    imatN_transpose_no_alias(res.v, m.v, __X__);
    return res;
}


/** dst = a @ b */
static imat__X__ imat__X___mul_mat(imat__X__ a, imat__X__ b) {
    imat__X__ res;
    imatN_mul_mat_no_alias(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a @ b */
static ivec__X__ imat__X___mul_vec(imat__X__ a, ivec__X__ b) {
    ivec__X__ res;
    imatN_mul_vec_no_alias(res.v, a.v, b.v, __X__);
    return res;
}


/** dst = a @ b */
static ivec__X__ ivec__X___mul_mat(ivec__X__ a, imat__X__ b) {
    ivec__X__ res;
    ivecN_mul_mat_no_alias(res.v, a.v, b.v, __X__);
    return res;
}

/*/ X==2 /*//** returns = determinant m */
/*/ X==2 /*/static float imat2_det(imat2 m) {
/*/ X==2 /*/    // from cglm/imat2.h/glm_mat2_det
/*/ X==2 /*/    return m.m[0][0] * m.m[1][1] - m.m[1][0] * m.m[0][1];
/*/ X==2 /*/}
/*/ X==2 /*/
/*/ X==2 /*/
/*/ X==2 /*//** dst = inverted m */
/*/ X==2 /*/static imat2 imat2_inv(imat2 m) {
/*/ X==2 /*/    // from cglm/imat2.h/glm_mat2_inv
/*/ X==2 /*/    float a = m.m[0][0], b = m.m[0][1];
/*/ X==2 /*/    float c = m.m[1][0], d = m.m[1][1];
/*/ X==2 /*/
/*/ X==2 /*/    imat2 res;
/*/ X==2 /*/    res.m[0][0] = d;
/*/ X==2 /*/    res.m[0][1] = -b;
/*/ X==2 /*/    res.m[1][0] = -c;
/*/ X==2 /*/    res.m[1][1] = a;
/*/ X==2 /*/
/*/ X==2 /*/    float det = a * d - b * c;
/*/ X==2 /*/    ivecN_div(res.v, res.v, det, 4);
/*/ X==2 /*/
/*/ X==2 /*/    return res;
/*/ X==2 /*/}

/*/ X==3 /*//** returns = determinant m */
/*/ X==3 /*/static float imat3_det(imat3 m) {
/*/ X==3 /*/    // from cglm/imat3.h/glm_mat3_det
/*/ X==3 /*/    float a = m.m[0][0], b = m.m[0][1], c = m.m[0][2];
/*/ X==3 /*/    float d = m.m[1][0], e = m.m[1][1], f = m.m[1][2];
/*/ X==3 /*/    float g = m.m[2][0], h = m.m[2][1], i = m.m[2][2];
/*/ X==3 /*/
/*/ X==3 /*/    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = inverted m */
/*/ X==3 /*/static imat3 imat3_inv(imat3 m) {
/*/ X==3 /*/    // from cglm/imat3.h/glm_mat3_inv
/*/ X==3 /*/    float a = m.m[0][0], b = m.m[0][1], c = m.m[0][2];
/*/ X==3 /*/    float d = m.m[1][0], e = m.m[1][1], f = m.m[1][2];
/*/ X==3 /*/    float g = m.m[2][0], h = m.m[2][1], i = m.m[2][2];
/*/ X==3 /*/
/*/ X==3 /*/    imat3 res;
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
/*/ X==3 /*/    ivecN_div(res.v, res.v, det, 9);
/*/ X==3 /*/
/*/ X==3 /*/    return res;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m[col:col+2, row:row+2] */
/*/ X==3 /*/static imat2 imat3_get_block2(imat3 m, int row, int col) {
/*/ X==3 /*/    imat2 res;
/*/ X==3 /*/    imatN_get_block(res.v, m.v, row, col, 2, 3);
/*/ X==3 /*/    return res;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m; dst[col:col+2, row:row+2] = block */
/*/ X==3 /*/static imat3 imat3_set_block2(imat3 m, imat2 block_2, int row, int col) {
/*/ X==3 /*/    imatN_set_block(m.v, block_2.v, row, col, 2, 3);
/*/ X==3 /*/    return m;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*//** m[col:col+2, row:row+2] = block; dst = m */
/*/ X==3 /*/static imat3 imat3_set_this_block2(imat3 *m, imat2 block_2, int row, int col) {
/*/ X==3 /*/    imatN_set_block(m->v, block_2.v, row, col, 2, 3);
/*/ X==3 /*/    return *m;
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m[:2, :2] */
/*/ X==3 /*/static imat2 imat3_get_upper_left(imat3 m) {
/*/ X==3 /*/    return imat3_get_block2(m, 0, 0);
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** dst = m; dst[:2, :2] = block */
/*/ X==3 /*/static imat3 imat3_set_upper_left(imat3 m, imat2 block_2) {
/*/ X==3 /*/    return imat3_set_block2(m, block_2, 0, 0);
/*/ X==3 /*/}
/*/ X==3 /*/
/*/ X==3 /*/
/*/ X==3 /*//** m[:2, :2] = block; dst = m */
/*/ X==3 /*/static imat3 imat3_set_this_upper_left(imat3 *m, imat2 block_2) {
/*/ X==3 /*/    return imat3_set_this_block2(m, block_2, 0, 0);
/*/ X==3 /*/}

/*/ X==4 /*//** returns = determinant mm */
/*/ X==4 /*/static float imat4_det(imat4 mm) {
/*/ X==4 /*/    // from cglm/imat4.h/glm_mat4_det
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
/*/ X==4 /*/static imat4 imat4_inv(imat4 mm) {
/*/ X==4 /*/    // from cglm/imat4.h/glm_mat4_inv
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
/*/ X==4 /*/    imat4 res;
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
/*/ X==4 /*/    ivecN_div(res.v, res.v, det, 16);
/*/ X==4 /*/
/*/ X==4 /*/    return res;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[col:col+2, row:row+2] */
/*/ X==4 /*/static imat2 imat4_get_block2(imat4 m, int row, int col) {
/*/ X==4 /*/    imat2 res;
/*/ X==4 /*/    imatN_get_block(res.v, m.v, row, col, 2, 4);
/*/ X==4 /*/    return res;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[col:col+2, row:row+2] = block */
/*/ X==4 /*/static imat4 imat4_set_block2(imat4 m, imat2 block_2, int row, int col) {
/*/ X==4 /*/    imatN_set_block(m.v, block_2.v, row, col, 2, 4);
/*/ X==4 /*/    return m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** m[col:col+2, row:row+2] = block; dst = m */
/*/ X==4 /*/static imat4 imat4_set_this_block2(imat4 *m, imat2 block_2, int row, int col) {
/*/ X==4 /*/    imatN_set_block(m->v, block_2.v, row, col, 2, 4);
/*/ X==4 /*/    return *m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[col:col+2, row:row+2] */
/*/ X==4 /*/static imat3 imat4_get_block3(imat4 m, int row, int col) {
/*/ X==4 /*/    imat3 res;
/*/ X==4 /*/    imatN_get_block(res.v, m.v, row, col, 3, 4);
/*/ X==4 /*/    return res;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[col:col+2, row:row+2] = block */
/*/ X==4 /*/static imat4 imat4_set_block3(imat4 m, imat3 block_3, int row, int col) {
/*/ X==4 /*/    imatN_set_block(m.v, block_3.v, row, col, 3, 4);
/*/ X==4 /*/    return m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** m[col:col+2, row:row+2] = block; dst = m */
/*/ X==4 /*/static imat4 imat4_set_this_block3(imat4 *m, imat3 block_3, int row, int col) {
/*/ X==4 /*/    imatN_set_block(m->v, block_3.v, row, col, 3, 4);
/*/ X==4 /*/    return *m;
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[:2, :2] */
/*/ X==4 /*/static imat2 imat4_get_upper_left2(imat4 m) {
/*/ X==4 /*/    return imat4_get_block2(m, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[:2, :2] = block */
/*/ X==4 /*/static imat4 imat4_set_upper_left2(imat4 m, imat2 block_2) {
/*/ X==4 /*/    return imat4_set_block2(m, block_2, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** m[:2, :2] = block; dst = m */
/*/ X==4 /*/static imat4 imat4_set_this_upper_left2(imat4 *m, imat2 block_2) {
/*/ X==4 /*/    return imat4_set_this_block2(m, block_2, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m[:3, :3] */
/*/ X==4 /*/static imat3 imat4_get_upper_left3(imat4 m) {
/*/ X==4 /*/    return imat4_get_block3(m, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*/
/*/ X==4 /*//** dst = m; dst[:3, :3] = block */
/*/ X==4 /*/static imat4 imat4_set_upper_left3(imat4 m, imat3 block_3) {
/*/ X==4 /*/    return imat4_set_block3(m, block_3, 0, 0);
/*/ X==4 /*/}
/*/ X==4 /*/
/*/ X==4 /*//** m[:3, :3] = block; dst = m */
/*/ X==4 /*/static imat4 imat4_set_this_upper_left3(imat4 *m, imat3 block_3) {
/*/ X==4 /*/    return imat4_set_this_block3(m, block_3, 0, 0);
/*/ X==4 /*/}

#endif //MATHC_MAT_IMAT__X___H
