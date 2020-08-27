#ifndef MATHC_MAT_DMAT3_V_H
#define MATHC_MAT_DMAT3_V_H

#include "dmat3.h"


/** dst = dmat[row][:] */
static dvec3 dmat3_get_row_v(const double *dmat, int row) {
    dvec3 res;
    dmatN_get_row(res.v, dmat, row, 3);
    return res;
}

/** dst = dmat[:][col] */
static dvec3 dmat3_get_col_v(const double *dmat, int col) {
    dvec3 res;
    dmatN_get_col(res.v, dmat, col, 3);
    return res;
}

/** dst = dmat; dst[row][:] = dvec */
static dmat3 dmat3_set_row_v(const double *dmat, const double *dvec, int row) {
    dmat3 dst = DMat3(dmat);
    dmatN_set_row(dst.v, dvec, row, 3);
    return dst;
}

/** dst = dmat; dst[:][col] = dvec */
static dmat3 dmat3_set_col_v(const double *dmat, const double *dvec, int col) {
    dmat3 dst = DMat3(dmat);
    dmatN_set_col(dst.v, dvec, col, 3);
    return dst;
}

/** dst = dmat; dst[row][:] = scalar */
static dmat3 dmat3_row_set_sca_v(const double *dmat, double scalar, int row) {
    dmat3 dst = DMat3(dmat);
    dmatN_row_set_sca(dst.v, scalar, row, 3);
    return dst;
}

/** dst = dmat; dst[:][col] = scalar */
static dmat3 dmat3_col_set_sca_v(const double *dmat, double scalar, int col) {
    dmat3 dst = DMat3(dmat);
    dmatN_col_set_sca(dst.v, scalar, col, 3);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static double dmat3_trace_v(const double *dmat) {
    return dmatN_trace(dmat, 3);
}

/** dst = dmat^t */
static dmat3 dmat3_transpose_v(const double *dmat) {
    dmat3 res;
    dmatN_transpose_no_alias(res.v, dmat, 3);
    return res;
}

/** dst = a @ b */
static dmat3 dmat3_mul_dmat_v(const double *dmat_a, const double *dmat_b) {
    dmat3 res;
    dmatN_mul_dmat_no_alias(res.v, dmat_a, dmat_b, 3);
    return res;
}

/** dst = a @ b */
static dvec3 dmat3_mul_dvec_v(const double *dmat_a, const double *dvec_b) {
    dvec3 res;
    dmatN_mul_dvec_no_alias(res.v, dmat_a, dvec_b, 3);
    return res;
}

/** dst = a @ b */
static dvec3 dvec3_mul_dmat_v(const double *dvec_a, const double *dmat_b) {
    dvec3 res;
    dvecN_mul_dmat_no_alias(res.v, dvec_a, dmat_b, 3);
    return res;
}

/** returns = determinant dmat */
static double dmat3_det_v(const double *dmat) {
    return dmat3_det(DMat3(dmat));
}

/** dst = inverted dmat */
static dmat3 dmat3_inv_v(const double *dmat) {
    return dmat3_inv(DMat3(dmat));
}

/** dst = dmat[col:col+2, row:row+2] */
static dmat2 dmat3_get_block2_v(const double *dmat, int row, int col) {
    dmat2 res;
    dmatN_get_block(res.v, dmat, row, col, 2, 3);
    return res;
}

/** dst = dmat; dst[col:col+2, row:row+2] = block */
static dmat3 dmat3_set_block2_v(const double *dmat, const double *block, int row, int col) {
    dmat3 dst = DMat3(dmat);
    dmatN_set_block(dst.v, block, row, col, 2, 3);
    return dst;
}

/** dst = dmat[:2, :2] */
static dmat2 dmat3_get_upper_left_v(const double *dmat) {
    return dmat3_get_block2_v(dmat, 0, 0);
}

/** dst = dmat; dst[:2, :2] = block */
static dmat3 dmat3_set_upper_left_v(const double *dmat, const double *block) {
    return dmat3_set_block2_v(dmat, block, 0, 0);
}

/** angle_axis as xyz = axis and w = angle [rad] */
static dmat3 dmat3_rotation_from_angle_axis_v(const double *angle_axis) {
    return dmat3_rotation_from_angle_axis(DVec4(angle_axis));
}

#endif //MATHC_MAT_DMAT3_V_H
