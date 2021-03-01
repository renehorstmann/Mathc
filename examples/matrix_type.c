#include "mathc/mathc.h"

int main() {

    // 180° via Z matrix (X points to -X, Y to -Y)
    mat3 rotation_matrix = {{
        -1, 0, 0,   // X
        0, -1, 0,   // Y
        0, 0, 1     // Z
    }};

    // identity matrix
    rotation_matrix = mat3_eye();

    // Access via matrix position
    rotation_matrix.m00 = -1;
    rotation_matrix.m11 = -1;

    // or by the raw pointer as matrix[3][3]
    rotation_matrix.m[0][0] = -1;
    rotation_matrix.m[1][1] = -1;

    // or as vector[9] position
    rotation_matrix.v0 = -1;
    rotation_matrix.v4 = -1;

    // or by the raw pointer as vector[9]
    rotation_matrix.v[0] = -1;
    rotation_matrix.v[4] = -1;

    // or by each column as vec3[3]
    rotation_matrix.col[0].x = -1;      // x column, value x
    rotation_matrix.col[1].y = -1;      // y column, value y

    mat3_println(rotation_matrix);      // nice to view
    mat3_println_repr(rotation_matrix); // easy to copy into c

    // eye by col vectors
    vec3 x = vec3_unit_x();
    vec3 y = vec3_unit_y();
    vec3 z = vec3_unit_z();
    rotation_matrix.col[0] = x;
    rotation_matrix.col[1] = y;
    rotation_matrix.col[2] = z;

    mat3_println(rotation_matrix);

    // casts are like vector casts:
    float rot_mat_raw[9];
    Mat3(rot_mat_raw) = rotation_matrix;
}
