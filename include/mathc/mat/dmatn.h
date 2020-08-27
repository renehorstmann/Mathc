#ifndef MATHC_MAT_DMATN_H
#define MATHC_MAT_DMATN_H

// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

#include "math.h"
#include "assert.h"


/** dst = r==c ? 1 : 0 (identity) */
static void dmatN_eye(double *dst_dmat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            dst_dmat[r * n + c] = r == c ? 1 : 0;
    }
}

/** dst = dmat[row][:] */
static void dmatN_get_row(double *dst_dvec, const double *dmat, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst_dvec[c] = dmat[c * n + row];
}

/** dst = dmat[:][col] */
static void dmatN_get_col(double *dst_dvec, const double *dmat, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst_dvec[r] = dmat[col * n + r];
}

/** dst[row][:] = dvec */
static void dmatN_set_row(double *dst_dmat, const double *dvec, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst_dmat[c * n + row] = dvec[c];
}

/** dst[:][col] = dvec */
static void dmatN_set_col(double *dst_dmat, const double *dvec, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst_dmat[col * n + r] = dvec[r];
}

/** dst[row][:] = scalar */
static void dmatN_row_set_sca(double *dst_dmat, double scalar, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst_dmat[c * n + row] = scalar;
}

/** dst[:][col] = scalar */
static void dmatN_col_set_sca(double *dst_dmat, double scalar, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst_dmat[col * n + r] = scalar;
}

/** returns sum of diagonal form upper left to lower right */
static double dmatN_trace(const double *dmat, int n) {
    double sum = 0;
    for(int i=0; i<n; i++)
        sum += dmat[i*n + i];
    return sum;
}

/** dst = dmat^t  (restrict data) */
static void dmatN_transpose_no_alias(double *restrict dst_dmat, const double *restrict dmat, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_dmat[c * n + r] = dmat[c * n + r];
        }
    }
}

/** dst = dmat^t */
static void dmatN_transpose(double *dst_dmat, const double *dmat, int n) {
    double tmp[n * n];
    dmatN_transpose_no_alias(tmp, dmat, n);
    for (int i = 0; i < n * n; i++)
        dst_dmat[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void dmatN_mul_dmat_no_alias(double *restrict dst_dmat, const double *restrict dmat_a,
                                  const double *restrict dmat_b, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_dmat[c * n + r] = 0;
            for (int k = 0; k < n; k++)
                dst_dmat[c * n + r] += dmat_a[k * n + r] * dmat_b[c * n + k];
        }
    }
}

/** dst = a @ b */
static void dmatN_mul_dmat(double *dst_dmat, const double *dmat_a, const double *dmat_b, int n) {
    double tmp[n * n];
    dmatN_mul_dmat_no_alias(tmp, dmat_a, dmat_b, n);
    for (int i = 0; i < n * n; i++)
        dst_dmat[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void dmatN_mul_dvec_no_alias(double *restrict dst_dvec, const double *restrict dmat_a,
                                  const double *restrict dvec_b, int n) {
    for (int r = 0; r < n; r++) {
        dst_dvec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_dvec[r] += dmat_a[c * n + r] * dvec_b[c];
        }
    }
}

/** dst = a @ b */
static void dmatN_mul_dvec(double *dst_dvec, const double *dmat_a, const double *dvec_b, int n) {
    double tmp[n];
    dmatN_mul_dvec_no_alias(tmp, dmat_a, dvec_b, n);
    for (int i = 0; i < n; i++)
        dst_dvec[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void dvecN_mul_dmat_no_alias(double *restrict dst_dvec, const double *restrict dvec_a,
                                  const double *restrict dmat_b, int n) {
    for (int c = 0; c < n; c++) {
        dst_dvec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_dvec[c] += dmat_b[c * n + r] * dvec_a[r];
        }
    }
}

/** dst = a @ b */
static void dvecN_mul_dmat(double *dst_dvec, const double *dvec_a, const double *dmat_b, int n) {
    double tmp[n];
    dvecN_mul_dmat_no_alias(tmp, dvec_a, dmat_b, n);
    for (int i = 0; i < n; i++)
        dst_dvec[i] = tmp[i];
}

/** block<block_n*block_n> = dmat<n*n>[col:col+block_n, row:row+block_n] */
static void dmatN_get_block(double * restrict dst_block, const double * restrict dmat, int row, int col, int block_n, int n) {
    assert(row >= 0 && row + block_n <= n);
    assert(col >= 0 && col + block_n <= n);
    for(int c=0; c<block_n; c++) {
        for(int r=0; r<block_n; r++) {
            dst_block[c * block_n + r] = dmat[c * n + r];
        }
    }
}

/** dst<n*n>[col:col+block_n, row:row+block_n] = block<block_n*block_n> */
static void dmatN_set_block(double * restrict dst_dmat, const double * restrict block, int row, int col, int block_n, int n) {
    assert(row >= 0 && row + block_n <= n);
    assert(col >= 0 && col + block_n <= n);
    for(int c=0; c<block_n; c++) {
        for(int r=0; r<block_n; r++) {
            dst_dmat[c * n + r] = block[c * block_n + r];
        }
    }
}

#endif //MATHC_MAT_DMATN_H
