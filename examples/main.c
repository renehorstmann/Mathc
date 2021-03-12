#include "mathc/mathc.h"
#include <time.h>

int main() {
    // some tests here...

    ucvec4 rgba = {{100, 200, 50, 255}};
    vec4 col = vec4_cast_from_uchar_1(rgba.v);
    vec4_println(col);

    vec3 hsv = vec3_rgb2hsv(col.rgb);
    vec3_println(hsv);
    hsv.v0 += 120;
    vec3_println(hsv);
    col.rgb = vec3_hsv2rgb(hsv);
    vec4_println(col);

    rgba = ucvec4_cast_from_float_1(col.v);
    ucvec4_println(rgba);

    srand(time(NULL));
    vec4 normal = vec4_random_normal(0, 1);
    vec4_println(normal);
}
