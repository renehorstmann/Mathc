#ifndef MATHC_MAT_FUNCTIONS_H
#define MATHC_MAT_FUNCTIONS_H

// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

#include <math.h>   //sqrt(f)

//
// this header file has the following content:
// 1. functions for float matrix math matf_
// 2. functions for double matrix math matd_
// 3. functions for int matrix math mati_
//


//
// matf = float
//
/** mat<n*n> dst = r==c ? 1 : 0 (identity) */
static void matf_eye(float *dst_mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            dst_mat[r * n + c] = r == c ? 1 : 0;
    }
}

/** vec<n> dst = mat<n*n>[row][:] */
static void matf_get_row(float *dst_vec, const float *mat, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_vec[c] = mat[row * n + c];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void matf_get_col(float *dst_vec, const float *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[r * n + col];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void matf_set_row(float *dst_mat, const float *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void matf_set_col(float *dst_mat, const float *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void matf_row_set_sca(float *dst_mat, float scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void matf_col_set_sca(float *dst_mat, float scalar, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = scalar;
}

/** mat<n*n> dst = mat<n*n>^t  (restrict data) */
static void matf_transpose_no_alias(float *restrict dst_mat, const float *restrict mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = mat[c * n + r];
        }
    }
}

/** mat<n*n> dst = mat<n*n>^t */
static void matf_transpose(float *dst_mat, const float *mat, int n) {
    float tmp[n * n];
    matf_transpose_no_alias(tmp, mat, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b  (restrict data) */
static void matf_mul_mat_no_alias(float *restrict dst_mat, const float *restrict mat_a,
                                  const float *restrict mat_b, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = 0;
            for (int k = 0; k < n; k++)
                dst_mat[r * n + c] += mat_a[r * n + k] * mat_b[k * n + c];
        }
    }
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static void matf_mul_mat(float *dst_mat, const float *mat_a, const float *mat_b, int n) {
    float tmp[n * n];
    matf_mul_mat_no_alias(tmp, mat_a, mat_b, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** vec<n> dst = mat<n*n> a * vec<n> b  (restrict data) */
static void matf_mul_vec_no_alias(float *restrict dst_vec, const float *restrict mat_a,
                                  const float *restrict vec_b, int n) {
    for (int r = 0; r < n; r++) {
        dst_vec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_vec[r] += mat_a[r * n + c] * vec_b[c];
        }
    }
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void matf_mul_vec(float *dst_vec, const float *mat_a, const float *vec_b, int n) {
    float tmp[n];
    matf_mul_vec_no_alias(tmp, mat_a, vec_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** vec<n> dst = vec<n> a * mat<n*n> b  (restrict data) */
static void vecf_mul_mat_no_alias(float *restrict dst_vec, const float *restrict vec_a,
                                  const float *restrict mat_b, int n) {
    for (int c = 0; c < n; c++) {
        dst_vec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_vec[c] += mat_b[r * n + c] * vec_a[r];
        }
    }
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static void vecf_mul_mat(float *dst_vec, const float *vec_a, const float *mat_b, int n) {
    float tmp[n];
    vecf_mul_mat_no_alias(tmp, vec_a, mat_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** returns = det mat<3*3> mat33 */
static float matf_determinant33(const float *mat) {
    const float (*m)[3] = (const float (*)[3]) mat;
    return
            m[0][0] * m[1][1] * m[2][2] +
            m[0][1] * m[1][2] * m[2][0] +
            m[0][2] * m[1][0] * m[2][1] -
            m[0][0] * m[1][2] * m[2][1] -
            m[0][1] * m[1][0] * m[2][2] -
            m[0][2] * m[1][1] * m[2][0];
}

/** returns = det mat<4*4> mat44 */
static float matf_determinant44(const float *mat) {
    const float (*m)[4] = (const float (*)[4]) mat;
    return
            m[0][3] * m[1][2] * m[2][1] * m[3][0] -
            m[0][2] * m[1][3] * m[2][1] * m[3][0] -
            m[0][3] * m[1][1] * m[2][2] * m[3][0] +
            m[0][1] * m[1][3] * m[2][2] * m[3][0] +
            m[0][2] * m[1][1] * m[2][3] * m[3][0] -
            m[0][1] * m[1][2] * m[2][3] * m[3][0] -
            m[0][3] * m[1][2] * m[2][0] * m[3][1] +
            m[0][2] * m[1][3] * m[2][0] * m[3][1] +
            m[0][3] * m[1][0] * m[2][2] * m[3][1] -
            m[0][0] * m[1][3] * m[2][2] * m[3][1] -
            m[0][2] * m[1][0] * m[2][3] * m[3][1] +
            m[0][0] * m[1][2] * m[2][3] * m[3][1] +
            m[0][3] * m[1][1] * m[2][0] * m[3][2] -
            m[0][1] * m[1][3] * m[2][0] * m[3][2] -
            m[0][3] * m[1][0] * m[2][1] * m[3][2] +
            m[0][0] * m[1][3] * m[2][1] * m[3][2] +
            m[0][1] * m[1][0] * m[2][3] * m[3][2] -
            m[0][0] * m[1][1] * m[2][3] * m[3][2] -
            m[0][2] * m[1][1] * m[2][0] * m[3][3] +
            m[0][1] * m[1][2] * m[2][0] * m[3][3] +
            m[0][2] * m[1][0] * m[2][1] * m[3][3] -
            m[0][0] * m[1][2] * m[2][1] * m[3][3] -
            m[0][1] * m[1][0] * m[2][2] * m[3][3] +
            m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

/** mat<3*3> dst = inv(mat<3*3> mat33)  (restrict data) */
static void matf_invert33_no_alias(float *restrict dst_mat, const float *restrict mat) {
    float inv_det = 1.0f / matf_determinant33(mat);
    const float (*m)[3] = (const float (*)[3]) mat;
    float (*d)[3] = (float (*)[3]) dst_mat;
    d[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * inv_det;
    d[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * inv_det;
    d[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * inv_det;
    d[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * inv_det;
    d[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * inv_det;
    d[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * inv_det;
    d[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * inv_det;
    d[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * inv_det;
    d[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * inv_det;
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static void matf_invert33(float *dst_mat, const float *mat) {
    float tmp[9];
    matf_invert33_no_alias(tmp, mat);
    for (int i = 0; i < 9; i++)
        dst_mat[i] = tmp[i];
}

/** mat<4*4> dst = inv(mat<4*4> mat44)  (restrict data) */
static void matf_invert44_no_alias(float *restrict dst_mat, const float *restrict mat) {
    // algorithm from https://github.com/datenwolf/linmath.h/blob/master/linmath.h
    float s[6];
    float c[6];
    const float (*m)[4] = (const float (*)[4]) mat;
    float (*d)[4] = (float (*)[4]) dst_mat;
    s[0] = m[0][0] * m[1][1] - m[1][0] * m[0][1];
    s[1] = m[0][0] * m[1][2] - m[1][0] * m[0][2];
    s[2] = m[0][0] * m[1][3] - m[1][0] * m[0][3];
    s[3] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
    s[4] = m[0][1] * m[1][3] - m[1][1] * m[0][3];
    s[5] = m[0][2] * m[1][3] - m[1][2] * m[0][3];

    c[0] = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    c[1] = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    c[2] = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    c[3] = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    c[4] = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    c[5] = m[2][2] * m[3][3] - m[3][2] * m[2][3];

    /* Assumes it is invertible */
    float inv_det = 1.0f / (s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0]);

    d[0][0] = (m[1][1] * c[5] - m[1][2] * c[4] + m[1][3] * c[3]) * inv_det;
    d[0][1] = (-m[0][1] * c[5] + m[0][2] * c[4] - m[0][3] * c[3]) * inv_det;
    d[0][2] = (m[3][1] * s[5] - m[3][2] * s[4] + m[3][3] * s[3]) * inv_det;
    d[0][3] = (-m[2][1] * s[5] + m[2][2] * s[4] - m[2][3] * s[3]) * inv_det;

    d[1][0] = (-m[1][0] * c[5] + m[1][2] * c[2] - m[1][3] * c[1]) * inv_det;
    d[1][1] = (m[0][0] * c[5] - m[0][2] * c[2] + m[0][3] * c[1]) * inv_det;
    d[1][2] = (-m[3][0] * s[5] + m[3][2] * s[2] - m[3][3] * s[1]) * inv_det;
    d[1][3] = (m[2][0] * s[5] - m[2][2] * s[2] + m[2][3] * s[1]) * inv_det;

    d[2][0] = (m[1][0] * c[4] - m[1][1] * c[2] + m[1][3] * c[0]) * inv_det;
    d[2][1] = (-m[0][0] * c[4] + m[0][1] * c[2] - m[0][3] * c[0]) * inv_det;
    d[2][2] = (m[3][0] * s[4] - m[3][1] * s[2] + m[3][3] * s[0]) * inv_det;
    d[2][3] = (-m[2][0] * s[4] + m[2][1] * s[2] - m[2][3] * s[0]) * inv_det;

    d[3][0] = (-m[1][0] * c[3] + m[1][1] * c[1] - m[1][2] * c[0]) * inv_det;
    d[3][1] = (m[0][0] * c[3] - m[0][1] * c[1] + m[0][2] * c[0]) * inv_det;
    d[3][2] = (-m[3][0] * s[3] + m[3][1] * s[1] - m[3][2] * s[0]) * inv_det;
    d[3][3] = (m[2][0] * s[3] - m[2][1] * s[1] + m[2][2] * s[0]) * inv_det;
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static void matf_invert44(float *dst_mat, const float *mat) {
    float tmp[16];
    matf_invert44_no_alias(tmp, mat);
    for (int i = 0; i < 16; i++)
        dst_mat[i] = tmp[i];
}


//
// matd = double
//
/** mat<n*n> dst = r==c ? 1 : 0 (identity) */
static void matd_eye(double *dst_mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            dst_mat[r * n + c] = r == c ? 1 : 0;
    }
}

/** vec<n> dst = mat<n*n>[row][:] */
static void matd_get_row(double *dst_vec, const double *mat, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_vec[c] = mat[row * n + c];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void matd_get_col(double *dst_vec, const double *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[r * n + col];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void matd_set_row(double *dst_mat, const double *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void matd_set_col(double *dst_mat, const double *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void matd_row_set_sca(double *dst_mat, double scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void matd_col_set_sca(double *dst_mat, double scalar, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = scalar;
}

/** mat<n*n> dst = mat<n*n>^t  (restrict data) */
static void matd_transpose_no_alias(double *restrict dst_mat, const double *restrict mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = mat[c * n + r];
        }
    }
}

/** mat<n*n> dst = mat<n*n>^t */
static void matd_transpose(double *dst_mat, const double *mat, int n) {
    double tmp[n * n];
    matd_transpose_no_alias(tmp, mat, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b  (restrict data) */
static void matd_mul_mat_no_alias(double *restrict dst_mat, const double *restrict mat_a,
                                  const double *restrict mat_b, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = 0;
            for (int k = 0; k < n; k++)
                dst_mat[r * n + c] += mat_a[r * n + k] * mat_b[k * n + c];
        }
    }
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static void matd_mul_mat(double *dst_mat, const double *mat_a, const double *mat_b, int n) {
    double tmp[n * n];
    matd_mul_mat_no_alias(tmp, mat_a, mat_b, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** vec<n> dst = mat<n*n> a * vec<n> b  (restrict data) */
static void matd_mul_vec_no_alias(double *restrict dst_vec, const double *restrict mat_a,
                                  const double *restrict vec_b, int n) {
    for (int r = 0; r < n; r++) {
        dst_vec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_vec[r] += mat_a[r * n + c] * vec_b[c];
        }
    }
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void matd_mul_vec(double *dst_vec, const double *mat_a, const double *vec_b, int n) {
    double tmp[n];
    matd_mul_vec_no_alias(tmp, mat_a, vec_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** vec<n> dst = vec<n> a * mat<n*n> b  (restrict data) */
static void vecd_mul_mat_no_alias(double *restrict dst_vec, const double *restrict vec_a,
                                  const double *restrict mat_b, int n) {
    for (int c = 0; c < n; c++) {
        dst_vec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_vec[c] += mat_b[r * n + c] * vec_a[r];
        }
    }
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static void vecd_mul_mat(double *dst_vec, const double *vec_a, const double *mat_b, int n) {
    double tmp[n];
    vecd_mul_mat_no_alias(tmp, vec_a, mat_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** returns = det mat<3*3> mat33 */
static double matd_determinant33(const double *mat) {
    const double (*m)[3] = (const double (*)[3]) mat;
    return
            m[0][0] * m[1][1] * m[2][2] +
            m[0][1] * m[1][2] * m[2][0] +
            m[0][2] * m[1][0] * m[2][1] -
            m[0][0] * m[1][2] * m[2][1] -
            m[0][1] * m[1][0] * m[2][2] -
            m[0][2] * m[1][1] * m[2][0];
}

/** returns = det mat<4*4> mat44 */
static double matd_determinant44(const double *mat) {
    const double (*m)[4] = (const double (*)[4]) mat;
    return
            m[0][3] * m[1][2] * m[2][1] * m[3][0] -
            m[0][2] * m[1][3] * m[2][1] * m[3][0] -
            m[0][3] * m[1][1] * m[2][2] * m[3][0] +
            m[0][1] * m[1][3] * m[2][2] * m[3][0] +
            m[0][2] * m[1][1] * m[2][3] * m[3][0] -
            m[0][1] * m[1][2] * m[2][3] * m[3][0] -
            m[0][3] * m[1][2] * m[2][0] * m[3][1] +
            m[0][2] * m[1][3] * m[2][0] * m[3][1] +
            m[0][3] * m[1][0] * m[2][2] * m[3][1] -
            m[0][0] * m[1][3] * m[2][2] * m[3][1] -
            m[0][2] * m[1][0] * m[2][3] * m[3][1] +
            m[0][0] * m[1][2] * m[2][3] * m[3][1] +
            m[0][3] * m[1][1] * m[2][0] * m[3][2] -
            m[0][1] * m[1][3] * m[2][0] * m[3][2] -
            m[0][3] * m[1][0] * m[2][1] * m[3][2] +
            m[0][0] * m[1][3] * m[2][1] * m[3][2] +
            m[0][1] * m[1][0] * m[2][3] * m[3][2] -
            m[0][0] * m[1][1] * m[2][3] * m[3][2] -
            m[0][2] * m[1][1] * m[2][0] * m[3][3] +
            m[0][1] * m[1][2] * m[2][0] * m[3][3] +
            m[0][2] * m[1][0] * m[2][1] * m[3][3] -
            m[0][0] * m[1][2] * m[2][1] * m[3][3] -
            m[0][1] * m[1][0] * m[2][2] * m[3][3] +
            m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

/** mat<3*3> dst = inv(mat<3*3> mat33)  (restrict data) */
static void matd_invert33_no_alias(double *restrict dst_mat, const double *restrict mat) {
    double inv_det = 1.0f / matd_determinant33(mat);
    const double (*m)[3] = (const double (*)[3]) mat;
    double (*d)[3] = (double (*)[3]) dst_mat;
    d[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * inv_det;
    d[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * inv_det;
    d[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * inv_det;
    d[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * inv_det;
    d[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * inv_det;
    d[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * inv_det;
    d[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * inv_det;
    d[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * inv_det;
    d[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * inv_det;
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static void matd_invert33(double *dst_mat, const double *mat) {
    double tmp[9];
    matd_invert33_no_alias(tmp, mat);
    for (int i = 0; i < 9; i++)
        dst_mat[i] = tmp[i];
}

/** mat<4*4> dst = inv(mat<4*4> mat44)  (restrict data) */
static void matd_invert44_no_alias(double *restrict dst_mat, const double *restrict mat) {
    // algorithm from https://github.com/datenwolf/linmath.h/blob/master/linmath.h
    double s[6];
    double c[6];
    const double (*m)[4] = (const double (*)[4]) mat;
    double (*d)[4] = (double (*)[4]) dst_mat;
    s[0] = m[0][0] * m[1][1] - m[1][0] * m[0][1];
    s[1] = m[0][0] * m[1][2] - m[1][0] * m[0][2];
    s[2] = m[0][0] * m[1][3] - m[1][0] * m[0][3];
    s[3] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
    s[4] = m[0][1] * m[1][3] - m[1][1] * m[0][3];
    s[5] = m[0][2] * m[1][3] - m[1][2] * m[0][3];

    c[0] = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    c[1] = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    c[2] = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    c[3] = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    c[4] = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    c[5] = m[2][2] * m[3][3] - m[3][2] * m[2][3];

    /* Assumes it is invertible */
    double inv_det = 1.0f / (s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0]);

    d[0][0] = (m[1][1] * c[5] - m[1][2] * c[4] + m[1][3] * c[3]) * inv_det;
    d[0][1] = (-m[0][1] * c[5] + m[0][2] * c[4] - m[0][3] * c[3]) * inv_det;
    d[0][2] = (m[3][1] * s[5] - m[3][2] * s[4] + m[3][3] * s[3]) * inv_det;
    d[0][3] = (-m[2][1] * s[5] + m[2][2] * s[4] - m[2][3] * s[3]) * inv_det;

    d[1][0] = (-m[1][0] * c[5] + m[1][2] * c[2] - m[1][3] * c[1]) * inv_det;
    d[1][1] = (m[0][0] * c[5] - m[0][2] * c[2] + m[0][3] * c[1]) * inv_det;
    d[1][2] = (-m[3][0] * s[5] + m[3][2] * s[2] - m[3][3] * s[1]) * inv_det;
    d[1][3] = (m[2][0] * s[5] - m[2][2] * s[2] + m[2][3] * s[1]) * inv_det;

    d[2][0] = (m[1][0] * c[4] - m[1][1] * c[2] + m[1][3] * c[0]) * inv_det;
    d[2][1] = (-m[0][0] * c[4] + m[0][1] * c[2] - m[0][3] * c[0]) * inv_det;
    d[2][2] = (m[3][0] * s[4] - m[3][1] * s[2] + m[3][3] * s[0]) * inv_det;
    d[2][3] = (-m[2][0] * s[4] + m[2][1] * s[2] - m[2][3] * s[0]) * inv_det;

    d[3][0] = (-m[1][0] * c[3] + m[1][1] * c[1] - m[1][2] * c[0]) * inv_det;
    d[3][1] = (m[0][0] * c[3] - m[0][1] * c[1] + m[0][2] * c[0]) * inv_det;
    d[3][2] = (-m[3][0] * s[3] + m[3][1] * s[1] - m[3][2] * s[0]) * inv_det;
    d[3][3] = (m[2][0] * s[3] - m[2][1] * s[1] + m[2][2] * s[0]) * inv_det;
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static void matd_invert44(double *dst_mat, const double *mat) {
    double tmp[16];
    matd_invert44_no_alias(tmp, mat);
    for (int i = 0; i < 16; i++)
        dst_mat[i] = tmp[i];
}


//
// mati = int
//
/** mat<n*n> dst = r==c ? 1 : 0 (identity) */
static void mati_eye(int *dst_mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            dst_mat[r * n + c] = r == c ? 1 : 0;
    }
}

/** vec<n> dst = mat<n*n>[row][:] */
static void mati_get_row(int *dst_vec, const int *mat, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_vec[c] = mat[row * n + c];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void mati_get_col(int *dst_vec, const int *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[r * n + col];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void mati_set_row(int *dst_mat, const int *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void mati_set_col(int *dst_mat, const int *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void mati_row_set_sca(int *dst_mat, int scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void mati_col_set_sca(int *dst_mat, int scalar, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = scalar;
}

/** mat<n*n> dst = mat<n*n>^t  (restrict data) */
static void mati_transpose_no_alias(int *restrict dst_mat, const int *restrict mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = mat[c * n + r];
        }
    }
}

/** mat<n*n> dst = mat<n*n>^t */
static void mati_transpose(int *dst_mat, const int *mat, int n) {
    int tmp[n * n];
    mati_transpose_no_alias(tmp, mat, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b  (restrict data) */
static void mati_mul_mat_no_alias(int *restrict dst_mat, const int *restrict mat_a,
                                  const int *restrict mat_b, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = 0;
            for (int k = 0; k < n; k++)
                dst_mat[r * n + c] += mat_a[r * n + k] * mat_b[k * n + c];
        }
    }
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b */
static void mati_mul_mat(int *dst_mat, const int *mat_a, const int *mat_b, int n) {
    int tmp[n * n];
    mati_mul_mat_no_alias(tmp, mat_a, mat_b, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** vec<n> dst = mat<n*n> a * vec<n> b  (restrict data) */
static void mati_mul_vec_no_alias(int *restrict dst_vec, const int *restrict mat_a,
                                  const int *restrict vec_b, int n) {
    for (int r = 0; r < n; r++) {
        dst_vec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_vec[r] += mat_a[r * n + c] * vec_b[c];
        }
    }
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void mati_mul_vec(int *dst_vec, const int *mat_a, const int *vec_b, int n) {
    int tmp[n];
    mati_mul_vec_no_alias(tmp, mat_a, vec_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** vec<n> dst = vec<n> a * mat<n*n> b  (restrict data) */
static void veci_mul_mat_no_alias(int *restrict dst_vec, const int *restrict vec_a,
                                  const int *restrict mat_b, int n) {
    for (int c = 0; c < n; c++) {
        dst_vec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_vec[c] += mat_b[r * n + c] * vec_a[r];
        }
    }
}

/** vec<n> dst = vec<n> a * mat<n*n> b */
static void veci_mul_mat(int *dst_vec, const int *vec_a, const int *mat_b, int n) {
    int tmp[n];
    veci_mul_mat_no_alias(tmp, vec_a, mat_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** returns = det mat<3*3> mat33 */
static int mati_determinant33(const int *mat) {
    const int (*m)[3] = (const int (*)[3]) mat;
    return
            m[0][0] * m[1][1] * m[2][2] +
            m[0][1] * m[1][2] * m[2][0] +
            m[0][2] * m[1][0] * m[2][1] -
            m[0][0] * m[1][2] * m[2][1] -
            m[0][1] * m[1][0] * m[2][2] -
            m[0][2] * m[1][1] * m[2][0];
}

/** returns = det mat<4*4> mat44 */
static int mati_determinant44(const int *mat) {
    const int (*m)[4] = (const int (*)[4]) mat;
    return
            m[0][3] * m[1][2] * m[2][1] * m[3][0] -
            m[0][2] * m[1][3] * m[2][1] * m[3][0] -
            m[0][3] * m[1][1] * m[2][2] * m[3][0] +
            m[0][1] * m[1][3] * m[2][2] * m[3][0] +
            m[0][2] * m[1][1] * m[2][3] * m[3][0] -
            m[0][1] * m[1][2] * m[2][3] * m[3][0] -
            m[0][3] * m[1][2] * m[2][0] * m[3][1] +
            m[0][2] * m[1][3] * m[2][0] * m[3][1] +
            m[0][3] * m[1][0] * m[2][2] * m[3][1] -
            m[0][0] * m[1][3] * m[2][2] * m[3][1] -
            m[0][2] * m[1][0] * m[2][3] * m[3][1] +
            m[0][0] * m[1][2] * m[2][3] * m[3][1] +
            m[0][3] * m[1][1] * m[2][0] * m[3][2] -
            m[0][1] * m[1][3] * m[2][0] * m[3][2] -
            m[0][3] * m[1][0] * m[2][1] * m[3][2] +
            m[0][0] * m[1][3] * m[2][1] * m[3][2] +
            m[0][1] * m[1][0] * m[2][3] * m[3][2] -
            m[0][0] * m[1][1] * m[2][3] * m[3][2] -
            m[0][2] * m[1][1] * m[2][0] * m[3][3] +
            m[0][1] * m[1][2] * m[2][0] * m[3][3] +
            m[0][2] * m[1][0] * m[2][1] * m[3][3] -
            m[0][0] * m[1][2] * m[2][1] * m[3][3] -
            m[0][1] * m[1][0] * m[2][2] * m[3][3] +
            m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

/** mat<3*3> dst = inv(mat<3*3> mat33)  (restrict data) */
static void mati_invert33_no_alias(int *restrict dst_mat, const int *restrict mat) {
    int det = mati_determinant33(mat);
    const int (*m)[3] = (const int (*)[3]) mat;
    int (*d)[3] = (int (*)[3]) dst_mat;
    d[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
    d[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
    d[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
    d[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
    d[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    d[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
    d[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
    d[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
    d[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static void mati_invert33(int *dst_mat, const int *mat) {
    int tmp[9];
    mati_invert33_no_alias(tmp, mat);
    for (int i = 0; i < 9; i++)
        dst_mat[i] = tmp[i];
}

/** mat<4*4> dst = inv(mat<4*4> mat44)  (restrict data) */
static void mati_invert44_no_alias(int *restrict dst_mat, const int *restrict mat) {
    // algorithm from https://github.com/datenwolf/linmath.h/blob/master/linmath.h
    int s[6];
    int c[6];
    const int (*m)[4] = (const int (*)[4]) mat;
    int (*d)[4] = (int (*)[4]) dst_mat;
    s[0] = m[0][0] * m[1][1] - m[1][0] * m[0][1];
    s[1] = m[0][0] * m[1][2] - m[1][0] * m[0][2];
    s[2] = m[0][0] * m[1][3] - m[1][0] * m[0][3];
    s[3] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
    s[4] = m[0][1] * m[1][3] - m[1][1] * m[0][3];
    s[5] = m[0][2] * m[1][3] - m[1][2] * m[0][3];

    c[0] = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    c[1] = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    c[2] = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    c[3] = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    c[4] = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    c[5] = m[2][2] * m[3][3] - m[3][2] * m[2][3];

    /* Assumes it is invertible */
    int det = s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0];

    d[0][0] = (m[1][1] * c[5] - m[1][2] * c[4] + m[1][3] * c[3]) / det;
    d[0][1] = (-m[0][1] * c[5] + m[0][2] * c[4] - m[0][3] * c[3]) / det;
    d[0][2] = (m[3][1] * s[5] - m[3][2] * s[4] + m[3][3] * s[3]) / det;
    d[0][3] = (-m[2][1] * s[5] + m[2][2] * s[4] - m[2][3] * s[3]) / det;

    d[1][0] = (-m[1][0] * c[5] + m[1][2] * c[2] - m[1][3] * c[1]) / det;
    d[1][1] = (m[0][0] * c[5] - m[0][2] * c[2] + m[0][3] * c[1]) / det;
    d[1][2] = (-m[3][0] * s[5] + m[3][2] * s[2] - m[3][3] * s[1]) / det;
    d[1][3] = (m[2][0] * s[5] - m[2][2] * s[2] + m[2][3] * s[1]) / det;

    d[2][0] = (m[1][0] * c[4] - m[1][1] * c[2] + m[1][3] * c[0]) / det;
    d[2][1] = (-m[0][0] * c[4] + m[0][1] * c[2] - m[0][3] * c[0]) / det;
    d[2][2] = (m[3][0] * s[4] - m[3][1] * s[2] + m[3][3] * s[0]) / det;
    d[2][3] = (-m[2][0] * s[4] + m[2][1] * s[2] - m[2][3] * s[0]) / det;

    d[3][0] = (-m[1][0] * c[3] + m[1][1] * c[1] - m[1][2] * c[0]) / det;
    d[3][1] = (m[0][0] * c[3] - m[0][1] * c[1] + m[0][2] * c[0]) / det;
    d[3][2] = (-m[3][0] * s[3] + m[3][1] * s[1] - m[3][2] * s[0]) / det;
    d[3][3] = (m[2][0] * s[3] - m[2][1] * s[1] + m[2][2] * s[0]) / det;
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static void mati_invert44(int *dst_mat, const int *mat) {
    int tmp[16];
    mati_invert44_no_alias(tmp, mat);
    for (int i = 0; i < 16; i++)
        dst_mat[i] = tmp[i];
}

#endif //MATHC_MAT_FUNCTIONS_H
