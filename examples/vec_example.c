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

    const float *a_view = data_a;
    vec3f neg = vec3_neg_v(a_view);
    print_vec(neg.v, 3);

    // calls vec3f_add_sca and saves the result into data_res
    Vec3f(data_res) = vec_add(Vec3f(data_a), 10);
    print_vec(data_res, 3);

    // it is also possible to cast the float pointers into vec3f pointer:
    vec3f *a = (vec3f *) data_a;
    vec3f *b = (vec3f *) data_b;
    vec3f *res = (vec3f *) data_res;

    // in this case, the vec3f pointers needs to be dereferenced:
    // calls vec3f_add_vec
    *res = vec_add(*a, *b);
    print_vec(data_res, 3);

    float norm = vec_norm(*res);
    printf("%f\n", norm);

    float dot = vec_dot(*a, *b);
    printf("%f\n", dot);
}

void int_test() {
    // the same is working for ints (and doubles and vec4s...)
    int data_a[3] = {1, 2, 3};
    int data_b[3] = {10, 20, 30};

    int data_res[3];

    // calls vec3i_add_sca
    Vec3i(data_res) = vec_add(Vec3i(data_a), 10);
    print_veci(data_res, 3);

    vec3i *a = (vec3i *) data_a;
    vec3i *b = (vec3i *) data_b;
    vec3i *res = (vec3i *) data_res;

    // calls vec3i_add_vec
    *res = vec_add(*a, *b);
    print_veci(data_res, 3);

    float norm = vec_norm(*res);
    printf("%f\n", norm);

    int dot = vec_dot(*a, *b);
    printf("%d\n", dot);
}


int main() {
    float_test();
    int_test();
}
