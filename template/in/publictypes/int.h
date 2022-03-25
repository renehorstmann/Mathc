#ifndef MATHC_PUBLICTYPES_INT_H
#define MATHC_PUBLICTYPES_INT_H


//
// vectors 2, 3, 4
//

typedef union {
    int v[2];
    struct {
        int v0, v1;
    };
    struct {
        int x, y;
    };
    struct {
        int r, g;
    };
} mathc_ivec2;
_Static_assert(sizeof(mathc_ivec2) == sizeof(int) * 2, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced ivec2 */
#define MATHC_VEC2(ivec) (*(mathc_ivec2 *) (ivec))


typedef union {
    int v[3];
    struct {
        int v0, v1, v2;
    };
    mathc_ivec2 xy;
    struct {
        int x;
        union {
            struct {
                int y, z;
            };
            mathc_ivec2 yz;
        };
    };
    mathc_ivec2 rg;
    struct {
        int r;
        union {
            struct {
                int g, b;
            };
            mathc_ivec2 gb;
        };
    };
} mathc_ivec3;
_Static_assert(sizeof(mathc_ivec3) == sizeof(int) * 3, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced ivec3 */
#define MATHC_VEC3(ivec) (*(mathc_ivec3 *) (ivec))


typedef union {
    int v[4];
    struct {
        int v0, v1, v2, v3;
    };
    mathc_ivec2 xy;
    mathc_ivec3 xyz;
    struct {
        int x;
        union {
            struct {
                int y;
                union {
                    struct {
                        int z, w;
                    };
                    mathc_ivec2 zw;
                };
            };
            mathc_ivec2 yz;
            mathc_ivec3 yzw;
        };
    };
    mathc_ivec2 rg;
    mathc_ivec3 rgb;
    struct {
        int r;
        union {
            struct {
                int g;
                union {
                    struct {
                        int b, a;
                    };
                    mathc_ivec2 ba;
                };
            };
            mathc_ivec2 gb;
            mathc_ivec3 gba;
        };
    };
} mathc_ivec4;
_Static_assert(sizeof(mathc_ivec4) == sizeof(int) * 4, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced ivec4 */
#define MATHC_VEC4(ivec) (*(mathc_ivec4 *) (ivec))


//
// square matrices 2x2, 3x3, 4x4
//

typedef union {
    int v[4];
    int m[2][2];
    mathc_ivec2 col[2];
    struct {
        int v0, v1;
        int v2, v3;
    };
    struct {
        int m00, m01;
        int m10, m11;
    };
} mathc_imat2;
_Static_assert(sizeof(mathc_imat2) == sizeof(int) * 4, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced imat2 */
#define MATHC_IMAT2(imat) (*(mathc_imat2 *) (imat))


typedef union {
    int v[9];
    int m[3][3];
    mathc_ivec3 col[3];
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
} mathc_imat3;
_Static_assert(sizeof(mathc_imat3) == sizeof(int) * 9, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced imat3 */
#define MATHC_IMAT3(imat) (*(mathc_imat3 *) (imat))


typedef union {
    int v[16];
    int m[4][4];
    mathc_ivec4 col[4];
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
} mathc_imat4;
_Static_assert(sizeof(mathc_imat4) == sizeof(int) * 16, "[Mathc] wrong expected size");

/** casts a int * to a dereferenced imat4 */
#define MATHC_IMAT4(imat) (*(mathc_imat4 *) (imat))


#endif //MATHC_PUBLICTYPES_INT_H
