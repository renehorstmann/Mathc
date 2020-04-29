#include <stdio.h>
#include <mathc/mathc.h>

void print_vec(const float *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%f ", vec[i]);
    puts("");
}

int main() {
    float a[3] = {1, 2, 3};
    float b[3] = {10, 20, 30};

    vec3f add = vec3_add_v(a, b);
    print_vec(add.v, 3);
}
