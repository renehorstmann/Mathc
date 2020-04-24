#include <stdio.h>

#include "mathc/mat.h"



void print_mat(const float *mat, int n) {
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++)
            printf("%f ", mat[r*n + c]);
        puts("");
    }
}

void print_mati(const int *mat, int n) {
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++)
            printf("%d ", mat[r*n + c]);
        puts("");
    }
}

void print_vec(const float *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%f ", vec[i]);
    puts("");
}

void print_veci(const int *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    puts("");
}

void float_test() {
    mat33f eye = mat33f_eye();
    print_mat(eye.m[0], 3);
    eye.m[1][0] = 20;

    vec3f row = mat_get_col(eye, 0);
    print_vec(row.v, 3);
}


int main() {
    float_test();
}
