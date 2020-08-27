#ifndef MATHC_MAT_IMAT4_V_H
#define MATHC_MAT_IMAT4_V_H

#include "imat4.h"


/** dst = imat[row][:] */
static ivec4 imat4_get_row_v(const int *imat, int row) {
    ivec4 res;
    imatN_get_row(res.v, imat, row, 4);
    return res;
}

/** dst = imat[:][col] */
static ivec4 imat4_get_col_v(const int *imat, int col) {
    ivec4 res;
    imatN_get_col(res.v, imat, col, 4);
    return res;
}

/** dst = imat; dst[row][:] = ivec */
static imat4 imat4_set_row_v(const int *imat, const int *ivec, int row) {
    imat4 dst = IMat4(imat);
    imatN_set_row(dst.v, ivec, row, 4);
    return dst;
}

/** dst = imat; dst[:][col] = ivec */
static imat4 imat4_set_col_v(const int *imat, const int *ivec, int col) {
    imat4 dst = IMat4(imat);
    imatN_set_col(dst.v, ivec, col, 4);
    return dst;
}

/** dst = imat; dst[row][:] = scalar */
static imat4 imat4_row_set_sca_v(const int *imat, int scalar, int row) {
    imat4 dst = IMat4(imat);
    imatN_row_set_sca(dst.v, scalar, row, 4);
    return dst;
}

/** dst = imat; dst[:][col] = scalar */
static imat4 imat4_col_set_sca_v(const int *imat, int scalar, int col) {
    imat4 dst = IMat4(imat);
    imatN_col_set_sca(dst.v, scalar, col, 4);
    return dst;
}

/** returns sum of diagonal form upper left to lower right */
static int imat4_trace_v(const int *imat) {
    return imatN_trace(imat, 4);
}

/** dst = imat^t */
static imat4 imat4_transpose_v(const int *imat) {
    imat4 res;
    imatN_transpose_no_alias(res.v, imat, 4);
    return res;
}

/** dst = a @ b */
static imat4 imat4_mul_imat_v(const int *imat_a, const int *imat_b) {
    imat4 res;
    imatN_mul_imat_no_alias(res.v, imat_a, imat_b, 4);
    return res;
}

/** dst = a @ b */
static ivec4 imat4_mul_ivec_v(const int *imat_a, const int *ivec_b) {
    ivec4 res;
    imatN_mul_ivec_no_alias(res.v, imat_a, ivec_b, 4);
    return res;
}

/** dst = a @ b */
static ivec4 ivec4_mul_imat_v(const int *ivec_a, const int *imat_b) {
    ivec4 res;
    ivecN_mul_imat_no_alias(res.v, ivec_a, imat_b, 4);
    return res;
}

/** returns = determinant imat */
static int imat4_det_v(const int *imat) {
    return imat4_det(IMat4(imat));
}

/** dst = inverted imat */
static imat4 imat4_inv_v(const int *imat) {
    return imat4_inv(IMat4(imat));
}


/** dst = imat[col:col+2, row:row+2] */
static imat2 imat4_get_block2_v(const int *imat, int row, int col) {
    imat2 res;
    imatN_get_block(res.v, imat, row, col, 2, 4);
    return res;
}

/** dst = imat; dst[col:col+2, row:row+2] = block */
static imat4 imat4_set_block2_v(const int *imat, const int *block, int row, int col) {
    imat4 dst = IMat4(imat);
    imatN_set_block(dst.v, block, row, col, 2, 4);
    return dst;
}

/** dst = imat[col:col+2, row:row+2] */
static imat3 imat4_get_block3_v(const int *imat, int row, int col) {
    imat3 res;
    imatN_get_block(res.v, imat, row, col, 3, 4);
    return res;
}

/** dst = imat; dst[col:col+2, row:row+2] = block */
static imat4 imat4_set_block3_v(const int *imat, const int *block, int row, int col) {
    imat4 dst = IMat4(imat);
    imatN_set_block(dst.v, block, row, col, 3, 4);
    return dst;
}

/** dst = imat[:2, :2] */
static imat2 imat4_get_upper_left2_v(const int *imat) {
    return imat4_get_block2_v(imat, 0, 0);
}

/** dst = imat; dst[:2, :2] = block */
static imat4 imat4_set_upper_left2_v(const int *imat, const int *block) {
    return imat4_set_block2_v(imat, block, 0, 0);
}

/** dst = imat[:3, :3] */
static imat3 imat4_get_upper_left3_v(const int *imat) {
    return imat4_get_block3_v(imat, 0, 0);
}

/** dst = imat; dst[:3, :3] = block */
static imat4 imat4_set_upper_left3_v(const int *imat, const int *block) {
    return imat4_set_block3_v(imat, block, 0, 0);
}

#endif //MATHC_MAT_IMAT4_V_H
