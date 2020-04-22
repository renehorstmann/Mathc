#ifndef MATHC_TYPED_GENERIC_H
#define MATHC_TYPED_GENERIC_H

#include "typed.h"

/** casts a float, double, into <const> vec3<x> */
#define Vec3(vec) _Generic((vec), \
float *: Vec3f(vec), \
const float *: ConstVec3f(vec), \
double *: Vec3d(vec), \
const double *: ConstVec3d(vec), \
int *: Vec3i(vec), \
const int *: ConstVec3i(vec), \
default: "type_error" \
)

/** casts a float, double, into <const> vec4<x> */
#define Vec4(vec) _Generic((vec), \
float *: Vec4f(vec), \
const float *: ConstVec4f(vec), \
double *: Vec4d(vec), \
const double *: ConstVec4d(vec), \
int *: Vec4i(vec), \
const int *: ConstVec4i(vec), \
default: "type_error" \
)

// todo: const necessary?
#define vec_neg(vec) _Generic((vec), \
vec3f: vec3f_neg, \
const vec3f: vec3f_neg, \
vec4f: vec3f_neg, \
const vec4f: vec3f_neg, \
vec3d: vec3d_neg, \
const vec3d: vec3d_neg, \
vec4d: vec3d_neg, \
const vec4d: vec3d_neg, \
vec3i: vec3i_neg, \
const vec3i: vec3i_neg, \
vec4i: vec3i_neg, \
const vec4i: vec3i_neg, \
default: "type_error" \
) ((vec))


#define vec_add_vec(vec_a, vec_b) _Generic((vec_a), \
vec3f: vec3f_add_vec, \
vec4f: vec3f_add_vec, \
vec3d: vec3d_add_vec, \
vec4d: vec3d_add_vec, \
vec3i: vec3i_add_vec, \
vec4i: vec3i_add_vec, \
default: "type_error" \
) ((vec_a), (vec_b))


#define vec_add_sca(vec_a, scalar_b) _Generic((vec_a), \
vec3f: vec3f_add_sca, \
vec4f: vec3f_add_sca, \
vec3d: vec3d_add_sca, \
vec4d: vec3d_add_sca, \
vec3i: vec3i_add_sca, \
vec4i: vec3i_add_sca, \
default: "type_error" \
) ((vec_a), (scalar_b))

#define vec_add(vec_a, b) _Generic((b), \
vec3f: vec_add_vec, \
vec4f: vec_add_vec, \
vec3d: vec_add_vec, \
vec4d: vec_add_vec, \
vec3i: vec_add_vec, \
vec4i: vec_add_vec, \
float: vec3f_add_sca, \
const float: vec3f_add_sca, \
double: vec3f_add_sca, \
const double: vec3f_add_sca, \
int: vec3f_add_sca, \
const int: vec3f_add_sca, \
default: "type_error" \
) ((vec_a), (b))

#endif //MATHC_TYPED_GENERIC_H
