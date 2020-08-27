#ifndef MATHC_QUAT_QUAT_V_H
#define MATHC_QUAT_QUAT_V_H

#include "quat.h"


/** dst = -x, -y, -z, w */
static quat quat_conjugate_v(const float *q) {
    return quat_conjugate(Quat(q));
}

/** dst = inv(quat) */
static quat quat_invert_v(const float *q) {
    return quat_invert(Quat(q));
}

/** dst = a @ b Hamilton Product */
static quat quat_mul_v(const float *a, const float *b) {
    return quat_mul(Quat(a), Quat(b));
}

/** angle_axis = xyz + w=angle in rad */
static quat quat_from_angle_axis_v(const float *angle_axis) {
    return quat_from_angle_axis(Quat(angle_axis));
}

/** angle_axis = xyz + w=angle in rad */
static vec4 quat_to_angle_axis_v(const float *q) {
    return quat_to_angle_axis(Quat(q));
}

static mat3 quat_to_rotation_matrix_v(const float *q) {
    return quat_to_rotation_matrix(Quat(q));
}

static quat quat_from_rotation_matrix_v(const float *mat) {
    return quat_from_rotation_matrix(Mat3(mat));
}

static quat quat_slerp_v(const float *from, const float *to, float t) {
    return quat_slerp(Quat(from), Quat(to), t);
}

#endif //MATHC_QUAT_QUAT_H
