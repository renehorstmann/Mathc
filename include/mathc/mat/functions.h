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
        dst_vec[c] = mat[c * n + row];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void matf_get_col(float *dst_vec, const float *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[col * n + r];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void matf_set_row(float *dst_mat, const float *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[c * n + row] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void matf_set_col(float *dst_mat, const float *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[col * n + r] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void matf_row_set_sca(float *dst_mat, float scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[c * n + row] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void matf_col_set_sca(float *dst_mat, float scalar, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[col * n + r] = scalar;
}

/** mat<n*n> dst = mat<n*n>^t  (restrict data) */
static void matf_transpose_no_alias(float *restrict dst_mat, const float *restrict mat, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_mat[c * n + r] = mat[c * n + r];
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
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_mat[c * n + r] = 0;
            for (int k = 0; k < n; k++)
                dst_mat[c * n + r] += mat_a[k * n + r] * mat_b[c * n + k];
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
            dst_vec[r] += mat_a[c * n + r] * vec_b[c];
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
            dst_vec[c] += mat_b[c * n + r] * vec_a[r];
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

/** returns det mat<2*2> matrix */
static float matf_determinant22(const float *matrix) {
    // from cglm/mat2.h/glm_mat2_det
    const float (*mat)[2] = (const float (*)[2]) matrix;
    return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

/** returns = det mat<3*3> matrix */
static float matf_determinant33(const float *matrix) {
    // from cglm/mat3.h/glm_mat3_det
    const float (*mat)[3] = (const float (*)[3]) matrix;
    float a = mat[0][0], b = mat[0][1], c = mat[0][2],
            d = mat[1][0], e = mat[1][1], f = mat[1][2],
            g = mat[2][0], h = mat[2][1], i = mat[2][2];

    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
}

/** returns = det mat<4*4> matrix */
static float matf_determinant44(const float *matrix) {
    // from cglm/mat4.h/glm_mat4_det
    const float (*mat)[4] = (const float (*)[4]) matrix;
    /* [square] det(A) = det(At) */
    float t[6];
    float a = mat[0][0], b = mat[0][1], c = mat[0][2], d = mat[0][3],
            e = mat[1][0], f = mat[1][1], g = mat[1][2], h = mat[1][3],
            i = mat[2][0], j = mat[2][1], k = mat[2][2], l = mat[2][3],
            m = mat[3][0], n = mat[3][1], o = mat[3][2], p = mat[3][3];

    t[0] = k * p - o * l;
    t[1] = j * p - n * l;
    t[2] = j * o - n * k;
    t[3] = i * p - m * l;
    t[4] = i * o - m * k;
    t[5] = i * n - m * j;

    return a * (f * t[0] - g * t[1] + h * t[2])
           - b * (e * t[0] - g * t[3] + h * t[4])
           + c * (e * t[1] - f * t[3] + h * t[5])
           - d * (e * t[2] - f * t[4] + g * t[5]);
}

/** mat<2*2> dst = inv(mat<2*2> matrix)  (restrict data) */
static void matf_invert22_no_alias(float *restrict dst_mat, const float *restrict matrix) {
    // from cglm/mat2.h/glm_mat2_inv
    float (*dest)[2] = (float (*)[2]) dst_mat;
    const float (*mat)[2] = (const float (*)[2]) matrix;

    float det;
    float a = mat[0][0], b = mat[0][1],
            c = mat[1][0], d = mat[1][1];

    det = 1.0f / (a * d - b * c);

    dest[0][0] =  d * det;
    dest[0][1] = -b * det;
    dest[1][0] = -c * det;
    dest[1][1] =  a * det;
}

/** mat<3*3> dst = inv(mat<3*3> mat) */
static void matf_invert22(float *dst_mat, const float *mat) {
    float tmp[4];
    matf_invert22_no_alias(tmp, mat);
    for (int i = 0; i < 4; i++)
        dst_mat[i] = tmp[i];
}

/** mat<3*3> dst = inv(mat<3*3> matrix)  (restrict data) */
static void matf_invert33_no_alias(float *restrict dst_mat, const float *restrict matrix) {
    // from cglm/mat3.h/glm_mat3_inv
    float (*dest)[3] = (float (*)[3]) dst_mat;
    const float (*mat)[3] = (const float (*)[3]) matrix;

    float det;
    float a = mat[0][0], b = mat[0][1], c = mat[0][2],
            d = mat[1][0], e = mat[1][1], f = mat[1][2],
            g = mat[2][0], h = mat[2][1], i = mat[2][2];

    dest[0][0] =   e * i - f * h;
    dest[0][1] = -(b * i - h * c);
    dest[0][2] =   b * f - e * c;
    dest[1][0] = -(d * i - g * f);
    dest[1][1] =   a * i - c * g;
    dest[1][2] = -(a * f - d * c);
    dest[2][0] =   d * h - g * e;
    dest[2][1] = -(a * h - g * b);
    dest[2][2] =   a * e - b * d;

    det = 1.0f / (a * dest[0][0] + b * dest[1][0] + c * dest[2][0]);

    for(int idx=0; idx < 9; idx++)
        dst_mat[idx] *= det;
}

/** mat<3*3> dst = inv(mat<3*3> mat) */
static void matf_invert33(float *dst_mat, const float *mat) {
    float tmp[9];
    matf_invert33_no_alias(tmp, mat);
    for (int i = 0; i < 9; i++)
        dst_mat[i] = tmp[i];
}

/** mat<4*4> dst = inv(mat<4*4> matrix)  (restrict data) */
static void matf_invert44_no_alias(float *restrict dst_mat, const float *restrict matrix) {
    // from cglm/mat4.h/glm_mat4_inv
    float (*dest)[4] = (float (*)[4]) dst_mat;
    const float (*mat)[4] = (const float (*)[4]) matrix;
    
    float t[6];
    float det;
    float a = mat[0][0], b = mat[0][1], c = mat[0][2], d = mat[0][3],
            e = mat[1][0], f = mat[1][1], g = mat[1][2], h = mat[1][3],
            i = mat[2][0], j = mat[2][1], k = mat[2][2], l = mat[2][3],
            m = mat[3][0], n = mat[3][1], o = mat[3][2], p = mat[3][3];

    t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;
    t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;

    dest[0][0] =  f * t[0] - g * t[1] + h * t[2];
    dest[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
    dest[2][0] =  e * t[1] - f * t[3] + h * t[5];
    dest[3][0] =-(e * t[2] - f * t[4] + g * t[5]);

    dest[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
    dest[1][1] =  a * t[0] - c * t[3] + d * t[4];
    dest[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
    dest[3][1] =  a * t[2] - b * t[4] + c * t[5];

    t[0] = g * p - o * h; t[1] = f * p - n * h; t[2] = f * o - n * g;
    t[3] = e * p - m * h; t[4] = e * o - m * g; t[5] = e * n - m * f;

    dest[0][2] =  b * t[0] - c * t[1] + d * t[2];
    dest[1][2] =-(a * t[0] - c * t[3] + d * t[4]);
    dest[2][2] =  a * t[1] - b * t[3] + d * t[5];
    dest[3][2] =-(a * t[2] - b * t[4] + c * t[5]);

    t[0] = g * l - k * h; t[1] = f * l - j * h; t[2] = f * k - j * g;
    t[3] = e * l - i * h; t[4] = e * k - i * g; t[5] = e * j - i * f;

    dest[0][3] =-(b * t[0] - c * t[1] + d * t[2]);
    dest[1][3] =  a * t[0] - c * t[3] + d * t[4];
    dest[2][3] =-(a * t[1] - b * t[3] + d * t[5]);
    dest[3][3] =  a * t[2] - b * t[4] + c * t[5];

    det = 1.0f / (a * dest[0][0] + b * dest[1][0]
                  + c * dest[2][0] + d * dest[3][0]);

    for(int idx=0; idx < 9; idx++)
        dst_mat[idx] *= det;
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
        dst_vec[c] = mat[c * n + row];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void matd_get_col(double *dst_vec, const double *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[col * n + r];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void matd_set_row(double *dst_mat, const double *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[c * n + row] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void matd_set_col(double *dst_mat, const double *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[col * n + r] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void matd_row_set_sca(double *dst_mat, double scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[c * n + row] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void matd_col_set_sca(double *dst_mat, double scalar, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[col * n + r] = scalar;
}

/** mat<n*n> dst = mat<n*n>^t  (restrict data) */
static void matd_transpose_no_alias(double *restrict dst_mat, const double *restrict mat, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_mat[c * n + r] = mat[c * n + r];
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
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_mat[c * n + r] = 0;
            for (int k = 0; k < n; k++)
                dst_mat[c * n + r] += mat_a[k * n + r] * mat_b[c * n + k];
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
            dst_vec[r] += mat_a[c * n + r] * vec_b[c];
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
            dst_vec[c] += mat_b[c * n + r] * vec_a[r];
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

/** returns det mat<2*2> matrix */
static double matd_determinant22(const double *matrix) {
    // from cglm/mat2.h/glm_mat2_det
    const double (*mat)[2] = (const double (*)[2]) matrix;
    return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

/** returns = det mat<3*3> matrix */
static double matd_determinant33(const double *matrix) {
    // from cglm/mat3.h/glm_mat3_det
    const double (*mat)[3] = (const double (*)[3]) matrix;
    double a = mat[0][0], b = mat[0][1], c = mat[0][2],
            d = mat[1][0], e = mat[1][1], f = mat[1][2],
            g = mat[2][0], h = mat[2][1], i = mat[2][2];

    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
}

/** returns = det mat<4*4> matrix */
static double matd_determinant44(const double *matrix) {
    // from cglm/mat4.h/glm_mat4_det
    const double (*mat)[4] = (const double (*)[4]) matrix;
    /* [square] det(A) = det(At) */
    double t[6];
    double a = mat[0][0], b = mat[0][1], c = mat[0][2], d = mat[0][3],
            e = mat[1][0], f = mat[1][1], g = mat[1][2], h = mat[1][3],
            i = mat[2][0], j = mat[2][1], k = mat[2][2], l = mat[2][3],
            m = mat[3][0], n = mat[3][1], o = mat[3][2], p = mat[3][3];

    t[0] = k * p - o * l;
    t[1] = j * p - n * l;
    t[2] = j * o - n * k;
    t[3] = i * p - m * l;
    t[4] = i * o - m * k;
    t[5] = i * n - m * j;

    return a * (f * t[0] - g * t[1] + h * t[2])
           - b * (e * t[0] - g * t[3] + h * t[4])
           + c * (e * t[1] - f * t[3] + h * t[5])
           - d * (e * t[2] - f * t[4] + g * t[5]);
}

/** mat<2*2> dst = inv(mat<2*2> matrix)  (restrict data) */
static void matd_invert22_no_alias(double *restrict dst_mat, const double *restrict matrix) {
    // from cglm/mat2.h/glm_mat2_inv
    double (*dest)[2] = (double (*)[2]) dst_mat;
    const double (*mat)[2] = (const double (*)[2]) matrix;

    double det;
    double a = mat[0][0], b = mat[0][1],
            c = mat[1][0], d = mat[1][1];

    det = 1.0f / (a * d - b * c);

    dest[0][0] =  d * det;
    dest[0][1] = -b * det;
    dest[1][0] = -c * det;
    dest[1][1] =  a * det;
}

/** mat<3*3> dst = inv(mat<3*3> mat) */
static void matd_invert22(double *dst_mat, const double *mat) {
    double tmp[4];
    matd_invert22_no_alias(tmp, mat);
    for (int i = 0; i < 4; i++)
        dst_mat[i] = tmp[i];
}

/** mat<3*3> dst = inv(mat<3*3> matrix)  (restrict data) */
static void matd_invert33_no_alias(double *restrict dst_mat, const double *restrict matrix) {
    // from cglm/mat3.h/glm_mat3_inv
    double (*dest)[3] = (double (*)[3]) dst_mat;
    const double (*mat)[3] = (const double (*)[3]) matrix;

    double det;
    double a = mat[0][0], b = mat[0][1], c = mat[0][2],
            d = mat[1][0], e = mat[1][1], f = mat[1][2],
            g = mat[2][0], h = mat[2][1], i = mat[2][2];

    dest[0][0] =   e * i - f * h;
    dest[0][1] = -(b * i - h * c);
    dest[0][2] =   b * f - e * c;
    dest[1][0] = -(d * i - g * f);
    dest[1][1] =   a * i - c * g;
    dest[1][2] = -(a * f - d * c);
    dest[2][0] =   d * h - g * e;
    dest[2][1] = -(a * h - g * b);
    dest[2][2] =   a * e - b * d;

    det = 1.0f / (a * dest[0][0] + b * dest[1][0] + c * dest[2][0]);

    for(int idx=0; idx < 9; idx++)
        dst_mat[idx] *= det;
}

/** mat<3*3> dst = inv(mat<3*3> mat) */
static void matd_invert33(double *dst_mat, const double *mat) {
    double tmp[9];
    matd_invert33_no_alias(tmp, mat);
    for (int i = 0; i < 9; i++)
        dst_mat[i] = tmp[i];
}

/** mat<4*4> dst = inv(mat<4*4> matrix)  (restrict data) */
static void matd_invert44_no_alias(double *restrict dst_mat, const double *restrict matrix) {
    // from cglm/mat4.h/glm_mat4_inv
    double (*dest)[4] = (double (*)[4]) dst_mat;
    const double (*mat)[4] = (const double (*)[4]) matrix;
    
    double t[6];
    double det;
    double a = mat[0][0], b = mat[0][1], c = mat[0][2], d = mat[0][3],
            e = mat[1][0], f = mat[1][1], g = mat[1][2], h = mat[1][3],
            i = mat[2][0], j = mat[2][1], k = mat[2][2], l = mat[2][3],
            m = mat[3][0], n = mat[3][1], o = mat[3][2], p = mat[3][3];

    t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;
    t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;

    dest[0][0] =  f * t[0] - g * t[1] + h * t[2];
    dest[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
    dest[2][0] =  e * t[1] - f * t[3] + h * t[5];
    dest[3][0] =-(e * t[2] - f * t[4] + g * t[5]);

    dest[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
    dest[1][1] =  a * t[0] - c * t[3] + d * t[4];
    dest[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
    dest[3][1] =  a * t[2] - b * t[4] + c * t[5];

    t[0] = g * p - o * h; t[1] = f * p - n * h; t[2] = f * o - n * g;
    t[3] = e * p - m * h; t[4] = e * o - m * g; t[5] = e * n - m * f;

    dest[0][2] =  b * t[0] - c * t[1] + d * t[2];
    dest[1][2] =-(a * t[0] - c * t[3] + d * t[4]);
    dest[2][2] =  a * t[1] - b * t[3] + d * t[5];
    dest[3][2] =-(a * t[2] - b * t[4] + c * t[5]);

    t[0] = g * l - k * h; t[1] = f * l - j * h; t[2] = f * k - j * g;
    t[3] = e * l - i * h; t[4] = e * k - i * g; t[5] = e * j - i * f;

    dest[0][3] =-(b * t[0] - c * t[1] + d * t[2]);
    dest[1][3] =  a * t[0] - c * t[3] + d * t[4];
    dest[2][3] =-(a * t[1] - b * t[3] + d * t[5]);
    dest[3][3] =  a * t[2] - b * t[4] + c * t[5];

    det = 1.0f / (a * dest[0][0] + b * dest[1][0]
                  + c * dest[2][0] + d * dest[3][0]);

    for(int idx=0; idx < 9; idx++)
        dst_mat[idx] *= det;
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
        dst_vec[c] = mat[c * n + row];
}

/** vec<n> dst = mat<n*n>[:][col] */
static void mati_get_col(int *dst_vec, const int *mat, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_vec[r] = mat[col * n + r];
}

/** mat<n*n>[row][:] dst = vec<n> */
static void mati_set_row(int *dst_mat, const int *vec, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[c * n + row] = vec[c];
}

/** mat<n*n>[:][col] dst = vec<n> */
static void mati_set_col(int *dst_mat, const int *vec, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[col * n + r] = vec[r];
}

/** mat<n*n>[row][:] dst = scalar */
static void mati_row_set_sca(int *dst_mat, int scalar, int row, int n) {
    for (int c = 0; c < n; c++)
        dst_mat[c * n + row] = scalar;
}

/** mat<n*n>[:][col] dst = scalar */
static void mati_col_set_sca(int *dst_mat, int scalar, int col, int n) {
    for (int r = 0; r < n; r++)
        dst_mat[col * n + r] = scalar;
}

/** mat<n*n> dst = mat<n*n>^t  (restrict data) */
static void mati_transpose_no_alias(int *restrict dst_mat, const int *restrict mat, int n) {
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_mat[c * n + r] = mat[c * n + r];
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
    for (int c = 0; c < n; c++) {
        for (int r = 0; r < n; r++) {
            dst_mat[c * n + r] = 0;
            for (int k = 0; k < n; k++)
                dst_mat[c * n + r] += mat_a[k * n + r] * mat_b[c * n + k];
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
            dst_vec[r] += mat_a[c * n + r] * vec_b[c];
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
            dst_vec[c] += mat_b[c * n + r] * vec_a[r];
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

/** returns det mat<2*2> matrix */
static int mati_determinant22(const int *matrix) {
    // from cglm/mat2.h/glm_mat2_det
    const int (*mat)[2] = (const int (*)[2]) matrix;
    return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

/** returns = det mat<3*3> matrix */
static int mati_determinant33(const int *matrix) {
    // from cglm/mat3.h/glm_mat3_det
    const int (*mat)[3] = (const int (*)[3]) matrix;
    int a = mat[0][0], b = mat[0][1], c = mat[0][2],
            d = mat[1][0], e = mat[1][1], f = mat[1][2],
            g = mat[2][0], h = mat[2][1], i = mat[2][2];

    return a * (e * i - h * f) - d * (b * i - c * h) + g * (b * f - c * e);
}

/** returns = det mat<4*4> matrix */
static int mati_determinant44(const int *matrix) {
    // from cglm/mat4.h/glm_mat4_det
    const int (*mat)[4] = (const int (*)[4]) matrix;
    /* [square] det(A) = det(At) */
    int t[6];
    int a = mat[0][0], b = mat[0][1], c = mat[0][2], d = mat[0][3],
            e = mat[1][0], f = mat[1][1], g = mat[1][2], h = mat[1][3],
            i = mat[2][0], j = mat[2][1], k = mat[2][2], l = mat[2][3],
            m = mat[3][0], n = mat[3][1], o = mat[3][2], p = mat[3][3];

    t[0] = k * p - o * l;
    t[1] = j * p - n * l;
    t[2] = j * o - n * k;
    t[3] = i * p - m * l;
    t[4] = i * o - m * k;
    t[5] = i * n - m * j;

    return a * (f * t[0] - g * t[1] + h * t[2])
           - b * (e * t[0] - g * t[3] + h * t[4])
           + c * (e * t[1] - f * t[3] + h * t[5])
           - d * (e * t[2] - f * t[4] + g * t[5]);
}

/** mat<2*2> dst = inv(mat<2*2> matrix)  (restrict data) */
static void mati_invert22_no_alias(int *restrict dst_mat, const int *restrict matrix) {
    // from cglm/mat2.h/glm_mat2_inv
    int (*dest)[2] = (int (*)[2]) dst_mat;
    const int (*mat)[2] = (const int (*)[2]) matrix;

    int det;
    int a = mat[0][0], b = mat[0][1],
            c = mat[1][0], d = mat[1][1];

    det = 1.0f / (a * d - b * c);

    dest[0][0] = d * det;
    dest[0][1] = -b * det;
    dest[1][0] = -c * det;
    dest[1][1] = a * det;
}

/** mat<3*3> dst = inv(mat<3*3> mat) */
static void mati_invert22(int *dst_mat, const int *mat) {
    int tmp[4];
    mati_invert22_no_alias(tmp, mat);
    for (int i = 0; i < 4; i++)
        dst_mat[i] = tmp[i];
}

/** mat<3*3> dst = inv(mat<3*3> matrix)  (restrict data) */
static void mati_invert33_no_alias(int *restrict dst_mat, const int *restrict matrix) {
    // from cglm/mat3.h/glm_mat3_inv
    int (*dest)[3] = (int (*)[3]) dst_mat;
    const int (*mat)[3] = (const int (*)[3]) matrix;

    int det;
    int a = mat[0][0], b = mat[0][1], c = mat[0][2],
            d = mat[1][0], e = mat[1][1], f = mat[1][2],
            g = mat[2][0], h = mat[2][1], i = mat[2][2];

    dest[0][0] = e * i - f * h;
    dest[0][1] = -(b * i - h * c);
    dest[0][2] = b * f - e * c;
    dest[1][0] = -(d * i - g * f);
    dest[1][1] = a * i - c * g;
    dest[1][2] = -(a * f - d * c);
    dest[2][0] = d * h - g * e;
    dest[2][1] = -(a * h - g * b);
    dest[2][2] = a * e - b * d;

    det = 1.0f / (a * dest[0][0] + b * dest[1][0] + c * dest[2][0]);

    for (int idx = 0; idx < 9; idx++)
        dst_mat[idx] *= det;
}

/** mat<3*3> dst = inv(mat<3*3> mat) */
static void mati_invert33(int *dst_mat, const int *mat) {
    int tmp[9];
    mati_invert33_no_alias(tmp, mat);
    for (int i = 0; i < 9; i++)
        dst_mat[i] = tmp[i];
}

/** mat<4*4> dst = inv(mat<4*4> matrix)  (restrict data) */
static void mati_invert44_no_alias(int *restrict dst_mat, const int *restrict matrix) {
    // from cglm/mat4.h/glm_mat4_inv
    int (*dest)[4] = (int (*)[4]) dst_mat;
    const int (*mat)[4] = (const int (*)[4]) matrix;

    int t[6];
    int det;
    int a = mat[0][0], b = mat[0][1], c = mat[0][2], d = mat[0][3],
            e = mat[1][0], f = mat[1][1], g = mat[1][2], h = mat[1][3],
            i = mat[2][0], j = mat[2][1], k = mat[2][2], l = mat[2][3],
            m = mat[3][0], n = mat[3][1], o = mat[3][2], p = mat[3][3];

    t[0] = k * p - o * l;
    t[1] = j * p - n * l;
    t[2] = j * o - n * k;
    t[3] = i * p - m * l;
    t[4] = i * o - m * k;
    t[5] = i * n - m * j;

    dest[0][0] = f * t[0] - g * t[1] + h * t[2];
    dest[1][0] = -(e * t[0] - g * t[3] + h * t[4]);
    dest[2][0] = e * t[1] - f * t[3] + h * t[5];
    dest[3][0] = -(e * t[2] - f * t[4] + g * t[5]);

    dest[0][1] = -(b * t[0] - c * t[1] + d * t[2]);
    dest[1][1] = a * t[0] - c * t[3] + d * t[4];
    dest[2][1] = -(a * t[1] - b * t[3] + d * t[5]);
    dest[3][1] = a * t[2] - b * t[4] + c * t[5];

    t[0] = g * p - o * h;
    t[1] = f * p - n * h;
    t[2] = f * o - n * g;
    t[3] = e * p - m * h;
    t[4] = e * o - m * g;
    t[5] = e * n - m * f;

    dest[0][2] = b * t[0] - c * t[1] + d * t[2];
    dest[1][2] = -(a * t[0] - c * t[3] + d * t[4]);
    dest[2][2] = a * t[1] - b * t[3] + d * t[5];
    dest[3][2] = -(a * t[2] - b * t[4] + c * t[5]);

    t[0] = g * l - k * h;
    t[1] = f * l - j * h;
    t[2] = f * k - j * g;
    t[3] = e * l - i * h;
    t[4] = e * k - i * g;
    t[5] = e * j - i * f;

    dest[0][3] = -(b * t[0] - c * t[1] + d * t[2]);
    dest[1][3] = a * t[0] - c * t[3] + d * t[4];
    dest[2][3] = -(a * t[1] - b * t[3] + d * t[5]);
    dest[3][3] = a * t[2] - b * t[4] + c * t[5];

    det = 1.0f / (a * dest[0][0] + b * dest[1][0]
                  + c * dest[2][0] + d * dest[3][0]);

    for (int idx = 0; idx < 9; idx++)
        dst_mat[idx] *= det;
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static void mati_invert44(int *dst_mat, const int *mat) {
    int tmp[16];
    mati_invert44_no_alias(tmp, mat);
    for (int i = 0; i < 16; i++)
        dst_mat[i] = tmp[i];
}



#endif //MATHC_MAT_FUNCTIONS_H
