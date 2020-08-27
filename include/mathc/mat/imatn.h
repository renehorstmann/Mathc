#ifndef MATHC_MAT_IMATN_H
#define MATHC_MAT_IMATN_H

// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

#include "math.h"
#include "assert.h"


/** dst = r==c ? 1 : 0 (identity) */
static void imatN_eye(int *dst_imat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            dst_imat[r * n + c] = r == c ? 1 : 0;
    }
}

/** dst = imat[row][:] */
static void imatN_get_row(int *dst_ivec, const int *imat, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst_ivec[c] = imat[c * n + row];
}

/** dst = imat[:][col] */
static void imatN_get_col(int *dst_ivec, const int *imat, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst_ivec[r] = imat[col * n + r];
}

/** dst[row][:] = ivec */
static void imatN_set_row(int *dst_imat, const int *ivec, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst_imat[c * n + row] = ivec[c];
}

/** dst[:][col] = ivec */
static void imatN_set_col(int *dst_imat, const int *ivec, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst_imat[col * n + r] = ivec[r];
}

/** dst[row][:] = scalar */
static void imatN_row_set_sca(int *dst_imat, int scalar, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst_imat[c * n + row] = scalar;
}

/** dst[:][col] = scalar */
static void imatN_col_set_sca(int *dst_imat, int scalar, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst_imat[col * n + r] = scalar;
}

/** returns sum of diagonal form upper left to lower right */
static int imatN_trace(const int *imat, int n) {
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += imat[i*n + i];
    return sum;
}

/** dst = imat^t  (restrict data) */
static void imatN_transpose_no_alias(int *restrict dst_imat, const int *restrict imat, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_imat[c * n + r] = imat[c * n + r];
        }
    }
}

/** dst = imat^t */
static void imatN_transpose(int *dst_imat, const int *imat, int n) {
    int tmp[n * n];
    imatN_transpose_no_alias(tmp, imat, n);
    for (int i = 0; i < n * n; i++)
        dst_imat[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void imatN_mul_imat_no_alias(int *restrict dst_imat, const int *restrict imat_a,
                                  const int *restrict imat_b, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_imat[c * n + r] = 0;
            for (int k = 0; k < n; k++)
                dst_imat[c * n + r] += imat_a[k * n + r] * imat_b[c * n + k];
        }
    }
}

/** dst = a @ b */
static void imatN_mul_imat(int *dst_imat, const int *imat_a, const int *imat_b, int n) {
    int tmp[n * n];
    imatN_mul_imat_no_alias(tmp, imat_a, imat_b, n);
    for (int i = 0; i < n * n; i++)
        dst_imat[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void imatN_mul_ivec_no_alias(int *restrict dst_ivec, const int *restrict imat_a,
                                  const int *restrict ivec_b, int n) {
    for (int r = 0; r < n; r++) {
        dst_ivec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_ivec[r] += imat_a[c * n + r] * ivec_b[c];
        }
    }
}

/** dst = a @ b */
static void imatN_mul_ivec(int *dst_ivec, const int *imat_a, const int *ivec_b, int n) {
    int tmp[n];
    imatN_mul_ivec_no_alias(tmp, imat_a, ivec_b, n);
    for (int i = 0; i < n; i++)
        dst_ivec[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void ivecN_mul_imat_no_alias(int *restrict dst_ivec, const int *restrict ivec_a,
                                  const int *restrict imat_b, int n) {
    for (int c = 0; c < n; c++) {
        dst_ivec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_ivec[c] += imat_b[c * n + r] * ivec_a[r];
        }
    }
}

/** dst = a @ b */
static void ivecN_mul_imat(int *dst_ivec, const int *ivec_a, const int *imat_b, int n) {
    int tmp[n];
    ivecN_mul_imat_no_alias(tmp, ivec_a, imat_b, n);
    for (int i = 0; i < n; i++)
        dst_ivec[i] = tmp[i];
}

/** block<block_n*block_n> = imat<n*n>[col:col+block_n, row:row+block_n] */
static void imatN_get_block(int * restrict dst_block, const int * restrict imat, int row, int col, int block_n, int n) {
    assert(row >= 0 && row + block_n <= n);
    assert(col >= 0 && col + block_n <= n);
    for(int c=0; c<block_n; c++) {
        for(int r=0; r<block_n; r++) {
            dst_block[c * block_n + r] = imat[c * n + r];
        }
    }
}

/** dst<n*n>[col:col+block_n, row:row+block_n] = block<block_n*block_n> */
static void imatN_set_block(int * restrict dst_imat, const int * restrict block, int row, int col, int block_n, int n) {
    assert(row >= 0 && row + block_n <= n);
    assert(col >= 0 && col + block_n <= n);
    for(int c=0; c<block_n; c++) {
        for(int r=0; r<block_n; r++) {
            dst_imat[c * n + r] = block[c * block_n + r];
        }
    }
}

#endif //MATHC_MAT_IMATN_H
