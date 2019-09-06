#include <stdio.h>

#include "mathc/matmath.h"

void print_vec(float *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%f ", vec[i]);
    puts("");
}

void print_mat(float *mat, int n) {
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++)
            printf("%f ", mat[r*n+c]);

        puts("");
    }
}


int main() {
    float mat_as_cmat[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    float *a = (float *) mat_as_cmat;

    float b[9];
    mat_eye(b, 3);
    mat_row_set(b, 10, 2, 3);

    print_mat(b, 3);
    // 1.000000 0.000000 0.000000
    // 0.000000 1.000000 0.000000
    // 10.000000 10.000000 10.000000

    float det = mat_determinant33(b);
    printf("%f\n", det);
    // 10.000000

    mat_invert33(b, b);
    print_mat(b, 3);
    // 1.000000 0.000000 0.000000
    // 0.000000 1.000000 0.000000
    // -1.000000 -1.000000 0.100000

    mat_mul_mat(a, a, b, 3);
    print_mat(a, 3);
    // -2.000000 -1.000000 0.300000
    // -2.000000 -1.000000 0.600000
    // -2.000000 -1.000000 0.900000

    Mat44 mat = mat44_eye();
    mat_col_set(mat.m, -1, 1, 4);
    mat.m[3] = 3;

    Mat44 inv = mat44_invert(mat.m);
    print_mat(inv.m, 4);
    // 1.000000 2.000000 -0.000000 -3.000000
    // -0.000000 -1.000000 -0.000000 -0.000000
    // -0.000000 -1.000000 1.000000 -0.000000
    // 0.000000 -1.000000 -0.000000 1.000000

    float col[4];
    mat_col(col, inv.m, 1, 4);
    print_vec(col, 4);
    // 2.000000 -1.000000 -1.000000 -1.000000

    float vec[4];
    mat_mul_vec(vec, inv.m, col, 4);
    print_vec(vec, 4);
    // 3.000000 1.000000 0.000000 0.000000
}
