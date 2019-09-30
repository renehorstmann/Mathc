# Mathc
Some independent vector and matrix single header file libraries for C(++) programming.

## Getting Started
Copy a header file for its library to your project and have fun.
The libraries are written in C and compatible with C++ (tested on GCC 7.4.0)

### Libraries
* VecMath: macros and functions for vector math
* MatMath: functions for matrix math

## VecMath
The header file [vecmath.h](include/mathc/vecmath.h) defines multiple macros for vector math.
Each macro (e. g. VecDot) can be used with different number types (int, float, ...).
In addition to the macros, there are typed functions for float and double (vec/ vecd).
And for three and four component vectors (vec3(d) and vec4(d)).
```c
#include "vecmath.h"
//...

int main() {

    float vec[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float res[10];
    VecScaleVec(res, vec, vec, 10)   // typeless macro
    float norm = vec_norm(res, 10);  // float typed function
    printf("%f\n", norm);

    // double typed function with specified size
    vec3d vec_d = vec3d_add_sca((double[]){-1.23, -2.34, -3.45}, 10);
    double sum = vecd_sum(vec_d.v, 3);
    printf("%f\n", sum);

    // output:
    //123.826492
    // 22.980000
}
```

## MatMath
The header file [matmath.h](include/mathc/matmath.h) defines multiple functions for squared matrix math.
There are typed functions for float and double (mat/ matd).
And for 3x3 and 4x4 component matrices (mat33(d) and mat44(d)).
One can use this header file, together with the [vecmath.h](include/utilc/vecmath.h) header, 
to use functions like set, copy or scale (vec_copy(dst_mat, src_mat, 9)).
```c
#include "matmath.h"
//...

int main() {

    float mat33[] = {1, 2, 3, 40, 50, 60, 0, -1, 5};
    float det = mat_determinant33(mat33);
    printf("%f\n", det);

    float inv[9];
    mat_invert33(inv, mat33);
    float col[3];
    mat_col(col, inv, 0, 3);
    printf("%f %f %f\n", col[0], col[1], col[2]);

    // double typed function with specified size
    mat44d mat_d = mat44d_eye();
    printf("%f\n", mat_d.m[1*4+1]);

    // output:
    // -210.000000
    // -1.476191 0.952381 0.190476
    // 1.000000
}
```

## Running the examples
The top directory of this project contains a CmakeLists.txt file, which sets up the examples for each library

## Author

* **René Horstmann**

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
