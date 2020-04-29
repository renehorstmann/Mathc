#include <stdio.h>
#include "mathc/vec.h"

int main() {

    // vector float base functions that are sizeless
    float vec_a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float res[10];
    vecf_scale_vec(res, vec_a, vec_a, 10);
    float norm = vecf_norm(res, 10);
    printf("%f\n", norm);

    // double typed with generic macros (vec_add also works for vec3f, vec4i, ...)
    vec3d vec_b = {{-1.23, -2.34, -3.45}};
    vec_b = vec_add(vec_b, 10);
    double sum = vec_sum(vec_b);
    printf("%f\n", sum);

    // with the Vec macros, raw pointers can be casted to the given type.
    // the typed_v functions allow the use of raw pointers as parameters.
    int vec_c[3] = {100, 200, 300};
    Vec3i(vec_c) = vec_add(Vec3i(vec_c), 5);
    int sum_c = vec3_sum_v(vec_c);
    printf("%d\n", sum_c);

    // output:
    // 123.826492
    // 22.980000
    // 615
}
