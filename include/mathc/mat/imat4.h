#ifndef MATHC_MAT_IMAT4_H
#define MATHC_MAT_IMAT4_H

#include "imatn.h"
#include "../types.h"
#include "../vec/ivecn.h"


/** dst = r==c ? 1 : 0 (identity)  */
static imat4 imat4_eye() {
    imat4 res;
    imatN_eye(res.v, 4);
    return res;
}

/** dst = imat[row][:] */
static ivec4 imat4_get_row(imat4 imat, int row) {
    ivec4 res;
    imatN_get_row(res.v, imat.v, row, 4);
    return res;
}

/** dst = imat[:][col] */
static ivec4 imat4_get_col(imat4 imat, int col) {
    ivec4 res;
    imatN_get_col(res.v, imat.v, col, 4);
    return res;
}

/** dst = imat; dst[row][:] = ivec */
static imat4 imat4_set_row(imat4 imat, ivec4 ivec, int row) {
    imatN_set_row(imat.v, ivec.v, row, 4);
    return imat;
}

/** dst = imat; dst[:][col] = ivec */
static imat4 imat4_set_col(imat4 imat, ivec4 ivec, int col) {
    imatN_set_col(imat.v, ivec.v, col, 4);
    return imat;
}

/** dst = imat; dst[row][:] = scalar */
static imat4 imat4_row_set_sca(imat4 imat, int scalar, int row) {
    imatN_row_set_sca(imat.v, scalar, row, 4);
    return imat;
}

/** dst = imat; dst[:][col] = scalar */
static imat4 imat4_col_set_sca(imat4 imat, int scalar, int col) {
    imatN_col_set_sca(imat.v, scalar, col, 4);
    return imat;
}

/** returns sum of diagonal form upper left to lower right */
static int imat4_trace(imat4 imat) {
    return imatN_trace(imat.v, 4);
}

/** dst = imat^t */
static imat4 imat4_transpose(imat4 imat) {
    imat4 res;
    imatN_transpose_no_alias(res.v, imat.v, 4);
    return res;
}

/** dst = a @ b */
static imat4 imat4_mul_imat(imat4 imat_a, imat4 imat_b) {
    imat4 res;
    imatN_mul_imat_no_alias(res.v, imat_a.v, imat_b.v, 4);
    return res;
}

/** dst = a @ b */
static ivec4 imat4_mul_ivec(imat4 imat_a, ivec4 ivec_b) {
    ivec4 res;
    imatN_mul_ivec_no_alias(res.v, imat_a.v, ivec_b.v, 4);
    return res;
}

/** dst = a @ b */
static ivec4 ivec4_mul_imat(ivec4 ivec_a, imat4 imat_b) {
    ivec4 res;
    ivecN_mul_imat_no_alias(res.v, ivec_a.v, imat_b.v, 4);
    return res;
}

/** returns = determinant imat */
static int imat4_det(imat4 imat) {
    // from cglm/imat4.h/glm_imat4_det
    /* [square] det(A) = det(At) */
    int t[6];
    int a = imat.m[0][0], b = imat.m[0][1], c = imat.m[0][2], d = imat.m[0][3],
            e = imat.m[1][0], f = imat.m[1][1], g = imat.m[1][2], h = imat.m[1][3],
            i = imat.m[2][0], j = imat.m[2][1], k = imat.m[2][2], l = imat.m[2][3],
            m = imat.m[3][0], n = imat.m[3][1], o = imat.m[3][2], p = imat.m[3][3];

    t[0] = k * p - o * l;
    t[1] = j * p - n * l;
    t[2] = j * o - n * k;
    t[3] = i * p - m * l;
    t[4] = i * o - m * k;
    t[5] = i * n - m * j;

    return a * (f * t[0] - g * t[1] + h * t[2])
           - b * (e * t[0] - g * t[3] + h * t[4])
           + c * (e * t[1] - f * t[3] + h * t[5])
           - d * (e * t[2] - f * t[4] + g * t[5]);
}

/** dst = inverted imat */
static imat4 imat4_inv(imat4 imat) {
    // from cglm/imat4.h/glm_imat4_inv
    int t[6];
    int a = imat.m[0][0], b = imat.m[0][1], c = imat.m[0][2], d = imat.m[0][3],
            e = imat.m[1][0], f = imat.m[1][1], g = imat.m[1][2], h = imat.m[1][3],
            i = imat.m[2][0], j = imat.m[2][1], k = imat.m[2][2], l = imat.m[2][3],
            m = imat.m[3][0], n = imat.m[3][1], o = imat.m[3][2], p = imat.m[3][3];

    t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;
    t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;

    imat4 res;
    res.m[0][0] =  f * t[0] - g * t[1] + h * t[2];
    res.m[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
    res.m[2][0] =  e * t[1] - f * t[3] + h * t[5];
    res.m[3][0] =-(e * t[2] - f * t[4] + g * t[5]);

    res.m[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
    res.m[1][1] =  a * t[0] - c * t[3] + d * t[4];
    res.m[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
    res.m[3][1] =  a * t[2] - b * t[4] + c * t[5];

    t[0] = g * p - o * h; t[1] = f * p - n * h; t[2] = f * o - n * g;
    t[3] = e * p - m * h; t[4] = e * o - m * g; t[5] = e * n - m * f;

    res.m[0][2] =  b * t[0] - c * t[1] + d * t[2];
    res.m[1][2] =-(a * t[0] - c * t[3] + d * t[4]);
    res.m[2][2] =  a * t[1] - b * t[3] + d * t[5];
    res.m[3][2] =-(a * t[2] - b * t[4] + c * t[5]);

    t[0] = g * l - k * h; t[1] = f * l - j * h; t[2] = f * k - j * g;
    t[3] = e * l - i * h; t[4] = e * k - i * g; t[5] = e * j - i * f;

    res.m[0][3] =-(b * t[0] - c * t[1] + d * t[2]);
    res.m[1][3] =  a * t[0] - c * t[3] + d * t[4];
    res.m[2][3] =-(a * t[1] - b * t[3] + d * t[5]);
    res.m[3][3] =  a * t[2] - b * t[4] + c * t[5];

    int inv_det = 1.0f / (a * res.m[0][0] + b * res.m[1][0]
                  + c * res.m[2][0] + d * res.m[3][0]);

    ivecN_scale_sca(res.v, res.v, inv_det, 16);
    return res;
}


/** dst = imat[col:col+2, row:row+2] */
static imat2 imat4_get_block2(imat4 imat, int row, int col) {
    imat2 res;
    imatN_get_block(res.v, imat.v, row, col, 2, 4);
    return res;
}

/** dst = imat; dst[col:col+2, row:row+2] = block */
static imat4 imat4_set_block2(imat4 imat, imat2 block, int row, int col) {
    imatN_set_block(imat.v, block.v, row, col, 2, 4);
    return imat;
}

/** dst = imat[col:col+2, row:row+2] */
static imat3 imat4_get_block3(imat4 imat, int row, int col) {
    imat3 res;
    imatN_get_block(res.v, imat.v, row, col, 3, 4);
    return res;
}

/** dst = imat; dst[col:col+2, row:row+2] = block */
static imat4 imat4_set_block3(imat4 imat, imat3 block, int row, int col) {
    imatN_set_block(imat.v, block.v, row, col, 3, 4);
    return imat;
}

/** dst = imat[:2, :2] */
static imat2 imat4_get_upper_left2(imat4 imat) {
    return imat4_get_block2(imat, 0, 0);
}

/** dst = imat; dst[:2, :2] = block */
static imat4 imat4_set_upper_left2(imat4 imat, imat2 block) {
    return imat4_set_block2(imat, block, 0, 0);
}

/** dst = imat[:3, :3] */
static imat3 imat4_get_upper_left3(imat4 imat) {
    return imat4_get_block3(imat, 0, 0);
}

/** dst = imat; dst[:3, :3] = block */
static imat4 imat4_set_upper_left3(imat4 imat, imat3 block) {
    return imat4_set_block3(imat, block, 0, 0);
}

#endif //MATHC_MAT_IMAT4_H
