#ifndef MATHC_MAT_DMAT4_V_H
#define MATHC_MAT_DMAT4_V_H

#include "dmat4.h"


/** dst = dmat[row][:] */
static dvec4 dmat4_get_row_v(const double *dmat, int row) {
    dvec4 res;
    dmatN_get_row(res.v, dmat, row, 4);
    return res;
}

/** dst = dmat[:][col] */
static dvec4 dmat4_get_col_v(const double *dmat, int col) {
    dvec4 res;
    dmatN_get_col(res.v, dmat, col, 4);
    return res;
}

/** dst = dmat; dst[row][:] = dvec */
static dmat4 dmat4_set_row_v(const double *dmat, const double *dvec, int row) {
    dmat4 dst = DMat4(dmat);
    dmatN_set_row(dst.v, dvec, row, 4);
    return dst;
}

/** dst = dmat; dst[:][col] = dvec */
static dmat4 dmat4_set_col_v(const double *dmat, const double *dvec, int col) {
    dmat4 dst = DMat4(dmat);
    dmatN_set_col(dst.v, dvec, col, 4);
    return dst;
}

/** dst = dmat; dst[row][:] = scalar */
static dmat4 dmat4_row_set_sca_v(const double *dmat, double scalar, int row) {
    dmat4 dst = DMat4(dmat);
    dmatN_row_set_sca(dst.v, scalar, row, 4);
    return dst;
}

/** dst = dmat; dst[:][col] = scalar */
static dmat4 dmat4_col_set_sca_v(const double *dmat, double scalar, int col) {
    dmat4 dst = DMat4(dmat);
    dmatN_col_set_sca(dst.v, scalar, col, 4);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static double dmat4_trace_v(const double *dmat) {
    return dmatN_trace(dmat, 4);
}

/** dst = dmat^t */
static dmat4 dmat4_transpose_v(const double *dmat) {
    dmat4 res;
    dmatN_transpose_no_alias(res.v, dmat, 4);
    return res;
}

/** dst = a @ b */
static dmat4 dmat4_mul_dmat_v(const double *dmat_a, const double *dmat_b) {
    dmat4 res;
    dmatN_mul_dmat_no_alias(res.v, dmat_a, dmat_b, 4);
    return res;
}

/** dst = a @ b */
static dvec4 dmat4_mul_dvec_v(const double *dmat_a, const double *dvec_b) {
    dvec4 res;
    dmatN_mul_dvec_no_alias(res.v, dmat_a, dvec_b, 4);
    return res;
}

/** dst = a @ b */
static dvec4 dvec4_mul_dmat_v(const double *dvec_a, const double *dmat_b) {
    dvec4 res;
    dvecN_mul_dmat_no_alias(res.v, dvec_a, dmat_b, 4);
    return res;
}

/** returns = determinant dmat */
static double dmat4_det_v(const double *dmat) {
    return dmat4_det(DMat4(dmat));
}

/** dst = inverted dmat */
static dmat4 dmat4_inv_v(const double *dmat) {
    return dmat4_inv(DMat4(dmat));
}


/** dst = dmat[col:col+2, row:row+2] */
static dmat2 dmat4_get_block2_v(const double *dmat, int row, int col) {
    dmat2 res;
    dmatN_get_block(res.v, dmat, row, col, 2, 4);
    return res;
}

/** dst = dmat; dst[col:col+2, row:row+2] = block */
static dmat4 dmat4_set_block2_v(const double *dmat, const double *block, int row, int col) {
    dmat4 dst = DMat4(dmat);
    dmatN_set_block(dst.v, block, row, col, 2, 4);
    return dst;
}

/** dst = dmat[col:col+2, row:row+2] */
static dmat3 dmat4_get_block3_v(const double *dmat, int row, int col) {
    dmat3 res;
    dmatN_get_block(res.v, dmat, row, col, 3, 4);
    return res;
}

/** dst = dmat; dst[col:col+2, row:row+2] = block */
static dmat4 dmat4_set_block3_v(const double *dmat, const double *block, int row, int col) {
    dmat4 dst = DMat4(dmat);
    dmatN_set_block(dst.v, block, row, col, 3, 4);
    return dst;
}

/** dst = dmat[:2, :2] */
static dmat2 dmat4_get_upper_left2_v(const double *dmat) {
    return dmat4_get_block2_v(dmat, 0, 0);
}

/** dst = dmat; dst[:2, :2] = block */
static dmat4 dmat4_set_upper_left2_v(const double *dmat, const double *block) {
    return dmat4_set_block2_v(dmat, block, 0, 0);
}

/** dst = dmat[:3, :3] */
static dmat3 dmat4_get_upper_left3_v(const double *dmat) {
    return dmat4_get_block3_v(dmat, 0, 0);
}

/** dst = dmat; dst[:3, :3] = block */
static dmat4 dmat4_set_upper_left3_v(const double *dmat, const double *block) {
    return dmat4_set_block3_v(dmat, block, 0, 0);
}

#endif //MATHC_MAT_DMAT4_V_H
