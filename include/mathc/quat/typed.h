#ifndef MATHC_QUAT_TYPED_H
#define MATHC_QUAT_TYPED_H


#include "../types.h"
#include "../vec/typed.h"
#include <math.h>   //sqrt(f)

//
// this header file has the following content:
// 1. typed functions for float[4] as quatf
// 2. typed functions for double[4] as quatd
//


//
// quatf = float
//

/** quatf = [1, 0, 0, 0] */
static quatf quatf_eye() {
    return (quatf) QUAT4_INIT_EYE;
}

/** dst = -x, -y, -z, w */
static quatf quatf_conjugate(quatf quat) {
    return (quatf) {{-quat.x, -quat.y, -quat.z, quat.w}};
}

/** dst = inv(quat) */
static quatf quatf_invert(quatf quat) {
    quatf conj = quatf_conjugate(quat);
    return vec4f_scale_sca(conj, 1.0f / vec4f_dot(quat, quat));
}

/** dst = a @ b Hamilton Product */
static quatf quatf_mul(quatf a, quatf b) {
    // from cglm/quat/glm_quat_mul
    quatf res;
    res.v[0] = a.v[3] * b.v[0] + a.v[0] * b.v[3] + a.v[1] * b.v[2] - a.v[2] * b.v[1];
    res.v[1] = a.v[3] * b.v[1] - a.v[0] * b.v[2] + a.v[1] * b.v[3] + a.v[2] * b.v[0];
    res.v[2] = a.v[3] * b.v[2] + a.v[0] * b.v[1] - a.v[1] * b.v[0] + a.v[2] * b.v[3];
    res.v[3] = a.v[3] * b.v[3] - a.v[0] * b.v[0] - a.v[1] * b.v[1] - a.v[2] * b.v[2];
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static quatf quatf_from_angle_axis(vec4f angle_axis) {
    // from cglm/quat/glm_quatv
    float a = angle_axis.w * 0.5f;
    float c = cosf(a);
    float s = sinf(a);

    vec3f axis = vec3f_normalize(angle_axis.xyz);

    quatf res;
    res.xyz = vec3f_scale_sca(axis, s);
    res.w = c;
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static vec4f quatf_to_angle_axis(quatf quat) {
    // from cglm/quat/glm_quat_angle
    /*
     sin(theta / 2) = length(x*x + y*y + z*z)
     cos(theta / 2) = w
     theta          = 2 * atan(sin(theta / 2) / cos(theta / 2))
     */
    float imag_len = vec3f_norm(quat.xyz);
    float angle = 2.0f * atan2f(imag_len, quat.w);

    vec4f angle_axis;
    angle_axis.xyz = vec3f_normalize(quat.xyz);
    angle_axis.w = angle;
    return angle_axis;
}

static mat33f quatf_to_rotation_matrix(quatf quat) {
    // from cglm/quat/glm_quat_mat3
    float norm = vec4f_norm(quat);
    float s = norm > 0.0f ? 2.0f / norm : 0.0f;

    float x = quat.x;
    float y = quat.y;
    float z = quat.z;
    float w = quat.w;

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

    mat33f res;
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

static quatf quatf_from_rotation_matrix(mat33f mat) {
    // from cglm/mat3/glm_mat3_quat
    quatf res;
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

static quatf quatf_slerp(quatf from, quatf to, float t) {
    // from cglm/quat/glm_quat_slerp
    float cos_theta = vec4f_dot(from, to);

    if (fabsf(cos_theta) >= 1.0f)
        return from;

    if (cos_theta < 0.0f) {
        from = vec4f_neg(from);
        cos_theta = -cos_theta;
    }

    float sin_theta = sqrtf(1.0f - cos_theta * cos_theta);

    /* LERP to avoid zero division */
    if (fabsf(sin_theta) < 0.001f)
        return vec4f_lerp(from, to, t);

    /* SLERP */
    float angle = acosf(cos_theta);
    quatf q1 = vec4f_scale_sca(from, sinf((1.0f - t) * angle));
    quatf q2 = vec4f_scale_sca(to, sinf(t * angle));

    q1 = vec4f_add_vec(q1, q2);
    return vec4f_scale_sca(q1, 1.0f / sin_theta);
}



//
// quatd = double
//

/** quatd = [1, 0, 0, 0] */
static quatd quatd_eye() {
    return (quatd) QUAT4_INIT_EYE;
}

/** dst = -x, -y, -z, w */
static quatd quatd_conjugate(quatd quat) {
    return (quatd) {{-quat.x, -quat.y, -quat.z, quat.w}};
}

/** dst = inv(quat) */
static quatd quatd_invert(quatd quat) {
    quatd conj = quatd_conjugate(quat);
    return vec4d_scale_sca(conj, 1.0f / vec4d_dot(quat, quat));
}

/** dst = a @ b Hamilton Product */
static quatd quatd_mul(quatd a, quatd b) {
    // from cglm/quat/glm_quat_mul
    quatd res;
    res.v[0] = a.v[3] * b.v[0] + a.v[0] * b.v[3] + a.v[1] * b.v[2] - a.v[2] * b.v[1];
    res.v[1] = a.v[3] * b.v[1] - a.v[0] * b.v[2] + a.v[1] * b.v[3] + a.v[2] * b.v[0];
    res.v[2] = a.v[3] * b.v[2] + a.v[0] * b.v[1] - a.v[1] * b.v[0] + a.v[2] * b.v[3];
    res.v[3] = a.v[3] * b.v[3] - a.v[0] * b.v[0] - a.v[1] * b.v[1] - a.v[2] * b.v[2];
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static quatd quatd_from_angle_axis(vec4d angle_axis) {
    // from cglm/quat/glm_quatv
    double a = angle_axis.w * 0.5f;
    double c = cos(a);
    double s = sin(a);

    vec3d axis = vec3d_normalize(angle_axis.xyz);

    quatd res;
    res.xyz = vec3d_scale_sca(axis, s);
    res.w = c;
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static vec4d quatd_to_angle_axis(quatd quat) {
    // from cglm/quat/glm_quat_angle
    /*
     sin(theta / 2) = length(x*x + y*y + z*z)
     cos(theta / 2) = w
     theta          = 2 * atan(sin(theta / 2) / cos(theta / 2))
     */
    double imag_len = vec3d_norm(quat.xyz);
    double angle = 2.0f * atan2(imag_len, quat.w);

    vec4d angle_axis;
    angle_axis.xyz = vec3d_normalize(quat.xyz);
    angle_axis.w = angle;
    return angle_axis;
}

static mat33d quatd_to_rotation_matrix(quatd quat) {
    // from cglm/quat/glm_quat_mat3
    double norm = vec4d_norm(quat);
    double s = norm > 0.0f ? 2.0f / norm : 0.0f;

    double x = quat.x;
    double y = quat.y;
    double z = quat.z;
    double w = quat.w;

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

    mat33d res;
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

static quatd quatd_from_rotation_matrix(mat33d mat) {
    // from cglm/mat3/glm_mat3_quat
    quatd res;
    double trace, r, rinv;
    trace = mat.m[0][0] + mat.m[1][1] + mat.m[2][2];
    if (trace >= 0.0f) {
        r = sqrt(1.0 + trace);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[1][2] - mat.m[2][1]);
        res.v[1] = rinv * (mat.m[2][0] - mat.m[0][2]);
        res.v[2] = rinv * (mat.m[0][1] - mat.m[1][0]);
        res.v[3] = r * 0.5f;
    } else if (mat.m[0][0] >= mat.m[1][1] && mat.m[0][0] >= mat.m[2][2]) {
        r = sqrt(1.0 - mat.m[1][1] - mat.m[2][2] + mat.m[0][0]);
        rinv = 0.5f / r;

        res.v[0] = r * 0.5f;
        res.v[1] = rinv * (mat.m[0][1] + mat.m[1][0]);
        res.v[2] = rinv * (mat.m[0][2] + mat.m[2][0]);
        res.v[3] = rinv * (mat.m[1][2] - mat.m[2][1]);
    } else if (mat.m[1][1] >= mat.m[2][2]) {
        r = sqrt(1.0 - mat.m[0][0] - mat.m[2][2] + mat.m[1][1]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[0][1] + mat.m[1][0]);
        res.v[1] = r * 0.5f;
        res.v[2] = rinv * (mat.m[1][2] + mat.m[2][1]);
        res.v[3] = rinv * (mat.m[2][0] - mat.m[0][2]);
    } else {
        r = sqrt(1.0 - mat.m[0][0] - mat.m[1][1] + mat.m[2][2]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[0][2] + mat.m[2][0]);
        res.v[1] = rinv * (mat.m[1][2] + mat.m[2][1]);
        res.v[2] = r * 0.5f;
        res.v[3] = rinv * (mat.m[0][1] - mat.m[1][0]);
    }

    return res;
}

static quatd quatd_slerp(quatd from, quatd to, double t) {
    // from cglm/quat/glm_quat_slerp
    double cos_theta = vec4d_dot(from, to);

    if (fabs(cos_theta) >= 1.0f)
        return from;

    if (cos_theta < 0.0f) {
        from = vec4d_neg(from);
        cos_theta = -cos_theta;
    }

    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    /* LERP to avoid zero division */
    if (fabs(sin_theta) < 0.001f)
        return vec4d_lerp(from, to, t);

    /* SLERP */
    double angle = acos(cos_theta);
    quatd q1 = vec4d_scale_sca(from, sin((1.0 - t) * angle));
    quatd q2 = vec4d_scale_sca(to, sin(t * angle));

    q1 = vec4d_add_vec(q1, q2);
    return vec4d_scale_sca(q1, 1.0 / sin_theta);
}



#endif //MATHC_QUAT_TYPED_H
