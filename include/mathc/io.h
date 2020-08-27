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

static void vec2_print_f(vec2 vec, FILE *ostream) {
    fprintf(ostream, "vec2: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 2; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec2_print(vec2 vec) {
    vec2_print_f(vec, stdout);
}

static void mat2_print_f(mat2 mat, FILE *ostream) {
    fprintf(ostream, "mat2: " MATHC_PRINT_COLOR "\n");
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

static void mat2_print(mat2 matrix) {
    mat2_print_f(matrix, stdout);
}


static void vec3_print_f(vec3 vec, FILE *ostream) {
    fprintf(ostream, "vec3: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 3; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec3_print(vec3 vec) {
    vec3_print_f(vec, stdout);
}

static void mat3_print_f(mat3 mat, FILE *ostream) {
    fprintf(ostream, "mat3: " MATHC_PRINT_COLOR "\n");
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

static void mat3_print(mat3 matrix) {
    mat3_print_f(matrix, stdout);
}

static void vec4_print_f(vec4 vec, FILE *ostream) {
    fprintf(ostream, "vec4: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void vec4_print(vec4 vec) {
    vec4_print_f(vec, stdout);
}

static void mat4_print_f(mat4 mat, FILE *ostream) {
    fprintf(ostream, "mat4: " MATHC_PRINT_COLOR "\n");
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

static void mat4_print(mat4 matrix) {
    mat4_print_f(matrix, stdout);
}



// 
// d = double
//

static void dvec2_print_f(dvec2 vec, FILE *ostream) {
    fprintf(ostream, "dvec2: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 2; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void dvec2_print(dvec2 vec) {
    dvec2_print_f(vec, stdout);
}

static void dmat2_print_f(dmat2 mat, FILE *ostream) {
    fprintf(ostream, "dmat2: " MATHC_PRINT_COLOR "\n");
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

static void dmat2_print(dmat2 matrix) {
    dmat2_print_f(matrix, stdout);
}


static void dvec3_print_f(dvec3 vec, FILE *ostream) {
    fprintf(ostream, "dvec3: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 3; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void dvec3_print(dvec3 vec) {
    dvec3_print_f(vec, stdout);
}

static void dmat3_print_f(dmat3 mat, FILE *ostream) {
    fprintf(ostream, "dmat3: " MATHC_PRINT_COLOR "\n");
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

static void dmat3_print(dmat3 matrix) {
    dmat3_print_f(matrix, stdout);
}

static void dvec4_print_f(dvec4 vec, FILE *ostream) {
    fprintf(ostream, "dvec4: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void dvec4_print(dvec4 vec) {
    dvec4_print_f(vec, stdout);
}

static void dmat4_print_f(dmat4 mat, FILE *ostream) {
    fprintf(ostream, "dmat4: " MATHC_PRINT_COLOR "\n");
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

static void dmat4_print(dmat4 matrix) {
    dmat4_print_f(matrix, stdout);
}



// 
// i = int
//

static void ivec2_print_f(ivec2 vec, FILE *ostream) {
    fprintf(ostream, "ivec2: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 2; v++) {
        fprintf(ostream, " %d", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void ivec2_print(ivec2 vec) {
    ivec2_print_f(vec, stdout);
}

static void imat2_print_f(imat2 mat, FILE *ostream) {
    fprintf(ostream, "imat2: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 2; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 2; r++)
            fprintf(ostream, " %i", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void imat2_print(imat2 matrix) {
    imat2_print_f(matrix, stdout);
}


static void ivec3_print_f(ivec3 vec, FILE *ostream) {
    fprintf(ostream, "ivec3: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 3; v++) {
        fprintf(ostream, " %i", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void ivec3_print(ivec3 vec) {
    ivec3_print_f(vec, stdout);
}

static void imat3_print_f(imat3 mat, FILE *ostream) {
    fprintf(ostream, "imat3: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 3; r++)
            fprintf(ostream, " %i", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void imat3_print(imat3 matrix) {
    imat3_print_f(matrix, stdout);
}

static void ivec4_print_f(ivec4 vec, FILE *ostream) {
    fprintf(ostream, "ivec4: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        fprintf(ostream, " %i", vec.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void ivec4_print(ivec4 vec) {
    ivec4_print_f(vec, stdout);
}

static void imat4_print_f(imat4 mat, FILE *ostream) {
    fprintf(ostream, "imat4: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 4; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 4; r++)
            fprintf(ostream, " %d", mat.m[r][c]);

        fprintf(ostream, " |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

static void imat4_print(imat4 matrix) {
    imat4_print_f(matrix, stdout);
}


//
// quat
//

static void quat_print_f(quat quat, FILE *ostream) {
    fprintf(ostream, "quat: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (quat.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, quat.v[v]);
        else
            fprintf(ostream, " %g", quat.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void quat_print(quat quat) {
    quat_print_f(quat, stdout);
}

static void dquat_print_f(dquat quat, FILE *ostream) {
    fprintf(ostream, "dquat: " MATHC_PRINT_COLOR "(");
    for (int v = 0; v < 4; v++) {
        if (quat.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, quat.v[v]);
        else
            fprintf(ostream, " %g", quat.v[v]);
    }
    fprintf(ostream, " )" MATHC_PRINT_COLOR_RESET "\n");
}

static void dquat_print(dquat quat) {
    dquat_print_f(quat, stdout);
}

#endif //MATHC_IO_H
