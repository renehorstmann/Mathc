# Mathc
A simple math header only math library for C

## Getting Started
Copy the header files into your project and have fun.
The libraries are written in C(11) (tested on GCC 7.4.0)

### Libraries
* vec: functions, typed function and generic macros for vector math
* mat: functions, typed function and generic macros for matrix math
* mathc: includes vec.h and mat.h

## vec
The header file [vec.h](include/mathc/vec.h) includes all files in the vec dir.
These files contains functions, typed function and generic macros for vector math.
With the typed function, its possible to write readable math code in C.
```c
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
```

## mat
The header file [mat.h](include/mathc/mat.h) includes all files in the mat dir.
It works like vec, but adds squared matrix calculations.v
```c
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
```

## How it works
The header file [types.h](include/mathc/types.h) defines all types for the typed macros.
In C, its not trivial to copy a vector, because vectors are just pointers that need function for copying.
The Mathc library uses structs and unions to wrap these typed vectors. So C can copy them with the = operator.
The macro Vec3f will only cast the pointer into a pointer to the vec3f struct and dereference it.
```c
typedef struct vec3f {
    float v[3];
} vec3f;

/** casts a float * to a dereferenced vec3f */
#define Vec3f(vec) (*(vec3f *) (vec))

/** casts a float * to a dereferenced const vec3f */
#define ConstVec3f(vec) (*(const vec3f *) (vec))
```

## Performance
Also it seems that there will be an overhead due to the casts and copying. 
The [performance test](examples/performance_test_lib.c) shows that the overhead is only noticeable in debug mode of the compiler.

## Running the examples
The top directory of this project contains a CmakeLists.txt file, which sets up the examples for each library

## Author

* **René Horstmann**

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
