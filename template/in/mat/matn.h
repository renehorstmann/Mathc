#ifndef MATHC_MAT_MATN_H
#define MATHC_MAT_MATN_H

/*/ 0 /*/   // template file!
/*/ 0 /*/   //
/*/ 0 /*/   // all lines starting with "/*/ cond /*/[//]" may be removed
/*/ 0 /*/   // if cond is true:
/*/ 0 /*/   //      only the condition comment will be removed "/*/ cond /*/)"
/*/ 0 /*/   // if cond is false:
/*/ 0 /*/   //      the whole line will be removed
/*/ 0 /*/
/*/ 0 /*/   // the following setup is just here to pleasure an ide
/*/ 0 /*/ typedef float really_a_float;

// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

#ifndef MATHC_MAX_SIZE
#define MATHC_MAX_SIZE 16
#endif

#include <string.h>     // memcmp
#include <assert.h>
#include <stdbool.h>

/** macro to cast a mattor into a float mattor */
#define matN_cast_into(dst, from, n) \
do { \
    for(int matN_cast_into_i_=0; matN_cast_into_i_<((n)*(n)); matN_cast_into_i_++) \
        (dst)[matN_cast_into_i_] = (float) (from)[matN_cast_into_i_]; \
} while(0)


/*/ float /*//** dst = v / 255 */
/*/ float /*/static void matN_cast_from_uchar_1(float *dst_mat, const unsigned char *mat, int n) {
/*/ float /*/    for (int i = 0; i < n*n; i++)
/*/ float /*/        dst_mat[i] = (float) mat[i] / (float) 255;
/*/ float /*/}


/*/ int /*//** dst = mat * 255 */
/*/ int /*/static void matN_cast_from_float_1(float *dst_mat, const really_a_float *mat, int n) {
/*/ int /*/    for (int i = 0; i < n*n; i++)
/*/ int /*/        dst_mat[i] = (float) (mat[i] * 255.0f);
/*/ int /*/}

/*/ int /*//** dst = mat * 255 */
/*/ int /*/static void matN_cast_from_double_1(float *dst_mat, const double *mat, int n) {
/*/ int /*/    for (int i = 0; i < n*n; i++)
/*/ int /*/        dst_mat[i] = (float) (mat[i] * 255.0);
/*/ int /*/}

/*/ int /*//** dst = mat * 255 */
/*/ int /*/static void matN_cast_from_longdouble_1(float *dst_mat, const long double *mat, int n) {
/*/ int /*/    for (int i = 0; i < n*n; i++)
/*/ int /*/        dst_mat[i] = (float) (mat[i] * 255.0);
/*/ int /*/}


/** a == b */
static bool matN_cmp(const float *a, const float *b, int n) {
    return memcmp(a, b, (n*n) * sizeof(float)) == 0;
}

/** dst = v */
static void matN_copy(float *dst, const float *v, int n) {
    for (int i = 0; i < n*n; i++)
        dst[i] = v[i];
}

/** dst = s */
static void matN_set(float *dst, float s, int n) {
    for (int i = 0; i < n*n; i++)
        dst[i] = s;
}


/** dst = r==c ? 1 : 0 (identity) */
static void matN_eye(float *dst, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            dst[r * n + c] = r == c ? 1 : 0;
    }
}

/** dst = m[row][:] */
static void matN_get_row(float *dst_vec, const float *m, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst_vec[c] = m[c * n + row];
}

/** dst = m[:][col] */
static void matN_get_col(float *dst_vec, const float *m, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst_vec[r] = m[col * n + r];
}

/** dst[row][:] = v */
static void matN_set_row(float *dst, const float *v, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst[c * n + row] = v[c];
}

/** dst[:][col] = v */
static void matN_set_col(float *dst, const float *v, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst[col * n + r] = v[r];
}

/** dst[row][:] = s */
static void matN_set_row_sca(float *dst, float s, int row, int n) {
    assert(row >= 0 && row < n);
    for (int c = 0; c < n; c++)
        dst[c * n + row] = s;
}

/** dst[:][col] = s */
static void matN_set_col_sca(float *dst, float s, int col, int n) {
    assert(col >= 0 && col < n);
    for (int r = 0; r < n; r++)
        dst[col * n + r] = s;
}

/** returns sum of diagonal from upper left to lower right */
static float matN_trace(const float *mat, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += mat[i * n + i];
    return sum;
}

/** dst = m^t  (restrict data) */
static void matN_transpose_no_alias(float *restrict dst, const float *restrict m, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst[c * n + r] = m[r * n + c];
        }
    }
}

/** dst = m^t */
static void matN_transpose(float *dst, const float *m, int n) {
    assert(n <= MATHC_MAX_SIZE);
    float tmp[MATHC_MAX_SIZE * MATHC_MAX_SIZE];
    matN_transpose_no_alias(tmp, m, n);
    for (int i = 0; i < n * n; i++)
        dst[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void matN_mul_mat_no_alias(float *restrict dst, const float *restrict a,
                                  const float *restrict b, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst[c * n + r] = 0;
            for (int k = 0; k < n; k++)
                dst[c * n + r] += a[k * n + r] * b[c * n + k];
        }
    }
}

/** dst = a @ b */
static void matN_mul_mat(float *dst, const float *a, const float *b, int n) {
    assert(n <= MATHC_MAX_SIZE);
    float tmp[MATHC_MAX_SIZE * MATHC_MAX_SIZE];
    matN_mul_mat_no_alias(tmp, a, b, n);
    for (int i = 0; i < n * n; i++)
        dst[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void matN_mul_vec_no_alias(float *restrict dst_vec, const float *restrict a,
                                  const float *restrict b, int n) {
    for (int r = 0; r < n; r++) {
        dst_vec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_vec[r] += a[c * n + r] * b[c];
        }
    }
}

/** dst = a @ b */
static void matN_mul_vec(float *dst_vec, const float *a, const float *b, int n) {
    assert(n <= MATHC_MAX_SIZE);
    float tmp[MATHC_MAX_SIZE];
    matN_mul_vec_no_alias(tmp, a, b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** dst = a @ b  (restrict data) */
static void vecN_mul_mat_no_alias(float *restrict dst_vec, const float *restrict a,
                                  const float *restrict b, int n) {
    for (int c = 0; c < n; c++) {
        dst_vec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_vec[c] += b[c * n + r] * a[r];
        }
    }
}

/** dst = a @ b */
static void vecN_mul_mat(float *dst_vec, const float *a, const float *b, int n) {
    assert(n <= MATHC_MAX_SIZE);
    float tmp[MATHC_MAX_SIZE];
    vecN_mul_mat_no_alias(tmp, a, b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** block<block_n*block_n> = m<n*n>[col:col+block_n, row:row+block_n] */
static void matN_get_block(float *restrict dst_block, const float *restrict m, int row, int col, int block_n, int n) {
    assert(row >= 0 && row + block_n <= n);
    assert(col >= 0 && col + block_n <= n);
    for (int c = 0; c < block_n; c++) {
        for (int r = 0; r < block_n; r++) {
            dst_block[c * block_n + r] = m[c * n + r];
        }
    }
}

/** dst<n*n>[col:col+block_n, row:row+block_n] = block<block_n*block_n> */
static void matN_set_block(float *restrict dst, const float *restrict block, int row, int col, int block_n, int n) {
    assert(row >= 0 && row + block_n <= n);
    assert(col >= 0 && col + block_n <= n);
    for (int c = 0; c < block_n; c++) {
        for (int r = 0; r < block_n; r++) {
            dst[c * n + r] = block[c * block_n + r];
        }
    }
}

#endif //MATHC_MAT_MATN_H
