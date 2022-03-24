#ifndef MATHC_PUBLICTYPES_FLOAT_H
#define MATHC_PUBLICTYPES_FLOAT_H


//
// vectors 2, 3, 4
//

typedef union {
    float v[2];
    struct {
        float v0, v1;
    };
    struct {
        float x, y;
    };
    struct {
        float r, g;
    };
} mathc_vec2;
_Static_assert(sizeof(mathc_vec2) == sizeof(float) * 2, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec2 */
#define MATHC_VEC2(vec) (*(mathc_vec2 *) (vec))


typedef union {
    float v[3];
    struct {
        float v0, v1, v2;
    };
    mathc_vec2 xy;
    struct {
        float x;
        union {
            struct {
                float y, z;
            };
            mathc_vec2 yz;
        };
    };
    mathc_vec2 rg;
    struct {
        float r;
        union {
            struct {
                float g, b;
            };
            mathc_vec2 gb;
        };
    };
} mathc_vec3;
_Static_assert(sizeof(mathc_vec3) == sizeof(float) * 3, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec3 */
#define MATHC_VEC3(vec) (*(mathc_vec3 *) (vec))


typedef union {
    float v[4];
    struct {
        float v0, v1, v2, v3;
    };
    mathc_vec2 xy;
    mathc_vec3 xyz;
    struct {
        float x;
        union {
            struct {
                float y;
                union {
                    struct {
                        float z, w;
                    };
                    mathc_vec2 zw;
                };
            };
            mathc_vec2 yz;
            mathc_vec3 yzw;
        };
    };
    mathc_vec2 rg;
    mathc_vec3 rgb;
    struct {
        float r;
        union {
            struct {
                float g;
                union {
                    struct {
                        float b, a;
                    };
                    mathc_vec2 ba;
                };
            };
            mathc_vec2 gb;
            mathc_vec3 gba;
        };
    };
} mathc_vec4;
_Static_assert(sizeof(mathc_vec4) == sizeof(float) * 4, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec4 */
#define MATHC_VEC4(vec) (*(mathc_vec4 *) (vec))


//
// square matrices 2x2, 3x3, 4x4
//

typedef union {
    float v[4];
    float m[2][2];
    mathc_vec2 col[2];
    struct {
        float v0, v1;
        float v2, v3;
    };
    struct {
        float m00, m01;
        float m10, m11;
    };
} mathc_mat2;
_Static_assert(sizeof(mathc_mat2) == sizeof(float) * 4, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat2 */
#define MATHC_MAT2(mat) (*(mathc_mat2 *) (mat))


typedef union {
    float v[9];
    float m[3][3];
    mathc_vec3 col[3];
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
} mathc_mat3;
_Static_assert(sizeof(mathc_mat3) == sizeof(float) * 9, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat3 */
#define MATHC_MAT3(mat) (*(mathc_mat3 *) (mat))


typedef union {
    float v[16];
    float m[4][4];
    mathc_vec4 col[4];
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
} mathc_mat4;
_Static_assert(sizeof(mathc_mat4) == sizeof(float) * 16, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat4 */
#define MATHC_MAT4(mat) (*(mathc_mat4 *) (mat))


#endif //MATHC_PUBLICTYPES_FLOAT_H
