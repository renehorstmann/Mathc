#ifndef MATHC_MAT_IMAT3_H
#define MATHC_MAT_IMAT3_H

#include "imatn.h"
#include "../types.h"
#include "../vec/ivec3.h"


/** dst = r==c ? 1 : 0 (identity)  */
static imat3 imat3_eye() {
    imat3 res;
    imatN_eye(res.v, 3);
    return res;
}

/** dst = imat[row][:] */
static ivec3 imat3_get_row(imat3 imat, int row) {
    ivec3 res;
    imatN_get_row(res.v, imat.v, row, 3);
    return res;
}

/** dst = imat[:][col] */
static ivec3 imat3_get_col(imat3 imat, int col) {
    ivec3 res;
    imatN_get_col(res.v, imat.v, col, 3);
    return res;
}

/** dst = imat; dst[row][:] = ivec */
static imat3 imat3_set_row(imat3 imat, ivec3 ivec, int row) {
    imatN_set_row(imat.v, ivec.v, row, 3);
    return imat;
}

/** dst = imat; dst[:][col] = ivec */
static imat3 imat3_set_col(imat3 imat, ivec3 ivec, int col) {
    imatN_set_col(imat.v, ivec.v, col, 3);
    return imat;
}

/** dst = imat; dst[row][:] = scalar */
static imat3 imat3_row_set_sca(imat3 imat, int scalar, int row) {
    imatN_row_set_sca(imat.v, scalar, row, 3);
    return imat;
}

/** dst = imat; dst[:][col] = scalar */
static imat3 imat3_col_set_sca(imat3 imat, int scalar, int col) {
    imatN_col_set_sca(imat.v, scalar, col, 3);
    return imat;
}

/** returns sum of diagonal form upper left to lower right */
static int imat3_trace(imat3 imat) {
    return imatN_trace(imat.v, 3);
}

/** dst = imat^t */
static imat3 imat3_transpose(imat3 imat) {
    imat3 res;
    imatN_transpose_no_alias(res.v, imat.v, 3);
    return res;
}

/** dst = a @ b */
static imat3 imat3_mul_imat(imat3 imat_a, imat3 imat_b) {
    imat3 res;
    imatN_mul_imat_no_alias(res.v, imat_a.v, imat_b.v, 3);
    return res;
}

/** dst = a @ b */
static ivec3 imat3_mul_ivec(imat3 imat_a, ivec3 ivec_b) {
    ivec3 res;
    imatN_mul_ivec_no_alias(res.v, imat_a.v, ivec_b.v, 3);
    return res;
}

/** dst = a @ b */
static ivec3 ivec3_mul_imat(ivec3 ivec_a, imat3 imat_b) {
    ivec3 res;
    ivecN_mul_imat_no_alias(res.v, ivec_a.v, imat_b.v, 3);
    return res;
}

/** returns = determinant imat */
static int imat3_det(imat3 imat) {
    // from cglm/imat3.h/glm_imat3_det
    int a = imat.m[0][0], b = imat.m[0][1], c = imat.m[0][2];
    int d = imat.m[1][0], e = imat.m[1][1], f = imat.m[1][2];
    int g = imat.m[2][0], h = imat.m[2][1], i = imat.m[2][2];

    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
}

/** dst = inverted imat */
static imat3 imat3_inv(imat3 imat) {
    // from cglm/imat3.h/glm_imat3_inv
    float a = imat.m[0][0], b = imat.m[0][1];
    float c = imat.m[1][0], d = imat.m[1][1];
    int det = 1.0f / (a * d - b * c);

    imat3 res;
    res.m[0][0] = (int) (d * det);
    res.m[0][1] = (int) (-b * det);
    res.m[1][0] = (int) (-c * det);
    res.m[1][1] = (int) (a * det);
    return res;
}

/** dst = imat[col:col+2, row:row+2] */
static imat2 imat3_get_block2(imat3 imat, int row, int col) {
    imat2 res;
    imatN_get_block(res.v, imat.v, row, col, 2, 3);
    return res;
}

/** dst = imat; dst[col:col+2, row:row+2] = block */
static imat3 imat3_set_block2(imat3 imat, imat2 block, int row, int col) {
    imatN_set_block(imat.v, block.v, row, col, 2, 3);
    return imat;
}

/** dst = imat[:2, :2] */
static imat2 imat3_get_upper_left(imat3 imat) {
    return imat3_get_block2(imat, 0, 0);
}

/** dst = imat; dst[:2, :2] = block */
static imat3 imat3_set_upper_left(imat3 imat, imat2 block) {
    return imat3_set_block2(imat, block, 0, 0);
}

#endif //MATHC_MAT_IMAT3_H
