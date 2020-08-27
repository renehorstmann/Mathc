#ifndef MATHC_QUAT_DQUAT_H
#define MATHC_QUAT_DQUAT_H

#include "math.h"
#include "../types.h"
#include "../vec.h"


/** dquat = [0, 0, 0, 1] */
static dquat dquat_eye() {
    return (dquat) QUAT4_INIT_EYE;
}

/** dst = -x, -y, -z, w */
static dquat dquat_conjugate(dquat q) {
    return (dquat) {{-q.x, -q.y, -q.z, q.w}};
}

/** dst = inv(dquat) */
static dquat dquat_invert(dquat q) {
    dquat conj = dquat_conjugate(q);
    return dvec4_scale_sca(conj, 1.0 / dvec4_dot(q, q));
}

/** dst = a @ b Hamilton Product */
static dquat dquat_mul(dquat a, dquat b) {
    // from cglm/dquat/glm_dquat_mul
    dquat res;
    res.v[0] = a.v[3] * b.v[0] + a.v[0] * b.v[3] + a.v[1] * b.v[2] - a.v[2] * b.v[1];
    res.v[1] = a.v[3] * b.v[1] - a.v[0] * b.v[2] + a.v[1] * b.v[3] + a.v[2] * b.v[0];
    res.v[2] = a.v[3] * b.v[2] + a.v[0] * b.v[1] - a.v[1] * b.v[0] + a.v[2] * b.v[3];
    res.v[3] = a.v[3] * b.v[3] - a.v[0] * b.v[0] - a.v[1] * b.v[1] - a.v[2] * b.v[2];
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static dquat dquat_from_angle_axis(dvec4 angle_axis) {
    // from cglm/dquat/glm_dquatv
    double a = angle_axis.w * 0.5;
    double c = cosf(a);
    double s = sinf(a);

    dvec3 axis = dvec3_normalize(angle_axis.xyz);

    dquat res;
    res.xyz = dvec3_scale_sca(axis, s);
    res.w = c;
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static dvec4 dquat_to_angle_axis(dquat q) {
    // from cglm/dquat/glm_dquat_angle
    /*
     sin(theta / 2) = length(x*x + y*y + z*z)
     cos(theta / 2) = w
     theta          = 2 * atan(sin(theta / 2) / cos(theta / 2))
     */
    double imag_len = dvec3_norm(q.xyz);
    double angle = 2.0 * atan2(imag_len, q.w);

    dvec4 angle_axis;
    angle_axis.xyz = dvec3_normalize(q.xyz);
    angle_axis.w = angle;
    return angle_axis;
}

static dmat3 dquat_to_rotation_dmatrix(dquat q) {
    // from cglm/dquat/glm_dquat_dmat3
    double norm = dvec4_norm(q);
    double s = norm > 0.0 ? 2.0 / norm : 0.0;

    double x = q.x;
    double y = q.y;
    double z = q.z;
    double w = q.w;

    double xx, xy, wx;
    double yy, yz, wy;
    double zz, xz, wz;
    xx = s * x * x;
    xy = s * x * y;
    wx = s * w * x;
    yy = s * y * y;
    yz = s * y * z;
    wy = s * w * y;
    zz = s * z * z;
    xz = s * x * z;
    wz = s * w * z;

    dmat3 res;
    res.m[0][0] = 1.0 - yy - zz;
    res.m[1][1] = 1.0 - xx - zz;
    res.m[2][2] = 1.0 - xx - yy;

    res.m[0][1] = xy + wz;
    res.m[1][2] = yz + wx;
    res.m[2][0] = xz + wy;

    res.m[1][0] = xy - wz;
    res.m[2][1] = yz - wx;
    res.m[0][2] = xz - wy;
    return res;
}

static dquat dquat_from_rotation_dmatrix(dmat3 dmat) {
    // from cglm/dmat3/glm_dmat3_dquat
    dquat res;
    double trace, r, rinv;
    trace = dmat.m[0][0] + dmat.m[1][1] + dmat.m[2][2];
    if (trace >= 0.0) {
        r = sqrt(1.0 + trace);
        rinv = 0.5f / r;

        res.v[0] = rinv * (dmat.m[1][2] - dmat.m[2][1]);
        res.v[1] = rinv * (dmat.m[2][0] - dmat.m[0][2]);
        res.v[2] = rinv * (dmat.m[0][1] - dmat.m[1][0]);
        res.v[3] = r * 0.5f;
    } else if (dmat.m[0][0] >= dmat.m[1][1] && dmat.m[0][0] >= dmat.m[2][2]) {
        r = sqrt(1.0 - dmat.m[1][1] - dmat.m[2][2] + dmat.m[0][0]);
        rinv = 0.5f / r;

        res.v[0] = r * 0.5f;
        res.v[1] = rinv * (dmat.m[0][1] + dmat.m[1][0]);
        res.v[2] = rinv * (dmat.m[0][2] + dmat.m[2][0]);
        res.v[3] = rinv * (dmat.m[1][2] - dmat.m[2][1]);
    } else if (dmat.m[1][1] >= dmat.m[2][2]) {
        r = sqrt(1.0 - dmat.m[0][0] - dmat.m[2][2] + dmat.m[1][1]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (dmat.m[0][1] + dmat.m[1][0]);
        res.v[1] = r * 0.5f;
        res.v[2] = rinv * (dmat.m[1][2] + dmat.m[2][1]);
        res.v[3] = rinv * (dmat.m[2][0] - dmat.m[0][2]);
    } else {
        r = sqrt(1.0 - dmat.m[0][0] - dmat.m[1][1] + dmat.m[2][2]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (dmat.m[0][2] + dmat.m[2][0]);
        res.v[1] = rinv * (dmat.m[1][2] + dmat.m[2][1]);
        res.v[2] = r * 0.5f;
        res.v[3] = rinv * (dmat.m[0][1] - dmat.m[1][0]);
    }

    return res;
}

static dquat dquat_slerp(dquat from, dquat to, double t) {
    // from cglm/dquat/glm_dquat_slerp
    double cos_theta = dvec4_dot(from, to);

    if (fabs(cos_theta) >= 1.0)
        return from;

    if (cos_theta < 0.0) {
        from = dvec4_neg(from);
        cos_theta = -cos_theta;
    }

    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    /* LERP to avoid zero division */
    if (fabs(sin_theta) < 0.001f)
        return dvec4_lerp(from, to, t);

    /* SLERP */
    double angle = acosf(cos_theta);
    dquat q1 = dvec4_scale_sca(from, sinf((1.0 - t) * angle));
    dquat q2 = dvec4_scale_sca(to, sinf(t * angle));

    q1 = dvec4_add_dvec(q1, q2);
    return dvec4_scale_sca(q1, 1.0 / sin_theta);
}

#endif //MATHC_QUAT_DQUAT_H
