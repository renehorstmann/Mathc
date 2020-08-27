#ifndef MATHC_TYPES_H
#define MATHC_TYPES_H

typedef union vec2 {
    float v[2];
    struct {
        float v0, v1;
    };
    struct {
        float x, y;
    };
} vec2;
_Static_assert(sizeof(vec2) == sizeof(float) * 2, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec2 */
#define Vec2(vec) (*(vec2 *) (vec))

/** casts a float * to a dereferenced const vec2 */
#define ConstVec2(vec) (*(const vec2 *) (vec))


typedef union mat2 {
    float v[4];
    float m[2][2];
    vec2 col[2];
    struct {
        float v0, v1;
        float v2, v3;
    };
    struct {
        float m00, m01;
        float m10, m11;
    };
} mat2;
_Static_assert(sizeof(mat2) == sizeof(float) * 4, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat2 */
#define Mat2(mat) (*(mat2 *) (mat))

/** casts a float * to a dereferenced const mat2 */
#define ConstMat2(mat) (*(const mat2 *) (mat))

typedef union vec3 {
    float v[3];
    struct {
        float v0, v1, v2;
    };
    vec2 xy;
    struct {
        float x;
        union {
            struct {
                float y, z;
            };
            vec2 yz;
        };
    };
} vec3;
_Static_assert(sizeof(vec3) == sizeof(float) * 3, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec3 */
#define Vec3(vec) (*(vec3 *) (vec))

/** casts a float * to a dereferenced const vec3 */
#define ConstVec3(vec) (*(const vec3 *) (vec))


typedef union mat3 {
    float v[9];
    float m[3][3];
    vec3 col[3];
    struct {
        float v0, v1, v2;
        float v3, v4, v5;
        float v6, v7, v8;
    };
    struct {
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
    };
} mat3;
_Static_assert(sizeof(mat3) == sizeof(float) * 9, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat3 */
#define Mat3(mat) (*(mat3 *) (mat))

/** casts a float * to a dereferenced const mat3 */
#define ConstMat3(mat) (*(const mat3 *) (mat))


typedef union vec4 {
    float v[4];
    struct {
        float v0, v1, v2, v3;
    };
    vec2 xy;
    vec3 xyz;
    struct {
        float x;
        union {
            struct {
                float y;
                union {
                    struct {
                        float z, w;
                    };
                    vec2 zw;
                };
            };
            vec2 yz;
            vec3 yzw;
        };
    };
} vec4;
_Static_assert(sizeof(vec4) == sizeof(float) * 4, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec4 */
#define Vec4(vec) (*(vec4 *) (vec))

/** casts a float * to a dereferenced const vec4 */
#define ConstVec4(vec) (*(const vec4 *) (vec))


typedef union mat4 {
    float v[16];
    float m[4][4];
    vec4 col[4];
    struct {
        float v0, v1, v2, v3;
        float v4, v5, v6, v7;
        float v8, v9, v10, v11;
        float v12, v13, v14, v15;
    };
    struct {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    };
} mat4;
_Static_assert(sizeof(mat4) == sizeof(float) * 16, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat4 */
#define Mat4(mat) (*(mat4 *) (mat))

/** casts a float * to a dereferenced const mat4 */
#define ConstMat4(mat) (*(const mat4 *) (mat))


typedef union dvec2 {
    double v[2];
    struct {
        double v0, v1;
    };
    struct {
        double x, y;
    };
} dvec2;
_Static_assert(sizeof(dvec2) == sizeof(double) * 2, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced dvec2 */
#define DVec2(vec) (*(dvec2 *) (vec))

/** casts a double * to a dereferenced const dvec2 */
#define ConstDVec2(vec) (*(const dvec2 *) (vec))


typedef union dmat2 {
    double v[4];
    double m[2][2];
    dvec2 col[2];
    struct {
        double v0, v1;
        double v2, v3;
    };
    struct {
        double m00, m01;
        double m10, m11;
    };
} dmat2;
_Static_assert(sizeof(dmat2) == sizeof(double) * 4, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced dmat2 */
#define DMat2(mat) (*(dmat2 *) (mat))

/** casts a double * to a dereferenced const dmat2 */
#define ConstDMat2(mat) (*(const dmat2 *) (mat))

typedef union dvec3 {
    double v[3];
    struct {
        double v0, v1, v2;
    };
    dvec2 xy;
    struct {
        double x;
        union {
            struct {
                double y, z;
            };
            dvec2 yz;
        };
    };
} dvec3;
_Static_assert(sizeof(dvec3) == sizeof(double) * 3, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced dvec3 */
#define DVec3(vec) (*(dvec3 *) (vec))

/** casts a double * to a dereferenced const dvec3 */
#define ConstDVec3(vec) (*(const dvec3 *) (vec))


typedef union dmat3 {
    double v[9];
    double m[3][3];
    dvec3 col[3];
    struct {
        double v0, v1, v2;
        double v3, v4, v5;
        double v6, v7, v8;
    };
    struct {
        double m00, m01, m02;
        double m10, m11, m12;
        double m20, m21, m22;
    };
} dmat3;
_Static_assert(sizeof(dmat3) == sizeof(double) * 9, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced dmat3 */
#define DMat3(mat) (*(dmat3 *) (mat))

/** casts a double * to a dereferenced const dmat3 */
#define ConstDMat3(mat) (*(const dmat3 *) (mat))


typedef union dvec4 {
    double v[4];
    struct {
        double v0, v1, v2, v3;
    };
    dvec2 xy;
    dvec3 xyz;
    struct {
        double x;
        union {
            struct {
                double y;
                union {
                    struct {
                        double z, w;
                    };
                    dvec2 zw;
                };
            };
            dvec2 yz;
            dvec3 yzw;
        };
    };
} dvec4;
_Static_assert(sizeof(dvec4) == sizeof(double) * 4, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced dvec4 */
#define DVec4(vec) (*(dvec4 *) (vec))

/** casts a double * to a dereferenced const dvec4 */
#define ConstDVec4(vec) (*(const dvec4 *) (vec))


typedef union dmat4 {
    double v[16];
    double m[4][4];
    dvec4 col[4];
    struct {
        double v0, v1, v2, v3;
        double v4, v5, v6, v7;
        double v8, v9, v10, v11;
        double v12, v13, v14, v15;
    };
    struct {
        double m00, m01, m02, m03;
        double m10, m11, m12, m13;
        double m20, m21, m22, m23;
        double m30, m31, m32, m33;
    };
} dmat4;
_Static_assert(sizeof(dmat4) == sizeof(double) * 16, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced dmat4 */
#define DMat4(mat) (*(dmat4 *) (mat))

/** casts a double * to a dereferenced const dmat4 */
#define ConstDMat4(mat) (*(const dmat4 *) (mat))


typedef union ivec2 {
    int v[2];
    struct {
        int v0, v1;
    };
    struct {
        int x, y;
    };
} ivec2;
_Static_assert(sizeof(ivec2) == sizeof(int) * 2, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced ivec2 */
#define IVec2(vec) (*(ivec2 *) (vec))

/** casts a int * to a dereferenced const ivec2 */
#define ConstIVec2(vec) (*(const ivec2 *) (vec))


typedef union imat2 {
    int v[4];
    int m[2][2];
    ivec2 col[2];
    struct {
        int v0, v1;
        int v2, v3;
    };
    struct {
        int m00, m01;
        int m10, m11;
    };
} imat2;
_Static_assert(sizeof(imat2) == sizeof(int) * 4, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced imat2 */
#define IMat2(mat) (*(imat2 *) (mat))

/** casts a int * to a dereferenced const imat2 */
#define ConstIMat2(mat) (*(const imat2 *) (mat))

typedef union ivec3 {
    int v[3];
    struct {
        int v0, v1, v2;
    };
    ivec2 xy;
    struct {
        int x;
        union {
            struct {
                int y, z;
            };
            ivec2 yz;
        };
    };
} ivec3;
_Static_assert(sizeof(ivec3) == sizeof(int) * 3, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced ivec3 */
#define IVec3(vec) (*(ivec3 *) (vec))

/** casts a int * to a dereferenced const ivec3 */
#define ConstIVec3(vec) (*(const ivec3 *) (vec))


typedef union imat3 {
    int v[9];
    int m[3][3];
    ivec3 col[3];
    struct {
        int v0, v1, v2;
        int v3, v4, v5;
        int v6, v7, v8;
    };
    struct {
        int m00, m01, m02;
        int m10, m11, m12;
        int m20, m21, m22;
    };
} imat3;
_Static_assert(sizeof(imat3) == sizeof(int) * 9, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced imat3 */
#define IMat3(mat) (*(imat3 *) (mat))

/** casts a int * to a dereferenced const imat3 */
#define IConstMat3(mat) (*(const imat3 *) (mat))


typedef union ivec4 {
    int v[4];
    struct {
        int v0, v1, v2, v3;
    };
    ivec2 xy;
    ivec3 xyz;
    struct {
        int x;
        union {
            struct {
                int y;
                union {
                    struct {
                        int z, w;
                    };
                    ivec2 zw;
                };
            };
            ivec2 yz;
            ivec3 yzw;
        };
    };
} ivec4;
_Static_assert(sizeof(ivec4) == sizeof(int) * 4, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced ivec4 */
#define IVec4(vec) (*(ivec4 *) (vec))

/** casts a int * to a dereferenced const ivec4 */
#define ConstIVec4(vec) (*(const ivec4 *) (vec))


typedef union imat4 {
    int v[16];
    int m[4][4];
    ivec4 col[4];
    struct {
        int v0, v1, v2, v3;
        int v4, v5, v6, v7;
        int v8, v9, v10, v11;
        int v12, v13, v14, v15;
    };
    struct {
        int m00, m01, m02, m03;
        int m10, m11, m12, m13;
        int m20, m21, m22, m23;
        int m30, m31, m32, m33;
    };
} imat4;
_Static_assert(sizeof(imat4) == sizeof(int) * 16, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced imat4 */
#define IMat4(mat) (*(imat4 *) (mat))

/** casts a int * to a dereferenced const imat4 */
#define ConstIMat4(mat) (*(const imat4 *) (mat))


// quaternion type
typedef vec4 quat;
#define Quat Vec4
#define ConstQuat ConstVec4
typedef dvec4 dquat;
#define DQuat DVec4
#define ConstDQuat ConstDVec4


// initializer

#define VEC2_INIT_ZERO   {{0, 0}}
#define VEC2_INIT_ONE    {{1, 1}}
#define VEC2_INIT_UNIT_X {{1, 0}};
#define VEC2_INIT_UNIT_Y {{0, 1}};

#define VEC3_INIT_ZERO   {{0, 0, 0}}
#define VEC3_INIT_ONE    {{1, 1, 1}}
#define VEC3_INIT_UNIT_X {{1, 0, 0}};
#define VEC3_INIT_UNIT_Y {{0, 1, 0}};
#define VEC3_INIT_UNIT_Z {{0, 0, 1}};

#define VEC4_INIT_ZERO   {{0, 0, 0, 0}}
#define VEC4_INIT_ONE    {{1, 1, 1, 1}}
#define VEC4_INIT_UNIT_X {{1, 0, 0, 0}};
#define VEC4_INIT_UNIT_Y {{0, 1, 0, 0}};
#define VEC4_INIT_UNIT_Z {{0, 0, 1, 0}};
#define VEC4_INIT_UNIT_W {{0, 0, 0, 1}};

#define MAT2_INIT_ZERO   {{0, 0,  0, 0}}
#define MAT2_INIT_ONE    {{1, 1,  1, 1}}
#define MAT2_INIT_EYE    {{1, 0,  0, 1}}

#define MAT3_INIT_ZERO   {{0, 0, 0,  0, 0, 0,  0, 0, 0}}
#define MAT3_INIT_ONE    {{1, 1, 1,  1, 1, 1,  1, 1, 1}}
#define MAT3_INIT_EYE    {{1, 0, 0,  0, 1, 0,  0, 0, 1}}

#define MAT4_INIT_ZERO   {{0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0}}
#define MAT4_INIT_ONE    {{1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1}}
#define MAT4_INIT_EYE    {{1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1}}

// xyzw
#define QUAT4_INIT_EYE {{0, 0, 0, 1}}

#endif //MATHC_TYPES_H
