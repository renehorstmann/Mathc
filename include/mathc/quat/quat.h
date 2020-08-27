#ifndef MATHC_QUAT_QUAT_H
#define MATHC_QUAT_QUAT_H

#include "math.h"
#include "../types.h"
#include "../vec.h"


/** quat = [0, 0, 0, 1] */
static quat quat_eye() {
    return (quat) QUAT4_INIT_EYE;
}

/** dst = -x, -y, -z, w */
static quat quat_conjugate(quat q) {
    return (quat) {{-q.x, -q.y, -q.z, q.w}};
}

/** dst = inv(quat) */
static quat quat_invert(quat q) {
    quat conj = quat_conjugate(q);
    return vec4_scale_sca(conj, 1.0f / vec4_dot(q, q));
}

/** dst = a @ b Hamilton Product */
static quat quat_mul(quat a, quat b) {
    // from cglm/quat/glm_quat_mul
    quat res;
    res.v[0] = a.v[3] * b.v[0] + a.v[0] * b.v[3] + a.v[1] * b.v[2] - a.v[2] * b.v[1];
    res.v[1] = a.v[3] * b.v[1] - a.v[0] * b.v[2] + a.v[1] * b.v[3] + a.v[2] * b.v[0];
    res.v[2] = a.v[3] * b.v[2] + a.v[0] * b.v[1] - a.v[1] * b.v[0] + a.v[2] * b.v[3];
    res.v[3] = a.v[3] * b.v[3] - a.v[0] * b.v[0] - a.v[1] * b.v[1] - a.v[2] * b.v[2];
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static quat quat_from_angle_axis(vec4 angle_axis) {
    // from cglm/quat/glm_quatv
    float a = angle_axis.w * 0.5f;
    float c = cosf(a);
    float s = sinf(a);

    vec3 axis = vec3_normalize(angle_axis.xyz);

    quat res;
    res.xyz = vec3_scale_sca(axis, s);
    res.w = c;
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static vec4 quat_to_angle_axis(quat q) {
    // from cglm/quat/glm_quat_angle
    /*
     sin(theta / 2) = length(x*x + y*y + z*z)
     cos(theta / 2) = w
     theta          = 2 * atan(sin(theta / 2) / cos(theta / 2))
     */
    float imag_len = vec3_norm(q.xyz);
    float angle = 2.0f * atan2f(imag_len, q.w);

    vec4 angle_axis;
    angle_axis.xyz = vec3_normalize(q.xyz);
    angle_axis.w = angle;
    return angle_axis;
}

static mat3 quat_to_rotation_matrix(quat q) {
    // from cglm/quat/glm_quat_mat3
    float norm = vec4_norm(q);
    float s = norm > 0.0f ? 2.0f / norm : 0.0f;

    float x = q.x;
    float y = q.y;
    float z = q.z;
    float w = q.w;

    float xx, xy, wx;
    float yy, yz, wy;
    float zz, xz, wz;
    xx = s * x * x;
    xy = s * x * y;
    wx = s * w * x;
    yy = s * y * y;
    yz = s * y * z;
    wy = s * w * y;
    zz = s * z * z;
    xz = s * x * z;
    wz = s * w * z;

    mat3 res;
    res.m[0][0] = 1.0f - yy - zz;
    res.m[1][1] = 1.0f - xx - zz;
    res.m[2][2] = 1.0f - xx - yy;

    res.m[0][1] = xy + wz;
    res.m[1][2] = yz + wx;
    res.m[2][0] = xz + wy;

    res.m[1][0] = xy - wz;
    res.m[2][1] = yz - wx;
    res.m[0][2] = xz - wy;
    return res;
}

static quat quat_from_rotation_matrix(mat3 mat) {
    // from cglm/mat3/glm_mat3_quat
    quat res;
    float trace, r, rinv;
    trace = mat.m[0][0] + mat.m[1][1] + mat.m[2][2];
    if (trace >= 0.0f) {
        r = sqrtf(1.0f + trace);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[1][2] - mat.m[2][1]);
        res.v[1] = rinv * (mat.m[2][0] - mat.m[0][2]);
        res.v[2] = rinv * (mat.m[0][1] - mat.m[1][0]);
        res.v[3] = r * 0.5f;
    } else if (mat.m[0][0] >= mat.m[1][1] && mat.m[0][0] >= mat.m[2][2]) {
        r = sqrtf(1.0f - mat.m[1][1] - mat.m[2][2] + mat.m[0][0]);
        rinv = 0.5f / r;

        res.v[0] = r * 0.5f;
        res.v[1] = rinv * (mat.m[0][1] + mat.m[1][0]);
        res.v[2] = rinv * (mat.m[0][2] + mat.m[2][0]);
        res.v[3] = rinv * (mat.m[1][2] - mat.m[2][1]);
    } else if (mat.m[1][1] >= mat.m[2][2]) {
        r = sqrtf(1.0f - mat.m[0][0] - mat.m[2][2] + mat.m[1][1]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[0][1] + mat.m[1][0]);
        res.v[1] = r * 0.5f;
        res.v[2] = rinv * (mat.m[1][2] + mat.m[2][1]);
        res.v[3] = rinv * (mat.m[2][0] - mat.m[0][2]);
    } else {
        r = sqrtf(1.0f - mat.m[0][0] - mat.m[1][1] + mat.m[2][2]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[0][2] + mat.m[2][0]);
        res.v[1] = rinv * (mat.m[1][2] + mat.m[2][1]);
        res.v[2] = r * 0.5f;
        res.v[3] = rinv * (mat.m[0][1] - mat.m[1][0]);
    }

    return res;
}

static quat quat_slerp(quat from, quat to, float t) {
    // from cglm/quat/glm_quat_slerp
    float cos_theta = vec4_dot(from, to);

    if (fabsf(cos_theta) >= 1.0f)
        return from;

    if (cos_theta < 0.0f) {
        from = vec4_neg(from);
        cos_theta = -cos_theta;
    }

    float sin_theta = sqrtf(1.0f - cos_theta * cos_theta);

    /* LERP to avoid zero division */
    if (fabsf(sin_theta) < 0.001f)
        return vec4_lerp(from, to, t);

    /* SLERP */
    float angle = acosf(cos_theta);
    quat q1 = vec4_scale_sca(from, sinf((1.0f - t) * angle));
    quat q2 = vec4_scale_sca(to, sinf(t * angle));

    q1 = vec4_add_vec(q1, q2);
    return vec4_scale_sca(q1, 1.0f / sin_theta);
}

#endif //MATHC_QUAT_QUAT_H
