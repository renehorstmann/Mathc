#ifndef MATHC_MAT_DMAT3_H
#define MATHC_MAT_DMAT3_H

#include "dmatn.h"
#include "../types.h"
#include "../vec/dvec3.h"


/** dst = r==c ? 1 : 0 (identity)  */
static dmat3 dmat3_eye() {
    dmat3 res;
    dmatN_eye(res.v, 3);
    return res;
}

/** dst = dmat[row][:] */
static dvec3 dmat3_get_row(dmat3 dmat, int row) {
    dvec3 res;
    dmatN_get_row(res.v, dmat.v, row, 3);
    return res;
}

/** dst = dmat[:][col] */
static dvec3 dmat3_get_col(dmat3 dmat, int col) {
    dvec3 res;
    dmatN_get_col(res.v, dmat.v, col, 3);
    return res;
}

/** dst = dmat; dst[row][:] = dvec */
static dmat3 dmat3_set_row(dmat3 dmat, dvec3 dvec, int row) {
    dmatN_set_row(dmat.v, dvec.v, row, 3);
    return dmat;
}

/** dst = dmat; dst[:][col] = dvec */
static dmat3 dmat3_set_col(dmat3 dmat, dvec3 dvec, int col) {
    dmatN_set_col(dmat.v, dvec.v, col, 3);
    return dmat;
}

/** dst = dmat; dst[row][:] = scalar */
static dmat3 dmat3_row_set_sca(dmat3 dmat, double scalar, int row) {
    dmatN_row_set_sca(dmat.v, scalar, row, 3);
    return dmat;
}

/** dst = dmat; dst[:][col] = scalar */
static dmat3 dmat3_col_set_sca(dmat3 dmat, double scalar, int col) {
    dmatN_col_set_sca(dmat.v, scalar, col, 3);
    return dmat;
}

/** returns sum of diagonal form upper left to lower right */
static double dmat3_trace(dmat3 dmat) {
    return dmatN_trace(dmat.v, 3);
}

/** dst = dmat^t */
static dmat3 dmat3_transpose(dmat3 dmat) {
    dmat3 res;
    dmatN_transpose_no_alias(res.v, dmat.v, 3);
    return res;
}

/** dst = a @ b */
static dmat3 dmat3_mul_dmat(dmat3 dmat_a, dmat3 dmat_b) {
    dmat3 res;
    dmatN_mul_dmat_no_alias(res.v, dmat_a.v, dmat_b.v, 3);
    return res;
}

/** dst = a @ b */
static dvec3 dmat3_mul_dvec(dmat3 dmat_a, dvec3 dvec_b) {
    dvec3 res;
    dmatN_mul_dvec_no_alias(res.v, dmat_a.v, dvec_b.v, 3);
    return res;
}

/** dst = a @ b */
static dvec3 dvec3_mul_dmat(dvec3 dvec_a, dmat3 dmat_b) {
    dvec3 res;
    dvecN_mul_dmat_no_alias(res.v, dvec_a.v, dmat_b.v, 3);
    return res;
}

/** returns = determinant dmat */
static double dmat3_det(dmat3 dmat) {
    // from cglm/dmat3.h/glm_dmat3_det
    double a = dmat.m[0][0], b = dmat.m[0][1], c = dmat.m[0][2];
    double d = dmat.m[1][0], e = dmat.m[1][1], f = dmat.m[1][2];
    double g = dmat.m[2][0], h = dmat.m[2][1], i = dmat.m[2][2];

    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
}

/** dst = inverted dmat */
static dmat3 dmat3_inv(dmat3 dmat) {
    // from cglm/dmat3.h/glm_dmat3_inv
    double a = dmat.m[0][0], b = dmat.m[0][1];
    double c = dmat.m[1][0], d = dmat.m[1][1];
    double det = 1.0 / (a * d - b * c);

    dmat3 res;
    res.m[0][0] =  d * det;
    res.m[0][1] = -b * det;
    res.m[1][0] = -c * det;
    res.m[1][1] =  a * det;
    return res;
}

/** dst = dmat[col:col+2, row:row+2] */
static dmat2 dmat3_get_block2(dmat3 dmat, int row, int col) {
    dmat2 res;
    dmatN_get_block(res.v, dmat.v, row, col, 2, 3);
    return res;
}

/** dst = dmat; dst[col:col+2, row:row+2] = block */
static dmat3 dmat3_set_block2(dmat3 dmat, dmat2 block, int row, int col) {
    dmatN_set_block(dmat.v, block.v, row, col, 2, 3);
    return dmat;
}

/** dst = dmat[:2, :2] */
static dmat2 dmat3_get_upper_left(dmat3 dmat) {
    return dmat3_get_block2(dmat, 0, 0);
}

/** dst = dmat; dst[:2, :2] = block */
static dmat3 dmat3_set_upper_left(dmat3 dmat, dmat2 block) {
    return dmat3_set_block2(dmat, block, 0, 0);
}

/** angle_axis as xyz = axis and w = angle [rad] */
static dmat3 dmat3_rotation_from_angle_axis(dvec4 angle_axis) {
    // from cglm/affine/glm_rotate_make
    double c = cos(angle_axis.w);
    double s = sin(angle_axis.w);

    dvec3 axis = dvec3_normalize(angle_axis.xyz);
    dvec3 v = dvec3_scale_sca(axis, 1.0f - c);
    dvec3 vs = dvec3_scale_sca(axis, s);

    dmat3 res;
    res.col[0] = dvec3_scale_sca(axis, v.x);
    res.col[1] = dvec3_scale_sca(axis, v.y);
    res.col[2] = dvec3_scale_sca(axis, v.z);

    res.m[0][0] += c;      res.m[1][0] -= vs.z;   res.m[2][0] += vs.y;
    res.m[0][1] += vs.z;   res.m[1][1] += c;      res.m[2][1] -= vs.x;
    res.m[0][2] -= vs.y;   res.m[1][2] += vs.x;   res.m[2][2] += c;
    return res;
}

#endif //MATHC_MAT_DMAT3_H
