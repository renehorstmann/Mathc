#ifndef UTILC_MATMATH_H
#define UTILC_MATMATH_H

// restrict
#ifdef __cplusplus
#define restrict __restrict
#endif

//

// this header file has the following content:
//
// 1. functions for squared matrix math
// 2. functions for specific sized matrices
//


//
// 1. functions for squared matrix math (nxn)
//

//
// mat = float
//

/** mat<n*n> dst = r==c ? 1 : 0 (identity) */
static void mat_eye(float *dst_mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            dst_mat[r * n + c] = r == c ? 1 : 0;
    }
}

/** vec<n> dst = mat<n*n>[row][:] */
static void mat_row(float *dst_vec, const float *mat, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_vec[c] = mat[row * n + c];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void mat_col(float *dst_vec, const float *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[r * n + col];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void mat_row_copy(float *dst_mat, const float *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void mat_col_copy(float *dst_mat, const float *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void mat_row_set(float *dst_mat, float scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void mat_col_set(float *dst_mat, float scalar, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = scalar;
}

/** mat<n*n> dst = mat<n*n>^t  (restrict data) */
static void mat_transpose_no_alias(float *restrict dst_mat, const float *restrict mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = mat[c * n + r];
        }
    }
}

/** mat<n*n> dst = mat<n*n>^t */
static void mat_transpose(float *dst_mat, const float *mat, int n) {
    float tmp[n * n];
    mat_transpose_no_alias(tmp, mat, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b  (restrict data) */
static void mat_mul_mat_no_alias(float *restrict dst_mat, const float *restrict mat_a,
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
static void mat_mul_mat(float *dst_mat, const float *mat_a, const float *mat_b, int n) {
    float tmp[n * n];
    mat_mul_mat_no_alias(tmp, mat_a, mat_b, n);
    for (int i = 0; i < n * n; i++)
        dst_mat[i] = tmp[i];
}

/** vec<n> dst = mat<n*n> a * vec<n> b  (restrict data) */
static void mat_mul_vec_no_alias(float *restrict dst_vec, const float *restrict mat_a,
                                 const float *restrict vec_b, int n) {
    for (int r = 0; r < n; r++) {
        dst_vec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_vec[r] += mat_a[r * n + c] * vec_b[c];
        }
    }
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void mat_mul_vec(float *dst_vec, const float *mat_a, const float *vec_b, int n) {
    float tmp[n];
    mat_mul_vec_no_alias(tmp, mat_a, vec_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** vec<n> dst = mat<n*n> a * vec<n> b  (restrict data) */
static void vec_mul_mat_no_alias(float *restrict dst_vec, const float *restrict vec_a,
                                 const float *restrict mat_b, int n) {
    for (int c = 0; c < n; c++) {
        dst_vec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_vec[c] += mat_b[r * n + c] * vec_a[r];
        }
    }
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void vec_mul_mat(float *dst_vec, const float *vec_a, const float *mat_b, int n) {
    float tmp[n];
    vec_mul_mat_no_alias(tmp, vec_a, mat_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** returns = det mat<3*3> mat33 */
static float mat_determinant33(const float *mat) {
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
static float mat_determinant44(const float *mat) {
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
static void mat_invert33_no_alias(float *restrict dst_mat, const float *restrict mat) {
    float inv_det = 1.0f / mat_determinant33(mat);
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
static void mat_invert33(float *dst_mat, const float *mat) {
    float tmp[9];
    mat_invert33_no_alias(tmp, mat);
    for (int i = 0; i < 9; i++)
        dst_mat[i] = tmp[i];
}

/** mat<4*4> dst = inv(mat<4*4> mat44)  (restrict data) */
static void mat_invert44_no_alias(float *restrict dst_mat, const float *restrict mat) {
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
static void mat_invert44(float *dst_mat, const float *mat) {
    float tmp[16];
    mat_invert44_no_alias(tmp, mat);
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
static void matd_row(double *dst_vec, const double *mat, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_vec[c] = mat[row * n + c];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void matd_col(double *dst_vec, const double *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[r * n + col];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void matd_row_copy(double *dst_mat, const double *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void matd_col_copy(double *dst_mat, const double *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[r * n + col] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void matd_row_set(double *dst_mat, double scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[row * n + c] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void matd_col_set(double *dst_mat, double scalar, int col, int n) {
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

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b (restrict data) */
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

/** vec<n> dst = mat<n*n> a * vec<n> b (restrict data)*/
static void matd_mul_vec_no_alias(double *restrict dst_vec, const double *restrict mat_a,
                                  const double *restrict vec_b, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_vec[r] = 0;
            for (int i = 0; i < n; i++)
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

/** vec<n> dst = mat<n*n> a * vec<n> b  (restrict data) */
static void vecd_mul_mat_no_alias(double *restrict dst_vec, const double *restrict vec_a,
                                  const double *restrict mat_b, int n) {
    for (int c = 0; c < n; c++) {
        dst_vec[c] = 0;
        for (int r = 0; r < n; r++) {
            dst_vec[c] += mat_b[r * n + c] * vec_a[r];
        }
    }
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void vecd_mul_mat(double *dst_vec, const double *vec_a, const double *mat_b, int n) {
    double tmp[n];
    vecd_mul_mat_no_alias(tmp, vec_a, mat_b, n);
    for (int i = 0; i < n; i++)
        dst_vec[i] = tmp[i];
}

/** returns = det mat<3*3> mat33 */
static double matd_determinant33(const double *mat) {
    return
            mat[0 * 3 + 0] * mat[1 * 3 + 1] * mat[2 * 3 + 2] +
            mat[0 * 3 + 1] * mat[1 * 3 + 2] * mat[2 * 3 + 0] +
            mat[0 * 3 + 2] * mat[1 * 3 + 0] * mat[2 * 3 + 1] -
            mat[0 * 3 + 0] * mat[1 * 3 + 2] * mat[2 * 3 + 1] -
            mat[0 * 3 + 1] * mat[1 * 3 + 0] * mat[2 * 3 + 2] -
            mat[0 * 3 + 2] * mat[1 * 3 + 1] * mat[2 * 3 + 0];
}

/** returns = det mat<4*4> mat44 */
static double matd_determinant44(const double *mat) {
    return
            mat[0 * 4 + 3] * mat[1 * 4 + 2] * mat[2 * 4 + 1] * mat[3 * 4 + 0] -
            mat[0 * 4 + 2] * mat[1 * 4 + 3] * mat[2 * 4 + 1] * mat[3 * 4 + 0] -
            mat[0 * 4 + 3] * mat[1 * 4 + 1] * mat[2 * 4 + 2] * mat[3 * 4 + 0] +
            mat[0 * 4 + 1] * mat[1 * 4 + 3] * mat[2 * 4 + 2] * mat[3 * 4 + 0] +
            mat[0 * 4 + 2] * mat[1 * 4 + 1] * mat[2 * 4 + 3] * mat[3 * 4 + 0] -
            mat[0 * 4 + 1] * mat[1 * 4 + 2] * mat[2 * 4 + 3] * mat[3 * 4 + 0] -
            mat[0 * 4 + 3] * mat[1 * 4 + 2] * mat[2 * 4 + 0] * mat[3 * 4 + 1] +
            mat[0 * 4 + 2] * mat[1 * 4 + 3] * mat[2 * 4 + 0] * mat[3 * 4 + 1] +
            mat[0 * 4 + 3] * mat[1 * 4 + 0] * mat[2 * 4 + 2] * mat[3 * 4 + 1] -
            mat[0 * 4 + 0] * mat[1 * 4 + 3] * mat[2 * 4 + 2] * mat[3 * 4 + 1] -
            mat[0 * 4 + 2] * mat[1 * 4 + 0] * mat[2 * 4 + 3] * mat[3 * 4 + 1] +
            mat[0 * 4 + 0] * mat[1 * 4 + 2] * mat[2 * 4 + 3] * mat[3 * 4 + 1] +
            mat[0 * 4 + 3] * mat[1 * 4 + 1] * mat[2 * 4 + 0] * mat[3 * 4 + 2] -
            mat[0 * 4 + 1] * mat[1 * 4 + 3] * mat[2 * 4 + 0] * mat[3 * 4 + 2] -
            mat[0 * 4 + 3] * mat[1 * 4 + 0] * mat[2 * 4 + 1] * mat[3 * 4 + 2] +
            mat[0 * 4 + 0] * mat[1 * 4 + 3] * mat[2 * 4 + 1] * mat[3 * 4 + 2] +
            mat[0 * 4 + 1] * mat[1 * 4 + 0] * mat[2 * 4 + 3] * mat[3 * 4 + 2] -
            mat[0 * 4 + 0] * mat[1 * 4 + 1] * mat[2 * 4 + 3] * mat[3 * 4 + 2] -
            mat[0 * 4 + 2] * mat[1 * 4 + 1] * mat[2 * 4 + 0] * mat[3 * 4 + 3] +
            mat[0 * 4 + 1] * mat[1 * 4 + 2] * mat[2 * 4 + 0] * mat[3 * 4 + 3] +
            mat[0 * 4 + 2] * mat[1 * 4 + 0] * mat[2 * 4 + 1] * mat[3 * 4 + 3] -
            mat[0 * 4 + 0] * mat[1 * 4 + 2] * mat[2 * 4 + 1] * mat[3 * 4 + 3] -
            mat[0 * 4 + 1] * mat[1 * 4 + 0] * mat[2 * 4 + 2] * mat[3 * 4 + 3] +
            mat[0 * 4 + 0] * mat[1 * 4 + 1] * mat[2 * 4 + 2] * mat[3 * 4 + 3];
}

/** mat<3*3> dst = inv(mat<3*3> mat33) (restrict data) */
static void matd_invert33_no_alias(double *restrict dst_mat, const double *restrict mat) {
    double idet = 1.0 / matd_determinant33(mat);
    dst_mat[0 * 3 + 0] = (mat[1 * 3 + 1] * mat[2 * 3 + 2] - mat[1 * 3 + 2] * mat[2 * 3 + 1]) * idet;
    dst_mat[0 * 3 + 1] = (mat[0 * 3 + 2] * mat[2 * 3 + 1] - mat[0 * 3 + 1] * mat[2 * 3 + 2]) * idet;
    dst_mat[0 * 3 + 2] = (mat[0 * 3 + 1] * mat[1 * 3 + 2] - mat[0 * 3 + 2] * mat[1 * 3 + 1]) * idet;
    dst_mat[1 * 3 + 0] = (mat[1 * 3 + 2] * mat[2 * 3 + 0] - mat[1 * 3 + 0] * mat[2 * 3 + 2]) * idet;
    dst_mat[1 * 3 + 1] = (mat[0 * 3 + 0] * mat[2 * 3 + 2] - mat[0 * 3 + 2] * mat[2 * 3 + 0]) * idet;
    dst_mat[1 * 3 + 2] = (mat[0 * 3 + 2] * mat[1 * 3 + 0] - mat[0 * 3 + 0] * mat[1 * 3 + 2]) * idet;
    dst_mat[2 * 3 + 0] = (mat[1 * 3 + 0] * mat[2 * 3 + 1] - mat[1 * 3 + 1] * mat[2 * 3 + 0]) * idet;
    dst_mat[2 * 3 + 1] = (mat[0 * 3 + 1] * mat[2 * 3 + 0] - mat[0 * 3 + 0] * mat[2 * 3 + 1]) * idet;
    dst_mat[2 * 3 + 2] = (mat[0 * 3 + 0] * mat[1 * 3 + 1] - mat[0 * 3 + 1] * mat[1 * 3 + 0]) * idet;
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
    s[0] = mat[0 * 4 + 0] * mat[1 * 4 + 1] - mat[1 * 4 + 0] * mat[0 * 4 + 1];
    s[1] = mat[0 * 4 + 0] * mat[1 * 4 + 2] - mat[1 * 4 + 0] * mat[0 * 4 + 2];
    s[2] = mat[0 * 4 + 0] * mat[1 * 4 + 3] - mat[1 * 4 + 0] * mat[0 * 4 + 3];
    s[3] = mat[0 * 4 + 1] * mat[1 * 4 + 2] - mat[1 * 4 + 1] * mat[0 * 4 + 2];
    s[4] = mat[0 * 4 + 1] * mat[1 * 4 + 3] - mat[1 * 4 + 1] * mat[0 * 4 + 3];
    s[5] = mat[0 * 4 + 2] * mat[1 * 4 + 3] - mat[1 * 4 + 2] * mat[0 * 4 + 3];

    c[0] = mat[2 * 4 + 0] * mat[3 * 4 + 1] - mat[3 * 4 + 0] * mat[2 * 4 + 1];
    c[1] = mat[2 * 4 + 0] * mat[3 * 4 + 2] - mat[3 * 4 + 0] * mat[2 * 4 + 2];
    c[2] = mat[2 * 4 + 0] * mat[3 * 4 + 3] - mat[3 * 4 + 0] * mat[2 * 4 + 3];
    c[3] = mat[2 * 4 + 1] * mat[3 * 4 + 2] - mat[3 * 4 + 1] * mat[2 * 4 + 2];
    c[4] = mat[2 * 4 + 1] * mat[3 * 4 + 3] - mat[3 * 4 + 1] * mat[2 * 4 + 3];
    c[5] = mat[2 * 4 + 2] * mat[3 * 4 + 3] - mat[3 * 4 + 2] * mat[2 * 4 + 3];

    /* Assumes it is invertible */
    double idet = 1.0f / (s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0]);

    dst_mat[0 * 4 + 0] = (mat[1 * 4 + 1] * c[5] - mat[1 * 4 + 2] * c[4] + mat[1 * 4 + 3] * c[3]) * idet;
    dst_mat[0 * 4 + 1] = (-mat[0 * 4 + 1] * c[5] + mat[0 * 4 + 2] * c[4] - mat[0 * 4 + 3] * c[3]) * idet;
    dst_mat[0 * 4 + 2] = (mat[3 * 4 + 1] * s[5] - mat[3 * 4 + 2] * s[4] + mat[3 * 4 + 3] * s[3]) * idet;
    dst_mat[0 * 4 + 3] = (-mat[2 * 4 + 1] * s[5] + mat[2 * 4 + 2] * s[4] - mat[2 * 4 + 3] * s[3]) * idet;

    dst_mat[1 * 4 + 0] = (-mat[1 * 4 + 0] * c[5] + mat[1 * 4 + 2] * c[2] - mat[1 * 4 + 3] * c[1]) * idet;
    dst_mat[1 * 4 + 1] = (mat[0 * 4 + 0] * c[5] - mat[0 * 4 + 2] * c[2] + mat[0 * 4 + 3] * c[1]) * idet;
    dst_mat[1 * 4 + 2] = (-mat[3 * 4 + 0] * s[5] + mat[3 * 4 + 2] * s[2] - mat[3 * 4 + 3] * s[1]) * idet;
    dst_mat[1 * 4 + 3] = (mat[2 * 4 + 0] * s[5] - mat[2 * 4 + 2] * s[2] + mat[2 * 4 + 3] * s[1]) * idet;

    dst_mat[2 * 4 + 0] = (mat[1 * 4 + 0] * c[4] - mat[1 * 4 + 1] * c[2] + mat[1 * 4 + 3] * c[0]) * idet;
    dst_mat[2 * 4 + 1] = (-mat[0 * 4 + 0] * c[4] + mat[0 * 4 + 1] * c[2] - mat[0 * 4 + 3] * c[0]) * idet;
    dst_mat[2 * 4 + 2] = (mat[3 * 4 + 0] * s[4] - mat[3 * 4 + 1] * s[2] + mat[3 * 4 + 3] * s[0]) * idet;
    dst_mat[2 * 4 + 3] = (-mat[2 * 4 + 0] * s[4] + mat[2 * 4 + 1] * s[2] - mat[2 * 4 + 3] * s[0]) * idet;

    dst_mat[3 * 4 + 0] = (-mat[1 * 4 + 0] * c[3] + mat[1 * 4 + 1] * c[1] - mat[1 * 4 + 2] * c[0]) * idet;
    dst_mat[3 * 4 + 1] = (mat[0 * 4 + 0] * c[3] - mat[0 * 4 + 1] * c[1] + mat[0 * 4 + 2] * c[0]) * idet;
    dst_mat[3 * 4 + 2] = (-mat[3 * 4 + 0] * s[3] + mat[3 * 4 + 1] * s[1] - mat[3 * 4 + 2] * s[0]) * idet;
    dst_mat[3 * 4 + 3] = (mat[2 * 4 + 0] * s[3] - mat[2 * 4 + 1] * s[1] + mat[2 * 4 + 2] * s[0]) * idet;
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static void matd_invert44(double *dst_mat, const double *mat) {
    double tmp[16];
    matd_invert44_no_alias(tmp, mat);
    for (int i = 0; i < 16; i++)
        dst_mat[i] = tmp[i];
}



//
// 2. specific size functions
//

//
// mat33
//
typedef struct mat33 {
    float m[9];
} mat33;

/** Mat33 = r==c ? 1 : 0 (identity) */
static mat33 mat33_eye() {
    mat33 res;
    mat_eye(res.m, 3);
    return res;
}

/** Mat33 = mat<3*3>^t */
static mat33 mat33_transpose(const float *mat) {
    mat33 res;
    mat_transpose_no_alias(res.m, mat, 3);
    return res;
}

/** Mat33 = mat<3*3> a * mat<3*3> b */
static mat33 mat33_mul_mat(const float *mat_a, const float *mat_b) {
    mat33 res;
    mat_mul_mat_no_alias(res.m, mat_a, mat_b, 3);
    return res;
}

/** Mat33 = inv(mat<3*3> mat33) */
static mat33 mat33_invert(const float *mat) {
    mat33 res;
    mat_invert33_no_alias(res.m, mat);
    return res;
}


//
// mat33d
//
typedef struct mat33d {
    double m[9];
} mat33d;

/** Mat33 = r==c ? 1 : 0 (identity) */
static mat33d mat33d_eye() {
    mat33d res;
    matd_eye(res.m, 3);
    return res;
}

/** Mat33 = mat<3*3>^t */
static mat33d mat33d_transpose(const double *mat) {
    mat33d res;
    matd_transpose_no_alias(res.m, mat, 3);
    return res;
}

/** Mat33 = mat<3*3> a * mat<3*3> b */
static mat33d mat33d_mul_mat(const double *mat_a, const double *mat_b) {
    mat33d res;
    matd_mul_mat_no_alias(res.m, mat_a, mat_b, 3);
    return res;
}

/** Mat33 = inv(mat<3*3> mat33) */
static mat33d mat33d_invert(const double *mat) {
    mat33d res;
    matd_invert33_no_alias(res.m, mat);
    return res;
}


//
// mat44
//
typedef struct mat44 {
    float m[16];
} mat44;

/** Mat44 = r==c ? 1 : 0 (identity) */
static mat44 mat44_eye() {
    mat44 res;
    mat_eye(res.m, 4);
    return res;
}

/** Mat44 = mat<4*4>^t */
static mat44 mat44_transpose(const float *mat) {
    mat44 res;
    mat_transpose_no_alias(res.m, mat, 4);
    return res;
}

/** Mat44 = mat<4*4> a * mat<4*4> b */
static mat44 mat44_mul_mat(const float *mat_a, const float *mat_b) {
    mat44 res;
    mat_mul_mat_no_alias(res.m, mat_a, mat_b, 4);
    return res;
}

/** Mat44 = inv(mat<4*4> mat44) */
static mat44 mat44_invert(const float *mat) {
    mat44 res;
    mat_invert44_no_alias(res.m, mat);
    return res;
}


//
// mat44d
//
typedef struct mat44d {
    double m[16];
} mat44d;

/** Mat44 = r==c ? 1 : 0 (identity) */
static mat44d mat44d_eye() {
    mat44d res;
    matd_eye(res.m, 4);
    return res;
}

/** Mat44 = mat<4*4>^t */
static mat44d mat44d_transpose(const double *mat) {
    mat44d res;
    matd_transpose_no_alias(res.m, mat, 4);
    return res;
}

/** Mat44 = mat<4*4> a * mat<4*4> b */
static mat44d mat44d_mul_mat(const double *mat_a, const double *mat_b) {
    mat44d res;
    matd_mul_mat_no_alias(res.m, mat_a, mat_b, 4);
    return res;
}

/** Mat44 = inv(mat<4*4> mat44) */
static mat44d mat44d_invert(const double *mat) {
    mat44d res;
    matd_invert44_no_alias(res.m, mat);
    return res;
}


#endif //UTILC_MATMATH_H

