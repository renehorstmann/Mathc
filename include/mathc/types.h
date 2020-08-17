#ifndef MATHC_TYPES_H
#define MATHC_TYPES_H

typedef union vec2f {
    float v[2];
    struct {
        float v0, v1;
    };
    struct {
        float x, y;
    };
} vec2f;
_Static_assert(sizeof(vec2f) == sizeof(float) * 2, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec2f */
#define Vec2f(vec) (*(vec2f *) (vec))

/** casts a float * to a dereferenced const vec2f */
#define ConstVec2f(vec) (*(const vec2f *) (vec))

#define VEC2F_INIT_ZERO (vec2f) {{0, 0}}
#define VEC2F_INIT_ONE  (vec2f) {{1, 1}}


typedef union mat22f {
    float v[4];
    float m[2][2];
    vec2f col[2];
    struct {
        float v0, v1;
        float v2, v3;
    };
    struct {
        float m00, m01;
        float m10, m11;
    };
} mat22f;
_Static_assert(sizeof(mat22f) == sizeof(float) * 4, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat22f */
#define Mat22f(mat) (*(mat22f *) (mat))

/** casts a float * to a dereferenced const mat22f */
#define ConstMat22f(mat) (*(const mat22f *) (mat))

#define MAT22F_INIT_ZERO (mat22f) {{0, 0,  0, 0}}
#define MAT22F_INIT_ONE  (mat22f) {{1, 1,  1, 1}}
#define MAT22F_INIT_EYE  (mat22f) {{1, 0,  0, 1}}

typedef union vec3f {
    float v[3];
    struct {
        float v0, v1, v2;
    };
    vec2f xy;
    struct {
        float x;
        union {
            struct {
                float y, z;
            };
            vec2f yz;
        };
    };
} vec3f;
_Static_assert(sizeof(vec3f) == sizeof(float) * 3, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec3f */
#define Vec3f(vec) (*(vec3f *) (vec))

/** casts a float * to a dereferenced const vec3f */
#define ConstVec3f(vec) (*(const vec3f *) (vec))

#define VEC3F_INIT_ZERO (vec3f) {{0, 0, 0}}
#define VEC3F_INIT_ONE  (vec3f) {{1, 1, 1}}


typedef union mat33f {
    float v[9];
    float m[3][3];
    vec3f col[3];
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
} mat33f;
_Static_assert(sizeof(mat33f) == sizeof(float) * 9, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat33f */
#define Mat33f(mat) (*(mat33f *) (mat))

/** casts a float * to a dereferenced const mat33f */
#define ConstMat33f(mat) (*(const mat33f *) (mat))

#define MAT33F_INIT_ZERO (mat33f) {{0, 0, 0,  0, 0, 0,  0, 0, 0}}
#define MAT33F_INIT_ONE  (mat33f) {{1, 1, 1,  1, 1, 1,  1, 1, 1}}
#define MAT33F_INIT_EYE  (mat33f) {{1, 0, 0,  0, 1, 0,  0, 0, 1}}


typedef union vec4f {
    float v[4];
    struct {
        float v0, v1, v2, v3;
    };
    vec2f xy;
    vec3f xyz;
    struct {
        float x;
        union {
            struct {
                float y;
                union {
                    struct {
                        float z, w;
                    };
                    vec2f zw;
                };
            };
            vec2f yz;
            vec3f yzw;
        };
    };
} vec4f;
_Static_assert(sizeof(vec4f) == sizeof(float) * 4, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec4f */
#define Vec4f(vec) (*(vec4f *) (vec))

/** casts a float * to a dereferenced const vec4f */
#define ConstVec4f(vec) (*(const vec4f *) (vec))

#define VEC4F_INIT_ZERO (vec4f) {{0, 0, 0, 0}}
#define VEC4F_INIT_ONE  (vec4f) {{1, 1, 1, 1}}


typedef union mat44f {
    float v[16];
    float m[4][4];
    vec4f col[4];
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
} mat44f;
_Static_assert(sizeof(mat44f) == sizeof(float) * 16, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat44f */
#define Mat44f(mat) (*(mat44f *) (mat))

/** casts a float * to a dereferenced const mat44f */
#define ConstMat44f(mat) (*(const mat44f *) (mat))

#define MAT44F_INIT_ZERO (mat44f) {{0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0}}
#define MAT44F_INIT_ONE  (mat44f) {{1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1}}
#define MAT44F_INIT_EYE  (mat44f) {{1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1}}



typedef union vec2d {
    double v[2];
    struct {
        double v0, v1;
    };
    struct {
        double x, y;
    };
} vec2d;
_Static_assert(sizeof(vec2d) == sizeof(double) * 2, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced vec2d */
#define Vec2d(vec) (*(vec2d *) (vec))

/** casts a double * to a dereferenced const vec2d */
#define ConstVec2d(vec) (*(const vec2d *) (vec))

#define VEC2D_INIT_ZERO (vec2d) {{0, 0}}
#define VEC2D_INIT_ONE  (vec2d) {{1, 1}}


typedef union mat22d {
    double v[4];
    double m[2][2];
    vec2d col[2];
    struct {
        double v0, v1;
        double v2, v3;
    };
    struct {
        double m00, m01;
        double m10, m11;
    };
} mat22d;
_Static_assert(sizeof(mat22d) == sizeof(double) * 4, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced mat22d */
#define Mat22d(mat) (*(mat22d *) (mat))

/** casts a double * to a dereferenced const mat22d */
#define ConstMat22d(mat) (*(const mat22d *) (mat))

#define MAT22D_INIT_ZERO (mat22d) {{0, 0,  0, 0}}
#define MAT22D_INIT_ONE  (mat22d) {{1, 1,  1, 1}}
#define MAT22D_INIT_EYE  (mat22d) {{1, 0,  0, 1}}

typedef union vec3d {
    double v[3];
    struct {
        double v0, v1, v2;
    };
    vec2d xy;
    struct {
        double x;
        union {
            struct {
                double y, z;
            };
            vec2d yz;
        };
    };
} vec3d;
_Static_assert(sizeof(vec3d) == sizeof(double) * 3, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced vec3d */
#define Vec3d(vec) (*(vec3d *) (vec))

/** casts a double * to a dereferenced const vec3d */
#define ConstVec3d(vec) (*(const vec3d *) (vec))

#define VEC3D_INIT_ZERO (vec3d) {{0, 0, 0}}
#define VEC3D_INIT_ONE  (vec3d) {{1, 1, 1}}


typedef union mat33d {
    double v[9];
    double m[3][3];
    vec3d col[3];
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
} mat33d;
_Static_assert(sizeof(mat33d) == sizeof(double) * 9, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced mat33d */
#define Mat33d(mat) (*(mat33d *) (mat))

/** casts a double * to a dereferenced const mat33d */
#define ConstMat33d(mat) (*(const mat33d *) (mat))

#define MAT33D_INIT_ZERO (mat33d) {{0, 0, 0,  0, 0, 0,  0, 0, 0}}
#define MAT33D_INIT_ONE  (mat33d) {{1, 1, 1,  1, 1, 1,  1, 1, 1}}
#define MAT33D_INIT_EYE  (mat33d) {{1, 0, 0,  0, 1, 0,  0, 0, 1}}


typedef union vec4d {
    double v[4];
    struct {
        double v0, v1, v2, v3;
    };
    vec2d xy;
    vec3d xyz;
    struct {
        double x;
        union {
            struct {
                double y;
                union {
                    struct {
                        double z, w;
                    };
                    vec2d zw;
                };
            };
            vec2d yz;
            vec3d yzw;
        };
    };
} vec4d;
_Static_assert(sizeof(vec4d) == sizeof(double) * 4, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced vec4d */
#define Vec4d(vec) (*(vec4d *) (vec))

/** casts a double * to a dereferenced const vec4d */
#define ConstVec4d(vec) (*(const vec4d *) (vec))

#define VEC4D_INIT_ZERO (vec4d) {{0, 0, 0, 0}}
#define VEC4D_INIT_ONE  (vec4d) {{1, 1, 1, 1}}


typedef union mat44d {
    double v[16];
    double m[4][4];
    vec4d col[4];
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
} mat44d;
_Static_assert(sizeof(mat44d) == sizeof(double) * 16, "[Mathc] wrong expected size");

/** casts a double * to a dereferenced mat44d */
#define Mat44d(mat) (*(mat44d *) (mat))

/** casts a double * to a dereferenced const mat44d */
#define ConstMat44d(mat) (*(const mat44d *) (mat))

#define MAT44D_INIT_ZERO (mat44d) {{0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0}}
#define MAT44D_INIT_ONE  (mat44d) {{1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1}}
#define MAT44D_INIT_EYE  (mat44d) {{1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1}}



typedef union vec2i {
    int v[2];
    struct {
        int v0, v1;
    };
    struct {
        int x, y;
    };
} vec2i;
_Static_assert(sizeof(vec2i) == sizeof(int) * 2, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced vec2i */
#define Vec2i(vec) (*(vec2i *) (vec))

/** casts a int * to a dereferenced const vec2i */
#define ConstVec2i(vec) (*(const vec2i *) (vec))

#define VEC2I_INIT_ZERO (vec2i) {{0, 0}}
#define VEC2I_INIT_ONE  (vec2i) {{1, 1}}


typedef union mat22i {
    int v[4];
    int m[2][2];
    vec2i col[2];
    struct {
        int v0, v1;
        int v2, v3;
    };
    struct {
        int m00, m01;
        int m10, m11;
    };
} mat22i;
_Static_assert(sizeof(mat22i) == sizeof(int) * 4, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced mat22i */
#define Mat22i(mat) (*(mat22i *) (mat))

/** casts a int * to a dereferenced const mat22i */
#define ConstMat22i(mat) (*(const mat22i *) (mat))

#define MAT22I_INIT_ZERO (mat22i) {{0, 0,  0, 0}}
#define MAT22I_INIT_ONE  (mat22i) {{1, 1,  1, 1}}
#define MAT22I_INIT_EYE  (mat22i) {{1, 0,  0, 1}}

typedef union vec3i {
    int v[3];
    struct {
        int v0, v1, v2;
    };
    vec2i xy;
    struct {
        int x;
        union {
            struct {
                int y, z;
            };
            vec2i yz;
        };
    };
} vec3i;
_Static_assert(sizeof(vec3i) == sizeof(int) * 3, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced vec3i */
#define Vec3i(vec) (*(vec3i *) (vec))

/** casts a int * to a dereferenced const vec3i */
#define ConstVec3i(vec) (*(const vec3i *) (vec))

#define VEC3I_INIT_ZERO (vec3i) {{0, 0, 0}}
#define VEC3I_INIT_ONE  (vec3i) {{1, 1, 1}}


typedef union mat33i {
    int v[9];
    int m[3][3];
    vec3i col[3];
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
} mat33i;
_Static_assert(sizeof(mat33i) == sizeof(int) * 9, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced mat33i */
#define Mat33i(mat) (*(mat33i *) (mat))

/** casts a int * to a dereferenced const mat33i */
#define ConstMat33i(mat) (*(const mat33i *) (mat))

#define MAT33I_INIT_ZERO (mat33i) {{0, 0, 0,  0, 0, 0,  0, 0, 0}}
#define MAT33I_INIT_ONE  (mat33i) {{1, 1, 1,  1, 1, 1,  1, 1, 1}}
#define MAT33I_INIT_EYE  (mat33i) {{1, 0, 0,  0, 1, 0,  0, 0, 1}}


typedef union vec4i {
    int v[4];
    struct {
        int v0, v1, v2, v3;
    };
    vec2i xy;
    vec3i xyz;
    struct {
        int x;
        union {
            struct {
                int y;
                union {
                    struct {
                        int z, w;
                    };
                    vec2i zw;
                };
            };
            vec2i yz;
            vec3i yzw;
        };
    };
} vec4i;
_Static_assert(sizeof(vec4i) == sizeof(int) * 4, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced vec4i */
#define Vec4i(vec) (*(vec4i *) (vec))

/** casts a int * to a dereferenced const vec4i */
#define ConstVec4i(vec) (*(const vec4i *) (vec))

#define VEC4I_INIT_ZERO (vec4i) {{0, 0, 0, 0}}
#define VEC4I_INIT_ONE  (vec4i) {{1, 1, 1, 1}}


typedef union mat44i {
    int v[16];
    int m[4][4];
    vec4i col[4];
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
} mat44i;
_Static_assert(sizeof(mat44i) == sizeof(int) * 16, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced mat44i */
#define Mat44i(mat) (*(mat44i *) (mat))

/** casts a int * to a dereferenced const mat44i */
#define ConstMat44i(mat) (*(const mat44i *) (mat))

#define MAT44I_INIT_ZERO (mat44i) {{0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0}}
#define MAT44I_INIT_ONE  (mat44i) {{1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1}}
#define MAT44I_INIT_EYE  (mat44i) {{1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1}}



#endif //MATHC_TYPES_H
