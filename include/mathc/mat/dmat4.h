#ifndef MATHC_MAT_DMAT4_H
#define MATHC_MAT_DMAT4_H

#include "dmatn.h"
#include "../types.h"
#include "../vec/dvecn.h"


/** dst = r==c ? 1 : 0 (identity)  */
static dmat4 dmat4_eye() {
    dmat4 res;
    dmatN_eye(res.v, 4);
    return res;
}

/** dst = dmat[row][:] */
static dvec4 dmat4_get_row(dmat4 dmat, int row) {
    dvec4 res;
    dmatN_get_row(res.v, dmat.v, row, 4);
    return res;
}

/** dst = dmat[:][col] */
static dvec4 dmat4_get_col(dmat4 dmat, int col) {
    dvec4 res;
    dmatN_get_col(res.v, dmat.v, col, 4);
    return res;
}

/** dst = dmat; dst[row][:] = dvec */
static dmat4 dmat4_set_row(dmat4 dmat, dvec4 dvec, int row) {
    dmatN_set_row(dmat.v, dvec.v, row, 4);
    return dmat;
}

/** dst = dmat; dst[:][col] = dvec */
static dmat4 dmat4_set_col(dmat4 dmat, dvec4 dvec, int col) {
    dmatN_set_col(dmat.v, dvec.v, col, 4);
    return dmat;
}

/** dst = dmat; dst[row][:] = scalar */
static dmat4 dmat4_row_set_sca(dmat4 dmat, double scalar, int row) {
    dmatN_row_set_sca(dmat.v, scalar, row, 4);
    return dmat;
}

/** dst = dmat; dst[:][col] = scalar */
static dmat4 dmat4_col_set_sca(dmat4 dmat, double scalar, int col) {
    dmatN_col_set_sca(dmat.v, scalar, col, 4);
    return dmat;
}

/** returns sum of diagonal form upper left to lower right */
static double dmat4_trace(dmat4 dmat) {
    return dmatN_trace(dmat.v, 4);
}

/** dst = dmat^t */
static dmat4 dmat4_transpose(dmat4 dmat) {
    dmat4 res;
    dmatN_transpose_no_alias(res.v, dmat.v, 4);
    return res;
}

/** dst = a @ b */
static dmat4 dmat4_mul_dmat(dmat4 dmat_a, dmat4 dmat_b) {
    dmat4 res;
    dmatN_mul_dmat_no_alias(res.v, dmat_a.v, dmat_b.v, 4);
    return res;
}

/** dst = a @ b */
static dvec4 dmat4_mul_dvec(dmat4 dmat_a, dvec4 dvec_b) {
    dvec4 res;
    dmatN_mul_dvec_no_alias(res.v, dmat_a.v, dvec_b.v, 4);
    return res;
}

/** dst = a @ b */
static dvec4 dvec4_mul_dmat(dvec4 dvec_a, dmat4 dmat_b) {
    dvec4 res;
    dvecN_mul_dmat_no_alias(res.v, dvec_a.v, dmat_b.v, 4);
    return res;
}

/** returns = determinant dmat */
static double dmat4_det(dmat4 dmat) {
    // from cglm/dmat4.h/glm_dmat4_det
    /* [square] det(A) = det(At) */
    double t[6];
    double a = dmat.m[0][0], b = dmat.m[0][1], c = dmat.m[0][2], d = dmat.m[0][3],
            e = dmat.m[1][0], f = dmat.m[1][1], g = dmat.m[1][2], h = dmat.m[1][3],
            i = dmat.m[2][0], j = dmat.m[2][1], k = dmat.m[2][2], l = dmat.m[2][3],
            m = dmat.m[3][0], n = dmat.m[3][1], o = dmat.m[3][2], p = dmat.m[3][3];

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

/** dst = inverted dmat */
static dmat4 dmat4_inv(dmat4 dmat) {
    // from cglm/dmat4.h/glm_dmat4_inv
    double t[6];
    double a = dmat.m[0][0], b = dmat.m[0][1], c = dmat.m[0][2], d = dmat.m[0][3],
            e = dmat.m[1][0], f = dmat.m[1][1], g = dmat.m[1][2], h = dmat.m[1][3],
            i = dmat.m[2][0], j = dmat.m[2][1], k = dmat.m[2][2], l = dmat.m[2][3],
            m = dmat.m[3][0], n = dmat.m[3][1], o = dmat.m[3][2], p = dmat.m[3][3];

    t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;
    t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;

    dmat4 res;
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

    double inv_det = 1.0 / (a * res.m[0][0] + b * res.m[1][0]
                  + c * res.m[2][0] + d * res.m[3][0]);

    dvecN_scale_sca(res.v, res.v, inv_det, 16);
    return res;
}


/** dst = dmat[col:col+2, row:row+2] */
static dmat2 dmat4_get_block2(dmat4 dmat, int row, int col) {
    dmat2 res;
    dmatN_get_block(res.v, dmat.v, row, col, 2, 4);
    return res;
}

/** dst = dmat; dst[col:col+2, row:row+2] = block */
static dmat4 dmat4_set_block2(dmat4 dmat, dmat2 block, int row, int col) {
    dmatN_set_block(dmat.v, block.v, row, col, 2, 4);
    return dmat;
}

/** dst = dmat[col:col+2, row:row+2] */
static dmat3 dmat4_get_block3(dmat4 dmat, int row, int col) {
    dmat3 res;
    dmatN_get_block(res.v, dmat.v, row, col, 3, 4);
    return res;
}

/** dst = dmat; dst[col:col+2, row:row+2] = block */
static dmat4 dmat4_set_block3(dmat4 dmat, dmat3 block, int row, int col) {
    dmatN_set_block(dmat.v, block.v, row, col, 3, 4);
    return dmat;
}

/** dst = dmat[:2, :2] */
static dmat2 dmat4_get_upper_left2(dmat4 dmat) {
    return dmat4_get_block2(dmat, 0, 0);
}

/** dst = dmat; dst[:2, :2] = block */
static dmat4 dmat4_set_upper_left2(dmat4 dmat, dmat2 block) {
    return dmat4_set_block2(dmat, block, 0, 0);
}

/** dst = dmat[:3, :3] */
static dmat3 dmat4_get_upper_left3(dmat4 dmat) {
    return dmat4_get_block3(dmat, 0, 0);
}

/** dst = dmat; dst[:3, :3] = block */
static dmat4 dmat4_set_upper_left3(dmat4 dmat, dmat3 block) {
    return dmat4_set_block3(dmat, block, 0, 0);
}

#endif //MATHC_MAT_DMAT4_H
