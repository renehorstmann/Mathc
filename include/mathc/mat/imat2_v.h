#ifndef MATHC_MAT_IMAT2_V_H
#define MATHC_MAT_IMAT2_V_H

#include "imat2.h"


/** dst = imat[row][:] */
static ivec2 imat2_get_row_v(const int *imat, int row) {
    ivec2 res;
    imatN_get_row(res.v, imat, row, 2);
    return res;
}

/** dst = imat[:][col] */
static ivec2 imat2_get_col_v(const int *imat, int col) {
    ivec2 res;
    imatN_get_col(res.v, imat, col, 2);
    return res;
}

/** dst = imat; dst[row][:] = ivec */
static imat2 imat2_set_row_v(const int *imat, const int *ivec, int row) {
    imat2 dst = IMat2(imat);
    imatN_set_row(dst.v, ivec, row, 2);
    return dst;
}

/** dst = imat; dst[:][col] = ivec */
static imat2 imat2_set_col_v(const int *imat, const int *ivec, int col) {
    imat2 dst = IMat2(imat);
    imatN_set_col(dst.v, ivec, col, 2);
    return dst;
}

/** dst = imat; dst[row][:] = scalar */
static imat2 imat2_row_set_sca_v(const int *imat, int scalar, int row) {
    imat2 dst = IMat2(imat);
    imatN_row_set_sca(dst.v, scalar, row, 2);
    return dst;
}

/** dst = imat; dst[:][col] = scalar */
static imat2 imat2_col_set_sca_v(const int *imat, int scalar, int col) {
    imat2 dst = IMat2(imat);
    imatN_col_set_sca(dst.v, scalar, col, 2);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static int imat2_trace_v(const int *imat) {
    return imatN_trace(imat, 2);
}

/** dst = imat^t */
static imat2 imat2_transpose_v(const int *imat) {
    imat2 res;
    imatN_transpose_no_alias(res.v, imat, 2);
    return res;
}

/** dst = a @ b */
static imat2 imat2_mul_imat_v(const int *imat_a, const int *imat_b) {
    imat2 res;
    imatN_mul_imat_no_alias(res.v, imat_a, imat_b, 2);
    return res;
}

/** dst = a @ b */
static ivec2 imat2_mul_ivec_v(const int *imat_a, const int *ivec_b) {
    ivec2 res;
    imatN_mul_ivec_no_alias(res.v, imat_a, ivec_b, 2);
    return res;
}

/** dst = a @ b */
static ivec2 ivec2_mul_imat_v(const int *ivec_a, const int *imat_b) {
    ivec2 res;
    ivecN_mul_imat_no_alias(res.v, ivec_a, imat_b, 2);
    return res;
}

/** returns = determinant imat */
static int imat2_det_v(const int *imat) {
    return imat2_det(IMat2(imat));
}

/** dst = inverted imat */
static imat2 imat2_inv_v(const int *imat) {
    return imat2_inv(IMat2(imat));
}

#endif //MATHC_MAT_IMAT2_V_H
