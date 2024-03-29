#include "mathc/mathc.h"
#include <time.h>

int main() {
    // some tests here...
    ucvec4 rgba = {{100, 200, 50, 255}};
    vec4 col = vec4_cast_from_uchar_1(rgba.v);
    vec4_println(col);

    printf("color: " VEC4_PRINT_FORMAT "\n", mathc_u4(col));
    printf("color: " VEC4_PRINT_FORMAT_VALUES "\n", mathc_u4(col));
    mathc_terminalcolor_start();
    printf("color: " VEC4_PRINT_FORMAT_COLORED "\n", mathc_u4(col));
    mathc_terminalcolor_stop();

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


    vec3 a_pos = {{10, 20, 30}};
    vec3 a_dir = {{1, 0, 0}};
    vec3 b_pos = {{-10, -20, -30}};
    vec3 b_dir = {{0, 1, 0}};

    float a_tau, b_tau;
    intersection_line_line(&a_tau, &b_tau, a_pos, a_dir, b_pos, b_dir);

    float a_tau2, b_tau2;
    intersection2_line_line(&a_tau2, &b_tau2, a_pos.xy, a_dir.xy, b_pos.xy, b_dir.xy);

    printf("intersection:  %f %f\n", a_tau, b_tau);
    printf("intersection2: %f %f\n", a_tau2, b_tau2);


    for (int i = 0; i < 100; i++) {
        float x = (float) i / 100.0f;

        printf("signals (%+5.3f): %+5.3f %+5.3f %+5.3f %+5.3f %+5.3f %+5.3f %+5.3f\n",
               x,
               sca_signal_wave(x),
               sca_signal_block(x),
               sca_signal_saw(x),
               sca_signal_ramp(x),
               sca_signal_smoothsaw_single(x, 0.1),
               sca_signal_smoothsaw(x, 0.1),
               sca_signal_smoothramp(x, 0.1));
    }
}
