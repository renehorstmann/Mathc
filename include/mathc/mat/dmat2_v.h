#ifndef MATHC_MAT_DMAT2_V_H
#define MATHC_MAT_DMAT2_V_H

#include "dmat2.h"


/** dst = dmat[row][:] */
static dvec2 dmat2_get_row_v(const double *dmat, int row) {
    dvec2 res;
    dmatN_get_row(res.v, dmat, row, 2);
    return res;
}

/** dst = dmat[:][col] */
static dvec2 dmat2_get_col_v(const double *dmat, int col) {
    dvec2 res;
    dmatN_get_col(res.v, dmat, col, 2);
    return res;
}

/** dst = dmat; dst[row][:] = dvec */
static dmat2 dmat2_set_row_v(const double *dmat, const double *dvec, int row) {
    dmat2 dst = DMat2(dmat);
    dmatN_set_row(dst.v, dvec, row, 2);
    return dst;
}

/** dst = dmat; dst[:][col] = dvec */
static dmat2 dmat2_set_col_v(const double *dmat, const double *dvec, int col) {
    dmat2 dst = DMat2(dmat);
    dmatN_set_col(dst.v, dvec, col, 2);
    return dst;
}

/** dst = dmat; dst[row][:] = scalar */
static dmat2 dmat2_row_set_sca_v(const double *dmat, double scalar, int row) {
    dmat2 dst = DMat2(dmat);
    dmatN_row_set_sca(dst.v, scalar, row, 2);
    return dst;
}

/** dst = dmat; dst[:][col] = scalar */
static dmat2 dmat2_col_set_sca_v(const double *dmat, double scalar, int col) {
    dmat2 dst = DMat2(dmat);
    dmatN_col_set_sca(dst.v, scalar, col, 2);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static double dmat2_trace_v(const double *dmat) {
    return dmatN_trace(dmat, 2);
}

/** dst = dmat^t */
static dmat2 dmat2_transpose_v(const double *dmat) {
    dmat2 res;
    dmatN_transpose_no_alias(res.v, dmat, 2);
    return res;
}

/** dst = a @ b */
static dmat2 dmat2_mul_dmat_v(const double *dmat_a, const double *dmat_b) {
    dmat2 res;
    dmatN_mul_dmat_no_alias(res.v, dmat_a, dmat_b, 2);
    return res;
}

/** dst = a @ b */
static dvec2 dmat2_mul_dvec_v(const double *dmat_a, const double *dvec_b) {
    dvec2 res;
    dmatN_mul_dvec_no_alias(res.v, dmat_a, dvec_b, 2);
    return res;
}

/** dst = a @ b */
static dvec2 dvec2_mul_dmat_v(const double *dvec_a, const double *dmat_b) {
    dvec2 res;
    dvecN_mul_dmat_no_alias(res.v, dvec_a, dmat_b, 2);
    return res;
}

/** returns = determinant dmat */
static double dmat2_det_v(const double *dmat) {
    return dmat2_det(DMat2(dmat));
}

/** dst = inverted dmat */
static dmat2 dmat2_inv_v(const double *dmat) {
    return dmat2_inv(DMat2(dmat));
}

#endif //MATHC_MAT_DMAT2_V_H
