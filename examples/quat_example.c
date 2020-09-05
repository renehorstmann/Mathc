#include "mathc/float.h"

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
    //      inv
    //      lerp
    //      dot

    // There is also the variant for double:
    // dquat
}
