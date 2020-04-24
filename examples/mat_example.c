#include <stdio.h>

#include "mathc/mat.h"



void print_mat(const char *msg, const float *mat, int n) {
    printf("%s", msg);
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++)
            printf("%f ", mat[r*n + c]);
        puts("");
    }
}

void print_mati(const char *msg, const int *mat, int n) {
    printf("%s", msg);
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++)
            printf("%d ", mat[r*n + c]);
        puts("");
    }
}

void print_vec(const char *msg, const float *vec, int n) {
    printf("%s", msg);
    for (int i = 0; i < n; i++)
        printf("%f ", vec[i]);
    puts("");
}

void print_veci(const char *msg, const int *vec, int n) {
    printf("%s", msg);
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    puts("");
}

void float_test() {
    float data_a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float data_b[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    float data_res[9];
    float data_vec[3];

    // save eye into data_res
    Mat33(data_res) = mat33f_eye();
    print_mat("eye:\n", data_res, 3);

    // calls mat33f_transpose and saves the result into data_res
    Mat33(data_res) = mat_transpose(Mat33(data_a));
    print_mat("transpose:\n", data_res, 3);

    // it is also possible to cast the float pointers into vec3f pointer:
    mat33f *a = (mat33f *) data_a;
    mat33f *b = (mat33f *) data_b;
    mat33f *res = (mat33f *) data_res;
    vec3f *vec = (vec3f *) data_vec;

    *res = mat_mul_mat(*res, *a);
    print_mat("mul_mat:\n", data_res, 3);

    *vec = mat_get_col(*b, 2);
    print_vec("col: ", data_vec, 3);

    *vec = mat_mul_vec(*a, *vec);
    print_vec("mul_vec: ", data_vec, 3);

    mat33f A = {{
                        {10, 0, 20},
                        {30, 30, 20},
                        {5, 6, 10}
    }};
    vec3f r = {{1, 2, 3}};

    vec3f x = mat_mul_vec(mat_invert(A), r);
    print_vec("solve: ", x.v, 3);


}

void int_test() {
    int data_a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int data_b[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int data_res[9];
    int data_vec[3];

    // save eye into data_res
    Mat33(data_res) = mat33i_eye();
    print_mati("eye:\n", data_res, 3);

    // calls mat33i_transpose and saves the result into data_res
    Mat33(data_res) = mat_transpose(Mat33(data_a));
    print_mati("transpose:\n", data_res, 3);

    // it is also possible to cast the int pointers into vec3i pointer:
    mat33i *a = (mat33i *) data_a;
    mat33i *b = (mat33i *) data_b;
    mat33i *res = (mat33i *) data_res;
    vec3i *vec = (vec3i *) data_vec;

    *res = mat_mul_mat(*res, *a);
    print_mati("mul_mat:\n", data_res, 3);

    *vec = mat_get_col(*b, 2);
    print_veci("col: ", data_vec, 3);

    *vec = mat_mul_vec(*a, *vec);
    print_veci("mul_vec: ", data_vec, 3);
}


int main() {
    float_test();
    int_test();
}
