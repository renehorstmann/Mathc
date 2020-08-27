#include <stdio.h>
#include "mathc/quat.h"
#include "mathc/io.h"

int main() {

    quatf a = QUAT4_INIT_EYE;
    quatf b = quatf_from_angle_axis((vec4f) {{0, 0, 1, M_PI_2}});
    quatf_print(b);

    quatf c = quatf_slerp(a, b, 0.5f);
    quatf_print(c);

    vec4f angle_axis = quatf_to_angle_axis(c);
    vec4f_print(angle_axis);

    mat33f rot = quatf_to_rotation_matrix(c);
    mat33f_print(rot);
}
