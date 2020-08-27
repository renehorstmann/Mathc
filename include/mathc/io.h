#ifndef MATHC_IO_H
#define MATHC_IO_H

#include <stdio.h>
#include "types.h"

//
// from cglm/io.h
//

#ifndef MATHC_PRINT_PRECISION
#  define MATHC_PRINT_PRECISION 5
#endif

#ifndef MATHC_PRINT_MAX_TO_SHORT
#  define MATHC_PRINT_MAX_TO_SHORT 1e5
#endif

#ifndef MATHC_PRINT_COLOR
#  define MATHC_PRINT_COLOR "\033[36m"
#endif

#ifndef MATHC_PRINT_COLOR_RESET
#  define MATHC_PRINT_COLOR_RESET "\033[0m"
#endif

// 
// f = float
//

static void vec2f_print_f(vec2f vec, FILE *ostream) {
    fprintf(ostream, "vec2f: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 2; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec2f_print(vec2f vec) {
    vec2f_print_f(vec, stdout);
}

static void mat22f_print_f(mat22f mat, FILE *ostream) {
    fprintf(ostream, "mat22f: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 2; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 2; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat22f_print(mat22f matrix) {
    mat22f_print_f(matrix, stdout);
}


static void vec3f_print_f(vec3f vec, FILE *ostream) {
    fprintf(ostream, "vec3f: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 3; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec3f_print(vec3f vec) {
    vec3f_print_f(vec, stdout);
}

static void mat33f_print_f(mat33f mat, FILE *ostream) {
    fprintf(ostream, "mat33f: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 3; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat33f_print(mat33f matrix) {
    mat33f_print_f(matrix, stdout);
}

static void vec4f_print_f(vec4f vec, FILE *ostream) {
    fprintf(ostream, "vec4f: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec4f_print(vec4f vec) {
    vec4f_print_f(vec, stdout);
}

static void mat44f_print_f(mat44f mat, FILE *ostream) {
    fprintf(ostream, "mat44f: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 4; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 4; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat44f_print(mat44f matrix) {
    mat44f_print_f(matrix, stdout);
}



// 
// d = double
//

static void vec2d_print_f(vec2d vec, FILE *ostream) {
    fprintf(ostream, "vec2d: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 2; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec2d_print(vec2d vec) {
    vec2d_print_f(vec, stdout);
}

static void mat22d_print_f(mat22d mat, FILE *ostream) {
    fprintf(ostream, "mat22d: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 2; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 2; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat22d_print(mat22d matrix) {
    mat22d_print_f(matrix, stdout);
}


static void vec3d_print_f(vec3d vec, FILE *ostream) {
    fprintf(ostream, "vec3d: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 3; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec3d_print(vec3d vec) {
    vec3d_print_f(vec, stdout);
}

static void mat33d_print_f(mat33d mat, FILE *ostream) {
    fprintf(ostream, "mat33d: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 3; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat33d_print(mat33d matrix) {
    mat33d_print_f(matrix, stdout);
}

static void vec4d_print_f(vec4d vec, FILE *ostream) {
    fprintf(ostream, "vec4d: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec4d_print(vec4d vec) {
    vec4d_print_f(vec, stdout);
}

static void mat44d_print_f(mat44d mat, FILE *ostream) {
    fprintf(ostream, "mat44d: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 4; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 4; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat44d_print(mat44d matrix) {
    mat44d_print_f(matrix, stdout);
}



// 
// i = int
//

static void vec2i_print_f(vec2i vec, FILE *ostream) {
    fprintf(ostream, "vec2i: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 2; v++) {
        fprintf(ostream, " %d", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec2i_print(vec2i vec) {
    vec2i_print_f(vec, stdout);
}

static void mat22i_print_f(mat22i mat, FILE *ostream) {
    fprintf(ostream, "mat22i: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 2; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 2; r++)
            fprintf(ostream, " %i", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat22i_print(mat22i matrix) {
    mat22i_print_f(matrix, stdout);
}


static void vec3i_print_f(vec3i vec, FILE *ostream) {
    fprintf(ostream, "vec3i: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 3; v++) {
        fprintf(ostream, " %i", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec3i_print(vec3i vec) {
    vec3i_print_f(vec, stdout);
}

static void mat33i_print_f(mat33i mat, FILE *ostream) {
    fprintf(ostream, "mat33i: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 3; r++)
            fprintf(ostream, " %i", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat33i_print(mat33i matrix) {
    mat33i_print_f(matrix, stdout);
}

static void vec4i_print_f(vec4i vec, FILE *ostream) {
    fprintf(ostream, "vec4i: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        fprintf(ostream, " %i", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec4i_print(vec4i vec) {
    vec4i_print_f(vec, stdout);
}

static void mat44i_print_f(mat44i mat, FILE *ostream) {
    fprintf(ostream, "mat44i: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 4; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 4; r++)
            fprintf(ostream, " %d", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void mat44i_print(mat44i matrix) {
    mat44i_print_f(matrix, stdout);
}


//
// quat
//

static void quatf_print_f(quatf quat, FILE *ostream) {
    fprintf(ostream, "quatf: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (quat.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, quat.v[v]);
        else
            fprintf(ostream, " %g", quat.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void quatf_print(quatf quat) {
    quatf_print_f(quat, stdout);
}

static void quatd_print_f(quatd quat, FILE *ostream) {
    fprintf(ostream, "quatd: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (quat.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, quat.v[v]);
        else
            fprintf(ostream, " %g", quat.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void quatd_print(quatd quat) {
    quatd_print_f(quat, stdout);
}


// generic
#define vec_print(vec) _Generic((vec), \
vec2f: vec2f_print, \
vec3f: vec3f_print, \
vec4f: vec4f_print, \
vec2d: vec2d_print, \
vec3d: vec3d_print, \
vec4d: vec4d_print, \
vec2i: vec2i_print, \
vec3i: vec3i_print, \
vec4i: vec4i_print, \
default: "type_error" \
) ((vec))

#define vec_print_f(vec, file) _Generic((vec), \
vec2f: vec2f_print_f, \
vec3f: vec3f_print_f, \
vec4f: vec4f_print_f, \
vec2d: vec2d_print_f, \
vec3d: vec3d_print_f, \
vec4d: vec4d_print_f, \
vec2i: vec2i_print_f, \
vec3i: vec3i_print_f, \
vec4i: vec4i_print_f, \
default: "type_error" \
) ((vec), (file))

#define mat_print(mat) _Generic((mat), \
mat22f: mat22f_print, \
mat33f: mat33f_print, \
mat44f: mat44f_print, \
mat22d: mat22d_print, \
mat33d: mat33d_print, \
mat44d: mat44d_print, \
mat22i: mat22i_print, \
mat33i: mat33i_print, \
mat44i: mat44i_print, \
default: "type_error" \
) ((mat))

#define mat_print_f(mat, file) _Generic((mat), \
mat22f: mat22f_print_f, \
mat33f: mat33f_print_f, \
mat44f: mat44f_print_f, \
mat22d: mat22d_print_f, \
mat33d: mat33d_print_f, \
mat44d: mat44d_print_f, \
mat22i: mat22i_print_f, \
mat33i: mat33i_print_f, \
mat44i: mat44i_print_f, \
default: "type_error" \
) ((mat), (file))


#define vec2_print(vec) _Generic((vec), \
float *: vec2f_print, \
const float *: vec2f_print, \
double *: vec2d_print, \
const double *: vec2d_print, \
int *: vec2i_print, \
const int *: vec2i_print, \
default: "type_error" \
) ((vec))

#define vec2_print_f(vec, file) _Generic((vec), \
float *: vec2f_print_f, \
const float *: vec2f_print_f, \
double *: vec2d_print_f, \
const double *: vec2d_print_f, \
int *: vec2i_print_f, \
const int *: vec2i_print_f, \
default: "type_error" \
) ((vec), (file))


#define vec3_print(vec) _Generic((vec), \
float *: vec3f_print, \
const float *: vec3f_print, \
double *: vec3d_print, \
const double *: vec3d_print, \
int *: vec3i_print, \
const int *: vec3i_print, \
default: "type_error" \
) ((vec))

#define vec3_print_f(vec, file) _Generic((vec), \
float *: vec3f_print_f, \
const float *: vec3f_print_f, \
double *: vec3d_print_f, \
const double *: vec3d_print_f, \
int *: vec3i_print_f, \
const int *: vec3i_print_f, \
default: "type_error" \
) ((vec), (file))


#define vec4_print(vec) _Generic((vec), \
float *: vec4f_print, \
const float *: vec4f_print, \
double *: vec4d_print, \
const double *: vec4d_print, \
int *: vec4i_print, \
const int *: vec4i_print, \
default: "type_error" \
) ((vec))

#define vec4_print_f(vec, file) _Generic((vec), \
float *: vec4f_print_f, \
const float *: vec4f_print_f, \
double *: vec4d_print_f, \
const double *: vec4d_print_f, \
int *: vec4i_print_f, \
const int *: vec4i_print_f, \
default: "type_error" \
) ((vec), (file))


#define mat22_print(vec) _Generic((vec), \
float *: mat22f_print, \
const float *: mat22f_print, \
double *: mat22d_print, \
const double *: mat22d_print, \
int *: mat22i_print, \
const int *: mat22i_print, \
default: "type_error" \
) ((vec))

#define mat22_print_f(vec, file) _Generic((vec), \
float *: mat22f_print_f, \
const float *: mat22f_print_f, \
double *: mat22d_print_f, \
const double *: mat22d_print_f, \
int *: mat22i_print_f, \
const int *: mat22i_print_f, \
default: "type_error" \
) ((vec), (file))


#define mat33_print(vec) _Generic((vec), \
float *: mat33f_print, \
const float *: mat33f_print, \
double *: mat33d_print, \
const double *: mat33d_print, \
int *: mat33i_print, \
const int *: mat33i_print, \
default: "type_error" \
) ((vec))

#define mat33_print_f(vec, file) _Generic((vec), \
float *: mat33f_print_f, \
const float *: mat33f_print_f, \
double *: mat33d_print_f, \
const double *: mat33d_print_f, \
int *: mat33i_print_f, \
const int *: mat33i_print_f, \
default: "type_error" \
) ((vec), (file))


#define mat44_print(vec) _Generic((vec), \
float *: mat44f_print, \
const float *: mat44f_print, \
double *: mat44d_print, \
const double *: mat44d_print, \
int *: mat44i_print, \
const int *: mat44i_print, \
default: "type_error" \
) ((vec))

#define mat44_print_f(vec, file) _Generic((vec), \
float *: mat44f_print_f, \
const float *: mat44f_print_f, \
double *: mat44d_print_f, \
const double *: mat44d_print_f, \
int *: mat44i_print_f, \
const int *: mat44i_print_f, \
default: "type_error" \
) ((vec), (file))


//
// quat
//

#define quat_print(quat) _Generic((quat), \
quatf: quatf_print, \
quatd: quatd_print, \
default: "type_error" \
) ((quat))

#define quat_print_f(quat, file) _Generic((quat), \
quatf: quatf_print, \
quatd: quatd_print, \
default: "type_error" \
) ((quat), (file))

#endif //MATHC_IO_H
