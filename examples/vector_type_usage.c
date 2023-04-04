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

    // or by raw float *:
    c.v[0] = a.v[0] + b.v[0];
    c.v[1] = a.v[1] + b.v[1];
    c.v[2] = a.v[2] + b.v[2];

    // or with the macro
    c = vec3_(11, 22, 33);
    // evaluates as c = (vec3) {{11, 22, 33}};

    // copies c into copy1
    vec3 copy1 = c;
    vec3_println(copy1);  // mathc/io

    // or print using the format strings
    // mathc_uX is a macro tu unpack the values
    //    replaced by: c.v0, c.v1, c.v2
    printf("c: " VEC3_PRINT_FORMAT "\n", mathc_u3(c));

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
