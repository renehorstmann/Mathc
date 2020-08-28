# Mathc
A simple and clean, glsl like, math header only library for C.

## Getting Started
Copy the header files into your project and have fun.
The libraries are written in C(11) (tested on GCC 7.4.0)

### Libraries
* vec: for vector math
* mat: for matrix math
* quat: for quaternion math


### The types
Vectors and matrices are defined as structs.
With this convention (instead of passing pointers), 
vectors and matrices can be copied with the ```operator=``` in C.
In addition to this, the compiler can generate errors,
if a program wants to pass a vec3 where a vec4 is needed.
The copying seems like an overhead, but the compiler can optimize this out.
Not only that, he can do better because he knows more about the data.
<br>
The vec2 is defined as:
```c
typedef union vec2 {
    float v[2];
    struct {
        float v0, v1;
    };
    struct {
        float x, y;
    };
} vec2;
_Static_assert(sizeof(vec2) == sizeof(float) * 2, 
               "[Mathc] wrong expected size");
```
There are different options to access the data in the vec2:
```c
vec2 a = {{1, 2}};
printf("a.x = %f = %f = %f\n",
    a.v[0],     // raw vector data
    a.v0,       // vector data 0-1
    a.x         // x, y
);
```
The type vec3 can do a little bit more:
```c
typedef union vec3 {
    float v[3];
    struct {
        float v0, v1, v2;
    };
    vec2 xy;
    struct {
        float x;
        union {
            struct {
                float y, z;
            };
            vec2 yz;
        };
    };
} vec3;
_Static_assert(sizeof(vec3) == sizeof(float) * 3, 
               "[Mathc] wrong expected size");
```
In addition to v, v0-2, xyz, a vec3 lets you access subdata vec2:
```c
vec3 a {{1, 2, 3}};
vec2 b = a.yz;
assert(b.v0 == 2 && b.v1 == 3);
```
vec4 has subdata for both, vec2 and vec3 (.xy, .xyz)

## vec
The header file [vec.h](include/mathc/vec.h) includes all files in the vec dir.
These files contains functions and typed functions for vector math.
With the typed function, its possible to write readable math code in C.
```c
#include "mathc/mathc.h"

// see below main
static vec3 foo(vec4 a, vec2 b);
static void bar(float *vertices, int n);

int main() {
    vec4 a = {{1, 2, 3, 4}};
    a = vec4_scale_sca(a, 10);  // a = a * 10
    vec4_print(a);

    // access data:
    printf("x: %f = %f = %f\n",
           a.x,         // or y, z, w
           a.v0,        // vector data 0 - 3
           a.v[0]);     // raw float * vector

    // get sub data;
    vec2_print(a.yz);    // or xy, zw, xyz, yzw

    vec3 b = foo((vec4) {{1.1f, 2.2f, 3.3f, 0}}, a.zw);
    vec3_print(b);


    vec3 x = VEC3_INIT_UNIT_X;
    vec3 y = VEC3_INIT_UNIT_Y;
    vec3 z = vec3_cross(x, y);
    vec3_print(z);


    float data[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    // typeless functions:
    // (dst, a, b, n) for dst = a + b
    vecN_add_sca(data, data, -1, 8);

    // copy to a type:
    vec4 copy = Vec4(data);
    vec4_print(copy);

    // cast and change some values
    Vec2(data+4) = vec2_set(-1);
    Vec2(data+6) = vec2_set(-3);
    vec4_print(Vec4(data+4));

    // use the _v functions to pass raw vectors
    vec2 c = vec2_neg_v(data);
    // instead of c = vec2_neg(Vec2(data));
    vec2_print(c);
    
    float vertices[12];                    // (4 vertices * xyz = 12 floats)
    vecN_set(vertices, 10, 12);   // set every float to 10
    bar(vertices, 4);                   // call function below
    vec3_print(Vec3(vertices));            // print first vertex

    // have a look into mathc/vec/vec*.h for more functions. For example:
    //      norm, norm_p, norm_1, norm_inf
    //      normalize
    //      lerp
    //      dot

    // There are also variants for double int int:
    // dvec*
    // ivec*
}


// a function would take a copy, unless it takes a pointer of a vec type
static vec3 foo(vec4 a, vec2 b) {
    return vec3_div_sca(a.xyz, b.y);
}

// example function to use Mathc types in a function, taking raw data
static void bar(float *vertices, int n) {
    for(int i=0; i<n; i++) {
        // reference instead of copy:
        vec3 *vertex = (vec3 *) &vertices[i*3];
        *vertex = vec3_normalize(*vertex);
        // ...
        
        // or:
        float *vertex_p = &vertices[i*3];
        Vec3(vertex_p) = vec3_normalize_v(vertex_p);
        // ...
    }
}
```

## mat
The header file [mat.h](include/mathc/mat.h) includes all files in the mat dir.
It works like vec, but adds squared matrix calculations.
The matrices are in column major order, so ```matrix[col][row]```.
```c
#include "mathc/mathc.h"

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

    // There are also variants for double int int:
    // dmat*
    // imat*
}
```

## quat
The header file [quat.h](include/mathc/quat.h) includes all files in the quat dir.
A quat is a simple typedef for a vec4: ```{qx, qy, qz, qw}```.
```c
#include "mathc/mathc.h"

int main() {
    // a quat is a typedef to vec4
    quat a = QUAT4_INIT_EYE;
    quat b = quat_from_angle_axis((vec4) {{0, 0, 1, M_PI_2}});
    quat_print(b);

    // slerp is a more suitable function to interpolate rotations
    // sperical lerp
    quat c = quat_slerp(a, b, 0.5f);
    quat_print(c);

    vec4 angle_axis = quat_to_angle_axis(c);
    vec4_print(angle_axis);

    mat3 rot = quat_to_rotation_matrix(c);
    mat3_print(rot);

    // have a look into mathc/vec/vec*.h for more functions for quat math. For example:
    //      norm, norm_p, norm_1, norm_inf
    //      normalize
    //      lerp
    //      dot

    // There is also the variant for double:
    // dquat
}
```

## Performance
It seems that there will be an overhead due to the casts and copying. 
The [performance test](examples/performance_test_lib.c) shows that the overhead is only noticeable in debug mode of the compiler.
In Optimising mode, my compiler generated a better result than a manual, not copying example.

## Running the examples
The top directory of this project contains a CmakeLists.txt file, which sets up the examples for each library

## Todo:
- Fork functions from cglm to this style. LookAt, ortho, perspective, ...

## Author

* **René Horstmann**
* Copied some function implementations of: [cglm](https://github.com/recp/cglm)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
