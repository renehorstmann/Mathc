#ifndef UTILC_MATMATH_H
#define UTILC_MATMATH_H

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

/** mat<n*n> dst = mat<n*n>^t (dst != mat) */
static void mat_transpose_no_alias(float *dst_mat, const float *mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = mat[c * n + r];
        }
    }
}

/** mat<n*n> dst = mat<n*n>^t */
static void mat_transpose(float *dst_mat, const float *mat, int n) {
    if (dst_mat == mat) {
        float tmp[n * n];
        mat_transpose_no_alias(tmp, mat, n);
        for (int i = 0; i < n * n; i++)
            dst_mat[i] = tmp[i];
    } else
        mat_transpose_no_alias(dst_mat, mat, n);
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b (dst != a && dst != b) */
static void mat_mul_mat_no_alias(float *dst_mat, const float *mat_a, const float *mat_b, int n) {
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
    if (dst_mat == mat_a || dst_mat == mat_b) {
        float tmp[n * n];
        mat_mul_mat_no_alias(tmp, mat_a, mat_b, n);
        for (int i = 0; i < n * n; i++)
            dst_mat[i] = tmp[i];
    } else
        mat_mul_mat_no_alias(dst_mat, mat_a, mat_b, n);
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void mat_mul_vec(float *dst_vec, const float *mat_a, const float *vec_b, int n) {
    for (int r = 0; r < n; r++) {
        dst_vec[r] = 0;
        for (int c = 0; c < n; c++) {
            dst_vec[r] += mat_a[r * n + c] * vec_b[c];
        }
    }
}

/** returns = det mat<3*3> mat33 */
static float mat_determinant33(const float *mat33) {
    return
            mat33[0 * 3 + 0] * mat33[1 * 3 + 1] * mat33[2 * 3 + 2] +
            mat33[0 * 3 + 1] * mat33[1 * 3 + 2] * mat33[2 * 3 + 0] +
            mat33[0 * 3 + 2] * mat33[1 * 3 + 0] * mat33[2 * 3 + 1] -
            mat33[0 * 3 + 0] * mat33[1 * 3 + 2] * mat33[2 * 3 + 1] -
            mat33[0 * 3 + 1] * mat33[1 * 3 + 0] * mat33[2 * 3 + 2] -
            mat33[0 * 3 + 2] * mat33[1 * 3 + 1] * mat33[2 * 3 + 0];
}

/** returns = det mat<4*4> mat44 */
static float mat_determinant44(const float *mat44) {
    return
            mat44[0 * 4 + 3] * mat44[1 * 4 + 2] * mat44[2 * 4 + 1] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 2] * mat44[1 * 4 + 3] * mat44[2 * 4 + 1] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 3] * mat44[1 * 4 + 1] * mat44[2 * 4 + 2] * mat44[3 * 4 + 0] +
            mat44[0 * 4 + 1] * mat44[1 * 4 + 3] * mat44[2 * 4 + 2] * mat44[3 * 4 + 0] +
            mat44[0 * 4 + 2] * mat44[1 * 4 + 1] * mat44[2 * 4 + 3] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 1] * mat44[1 * 4 + 2] * mat44[2 * 4 + 3] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 3] * mat44[1 * 4 + 2] * mat44[2 * 4 + 0] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 2] * mat44[1 * 4 + 3] * mat44[2 * 4 + 0] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 3] * mat44[1 * 4 + 0] * mat44[2 * 4 + 2] * mat44[3 * 4 + 1] -
            mat44[0 * 4 + 0] * mat44[1 * 4 + 3] * mat44[2 * 4 + 2] * mat44[3 * 4 + 1] -
            mat44[0 * 4 + 2] * mat44[1 * 4 + 0] * mat44[2 * 4 + 3] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 0] * mat44[1 * 4 + 2] * mat44[2 * 4 + 3] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 3] * mat44[1 * 4 + 1] * mat44[2 * 4 + 0] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 1] * mat44[1 * 4 + 3] * mat44[2 * 4 + 0] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 3] * mat44[1 * 4 + 0] * mat44[2 * 4 + 1] * mat44[3 * 4 + 2] +
            mat44[0 * 4 + 0] * mat44[1 * 4 + 3] * mat44[2 * 4 + 1] * mat44[3 * 4 + 2] +
            mat44[0 * 4 + 1] * mat44[1 * 4 + 0] * mat44[2 * 4 + 3] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 0] * mat44[1 * 4 + 1] * mat44[2 * 4 + 3] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 2] * mat44[1 * 4 + 1] * mat44[2 * 4 + 0] * mat44[3 * 4 + 3] +
            mat44[0 * 4 + 1] * mat44[1 * 4 + 2] * mat44[2 * 4 + 0] * mat44[3 * 4 + 3] +
            mat44[0 * 4 + 2] * mat44[1 * 4 + 0] * mat44[2 * 4 + 1] * mat44[3 * 4 + 3] -
            mat44[0 * 4 + 0] * mat44[1 * 4 + 2] * mat44[2 * 4 + 1] * mat44[3 * 4 + 3] -
            mat44[0 * 4 + 1] * mat44[1 * 4 + 0] * mat44[2 * 4 + 2] * mat44[3 * 4 + 3] +
            mat44[0 * 4 + 0] * mat44[1 * 4 + 1] * mat44[2 * 4 + 2] * mat44[3 * 4 + 3];
}

/** mat<3*3> dst = inv(mat<3*3> mat33) (dst != mat33) */
static void mat_invert33_no_alias(float *dst_mat33, const float *mat33) {
    float idet = 1.0f / mat_determinant33(mat33);
    dst_mat33[0 * 3 + 0] = (mat33[1 * 3 + 1] * mat33[2 * 3 + 2] - mat33[1 * 3 + 2] * mat33[2 * 3 + 1]) * idet;
    dst_mat33[0 * 3 + 1] = (mat33[0 * 3 + 2] * mat33[2 * 3 + 1] - mat33[0 * 3 + 1] * mat33[2 * 3 + 2]) * idet;
    dst_mat33[0 * 3 + 2] = (mat33[0 * 3 + 1] * mat33[1 * 3 + 2] - mat33[0 * 3 + 2] * mat33[1 * 3 + 1]) * idet;
    dst_mat33[1 * 3 + 0] = (mat33[1 * 3 + 2] * mat33[2 * 3 + 0] - mat33[1 * 3 + 0] * mat33[2 * 3 + 2]) * idet;
    dst_mat33[1 * 3 + 1] = (mat33[0 * 3 + 0] * mat33[2 * 3 + 2] - mat33[0 * 3 + 2] * mat33[2 * 3 + 0]) * idet;
    dst_mat33[1 * 3 + 2] = (mat33[0 * 3 + 2] * mat33[1 * 3 + 0] - mat33[0 * 3 + 0] * mat33[1 * 3 + 2]) * idet;
    dst_mat33[2 * 3 + 0] = (mat33[1 * 3 + 0] * mat33[2 * 3 + 1] - mat33[1 * 3 + 1] * mat33[2 * 3 + 0]) * idet;
    dst_mat33[2 * 3 + 1] = (mat33[0 * 3 + 1] * mat33[2 * 3 + 0] - mat33[0 * 3 + 0] * mat33[2 * 3 + 1]) * idet;
    dst_mat33[2 * 3 + 2] = (mat33[0 * 3 + 0] * mat33[1 * 3 + 1] - mat33[0 * 3 + 1] * mat33[1 * 3 + 0]) * idet;
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static void mat_invert33(float *dst_mat33, const float *mat33) {
    if (dst_mat33 == mat33) {
        float tmp[9];
        mat_invert33_no_alias(tmp, mat33);
        for (int i = 0; i < 9; i++)
            dst_mat33[i] = tmp[i];
    } else
        mat_invert33_no_alias(dst_mat33, mat33);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) (dst != mat44) */
static void mat_invert44_no_alias(float *dst_mat44, const float *mat44) {
    // algorithm from https://github.com/datenwolf/linmath.h/blob/master/linmath.h
    float s[6];
    float c[6];
    s[0] = mat44[0 * 4 + 0] * mat44[1 * 4 + 1] - mat44[1 * 4 + 0] * mat44[0 * 4 + 1];
    s[1] = mat44[0 * 4 + 0] * mat44[1 * 4 + 2] - mat44[1 * 4 + 0] * mat44[0 * 4 + 2];
    s[2] = mat44[0 * 4 + 0] * mat44[1 * 4 + 3] - mat44[1 * 4 + 0] * mat44[0 * 4 + 3];
    s[3] = mat44[0 * 4 + 1] * mat44[1 * 4 + 2] - mat44[1 * 4 + 1] * mat44[0 * 4 + 2];
    s[4] = mat44[0 * 4 + 1] * mat44[1 * 4 + 3] - mat44[1 * 4 + 1] * mat44[0 * 4 + 3];
    s[5] = mat44[0 * 4 + 2] * mat44[1 * 4 + 3] - mat44[1 * 4 + 2] * mat44[0 * 4 + 3];

    c[0] = mat44[2 * 4 + 0] * mat44[3 * 4 + 1] - mat44[3 * 4 + 0] * mat44[2 * 4 + 1];
    c[1] = mat44[2 * 4 + 0] * mat44[3 * 4 + 2] - mat44[3 * 4 + 0] * mat44[2 * 4 + 2];
    c[2] = mat44[2 * 4 + 0] * mat44[3 * 4 + 3] - mat44[3 * 4 + 0] * mat44[2 * 4 + 3];
    c[3] = mat44[2 * 4 + 1] * mat44[3 * 4 + 2] - mat44[3 * 4 + 1] * mat44[2 * 4 + 2];
    c[4] = mat44[2 * 4 + 1] * mat44[3 * 4 + 3] - mat44[3 * 4 + 1] * mat44[2 * 4 + 3];
    c[5] = mat44[2 * 4 + 2] * mat44[3 * 4 + 3] - mat44[3 * 4 + 2] * mat44[2 * 4 + 3];

    /* Assumes it is invertible */
    float idet = 1.0f / (s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0]);

    dst_mat44[0 * 4 + 0] = (mat44[1 * 4 + 1] * c[5] - mat44[1 * 4 + 2] * c[4] + mat44[1 * 4 + 3] * c[3]) * idet;
    dst_mat44[0 * 4 + 1] = (-mat44[0 * 4 + 1] * c[5] + mat44[0 * 4 + 2] * c[4] - mat44[0 * 4 + 3] * c[3]) * idet;
    dst_mat44[0 * 4 + 2] = (mat44[3 * 4 + 1] * s[5] - mat44[3 * 4 + 2] * s[4] + mat44[3 * 4 + 3] * s[3]) * idet;
    dst_mat44[0 * 4 + 3] = (-mat44[2 * 4 + 1] * s[5] + mat44[2 * 4 + 2] * s[4] - mat44[2 * 4 + 3] * s[3]) * idet;

    dst_mat44[1 * 4 + 0] = (-mat44[1 * 4 + 0] * c[5] + mat44[1 * 4 + 2] * c[2] - mat44[1 * 4 + 3] * c[1]) * idet;
    dst_mat44[1 * 4 + 1] = (mat44[0 * 4 + 0] * c[5] - mat44[0 * 4 + 2] * c[2] + mat44[0 * 4 + 3] * c[1]) * idet;
    dst_mat44[1 * 4 + 2] = (-mat44[3 * 4 + 0] * s[5] + mat44[3 * 4 + 2] * s[2] - mat44[3 * 4 + 3] * s[1]) * idet;
    dst_mat44[1 * 4 + 3] = (mat44[2 * 4 + 0] * s[5] - mat44[2 * 4 + 2] * s[2] + mat44[2 * 4 + 3] * s[1]) * idet;

    dst_mat44[2 * 4 + 0] = (mat44[1 * 4 + 0] * c[4] - mat44[1 * 4 + 1] * c[2] + mat44[1 * 4 + 3] * c[0]) * idet;
    dst_mat44[2 * 4 + 1] = (-mat44[0 * 4 + 0] * c[4] + mat44[0 * 4 + 1] * c[2] - mat44[0 * 4 + 3] * c[0]) * idet;
    dst_mat44[2 * 4 + 2] = (mat44[3 * 4 + 0] * s[4] - mat44[3 * 4 + 1] * s[2] + mat44[3 * 4 + 3] * s[0]) * idet;
    dst_mat44[2 * 4 + 3] = (-mat44[2 * 4 + 0] * s[4] + mat44[2 * 4 + 1] * s[2] - mat44[2 * 4 + 3] * s[0]) * idet;

    dst_mat44[3 * 4 + 0] = (-mat44[1 * 4 + 0] * c[3] + mat44[1 * 4 + 1] * c[1] - mat44[1 * 4 + 2] * c[0]) * idet;
    dst_mat44[3 * 4 + 1] = (mat44[0 * 4 + 0] * c[3] - mat44[0 * 4 + 1] * c[1] + mat44[0 * 4 + 2] * c[0]) * idet;
    dst_mat44[3 * 4 + 2] = (-mat44[3 * 4 + 0] * s[3] + mat44[3 * 4 + 1] * s[1] - mat44[3 * 4 + 2] * s[0]) * idet;
    dst_mat44[3 * 4 + 3] = (mat44[2 * 4 + 0] * s[3] - mat44[2 * 4 + 1] * s[1] + mat44[2 * 4 + 2] * s[0]) * idet;
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static void mat_invert44(float *dst_mat44, const float *mat44) {
    if (dst_mat44 == mat44) {
        float tmp[16];
        mat_invert44_no_alias(tmp, mat44);
        for (int i = 0; i < 16; i++)
            dst_mat44[i] = tmp[i];
    } else
        mat_invert44_no_alias(dst_mat44, mat44);
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

/** mat<n*n> dst = mat<n*n>^t (dst != mat) */
static void matd_transpose_no_alias(double *dst_mat, const double *mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_mat[r * n + c] = mat[c * n + r];
        }
    }
}

/** mat<n*n> dst = mat<n*n>^t */
static void matd_transpose(double *dst_mat, const double *mat, int n) {
    if (dst_mat == mat) {
        double tmp[n * n];
        matd_transpose_no_alias(tmp, mat, n);
        for (int i = 0; i < n * n; i++)
            dst_mat[i] = tmp[i];
    } else
        matd_transpose_no_alias(dst_mat, mat, n);
}

/** mat<n*n> dst = mat<n*n> a * mat<n*n> b (dst != a && dst != b) */
static void matd_mul_mat_no_alias(double *dst_mat, const double *mat_a, const double *mat_b, int n) {
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
    if (dst_mat == mat_a || dst_mat == mat_b) {
        double tmp[n * n];
        matd_mul_mat_no_alias(tmp, mat_a, mat_b, n);
        for (int i = 0; i < n * n; i++)
            dst_mat[i] = tmp[i];
    } else
        matd_mul_mat_no_alias(dst_mat, mat_a, mat_b, n);
}

/** vec<n> dst = mat<n*n> a * vec<n> b */
static void matd_mul_vec(double *dst_vec, const double *mat_a, const double *vec_b, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            dst_vec[r] = 0;
            for (int i = 0; i < n; i++)
                dst_vec[r] += mat_a[r * n + c] * vec_b[c];
        }
    }
}

/** returns = det mat<3*3> mat33 */
static double matd_determinant33(const double *mat33) {
    return
            mat33[0 * 3 + 0] * mat33[1 * 3 + 1] * mat33[2 * 3 + 2] +
            mat33[0 * 3 + 1] * mat33[1 * 3 + 2] * mat33[2 * 3 + 0] +
            mat33[0 * 3 + 2] * mat33[1 * 3 + 0] * mat33[2 * 3 + 1] -
            mat33[0 * 3 + 0] * mat33[1 * 3 + 2] * mat33[2 * 3 + 1] -
            mat33[0 * 3 + 1] * mat33[1 * 3 + 0] * mat33[2 * 3 + 2] -
            mat33[0 * 3 + 2] * mat33[1 * 3 + 1] * mat33[2 * 3 + 0];
}

/** returns = det mat<4*4> mat44 */
static double matd_determinant44(const double *mat44) {
    return
            mat44[0 * 4 + 3] * mat44[1 * 4 + 2] * mat44[2 * 4 + 1] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 2] * mat44[1 * 4 + 3] * mat44[2 * 4 + 1] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 3] * mat44[1 * 4 + 1] * mat44[2 * 4 + 2] * mat44[3 * 4 + 0] +
            mat44[0 * 4 + 1] * mat44[1 * 4 + 3] * mat44[2 * 4 + 2] * mat44[3 * 4 + 0] +
            mat44[0 * 4 + 2] * mat44[1 * 4 + 1] * mat44[2 * 4 + 3] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 1] * mat44[1 * 4 + 2] * mat44[2 * 4 + 3] * mat44[3 * 4 + 0] -
            mat44[0 * 4 + 3] * mat44[1 * 4 + 2] * mat44[2 * 4 + 0] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 2] * mat44[1 * 4 + 3] * mat44[2 * 4 + 0] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 3] * mat44[1 * 4 + 0] * mat44[2 * 4 + 2] * mat44[3 * 4 + 1] -
            mat44[0 * 4 + 0] * mat44[1 * 4 + 3] * mat44[2 * 4 + 2] * mat44[3 * 4 + 1] -
            mat44[0 * 4 + 2] * mat44[1 * 4 + 0] * mat44[2 * 4 + 3] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 0] * mat44[1 * 4 + 2] * mat44[2 * 4 + 3] * mat44[3 * 4 + 1] +
            mat44[0 * 4 + 3] * mat44[1 * 4 + 1] * mat44[2 * 4 + 0] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 1] * mat44[1 * 4 + 3] * mat44[2 * 4 + 0] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 3] * mat44[1 * 4 + 0] * mat44[2 * 4 + 1] * mat44[3 * 4 + 2] +
            mat44[0 * 4 + 0] * mat44[1 * 4 + 3] * mat44[2 * 4 + 1] * mat44[3 * 4 + 2] +
            mat44[0 * 4 + 1] * mat44[1 * 4 + 0] * mat44[2 * 4 + 3] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 0] * mat44[1 * 4 + 1] * mat44[2 * 4 + 3] * mat44[3 * 4 + 2] -
            mat44[0 * 4 + 2] * mat44[1 * 4 + 1] * mat44[2 * 4 + 0] * mat44[3 * 4 + 3] +
            mat44[0 * 4 + 1] * mat44[1 * 4 + 2] * mat44[2 * 4 + 0] * mat44[3 * 4 + 3] +
            mat44[0 * 4 + 2] * mat44[1 * 4 + 0] * mat44[2 * 4 + 1] * mat44[3 * 4 + 3] -
            mat44[0 * 4 + 0] * mat44[1 * 4 + 2] * mat44[2 * 4 + 1] * mat44[3 * 4 + 3] -
            mat44[0 * 4 + 1] * mat44[1 * 4 + 0] * mat44[2 * 4 + 2] * mat44[3 * 4 + 3] +
            mat44[0 * 4 + 0] * mat44[1 * 4 + 1] * mat44[2 * 4 + 2] * mat44[3 * 4 + 3];
}

/** mat<3*3> dst = inv(mat<3*3> mat33) (dst != mat33) */
static void matd_invert33_no_alias(double *dst_mat33, const double *mat33) {
    double idet = 1.0 / matd_determinant33(mat33);
    dst_mat33[0 * 3 + 0] = (mat33[1 * 3 + 1] * mat33[2 * 3 + 2] - mat33[1 * 3 + 2] * mat33[2 * 3 + 1]) * idet;
    dst_mat33[0 * 3 + 1] = (mat33[0 * 3 + 2] * mat33[2 * 3 + 1] - mat33[0 * 3 + 1] * mat33[2 * 3 + 2]) * idet;
    dst_mat33[0 * 3 + 2] = (mat33[0 * 3 + 1] * mat33[1 * 3 + 2] - mat33[0 * 3 + 2] * mat33[1 * 3 + 1]) * idet;
    dst_mat33[1 * 3 + 0] = (mat33[1 * 3 + 2] * mat33[2 * 3 + 0] - mat33[1 * 3 + 0] * mat33[2 * 3 + 2]) * idet;
    dst_mat33[1 * 3 + 1] = (mat33[0 * 3 + 0] * mat33[2 * 3 + 2] - mat33[0 * 3 + 2] * mat33[2 * 3 + 0]) * idet;
    dst_mat33[1 * 3 + 2] = (mat33[0 * 3 + 2] * mat33[1 * 3 + 0] - mat33[0 * 3 + 0] * mat33[1 * 3 + 2]) * idet;
    dst_mat33[2 * 3 + 0] = (mat33[1 * 3 + 0] * mat33[2 * 3 + 1] - mat33[1 * 3 + 1] * mat33[2 * 3 + 0]) * idet;
    dst_mat33[2 * 3 + 1] = (mat33[0 * 3 + 1] * mat33[2 * 3 + 0] - mat33[0 * 3 + 0] * mat33[2 * 3 + 1]) * idet;
    dst_mat33[2 * 3 + 2] = (mat33[0 * 3 + 0] * mat33[1 * 3 + 1] - mat33[0 * 3 + 1] * mat33[1 * 3 + 0]) * idet;
}

/** mat<3*3> dst = inv(mat<3*3> mat33) */
static void matd_invert33(double *dst_mat33, const double *mat33) {
    if (dst_mat33 == mat33) {
        double tmp[9];
        matd_invert33_no_alias(tmp, mat33);
        for (int i = 0; i < 9; i++)
            dst_mat33[i] = tmp[i];
    } else
        matd_invert33_no_alias(dst_mat33, mat33);
}

/** mat<4*4> dst = inv(mat<4*4> mat44) (dst != mat44) */
static void matd_invert44_no_alias(double *dst_mat44, const double *mat44) {
    // algorithm from https://github.com/datenwolf/linmath.h/blob/master/linmath.h
    double s[6];
    double c[6];
    s[0] = mat44[0 * 4 + 0] * mat44[1 * 4 + 1] - mat44[1 * 4 + 0] * mat44[0 * 4 + 1];
    s[1] = mat44[0 * 4 + 0] * mat44[1 * 4 + 2] - mat44[1 * 4 + 0] * mat44[0 * 4 + 2];
    s[2] = mat44[0 * 4 + 0] * mat44[1 * 4 + 3] - mat44[1 * 4 + 0] * mat44[0 * 4 + 3];
    s[3] = mat44[0 * 4 + 1] * mat44[1 * 4 + 2] - mat44[1 * 4 + 1] * mat44[0 * 4 + 2];
    s[4] = mat44[0 * 4 + 1] * mat44[1 * 4 + 3] - mat44[1 * 4 + 1] * mat44[0 * 4 + 3];
    s[5] = mat44[0 * 4 + 2] * mat44[1 * 4 + 3] - mat44[1 * 4 + 2] * mat44[0 * 4 + 3];

    c[0] = mat44[2 * 4 + 0] * mat44[3 * 4 + 1] - mat44[3 * 4 + 0] * mat44[2 * 4 + 1];
    c[1] = mat44[2 * 4 + 0] * mat44[3 * 4 + 2] - mat44[3 * 4 + 0] * mat44[2 * 4 + 2];
    c[2] = mat44[2 * 4 + 0] * mat44[3 * 4 + 3] - mat44[3 * 4 + 0] * mat44[2 * 4 + 3];
    c[3] = mat44[2 * 4 + 1] * mat44[3 * 4 + 2] - mat44[3 * 4 + 1] * mat44[2 * 4 + 2];
    c[4] = mat44[2 * 4 + 1] * mat44[3 * 4 + 3] - mat44[3 * 4 + 1] * mat44[2 * 4 + 3];
    c[5] = mat44[2 * 4 + 2] * mat44[3 * 4 + 3] - mat44[3 * 4 + 2] * mat44[2 * 4 + 3];

    /* Assumes it is invertible */
    double idet = 1.0f / (s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0]);

    dst_mat44[0 * 4 + 0] = (mat44[1 * 4 + 1] * c[5] - mat44[1 * 4 + 2] * c[4] + mat44[1 * 4 + 3] * c[3]) * idet;
    dst_mat44[0 * 4 + 1] = (-mat44[0 * 4 + 1] * c[5] + mat44[0 * 4 + 2] * c[4] - mat44[0 * 4 + 3] * c[3]) * idet;
    dst_mat44[0 * 4 + 2] = (mat44[3 * 4 + 1] * s[5] - mat44[3 * 4 + 2] * s[4] + mat44[3 * 4 + 3] * s[3]) * idet;
    dst_mat44[0 * 4 + 3] = (-mat44[2 * 4 + 1] * s[5] + mat44[2 * 4 + 2] * s[4] - mat44[2 * 4 + 3] * s[3]) * idet;

    dst_mat44[1 * 4 + 0] = (-mat44[1 * 4 + 0] * c[5] + mat44[1 * 4 + 2] * c[2] - mat44[1 * 4 + 3] * c[1]) * idet;
    dst_mat44[1 * 4 + 1] = (mat44[0 * 4 + 0] * c[5] - mat44[0 * 4 + 2] * c[2] + mat44[0 * 4 + 3] * c[1]) * idet;
    dst_mat44[1 * 4 + 2] = (-mat44[3 * 4 + 0] * s[5] + mat44[3 * 4 + 2] * s[2] - mat44[3 * 4 + 3] * s[1]) * idet;
    dst_mat44[1 * 4 + 3] = (mat44[2 * 4 + 0] * s[5] - mat44[2 * 4 + 2] * s[2] + mat44[2 * 4 + 3] * s[1]) * idet;

    dst_mat44[2 * 4 + 0] = (mat44[1 * 4 + 0] * c[4] - mat44[1 * 4 + 1] * c[2] + mat44[1 * 4 + 3] * c[0]) * idet;
    dst_mat44[2 * 4 + 1] = (-mat44[0 * 4 + 0] * c[4] + mat44[0 * 4 + 1] * c[2] - mat44[0 * 4 + 3] * c[0]) * idet;
    dst_mat44[2 * 4 + 2] = (mat44[3 * 4 + 0] * s[4] - mat44[3 * 4 + 1] * s[2] + mat44[3 * 4 + 3] * s[0]) * idet;
    dst_mat44[2 * 4 + 3] = (-mat44[2 * 4 + 0] * s[4] + mat44[2 * 4 + 1] * s[2] - mat44[2 * 4 + 3] * s[0]) * idet;

    dst_mat44[3 * 4 + 0] = (-mat44[1 * 4 + 0] * c[3] + mat44[1 * 4 + 1] * c[1] - mat44[1 * 4 + 2] * c[0]) * idet;
    dst_mat44[3 * 4 + 1] = (mat44[0 * 4 + 0] * c[3] - mat44[0 * 4 + 1] * c[1] + mat44[0 * 4 + 2] * c[0]) * idet;
    dst_mat44[3 * 4 + 2] = (-mat44[3 * 4 + 0] * s[3] + mat44[3 * 4 + 1] * s[1] - mat44[3 * 4 + 2] * s[0]) * idet;
    dst_mat44[3 * 4 + 3] = (mat44[2 * 4 + 0] * s[3] - mat44[2 * 4 + 1] * s[1] + mat44[2 * 4 + 2] * s[0]) * idet;
}

/** mat<4*4> dst = inv(mat<4*4> mat44) */
static void matd_invert44(double *dst_mat44, const double *mat44) {
    if (dst_mat44 == mat44) {
        double tmp[16];
        matd_invert44_no_alias(tmp, mat44);
        for (int i = 0; i < 16; i++)
            dst_mat44[i] = tmp[i];
    } else
        matd_invert44_no_alias(dst_mat44, mat44);
}



//
// 2. specific size functions
//

//
// Mat33
//
typedef struct {
    float m[9];
} Mat33;

/** Mat33 = r==c ? 1 : 0 (identity) */
static Mat33 mat33_eye() {
    Mat33 res;
    mat_eye(res.m, 3);
    return res;
}

/** Mat33 = mat<3*3>^t */
static Mat33 mat33_transpose(const float *mat) {
    Mat33 res;
    mat_transpose_no_alias(res.m, mat, 3);
    return res;
}

/** Mat33 = mat<3*3> a * mat<3*3> b */
static Mat33 mat33_mul_mat(const float *mat_a, const float *mat_b) {
    Mat33 res;
    mat_mul_mat_no_alias(res.m, mat_a, mat_b, 3);
    return res;
}

/** Mat33 = inv(mat<3*3> mat33) */
static Mat33 mat33_invert(const float *mat33) {
    Mat33 res;
    mat_invert33_no_alias(res.m, mat33);
    return res;
}


//
// Mat33d
//
typedef struct {
    double m[9];
} Mat33d;

/** Mat33 = r==c ? 1 : 0 (identity) */
static Mat33d mat33d_eye() {
    Mat33d res;
    matd_eye(res.m, 3);
    return res;
}

/** Mat33 = mat<3*3>^t */
static Mat33d mat33d_transpose(const double *mat) {
    Mat33d res;
    matd_transpose_no_alias(res.m, mat, 3);
    return res;
}

/** Mat33 = mat<3*3> a * mat<3*3> b */
static Mat33d mat33d_mul_mat(const double *mat_a, const double *mat_b) {
    Mat33d res;
    matd_mul_mat_no_alias(res.m, mat_a, mat_b, 3);
    return res;
}

/** Mat33 = inv(mat<3*3> mat33) */
static Mat33d mat33d_invert(const double *mat33) {
    Mat33d res;
    matd_invert33_no_alias(res.m, mat33);
    return res;
}



//
// Mat44
//
typedef struct {
    float m[16];
} Mat44;

/** Mat44 = r==c ? 1 : 0 (identity) */
static Mat44 mat44_eye() {
    Mat44 res;
    mat_eye(res.m, 4);
    return res;
}

/** Mat44 = mat<4*4>^t */
static Mat44 mat44_transpose(const float *mat) {
    Mat44 res;
    mat_transpose_no_alias(res.m, mat, 4);
    return res;
}

/** Mat44 = mat<4*4> a * mat<4*4> b */
static Mat44 mat44_mul_mat(const float *mat_a, const float *mat_b) {
    Mat44 res;
    mat_mul_mat_no_alias(res.m, mat_a, mat_b, 4);
    return res;
}

/** Mat44 = inv(mat<4*4> mat44) */
static Mat44 mat44_invert(const float *mat44) {
    Mat44 res;
    mat_invert44_no_alias(res.m, mat44);
    return res;
}



//
// Mat44d
//
typedef struct {
    double m[16];
} Mat44d;

/** Mat44 = r==c ? 1 : 0 (identity) */
static Mat44d mat44d_eye() {
    Mat44d res;
    matd_eye(res.m, 4);
    return res;
}

/** Mat44 = mat<4*4>^t */
static Mat44d mat44d_transpose(const double *mat) {
    Mat44d res;
    matd_transpose_no_alias(res.m, mat, 4);
    return res;
}

/** Mat44 = mat<4*4> a * mat<4*4> b */
static Mat44d mat44d_mul_mat(const double *mat_a, const double *mat_b) {
    Mat44d res;
    matd_mul_mat_no_alias(res.m, mat_a, mat_b, 4);
    return res;
}

/** Mat44 = inv(mat<4*4> mat44) */
static Mat44d mat44d_invert(const double *mat44) {
    Mat44d res;
    matd_invert44_no_alias(res.m, mat44);
    return res;
}


#endif //UTILC_MATMATH_H
