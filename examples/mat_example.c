#include "mathc/float.h"

int main() {
    // column major order
    // a = | 0, 2 |
    //     | 1, 3 |
    mat2 a = {{0, 1, 2, 3}};
    float det = mat2_det(a);    // determinant
    printf("det: %f\n", det);

    // access data and subdata
    printf("a11: %f = %f = %f = %f = %f\n",
           a.m11,           // col 1, row 1
           a.v3,            // vector data 3
           a.m[1][1],       // as C matrix
           a.v[3],          // raw float * vector
           a.col[1].y);     // first column as a vec2

    // a.row is not available, because its column major order
    vec2 row = mat2_get_row(a, 1);
    vec2_print(row);

    // use vector functions:
    // (dst, a, b, n) for dst = a + b
    vecN_scale_sca(a.v, a.v, 10, 4);
    mat2_print(a);


    mat4 M = MAT4_INIT_EYE;
    // or M = mat4_eye();

    // affine transformation (translation in x)
    M.col[3].x = 10;
    vec4 res = mat4_mul_vec(M, (vec4){{1.1f, 2.2f, 3.3f, 1}});
    // for points: w=1, for vectors w=0
    vec4_print(res);

    // back transformation
    res = mat4_mul_vec(mat4_inv(M), res);
    vec4_print(res);


    // build an affine rotation matrix:
    M = mat4_eye();
    vec4 angle_axis = {{0, 0, 1, M_PI/2}};    // quarter turn via z axis
    mat3 rotation = mat3_rotation_from_angle_axis(angle_axis);
    M = mat4_set_upper_left3(M, rotation);
    mat4_print(M);

    float data[4] = {10, 20, 30, 40};
    // as with vec, mats can be casted from a raw vector
    mat2 copy = Mat2(data);
    mat2_print(copy);

    // have a look into mathc/mat/mat*.h for more functions. For example:
    //      set_, get_ | row, col
    //      set_, get_ block
    //      vec_mul_mat

    // There are also variants for double and int:
    // dmat*
    // imat*
}
