#ifndef MATHC_IO_H
#define MATHC_IO_H

#include <stdio.h>
#include "types.h"

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

void vec2f_print_f(vec2f vec, FILE *ostream) {
    fprintf(ostream, "vec2f: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 2; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec2f_print(vec2f vec) {
    vec2f_print_f(vec, stdout);
}

void mat22f_print_f(mat22f mat, FILE *ostream) {
    fprintf(ostream, "mat22f: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 2; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 2; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat22f_print(mat22f matrix) {
    mat22f_print_f(matrix, stdout);
}


void vec3f_print_f(vec3f vec, FILE *ostream) {
    fprintf(ostream, "vec3f: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 3; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec3f_print(vec3f vec) {
    vec3f_print_f(vec, stdout);
}

void mat33f_print_f(mat33f mat, FILE *ostream) {
    fprintf(ostream, "mat33f: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 3; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat33f_print(mat33f matrix) {
    mat33f_print_f(matrix, stdout);
}

void vec4f_print_f(vec4f vec, FILE *ostream) {
    fprintf(ostream, "vec4f: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 4; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec4f_print(vec4f vec) {
    vec4f_print_f(vec, stdout);
}

void mat44f_print_f(mat44f mat, FILE *ostream) {
    fprintf(ostream, "mat44f: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 4; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 4; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat44f_print(mat44f matrix) {
    mat44f_print_f(matrix, stdout);
}



// 
// d = double
//

void vec2d_print_f(vec2d vec, FILE *ostream) {
    fprintf(ostream, "vec2d: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 2; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec2d_print(vec2d vec) {
    vec2d_print_f(vec, stdout);
}

void mat22d_print_f(mat22d mat, FILE *ostream) {
    fprintf(ostream, "mat22d: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 2; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 2; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat22d_print(mat22d matrix) {
    mat22d_print_f(matrix, stdout);
}


void vec3d_print_f(vec3d vec, FILE *ostream) {
    fprintf(ostream, "vec3d: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 3; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec3d_print(vec3d vec) {
    vec3d_print_f(vec, stdout);
}

void mat33d_print_f(mat33d mat, FILE *ostream) {
    fprintf(ostream, "mat33d: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 3; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat33d_print(mat33d matrix) {
    mat33d_print_f(matrix, stdout);
}

void vec4d_print_f(vec4d vec, FILE *ostream) {
    fprintf(ostream, "vec4d: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 4; v++) {
        if (vec.v[v] < MATHC_PRINT_MAX_TO_SHORT)
            fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, vec.v[v]);
        else
            fprintf(ostream, " %g", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec4d_print(vec4d vec) {
    vec4d_print_f(vec, stdout);
}

void mat44d_print_f(mat44d mat, FILE *ostream) {
    fprintf(ostream, "mat44d: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 4; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 4; r++)
            if (mat.m[c][r] < MATHC_PRINT_MAX_TO_SHORT)
                fprintf(ostream, " %.*f", MATHC_PRINT_PRECISION, mat.m[r][c]);
            else
                fprintf(ostream, " %g", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat44d_print(mat44d matrix) {
    mat44d_print_f(matrix, stdout);
}



// 
// i = int
//

void vec2i_print_f(vec2i vec, FILE *ostream) {
    fprintf(ostream, "vec2i: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 2; v++) {
        fprintf(ostream, " %d", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec2i_print(vec2i vec) {
    vec2i_print_f(vec, stdout);
}

void mat22i_print_f(mat22i mat, FILE *ostream) {
    fprintf(ostream, "mat22i: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 2; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 2; r++)
            fprintf(ostream, " %i", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat22i_print(mat22i matrix) {
    mat22i_print_f(matrix, stdout);
}


void vec3i_print_f(vec3i vec, FILE *ostream) {
    fprintf(ostream, "vec3i: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 3; v++) {
        fprintf(ostream, " %i", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec3i_print(vec3i vec) {
    vec3i_print_f(vec, stdout);
}

void mat33i_print_f(mat33i mat, FILE *ostream) {
    fprintf(ostream, "mat33i: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 3; r++)
            fprintf(ostream, " %i", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat33i_print(mat33i matrix) {
    mat33i_print_f(matrix, stdout);
}

void vec4i_print_f(vec4i vec, FILE *ostream) {
    fprintf(ostream, "vec4i: " MATHC_PRINT_COLOR " ( ");
    for (int v = 0; v < 4; v++) {
        fprintf(ostream, " %i", vec.v[v]);
    }
    fprintf(ostream, " ) " MATHC_PRINT_COLOR_RESET "\n");
}

void vec4i_print(vec4i vec) {
    vec4i_print_f(vec, stdout);
}

void mat44i_print_f(mat44i mat, FILE *ostream) {
    fprintf(ostream, "mat44i: " MATHC_PRINT_COLOR "\n");
    for (int c = 0; c < 4; c++) {
        fprintf(ostream, "  |");
        for (int r = 0; r < 4; r++)
            fprintf(ostream, " %d", mat.m[r][c]);

        fprintf(ostream, "  |\n");
    }
    fprintf(ostream, MATHC_PRINT_COLOR_RESET "\n");
}

void mat44i_print(mat44i matrix) {
    mat44i_print_f(matrix, stdout);
}



#endif //MATHC_IO_H
