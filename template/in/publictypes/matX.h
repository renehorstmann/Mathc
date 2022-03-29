#ifndef MATHC_PUBLICTYPES_MAT__X___H
#define MATHC_PUBLICTYPES_MAT__X___H

#ifndef __cplusplus
#define static_assert _Static_assert
#endif

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
/*/ 0 /*/ typedef struct mathc_vec2 {int a;} mathc_vec2;
/*/ 0 /*/ typedef struct mathc_vec3 {int a;} mathc_vec3;
/*/ 0 /*/ typedef struct mathc_vec4 {int a;} mathc_vec4;
/*/ 0 /*/ typedef struct mathc_vec__X__ {int a;} mathc_vec__X__;

/*/ bool /*/#include <stdbool.h>

/*/ X==2 /*///#include "vec2.h"
/*/ X==2 /*/typedef union {
/*/ X==2 /*/    float v[2*2];
/*/ X==2 /*/    float m[2][2];
/*/ X==2 /*/    mathc_vec2 col[2];
/*/ X==2 /*/    struct {
/*/ X==2 /*/        float v0, v1;
/*/ X==2 /*/        float v2, v3;
/*/ X==2 /*/    };
/*/ X==2 /*/    struct {
/*/ X==2 /*/        float m00, m01;
/*/ X==2 /*/        float m10, m11;
/*/ X==2 /*/    };
/*/ X==2 /*/} mathc_mat2;


/*/ X==3 /*///#include "vec3.h"
/*/ X==3 /*/typedef union {
/*/ X==3 /*/    float v[3*3];
/*/ X==3 /*/    float m[3][3];
/*/ X==3 /*/    mathc_vec3 col[3];
/*/ X==3 /*/    struct {
/*/ X==3 /*/        float v0, v1, v2;
/*/ X==3 /*/        float v3, v4, v5;
/*/ X==3 /*/        float v6, v7, v8;
/*/ X==3 /*/    };
/*/ X==3 /*/    struct {
/*/ X==3 /*/        float m00, m01, m02;
/*/ X==3 /*/        float m10, m11, m12;
/*/ X==3 /*/        float m20, m21, m22;
/*/ X==3 /*/    };
/*/ X==3 /*/} mathc_mat3;


/*/ X==4 /*///#include "vec4.h"
/*/ X==4 /*/typedef union {
/*/ X==4 /*/    float v[4*4];
/*/ X==4 /*/    float m[4][4];
/*/ X==4 /*/    mathc_vec4 col[4];
/*/ X==4 /*/    struct {
/*/ X==4 /*/        float v0, v1, v2, v3;
/*/ X==4 /*/        float v4, v5, v6, v7;
/*/ X==4 /*/        float v8, v9, v10, v11;
/*/ X==4 /*/        float v12, v13, v14, v15;
/*/ X==4 /*/    };
/*/ X==4 /*/    struct {
/*/ X==4 /*/        float m00, m01, m02, m03;
/*/ X==4 /*/        float m10, m11, m12, m13;
/*/ X==4 /*/        float m20, m21, m22, m23;
/*/ X==4 /*/        float m30, m31, m32, m33;
/*/ X==4 /*/    };
/*/ X==4 /*/} mathc_mat4;


/*/ X>=5 /*///#include "vec__X__.h"
/*/ X>=5 /*/typedef union {
/*/ X>=5 /*/    float v[__X__ * __X__];
/*/ X>=5 /*/    float m[__X__][__X__];
/*/ X>=5 /*/    mathc_vec__X__ col[__X__];
/*/ X>=5 /*/} mathc_mat__X__;


_Static_assert(sizeof(mathc_mat__X__) == sizeof(float) * __X__ * __X__, "[Mathc] wrong expected size");

/** casts a float * to a dereferenced mat__X__ */
#define MATHC_AS_MAT__X__(mat) (*(mathc_mat__X__ *) (mat))

#endif //MATHC_PUBLICTYPES_MAT__X___H
