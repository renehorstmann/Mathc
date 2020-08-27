#ifndef MATHC_MAT_DMAT2_H
#define MATHC_MAT_DMAT2_H

#include "dmatn.h"
#include "../types.h"


/** dst = r==c ? 1 : 0 (identity)  */
static dmat2 dmat2_eye() {
    dmat2 res;
    dmatN_eye(res.v, 2);
    return res;
}

/** dst = dmat[row][:] */
static dvec2 dmat2_get_row(dmat2 dmat, int row) {
    dvec2 res;
    dmatN_get_row(res.v, dmat.v, row, 2);
    return res;
}

/** dst = dmat[:][col] */
static dvec2 dmat2_get_col(dmat2 dmat, int col) {
    dvec2 res;
    dmatN_get_col(res.v, dmat.v, col, 2);
    return res;
}

/** dst = dmat; dst[row][:] = dvec */
static dmat2 dmat2_set_row(dmat2 dmat, dvec2 dvec, int row) {
    dmatN_set_row(dmat.v, dvec.v, row, 2);
    return dmat;
}

/** dst = dmat; dst[:][col] = dvec */
static dmat2 dmat2_set_col(dmat2 dmat, dvec2 dvec, int col) {
    dmatN_set_col(dmat.v, dvec.v, col, 2);
    return dmat;
}

/** dst = dmat; dst[row][:] = scalar */
static dmat2 dmat2_row_set_sca(dmat2 dmat, double scalar, int row) {
    dmatN_row_set_sca(dmat.v, scalar, row, 2);
    return dmat;
}

/** dst = dmat; dst[:][col] = scalar */
static dmat2 dmat2_col_set_sca(dmat2 dmat, double scalar, int col) {
    dmatN_col_set_sca(dmat.v, scalar, col, 2);
    return dmat;
}

/** returns sum of diagonal form upper left to lower right */
static double dmat2_trace(dmat2 dmat) {
    return dmatN_trace(dmat.v, 2);
}

/** dst = dmat^t */
static dmat2 dmat2_transpose(dmat2 dmat) {
    dmat2 res;
    dmatN_transpose_no_alias(res.v, dmat.v, 2);
    return res;
}

/** dst = a @ b */
static dmat2 dmat2_mul_dmat(dmat2 dmat_a, dmat2 dmat_b) {
    dmat2 res;
    dmatN_mul_dmat_no_alias(res.v, dmat_a.v, dmat_b.v, 2);
    return res;
}

/** dst = a @ b */
static dvec2 dmat2_mul_dvec(dmat2 dmat_a, dvec2 dvec_b) {
    dvec2 res;
    dmatN_mul_dvec_no_alias(res.v, dmat_a.v, dvec_b.v, 2);
    return res;
}

/** dst = a @ b */
static dvec2 dvec2_mul_dmat(dvec2 dvec_a, dmat2 dmat_b) {
    dvec2 res;
    dvecN_mul_dmat_no_alias(res.v, dvec_a.v, dmat_b.v, 2);
    return res;
}

/** returns = determinant dmat */
static double dmat2_det(dmat2 dmat) {
    // from cglm/dmat2.h/glm_dmat2_det
    return dmat.m[0][0] * dmat.m[1][1] - dmat.m[1][0] * dmat.m[0][1];
}

/** dst = inverted dmat */
static dmat2 dmat2_inv(dmat2 dmat) {
    // from cglm/dmat2.h/glm_dmat2_inv
    double a = dmat.m[0][0], b = dmat.m[0][1];
    double c = dmat.m[1][0], d = dmat.m[1][1];
    double det = 1.0 / (a * d - b * c);

    dmat2 res;
    res.m[0][0] =  d * det;
    res.m[0][1] = -b * det;
    res.m[1][0] = -c * det;
    res.m[1][1] =  a * det;
    return res;
}

#endif //MATHC_MAT_DMAT2_H
