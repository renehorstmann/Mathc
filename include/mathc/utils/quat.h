#ifndef MATHC_QUAT_QUAT_H
#define MATHC_QUAT_QUAT_H

#include <math.h>
#include "../initializer.h"
#include "../types/float.h"
#include "../vec/vec3.h"
#include "../vec/vec4.h"


/** quat = [0, 0, 0, 1] */
static quat quat_eye() {
    return (quat) {{0, 0, 0, 1}};
}


/** dst = -x, -y, -z, w */
static quat quat_conj(quat q) {
    return (quat) {{-q.x, -q.y, -q.z, q.w}};
}

/** dst = -x, -y, -z, w */
static quat quat_conj_v(const float *q) {
    return quat_conj(Quat(q));
}


/** dst = inv(quat) */
static quat quat_inv(quat q) {
    quat conj = quat_conj(q);
    return vec4_scale(conj, 1.0f / vec4_dot(q, q));
}

/** dst = inv(quat) */
static quat quat_inv_v(const float *q) {
    return quat_inv(Quat(q));
}


/** dst = a @ b Hamilton Product */
static quat quat_mul(quat q_a, quat q_b) {
    // from cglm/quat/glm_quat_mul
    quat res;
    res.v[0] = q_a.v[3] * q_b.v[0] + q_a.v[0] * q_b.v[3] + q_a.v[1] * q_b.v[2] - q_a.v[2] * q_b.v[1];
    res.v[1] = q_a.v[3] * q_b.v[1] - q_a.v[0] * q_b.v[2] + q_a.v[1] * q_b.v[3] + q_a.v[2] * q_b.v[0];
    res.v[2] = q_a.v[3] * q_b.v[2] + q_a.v[0] * q_b.v[1] - q_a.v[1] * q_b.v[0] + q_a.v[2] * q_b.v[3];
    res.v[3] = q_a.v[3] * q_b.v[3] - q_a.v[0] * q_b.v[0] - q_a.v[1] * q_b.v[1] - q_a.v[2] * q_b.v[2];
    return res;
}

/** dst = a @ b Hamilton Product */
static quat quat_mul_v(const float *q_a, const float *q_b) {
    return quat_mul(Quat(q_a), Quat(q_b));
}


/** angle_axis = xyz + w=angle in rad */
static quat quat_from_angle_axis(vec4 angle_axis) {
    // from cglm/quat/glm_quatv
    float a = angle_axis.w * 0.5f;
    float c = sca_cos(a);
    float s = sca_sin(a);

    vec3 axis = vec3_normalize(angle_axis.xyz);

    quat res;
    res.xyz = vec3_scale(axis, s);
    res.w = c;
    return res;
}

/** angle_axis = xyz + w=angle in rad */
static quat quat_from_angle_axis_v(const float *angle_axis) {
    return quat_from_angle_axis(Quat(angle_axis));
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
    float angle = 2.0f * sca_atan2(imag_len, q.w);

    vec4 angle_axis;
    angle_axis.xyz = vec3_normalize(q.xyz);
    angle_axis.w = angle;
    return angle_axis;
}

/** angle_axis = xyz + w=angle in rad */
static vec4 quat_to_angle_axis_v(const float *q) {
    return quat_to_angle_axis(Quat(q));
}

/** returns the orientation of quat as 3*3 rotation matrix */
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

/** returns the orientation of quat as 3*3 rotation matrix */
static mat3 quat_to_rotation_matrix_v(const float *q) {
    return quat_to_rotation_matrix(Quat(q));
}


/** returns the orientation of a 3*3 rotation matrix as quat */
static quat quat_from_rotation_matrix(mat3 mat) {
    // from cglm/mat3/glm_mat3_quat
    quat res;
    float trace, r, rinv;
    trace = mat.m[0][0] + mat.m[1][1] + mat.m[2][2];
    if (trace >= 0.0f) {
        r = sca_sqrt(1.0f + trace);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[1][2] - mat.m[2][1]);
        res.v[1] = rinv * (mat.m[2][0] - mat.m[0][2]);
        res.v[2] = rinv * (mat.m[0][1] - mat.m[1][0]);
        res.v[3] = r * 0.5f;
    } else if (mat.m[0][0] >= mat.m[1][1] && mat.m[0][0] >= mat.m[2][2]) {
        r = sca_sqrt(1.0f - mat.m[1][1] - mat.m[2][2] + mat.m[0][0]);
        rinv = 0.5f / r;

        res.v[0] = r * 0.5f;
        res.v[1] = rinv * (mat.m[0][1] + mat.m[1][0]);
        res.v[2] = rinv * (mat.m[0][2] + mat.m[2][0]);
        res.v[3] = rinv * (mat.m[1][2] - mat.m[2][1]);
    } else if (mat.m[1][1] >= mat.m[2][2]) {
        r = sca_sqrt(1.0f - mat.m[0][0] - mat.m[2][2] + mat.m[1][1]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[0][1] + mat.m[1][0]);
        res.v[1] = r * 0.5f;
        res.v[2] = rinv * (mat.m[1][2] + mat.m[2][1]);
        res.v[3] = rinv * (mat.m[2][0] - mat.m[0][2]);
    } else {
        r = sca_sqrt(1.0f - mat.m[0][0] - mat.m[1][1] + mat.m[2][2]);
        rinv = 0.5f / r;

        res.v[0] = rinv * (mat.m[0][2] + mat.m[2][0]);
        res.v[1] = rinv * (mat.m[1][2] + mat.m[2][1]);
        res.v[2] = r * 0.5f;
        res.v[3] = rinv * (mat.m[0][1] - mat.m[1][0]);
    }

    return res;
}

/** returns the orientation of a 3*3 rotation matrix as quat */
static quat quat_from_rotation_matrix_v(const float *mat_3) {
    return quat_from_rotation_matrix(Mat3(mat_3));
}

/** returns the orientation of a 3*3 rotation matrix as quat */
static void quat_pose_from_pose_matrix(vec3 *out_pose_pos, quat *out_pose_quat, mat4 mat_pose) {
    *out_pose_pos = mat_pose.col[3].xyz;
    *out_pose_quat = quat_from_rotation_matrix(mat4_get_upper_left3(mat_pose));
}

/** returns the orientation of a 3*3 rotation matrix as quat */
static void quat_pose_from_pose_matrix_v(float *out_pose_pos3, float *out_pose_quat, const float *mat_pose44) {
    quat_pose_from_pose_matrix((vec3 *) out_pose_pos3, (quat *) out_pose_quat, Mat4(mat_pose44));
}

/** returns the orientation of a 3*3 rotation matrix as quat */
static mat4 quat_pose_to_pose_matrix(vec3 pose_pos, quat pose_quat) {
    mat4 pose = mat4_eye();
    pose.col[3].xyz = pose_pos;
    mat4_set_this_upper_left3(&pose, quat_to_rotation_matrix(pose_quat));
    return pose;
}

/** returns the orientation of a 3*3 rotation matrix as quat */
static mat4 quat_pose_to_pose_matrix_v(const float *pose_pos3, const float *pose_quat) {
    return quat_pose_to_pose_matrix(Vec3(pose_pos3), Quat(pose_quat));
}


/** returns the rotated position pos with the rotation of q */
static vec3 quat_rotate_pos(quat q, vec3 pos) {
    vec4 p;
    p.xyz = pos;
    p.w = 0;
    // res = q @ pos(w=0) @ conj(q)
    return quat_mul(q, quat_mul(p, quat_conj(q))).xyz;
}

/** returns the rotated position pos with the rotation of q */
static vec3 quat_rotate_pos_v(const float *q, const float *pos3) {
    return quat_rotate_pos(Quat(q), Vec3(pos3));
}


/**
 * Inverts the given pose (position + orientation)
 * Same as inverting a mat4 pose
 */
static void quat_pose_inv(vec3 *out_pose_inv_pos, quat *out_pose_inv_quat, vec3 pose_pos, quat pose_quat) {
    *out_pose_inv_quat = quat_inv(pose_quat);
    *out_pose_inv_pos = vec3_neg(quat_rotate_pos(*out_pose_inv_quat, pose_pos));
}

/**
 * Inverts the given pose (position + orientation)
 * Same as inverting a mat4 pose
 */
static void quat_pose_inv_v(float *out_pose_inv_pos3, float *out_pose_inv_quat,
                            const float *pose_pos3, const float *pose_quat) {
    quat_pose_inv((vec3 *) out_pose_inv_pos3, (quat *) out_pose_inv_quat, Vec3(pose_pos3), Quat(pose_quat));
}


/** returns pos transform by pose a @ b */
static vec3 quat_pose_transform_pos(vec3 a_pos, quat a_quat, vec3 pos_b) {
    return vec3_add_vec(a_pos, quat_rotate_pos(a_quat, pos_b));
}

/** returns the transform of the position pos by the pose of pose_pos and pose_quat */
static vec3 quat_pose_transform_pos_v(const float *a_pos3, const float *a_quat, const float *pos3_b) {
    return quat_pose_transform_pos(Vec3(a_pos3), Quat(a_quat), Vec3(pos3_b));
}


/** returns pose transform of a @ b */
static void quat_pose_transform_pose(vec3 *out_pos, quat *out_quat,
                                     vec3 a_pos, quat a_quat,
                                     vec3 b_pos, quat b_quat) {
    *out_pos = quat_pose_transform_pos(a_pos, a_quat, b_pos);
    *out_quat = quat_mul(a_quat, b_quat);
}

/** returns pose transform of a @ b */
static void quat_pose_transform_pose_v(float *out_pos3, float *out_quat,
                                       const float *a_pos3, const float *a_quat,
                                       const float *b_pos3, const float *b_quat) {
    quat_pose_transform_pose((vec3*) out_pos3, (quat*) out_quat, 
                             Vec3(a_pos3), Quat(a_quat), Vec3(b_pos3), Quat(b_quat));
}


/** spherical linear interpolation between a and b, t in [0 : 1] */
static quat quat_slerp(quat q_a, quat q_b, float t) {
    // from cglm/quat/glm_quat_slerp
    float cos_theta = vec4_dot(q_a, q_b);

    if (sca_abs(cos_theta) >= 1.0f)
        return q_a;

    if (cos_theta < 0.0f) {
        q_a = vec4_neg(q_a);
        cos_theta = -cos_theta;
    }

    float sin_theta = sca_sqrt(1.0f - cos_theta * cos_theta);

    /* LERP q_b avoid zero division */
    if (sca_abs(sin_theta) < 0.001f)
        return vec4_mix(q_a, q_b, t);

    /* SLERP */
    float angle = sca_acos(cos_theta);
    quat q1 = vec4_scale(q_a, sca_sin((1.0f - t) * angle));
    quat q2 = vec4_scale(q_b, sca_sin(t * angle));

    q1 = vec4_add_vec(q1, q2);
    return vec4_scale(q1, 1.0f / sin_theta);
}

/** spherical linear interpolation between a and b, t in [0 : 1] */
static quat quat_slerp_v(const float *q_a, const float *q_b, float t) {
    return quat_slerp(Quat(q_a), Quat(q_b), t);
}


#endif //MATHC_QUAT_QUAT_H
