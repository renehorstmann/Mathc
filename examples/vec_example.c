#include "mathc/mathc.h"

// see below main
static vec3 foo(vec4 a, vec2 b);

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
