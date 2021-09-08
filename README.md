# Mathc
A simple and clean, glsl like, math (linear algebra) header only library for C.

## Getting Started
Copy the header files into your project and have fun.
The libraries are written in C11 (tested on GCC 9.3.0).
C++11 should also work (also tested with GCC 9.3.0).

## Content
- types: vector and matrix types (vec3, mat4, ...)
- io: debug print for the types
- vec: vector math
- mat: matrix math
- sca: scalar math (provides functions like min, max, clamp, ... for float, double, int, ...)
- utils: some useful functions


## The Types
There are multiple types for different sizes and value types: (sizes (*): 2 - 4)
- vec* for float vectors
- mat* for float square matrices
- dvec*, dmat* for double vectors / square matrices
- ivec*, imat* for int vectors / square matrices
- uvec*, umat* for unsigned vectors / square matrices
- cvec*, cmat* for char vectors / square matrices
- ucvec*, ucmat* for unsigned char vectors / square matrices
- bvec* for bool vectors

### Vector type usage:
```c
#include "mathc/mathc.h"
int main() {
    vec3 a = {{1, 2, 3}};

    vec3 b;
    b.x = 10;
    b.y = 20;
    b.z = 30;

    vec3 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;

    // or by index:
    c.v0 = a.v0 + b.v0;
    c.v1 = a.v1 + b.v1;
    c.v2 = a.v2 + b.v2;

    // or by color:
    c.r = a.r + b.r;
    c.g = a.g + b.g;
    c.b = a.b + b.b;

    // or by raw float *:
    c.v[0] = a.v[0] + b.v[0];
    c.v[1] = a.v[1] + b.v[1];
    c.v[2] = a.v[2] + b.v[2];

    // or by function
    c = vec3_add_vec(a, b);

    // copies c into copy1
    vec3 copy1 = c;
    vec3_println(copy1);  // mathc/io

    // copies c into copy2, by a memcpy and the raw pointer
    vec3 copy2;
    memcpy(copy2.v, c.v, sizeof(vec3));
    vec3_println(copy2);


    vec3 rgb = {{0, 1, 0.5}};
    
    vec4 rgba;
    
    // .xyz returns a vec3
    rgba.xyz = rgb;         // or .rgb
    
    // .w is the 4. component (xyzw, rgba)
    rgba.w = 1;             // or .a
    
    // copies gb (vec2)
    vec2 gb = rgba.gb;      // or .yz
    vec2_println(gb);
}
```

### Vector type casting:
All types can be casted from raw pointers.
Functions, that operates on the types, normally have the type as prefix: vec3_*
```c
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
    vec3_println(Vec3(res_raw));

    vec3 vec = {{1, 2, 3}};
    vec3 res;
    foo2(res.v, vec.v);
    vec3_println(res);

    res = vec3_scale_add(vec, 1000, 50);
    vec3_println(res);
}
```

### Matrix type:
The matrices are stored in column major order.
```c
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
```


### Type implementation
Vectors and matrices are defined as unions.
With this convention (instead of passing pointers), 
vectors and matrices can be copied with the ```operator=``` in C.
In addition to this, the compiler can generate errors,
if a program wants to pass a vec3 where a vec4 is needed.
The copying seems like an overhead, but the compiler can optimize this out.
Not only that, he can do better because he knows more about the data.


The vec2 is defined as:
```c
typedef union {
    float v[2];
    struct {
        float v0, v1;
    };
    struct {
        float x, y;
    };
    struct {
        float r, g;
    };
} vec2;
static_assert(sizeof(vec2) == sizeof(float) * 2, "[Mathc] wrong expected size");
```


There are different options to access the data in the vec2:
```c
vec2 a = {{1, 2}};
printf("a.x = %f = %f = %f = %f\n",
    a.v[0],     // raw vector data
    a.v0,       // vector data 0-1
    a.x,        // x, y
    a.r         // r, g
);
```


The type vec3 can do a little bit more:
```c
typedef union {
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
    vec2 rg;
    struct {
        float r;
        union {
            struct {
                float g, b;
            };
            vec2 gb;
        };
    };
} vec3;
static_assert(sizeof(vec3) == sizeof(float) * 3, "[Mathc] wrong expected size");
```


In addition to v, v0-2, xyz, rgb, a vec3 lets you access subdata vec2:
```c
vec3 a = {{1, 2, 3}};
vec2 b = a.yz;
assert(b.v0 == 2 && b.v1 == 3);
```


vec4 has subdata for both, vec2 and vec3 (.xy, .xyz, .yza, .za, ...).
There are also variants for double, int, unsigned, char, uchar and bool with d, i, u, c, uc and b prefix.


## Basic functions
There are a lot of functions to use with the types:
- vec*_unit*
- vec*_set
- vec*_cast_from
- vec*_cmp
- vec*_neg
- vec*_add
- vec*_add_vec
- vec*_sub
- vec*_sub_vec
- vec*_scale
- vec*_scale_vec
- vec*_div
- vec*_div_vec
- vec*_radians
- vec*_degrees
- vec*_sin
- vec*_cos
- vec*_tan
- vec*_asin
- vec*_acos
- vec*_atan
- vec*_atan2
- vec*_pow
- vec*_pow_vec
- vec*_exp
- vec*_log
- vec*_exp2
- vec*_log2
- vec*_sqrt
- vec*_inversesqrt
- vec*_abs
- vec*_sign
- vec*_floor
- vec*_ceil
- vec*_fract
- vec*_mod
- vec*_mod_vec
- vec*_min
- vec*_min_vec
- vec*_max
- vec*_max_vec
- vec*_clamp
- vec*_clamp_vec
- vec*_mix
- vec*_mix_vec
- vec*_step
- vec*_step_vec
- vec*_smoothstep
- vec*_smoothstep_vec
- vec*_sum
- vec*_dot
- vec*_norm
- vec*_norm_p
- vec*_norm_1
- vec*_norm_inf
- vec*_normalize
- vec*_length
- vec*_distance
- vec*_faceforward
- vec*_reflect
- vec*_refract
- vec*_less_than
- vec*_less_than_vec
- vec*_less_than_equal_vec
- vec*_...
- vec*_isnan
- vec*_cross


Special bool vector functions:
- bvec*_not
- bvec*_or
- bvec*_and
- bvec*_...
- bvec*_any
- bvec*_all


Matrix functions:
- mat*_eye
- mat*_cast_from
- mat*_cmp
- mat*_get_row
- mat*_get_col
- mat*_set_row
- mat*_set_col
- mat*_trace
- mat*_transpose
- mat*_mul_mat
- mat*_mul_vec
- mat*_det
- mat*_inv
- mat*_get_block*
- mat*_set_block*
- mat*_get_upper_left*
- mat*_set_upper_left*


Scalar function:
- sca_radians
- sca_degrees
- sca_sin
- sca_cos
- sca_tan
- sca_asin
- sca_acos
- sca_atan
- sca_atan2
- sca_pow
- sca_exp
- sca_log
- sca_exp2
- sca_log2
- sca_sqrt
- sca_inversesqrt
- sca_abs
- sca_sign
- sca_floor
- sca_ceil
- sca_fract
- sca_mod
- sca_min
- sca_max
- sca_clamp
- sca_mix
- sca_step
- sca_smoothstep
- sca_isnan

### Typeless functions
Most functions have their base function as vecN_* or matN_*.
These functions take raw pointers as in and output and the size as last parameter:
```c
#include "mathc/mathc.h"

int main() {
    float a[7];
    float res[7];
    vecN_scale(res, a, 1000, 7);
    vecN_add(res, res, 50, 7);
}
```

### Utils functions
Within the sub folder utils/ are some additional libraries:
- [camera.h](include/mathc/utils/camera.h): for camera matrices for view and projection
- [color.h](include/mathc/utils/color.h): for rgb hsv conversions
- [intersection.h](include/mathc/utils/intersection.h): for plane, line, triangle intersections
- [rotation.h](include/mathc/utils/rotation.h): for angle axis to matrix rotations
- [quat.h](include/mathc/utils/quat.h): for Quaternion math
- [random.h](include/mathc/utils/random.h): for random number generation (rand function can be user defined)

All these libraries should have a d* prefix for double versions

## Import system
Import everything from Mathc:
```#include "mathc/mathc.h"```

Import float related functions (except of utils/):
```#include "mathc/float.h"```

Import float related utils functions:
```#include "mathc/utils/float.h"```

Import only float vector functions:
```#include "mathc/vec/float.h"```

Import only float typeless vector functions:
```#include "mathc/vec/vecn.h"```

Import only float vector4 functions:
```#include "mathc/vec/vec4.h"```

Same for double, int, unsigned, char, uchar and bool.

Only importing a subset (like mathc/float.h), speeds up the compilation process

### Example usage
```c
// includes float related vector and matrix functions
#include "mathc/float.h"

// includes all float related utils functions
#include "mathc/utils/float.h"

// includes bool related vector functions
#include "mathc/bool.h"


/** Transform a 3d point with a transformation matrix M */
vec3 transform_point(mat4 M, vec3 point) {
    // Create a homogenous 3d point
    vec4 hpoint;
    hpoint.xyz = point;
    // 1 for points, 0 for vectors
    hpoint.w = 1;

    // return only xyz=vec3 of the resulting vec4 point
    return mat4_mul_vec(M, hpoint).xyz;
}

/** Transform a 3d vector with a transformation matrix M */
vec3 transform_vector(mat4 M, vec3 vector) {
    // vectors need (M^-1)^t for transformations
    // (if the matrix uses scaling and sheering)
    // its safe to override (copies)
    M = mat4_transpose(mat4_inv(M));
    vec4 hvector;
    hvector.xyz = vector;
    hvector.w = 0;
    return mat4_mul_vec(M, hvector).xyz;
}

typedef struct {
    float x, y, z, radius;
    // ...
} Sphere_s;

/** Test collision between spheres */
bool sphere_collision(Sphere_s a, Sphere_s b) {
    // _v functions take const float * and treats them as vec3
    vec3 dist = vec3_sub_vec_v(&b.x, &a.x);

    // norm(dist) < a.r+b.r
    // powf(,2) is much faster than sqrt
    return vec3_dot(dist, dist) < powf(a.radius + b.radius, 2);
}

/** calculates the angle between vector a and b */
float vec_angle(vec3 a, vec3 b) {
    // Safe to override (copies)
    a = vec3_normalize(a);
    b = vec3_normalize(b);
    return acosf(vec3_dot(a, b));
}

/** creates a pose from a ray. dir -> Z axis */
mat4 ray_to_pose(vec3 pos, vec3 dir) {
    vec3 z = vec3_normalize(dir);

    // align x axis of pose to unit x
    vec3 y = vec3_cross(z, vec3_unit_x());
    if(vec3_norm(y) < 0.01f) {
        // z is parallel to x, using y for x instead
        y = vec3_cross(z, vec3_unit_y());
    }
    y = vec3_normalize(y);

    vec3 x = vec3_cross(y, z);
    // no need to normalize, cause y and z are orthogonal and normalized

    mat4 pose = mat4_eye();
    pose.col[0].xyz = x;
    pose.col[1].xyz = y;
    pose.col[2].xyz = z;
    pose.col[3].xyz = pos;
    return pose;
}

/** creates a camera VP matrix */
mat4 create_camera_VP(vec3 eye, vec3 dir, vec3 up, bool orhto) {
    vec3 center = vec3_add_vec(eye, dir);
    mat4 V = mat4_camera_lookat(eye, center, up);
    mat4 P;
    if(orhto)
        P = mat4_camera_ortho(-1, 1, -1, 1, -2, 10);
    else
        P = mat4_camera_frustum(-1, 1, -1, 1, -2, 10);
    return mat4_mul_mat(P, V);
}

bool axles_in_limits(vec3 axles) {

    // lower, upper limits in degree
    vec3 limits_deg[2] = {
            {{-5, 10, 0}},
            {{50, 170, 90}}
    };

    vec3 limits[2] = {
            vec3_radians(limits_deg[0]),
            vec3_radians(limits_deg[1])
    };

    bvec3 in_lower_limit = vec3_greater_than_equal_vec(axles, limits[0]);
    bvec3 in_upper_limit = vec3_less_than_equal_vec(axles, limits[1]);
    bvec3 in_limit = bvec3_and(in_lower_limit, in_upper_limit);

    // returns true if all axles are in limits
    return bvec3_all(in_limit);
}

bool vec_equals(vec3 a, vec3 b) {
    return bvec3_all(vec3_equal_eps_vec(a, b, 0.01f));
}

int main() {
    mat4 pose = ray_to_pose((vec3) {{100, 100, 50}}, (vec3) {{0, 0, 1}});
    vec3 point = {{10, 20, 30}};
    point = transform_point(mat4_inv(pose), point);
    vec3_println(point);

    mat4 VP = create_camera_VP((vec3) {{10, 20, 30}},
                               vec3_neg(vec3_unit_z()),
                               vec3_unit_y(),
                               false);
    vec3 normal = {{0, 1, 0}};
    normal = transform_vector(VP, normal);
    vec3_println(normal);

    printf("angle: %f\n", vec_angle(vec3_unit_x(), vec3_unit_y()));

    printf("in_limits: %d\n", axles_in_limits((vec3) {{0, M_PI_2, M_PI_4}}));
}

```

## Performance
It seems that there will be an overhead due to the casts and copying. 
The [performance test](examples/performance_test_lib.c) shows that the overhead is only noticeable in debug mode of the compiler.
In Optimising mode, my compiler generated a better result than a manual, not copying example.

## Running the examples
The top directory of this project contains a CmakeLists.txt file, which sets up the examples for each library

## Author

* **René Horstmann**
* Copied some function implementations of: [cglm](https://github.com/recp/cglm) (noted in my comments) (MIT License)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
