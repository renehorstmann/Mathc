#ifndef MATHC_PUBLICTYPES_VEC__X___H
#define MATHC_PUBLICTYPES_VEC__X___H

/*/ 0 /*/   // template file!
/*/ 0 /*/   //
/*/ 0 /*/   // __X__ will be replaced by X=[2, 3, 4, ...]
/*/ 0 /*/   //
/*/ 0 /*/   // all lines starting with "/*/ cond /*/[//]" may be removed
/*/ 0 /*/   // if cond is true:
/*/ 0 /*/   //      only the condition comment will be removed "/*/ cond /*/)"
/*/ 0 /*/   // if cond is false:
/*/ 0 /*/   //      the whole line will be removed
/*/ 0 /*/
/*/ 0 /*/   // the following setup is just here to pleasure an ide
/*/ 0 /*/ #define __X__ 4

/*/ bool /*/#include <stdbool.h>

/*/ X==2 /*/typedef union {
/*/ X==2 /*/    float v[2];
/*/ X==2 /*/    struct {
/*/ X==2 /*/        float v0, v1;
/*/ X==2 /*/    };
/*/ X==2 /*/    struct {
/*/ X==2 /*/        float x, y;
/*/ X==2 /*/    };
/*/ X==2 /*/    struct {
/*/ X==2 /*/        float r, g;
/*/ X==2 /*/    };
/*/ X==2 /*/} mathc_vec2;


/*/ X==3 /*///#include "vec2.h"
/*/ X==3 /*/typedef union {
/*/ X==3 /*/    float v[3];
/*/ X==3 /*/    struct {
/*/ X==3 /*/        float v0, v1, v2;
/*/ X==3 /*/    };
/*/ X==3 /*/    mathc_vec2 xy;
/*/ X==3 /*/    struct {
/*/ X==3 /*/        float x;
/*/ X==3 /*/        union {
/*/ X==3 /*/            struct {
/*/ X==3 /*/                float y, z;
/*/ X==3 /*/            };
/*/ X==3 /*/            mathc_vec2 yz;
/*/ X==3 /*/        };
/*/ X==3 /*/    };
/*/ X==3 /*/    mathc_vec2 rg;
/*/ X==3 /*/    struct {
/*/ X==3 /*/        float r;
/*/ X==3 /*/        union {
/*/ X==3 /*/            struct {
/*/ X==3 /*/                float g, b;
/*/ X==3 /*/            };
/*/ X==3 /*/            mathc_vec2 gb;
/*/ X==3 /*/        };
/*/ X==3 /*/    };
/*/ X==3 /*/} mathc_vec3;


/*/ X==4 /*///#include "vec2.h"
/*/ X==4 /*///#include "vec3.h"
/*/ X==4 /*/typedef union {
/*/ X==4 /*/    float v[4];
/*/ X==4 /*/    struct {
/*/ X==4 /*/        float v0, v1, v2, v3;
/*/ X==4 /*/    };
/*/ X==4 /*/    mathc_vec2 xy;
/*/ X==4 /*/    mathc_vec3 xyz;
/*/ X==4 /*/    struct {
/*/ X==4 /*/        float x;
/*/ X==4 /*/        union {
/*/ X==4 /*/            struct {
/*/ X==4 /*/                float y;
/*/ X==4 /*/                union {
/*/ X==4 /*/                    struct {
/*/ X==4 /*/                        float z, w;
/*/ X==4 /*/                    };
/*/ X==4 /*/                    mathc_vec2 zw;
/*/ X==4 /*/                };
/*/ X==4 /*/            };
/*/ X==4 /*/            mathc_vec2 yz;
/*/ X==4 /*/            mathc_vec3 yzw;
/*/ X==4 /*/        };
/*/ X==4 /*/    };
/*/ X==4 /*/    mathc_vec2 rg;
/*/ X==4 /*/    mathc_vec3 rgb;
/*/ X==4 /*/    struct {
/*/ X==4 /*/        float r;
/*/ X==4 /*/        union {
/*/ X==4 /*/            struct {
/*/ X==4 /*/                float g;
/*/ X==4 /*/                union {
/*/ X==4 /*/                    struct {
/*/ X==4 /*/                        float b, a;
/*/ X==4 /*/                    };
/*/ X==4 /*/                    mathc_vec2 ba;
/*/ X==4 /*/                };
/*/ X==4 /*/            };
/*/ X==4 /*/            mathc_vec2 gb;
/*/ X==4 /*/            mathc_vec3 gba;
/*/ X==4 /*/        };
/*/ X==4 /*/    };
/*/ X==4 /*/} mathc_vec4;


/*/ X>=5 /*/typedef struct {
/*/ X>=5 /*/    float v[__X__];
/*/ X>=5 /*/} mathc_vec__X__;


_Static_assert(sizeof(mathc_vec__X__) == sizeof(float) * __X__, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced vec__X__ */
#define MATHC_VEC__X__(vec) (*(mathc_vec__X__ *) (vec))

#endif //MATHC_PUBLICTYPES_VEC__X___H
