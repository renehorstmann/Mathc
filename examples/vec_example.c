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



int main() {

    int data[3] = {1, 2, 3};

//    Vec3(data).v[0] = 10;
    print_veci(data, 3);

    double norm = vec3i_norm(Vec3(data));
    printf("norm: %f\n", norm);

    Vec3(data) = vec_neg(ConstVec3i(data));
    print_veci(data, 3);

}
