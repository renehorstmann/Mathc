#include <stdio.h>

#include "mathc/vec.h"

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
    float data_a[3] = {1, 2, 3};
    float data_b[3] = {10, 20, 30};

    float data_res[3];

    vec3f *a = (vec3f *) data_a;
    vec3f *b = (vec3f *) data_b;
    vec3f *res = (vec3f *) data_res;

    *res = vec_add(*a, *b);

    print_vec(data_res, 3);
}



int main() {
    float_test();
}
