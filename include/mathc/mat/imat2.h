#ifndef MATHC_MAT_IMAT2_H
#define MATHC_MAT_IMAT2_H

#include "imatn.h"
#include "../types.h"


/** dst = r==c ? 1 : 0 (identity)  */
static imat2 imat2_eye() {
    imat2 res;
    imatN_eye(res.v, 2);
    return res;
}

/** dst = imat[row][:] */
static ivec2 imat2_get_row(imat2 imat, int row) {
    ivec2 res;
    imatN_get_row(res.v, imat.v, row, 2);
    return res;
}

/** dst = imat[:][col] */
static ivec2 imat2_get_col(imat2 imat, int col) {
    ivec2 res;
    imatN_get_col(res.v, imat.v, col, 2);
    return res;
}

/** dst = imat; dst[row][:] = ivec */
static imat2 imat2_set_row(imat2 imat, ivec2 ivec, int row) {
    imatN_set_row(imat.v, ivec.v, row, 2);
    return imat;
}

/** dst = imat; dst[:][col] = ivec */
static imat2 imat2_set_col(imat2 imat, ivec2 ivec, int col) {
    imatN_set_col(imat.v, ivec.v, col, 2);
    return imat;
}

/** dst = imat; dst[row][:] = scalar */
static imat2 imat2_row_set_sca(imat2 imat, int scalar, int row) {
    imatN_row_set_sca(imat.v, scalar, row, 2);
    return imat;
}

/** dst = imat; dst[:][col] = scalar */
static imat2 imat2_col_set_sca(imat2 imat, int scalar, int col) {
    imatN_col_set_sca(imat.v, scalar, col, 2);
    return imat;
}

/** returns sum of diagonal form upper left to lower right */
static int imat2_trace(imat2 imat) {
    return imatN_trace(imat.v, 2);
}

/** dst = imat^t */
static imat2 imat2_transpose(imat2 imat) {
    imat2 res;
    imatN_transpose_no_alias(res.v, imat.v, 2);
    return res;
}

/** dst = a @ b */
static imat2 imat2_mul_imat(imat2 imat_a, imat2 imat_b) {
    imat2 res;
    imatN_mul_imat_no_alias(res.v, imat_a.v, imat_b.v, 2);
    return res;
}

/** dst = a @ b */
static ivec2 imat2_mul_ivec(imat2 imat_a, ivec2 ivec_b) {
    ivec2 res;
    imatN_mul_ivec_no_alias(res.v, imat_a.v, ivec_b.v, 2);
    return res;
}

/** dst = a @ b */
static ivec2 ivec2_mul_imat(ivec2 ivec_a, imat2 imat_b) {
    ivec2 res;
    ivecN_mul_imat_no_alias(res.v, ivec_a.v, imat_b.v, 2);
    return res;
}

/** returns = determinant imat */
static int imat2_det(imat2 imat) {
    // from cglm/imat2.h/glm_imat2_det
    return imat.m[0][0] * imat.m[1][1] - imat.m[1][0] * imat.m[0][1];
}

/** dst = inverted imat */
static imat2 imat2_inv(imat2 imat) {
    // from cglm/imat2.h/glm_imat2_inv
    float a = imat.m[0][0], b = imat.m[0][1];
    float c = imat.m[1][0], d = imat.m[1][1];
    float det = 1.0f / (a * d - b * c);

    imat2 res;
    res.m[0][0] = (int) (d * det);
    res.m[0][1] = (int) (-b * det);
    res.m[1][0] = (int) (-c * det);
    res.m[1][1] = (int) (a * det);
    return res;
}

#endif //MATHC_MAT_IMAT2_H
