#include <stdio.h>

#include "mathc/vecmath.h"

void print_vec(float *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%f ", vec[i]);
    puts("");
}

void print_veci(int *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    puts("");
}


int main() {

    float a[] = {1, 2, 3};
    float b[] = {10, 20, 30};
    float x[] = {1, 0, 0};
    float y[] = {0, 1, 0};

    float res[3];

    VecAddVec(res, a, b, 3)
    print_vec(res, 3);
    // 11.000000 22.000000 33.000000

    VecSubVec(res, b, a, 3)
    print_vec(res, 3);
    // 9.000000 18.000000 27.000000

    vec_cross(res, x, y, 3);
    print_vec(res, 3);
    // 0.000000 0.000000 1.000000

    float dot = vec_dot(a, b, 3);
    printf("%f\n", dot);
    // 140.000000

    float norm = vec_norm(b, 3);
    printf("%f\n", norm);
    // 37.416573

    vec_normalize(res, b, 3);
    print_vec(res, 3);
    // 0.267261 0.534522 0.801784

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ires[10];
    VecScaleVec(ires, ia, ia, 10)
    print_veci(ires, 10);
    // 0 1 4 9 16 25 36 49 64 81

    vec3 vec = vec3_copy(b);
    print_vec(vec.v, 3);
    // 10.000000 20.000000 30.000000

    vec = vec3_normalize(vec.v);
    print_vec(vec.v, 3);
    // 0.267261 0.534522 0.801784

    norm = vec_norm(vec3_scale_sca(vec3_add_sca((float[]) {100, 50, 1}, -1).v, 0.1f).v, 3);
    printf("%f\n", norm);
    // 11.046267
}
