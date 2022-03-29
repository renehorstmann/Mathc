#ifndef MATHC_VEC_BVEC__X___H
#define MATHC_VEC_BVEC__X___H

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
/*/ 0 /*/ #include "../../out/mathc/types/bvec4.h"
/*/ 0 /*/ typedef bvec4 bvec__X__;
/*/ 0 /*/ #define __X__ 4

#include "bvecn.h"
/*/ 1 /*///#include "../types/bvec__X__.h"


/** bvec_a == bvec_b */
static bool bvec__X___cmp(bvec__X__ a, bvec__X__ b) {
    return bvecN_cmp(a.v, b.v, __X__);
}

/** dst = scalar */
static bvec__X__ bvec__X___set(bool set) {
    bvec__X__ res;
    bvecN_set(res.v, set, __X__);
    return res;
}


/** dst = unit_x */
static bvec__X__ bvec__X___unit_x() {
    bvec__X__ res;
    bvecN_unit_x(res.v, __X__);
    return res;
}


/** dst = unit_y */
static bvec__X__ bvec__X___unit_y() {
    bvec__X__ res;
    bvecN_unit_y(res.v, __X__);
    return res;
}


/*/ X>=3 /*//** dst = unit_z */
/*/ X>=3 /*/static bvec__X__ bvec__X___unit_z() {
/*/ X>=3 /*/    bvec__X__ res;
/*/ X>=3 /*/    bvecN_unit_z(res.v, __X__);
/*/ X>=3 /*/    return res;
/*/ X>=3 /*/}


/*/ X>=4 /*//** dst = unit_w */
/*/ X>=4 /*/static bvec__X__ bvec__X___unit_w() {
/*/ X>=4 /*/    bvec__X__ res;
/*/ X>=4 /*/    bvecN_unit_w(res.v, __X__);
/*/ X>=4 /*/    return res;
/*/ X>=4 /*/}


/** dst = !vec */
static bvec__X__ bvec__X___not(bvec__X__ vec) {
    bvec__X__ res;
    bvecN_not(res.v, vec.v, __X__);
    return res;
}


/** dst = a || b */
static bvec__X__ bvec__X___or(bvec__X__ vec_a, bvec__X__ vec_b) {
    bvec__X__ res;
    bvecN_or(res.v, vec_a.v, vec_b.v, __X__);
    return res;
}


/** dst = !(a || b) */
static bvec__X__ bvec__X___nor(bvec__X__ vec_a, bvec__X__ vec_b) {
    bvec__X__ res;
    bvecN_nor(res.v, vec_a.v, vec_b.v, __X__);
    return res;
}


/** dst = a ^ b */
static bvec__X__ bvec__X___xor(bvec__X__ vec_a, bvec__X__ vec_b) {
    bvec__X__ res;
    bvecN_xor(res.v, vec_a.v, vec_b.v, __X__);
    return res;
}


/** dst = !(a ^ b) */
static bvec__X__ bvec__X___nxor(bvec__X__ vec_a, bvec__X__ vec_b) {
    bvec__X__ res;
    bvecN_nxor(res.v, vec_a.v, vec_b.v, __X__);
    return res;
}


/** dst = a && b */
static bvec__X__ bvec__X___and(bvec__X__ vec_a, bvec__X__ vec_b) {
    bvec__X__ res;
    bvecN_and(res.v, vec_a.v, vec_b.v, __X__);
    return res;
}


/** dst = !(a && b) */
static bvec__X__ bvec__X___nand(bvec__X__ vec_a, bvec__X__ vec_b) {
    bvec__X__ res;
    bvecN_nand(res.v, vec_a.v, vec_b.v, __X__);
    return res;
}


/** returns the sum of true values */
static int bvec__X___sum(bvec__X__ vec) {
    return bvecN_sum(vec.v, __X__);
}


/** returns sum(vec) > 0 */
static bool bvec__X___any(bvec__X__ vec) {
    return bvecN_any(vec.v, __X__);
}


/** returns sum(vec) == n */
static bool bvec__X___all(bvec__X__ vec) {
    return bvecN_all(vec.v, __X__);
}

#endif //MATHC_VEC_BVEC__X___H
