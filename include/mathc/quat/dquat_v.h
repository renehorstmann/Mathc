#ifndef MATHC_QUAT_DQUAT_V_H
#define MATHC_QUAT_DQUAT_V_H

#include "dquat.h"


/** dst = -x, -y, -z, w */
static dquat dquat_conjugate_v(const double *q) {
    return dquat_conjugate(DQuat(q));
}

/** dst = inv(dquat) */
static dquat dquat_invert_v(const double *q) {
    return dquat_invert(DQuat(q));
}

/** dst = a @ b Hamilton Product */
static dquat dquat_mul_v(const double *a, const double *b) {
    return dquat_mul(DQuat(a), DQuat(b));
}

/** angle_axis = xyz + w=angle in rad */
static dquat dquat_from_angle_axis_v(const double *angle_axis) {
    return dquat_from_angle_axis(DQuat(angle_axis));
}

/** angle_axis = xyz + w=angle in rad */
static dvec4 dquat_to_angle_axis_v(const double *q) {
    return dquat_to_angle_axis(DQuat(q));
}

static dmat3 dquat_to_rotation_dmatrix_v(const double *q) {
    return dquat_to_rotation_dmatrix(DQuat(q));
}

static dquat dquat_from_rotation_dmatrix_v(const double *dmat) {
    return dquat_from_rotation_dmatrix(DMat3(dmat));
}

static dquat dquat_slerp_v(const double *from, const double *to, double t) {
    return dquat_slerp(DQuat(from), DQuat(to), t);
}

#endif //MATHC_QUAT_DQUAT_H
