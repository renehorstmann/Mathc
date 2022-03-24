#ifndef MATHC_PUBLICTYPES_BOOL_H
#define MATHC_PUBLICTYPES_BOOL_H

#include <stdbool.h>

//
// bvectors 2, 3, 4
//

typedef union {
    bool v[2];
    struct {
        bool v0, v1;
    };
    struct {
        bool x, y;
    };
    struct {
        bool r, g;
    };
} mathc_bvec2;
_Static_assert(sizeof(mathc_bvec2) == sizeof(bool) * 2, "[Mathc] wrong expected size");

/** casts a bool * to a dereferenced bvec2 */
#define MATHC_BVEC2(bvec) (*(mathc_bvec2 *) (bvec))


typedef union {
    bool v[3];
    struct {
        bool v0, v1, v2;
    };
    mathc_bvec2 xy;
    struct {
        bool x;
        union {
            struct {
                bool y, z;
            };
            mathc_bvec2 yz;
        };
    };
    mathc_bvec2 rg;
    struct {
        bool r;
        union {
            struct {
                bool g, b;
            };
            mathc_bvec2 gb;
        };
    };
} mathc_bvec3;
_Static_assert(sizeof(mathc_bvec3) == sizeof(bool) * 3, "[Mathc] wrong expected size");

/** casts a bool * to a dereferenced bvec3 */
#define MATHC_BVEC3(bvec) (*(mathc_bvec3 *) (bvec))


typedef union {
    bool v[4];
    struct {
        bool v0, v1, v2, v3;
    };
    mathc_bvec2 xy;
    mathc_bvec3 xyz;
    struct {
        bool x;
        union {
            struct {
                bool y;
                union {
                    struct {
                        bool z, w;
                    };
                    mathc_bvec2 zw;
                };
            };
            mathc_bvec2 yz;
            mathc_bvec3 yzw;
        };
    };
    mathc_bvec2 rg;
    mathc_bvec3 rgb;
    struct {
        bool r;
        union {
            struct {
                bool g;
                union {
                    struct {
                        bool b, a;
                    };
                    mathc_bvec2 ba;
                };
            };
            mathc_bvec2 gb;
            mathc_bvec3 gba;
        };
    };
} mathc_bvec4;
_Static_assert(sizeof(mathc_bvec4) == sizeof(bool) * 4, "[Mathc] wrong expected size");

/** casts a bool * to a dereferenced bvec4 */
#define MATHC_BVEC4(bvec) (*(mathc_bvec4 *) (bvec))


#endif //MATHC_PUBLICTYPES_BOOL_H
