#ifndef MATHC_TYPES_H
#define MATHC_TYPES_H

typedef struct vec3f {
    float v[3];
} vec3f;

/** casts a float * to a dereferenced vec3f */
#define Vec3f(vec) (*(vec3f *) (vec))

/** casts a float * to a dereferenced const vec3f */
#define ConstVec3f(vec) (*(const vec3f *) (vec))


typedef union mat33f {
    float v[9];
    float m[3][3];
    vec3f rows[3];
} mat33f;

/** casts a float * to a dereferenced mat33f */
#define Mat33f(mat) (*(mat33f *) (mat))

/** casts a float * to a dereferenced const mat33f */
#define ConstMat33f(mat) (*(const mat33f *) (mat))


typedef struct vec4f {
    float v[4];
} vec4f;

/** casts a float * to a dereferenced vec4f */
#define Vec4f(vec) (*(vec4f *) (vec))

/** casts a float * to a dereferenced const vec4f */
#define ConstVec4f(vec) (*(const vec4f *) (vec))


typedef union mat44f {
    float v[16];
    float m[4][4];
    vec4f rows[4];
} mat44f;

/** casts a float * to a dereferenced mat44f */
#define Mat44f(mat) (*(mat44f *) (mat))

/** casts a float * to a dereferenced const mat44f */
#define ConstMat44f(mat) (*(const mat44f *) (mat))


typedef struct vec3d {
    double v[3];
} vec3d;

/** casts a double * to a dereferenced vec3d */
#define Vec3d(vec) (*(vec3d *) (vec))

/** casts a double * to a dereferenced const vec3d */
#define ConstVec3d(vec) (*(const vec3d *) (vec))


typedef union mat33d {
    double v[9];
    double m[3][3];
    vec3d rows[3];
} mat33d;

/** casts a double * to a dereferenced mat33d */
#define Mat33d(mat) (*(mat33d *) (mat))

/** casts a double * to a dereferenced const mat33d */
#define ConstMat33d(mat) (*(const mat33d *) (mat))


typedef struct vec4d {
    double v[4];
} vec4d;

/** casts a double * to a dereferenced vec4d */
#define Vec4d(vec) (*(vec4d *) (vec))

/** casts a double * to a dereferenced vec4d */
#define ConstVec4d(vec) (*(const vec4d *) (vec))


typedef union mat44d {
    double v[16];
    double m[4][4];
    vec4d rows[4];
} mat44d;

/** casts a double * to a dereferenced mat44d */
#define Mat44d(mat) (*(mat44d *) (mat))

/** casts a double * to a dereferenced const mat44d */
#define ConstMat44d(mat) (*(const mat44d *) (mat))


typedef struct vec3i {
    int v[3];
} vec3i;

/** casts an int * to a dereferenced vec3i */
#define Vec3i(vec) (*(vec3i *) (vec))

/** casts an int * to a dereferenced vec3i */
#define ConstVec3i(vec) (*(const vec3i *) (vec))


typedef union mat33i {
    int v[9];
    int m[3][3];
    vec3i rows[3];
} mat33i;

/** casts a int * to a dereferenced mat33i */
#define Mat33i(mat) (*(mat33i *) (mat))

/** casts a int * to a dereferenced const mat33i */
#define ConstMat33i(mat) (*(const mat33i *) (mat))


typedef struct vec4i {
    int v[4];
} vec4i;


/** casts an int * to a dereferenced vec4i */
#define Vec4i(vec) (*(vec4i *) (vec))

/** casts an int * to a dereferenced const vec4i */
#define ConstVec4i(vec) (*(const vec4i *) (vec))


typedef union mat44i {
    int v[16];
    int m[4][4];
    vec4i rows[4];
} mat44i;

/** casts a int * to a dereferenced mat44i */
#define Mat44i(mat) (*(mat44i *) (mat))

/** casts a int * to a dereferenced const mat44i */
#define ConstMat44i(mat) (*(const mat44i *) (mat))


#endif //MATHC_TYPES_H
