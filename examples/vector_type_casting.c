#include "mathc/mathc.h"

// use the types from raw pointers
void foo1(float *result3, const float *vector3) {
    // tmp = vector3 * 1000
    // Vec3() casts a raw pointer into a vec3
    vec3 tmp = vec3_scale(Vec3(vector3), 1000);

    // tmp = tmp + 50
    tmp = vec3_add(tmp, 50);

    // cast result3 into a vec3 and copy tmp into it
    Vec3(result3) = tmp;
}

// like foo1, but without tmp
void foo2(float *result3, const float *vector3) {
    // result3 = (vector3 * 1000) + 50
    // the *_v functions take raw float pointers, instead of vec3
    //    can be used instead of vec3_scale(Vec3(vector3), 1000)
    Vec3(result3) = vec3_add(
            vec3_scale_v(vector3, 1000),
            50);
}

// add foo functionality
vec3 vec3_scale_add(vec3 vector, float scale, float add) {
    return vec3_add(vec3_scale(vector, scale), add);
}

int main() {
    float vec_raw[3] = {1, 2, 3};
    float res_raw[3];
    foo1(res_raw, vec_raw);
    vec3_print(Vec3(res_raw));

    vec3 vec = {{1, 2, 3}};
    vec3 res;
    foo2(res.v, vec.v);
    vec3_print(res);

    res = vec3_scale_add(vec, 1000, 50);
    vec3_print(res);
}
