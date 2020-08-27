#ifndef MATHC_MAT_IMAT3_V_H
#define MATHC_MAT_IMAT3_V_H

#include "imat3.h"


/** dst = imat[row][:] */
static ivec3 imat3_get_row_v(const int *imat, int row) {
    ivec3 res;
    imatN_get_row(res.v, imat, row, 3);
    return res;
}

/** dst = imat[:][col] */
static ivec3 imat3_get_col_v(const int *imat, int col) {
    ivec3 res;
    imatN_get_col(res.v, imat, col, 3);
    return res;
}

/** dst = imat; dst[row][:] = ivec */
static imat3 imat3_set_row_v(const int *imat, const int *ivec, int row) {
    imat3 dst = IMat3(imat);
    imatN_set_row(dst.v, ivec, row, 3);
    return dst;
}

/** dst = imat; dst[:][col] = ivec */
static imat3 imat3_set_col_v(const int *imat, const int *ivec, int col) {
    imat3 dst = IMat3(imat);
    imatN_set_col(dst.v, ivec, col, 3);
    return dst;
}

/** dst = imat; dst[row][:] = scalar */
static imat3 imat3_row_set_sca_v(const int *imat, int scalar, int row) {
    imat3 dst = IMat3(imat);
    imatN_row_set_sca(dst.v, scalar, row, 3);
    return dst;
}

/** dst = imat; dst[:][col] = scalar */
static imat3 imat3_col_set_sca_v(const int *imat, int scalar, int col) {
    imat3 dst = IMat3(imat);
    imatN_col_set_sca(dst.v, scalar, col, 3);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static int imat3_trace_v(const int *imat) {
    return imatN_trace(imat, 3);
}

/** dst = imat^t */
static imat3 imat3_transpose_v(const int *imat) {
    imat3 res;
    imatN_transpose_no_alias(res.v, imat, 3);
    return res;
}

/** dst = a @ b */
static imat3 imat3_mul_imat_v(const int *imat_a, const int *imat_b) {
    imat3 res;
    imatN_mul_imat_no_alias(res.v, imat_a, imat_b, 3);
    return res;
}

/** dst = a @ b */
static ivec3 imat3_mul_ivec_v(const int *imat_a, const int *ivec_b) {
    ivec3 res;
    imatN_mul_ivec_no_alias(res.v, imat_a, ivec_b, 3);
    return res;
}

/** dst = a @ b */
static ivec3 ivec3_mul_imat_v(const int *ivec_a, const int *imat_b) {
    ivec3 res;
    ivecN_mul_imat_no_alias(res.v, ivec_a, imat_b, 3);
    return res;
}

/** returns = determinant imat */
static int imat3_det_v(const int *imat) {
    return imat3_det(IMat3(imat));
}

/** dst = inverted imat */
static imat3 imat3_inv_v(const int *imat) {
    return imat3_inv(IMat3(imat));
}

/** dst = imat[col:col+2, row:row+2] */
static imat2 imat3_get_block2_v(const int *imat, int row, int col) {
    imat2 res;
    imatN_get_block(res.v, imat, row, col, 2, 3);
    return res;
}

/** dst = imat; dst[col:col+2, row:row+2] = block */
static imat3 imat3_set_block2_v(const int *imat, const int *block, int row, int col) {
    imat3 dst = IMat3(imat);
    imatN_set_block(dst.v, block, row, col, 2, 3);
    return dst;
}

/** dst = imat[:2, :2] */
static imat2 imat3_get_upper_left_v(const int *imat) {
    return imat3_get_block2_v(imat, 0, 0);
}

/** dst = imat; dst[:2, :2] = block */
static imat3 imat3_set_upper_left_v(const int *imat, const int *block) {
    return imat3_set_block2_v(imat, block, 0, 0);
}

#endif //MATHC_MAT_IMAT3_V_H
