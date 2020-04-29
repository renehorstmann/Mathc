#include <stdio.h>
#include "mathc/mat.h"

int main() {

    // matrix float base functions that are sizeless
    float mat_a[] = {1, 2, 3, 40, 50, 60, 0, -1, 5};
    float det = matf_determinant33(mat_a);
    printf("%f\n", det);

    // double typed with generic macros (vec_add also works for mat33f, mat44i, ...)
    mat44d mat_b = {{
                            1, 0, 0, 0,
                            0, -1, 0, 0,
                            0, 0, -1, 0,
                            100, 200, 300, 1
                    }};
    mat_b = mat_invert(mat_b);
    for(int c=0; c < 4; c++) {
        vec4d col = mat_get_col(mat_b, c);
        printf("col[%d] = {%f %f %f %f}\n", c, col.v[0], col.v[1], col.v[2], col.v[3]);
    }

    // Homogeneous coordinates transformation (calcs: vec_b = vec_b @ mat_b)
    // there is also the function/macro mat_mul_vec (calcs: vec_b = mat_b @ vec_b)
    vec4d vec_b = {{10, 20, 30, 1}};
    vec_b = vec_mul_mat(vec_b, mat_b);
    printf("vec = {%f %f %f %f}\n", vec_b.v[0], vec_b.v[1], vec_b.v[2], vec_b.v[3]);

    // with the Mat macros, raw pointers can be casted to the given type.
    // the typed_v functions allow the use of raw pointers as parameters.
    int mat_c[9];
    Mat33i(mat_c) = mat33i_eye();
    for(int r=0; r < 3; r++) {
        vec3i row = mat33_get_row_v(mat_c, r);
        printf("row[%d] = {%d %d %d}\n", r, row.v[0], row.v[1], row.v[2]);
    }

    // output:
    // -210.000000
    // col[0] = {1.000000 0.000000 0.000000 -100.000000}
    // col[1] = {0.000000 -1.000000 0.000000 200.000000}
    // col[2] = {0.000000 0.000000 -1.000000 300.000000}
    // col[3] = {-0.000000 0.000000 0.000000 1.000000}
    // vec = {-90.000000 180.000000 270.000000 1.000000}
    // row[0] = {1 0 0}
    // row[1] = {0 1 0}
    // row[2] = {0 0 1}
}
