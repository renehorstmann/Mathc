#ifndef MATHC_IO_VEC__X___H
#define MATHC_IO_VEC__X___H

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
/*/ 0 /*/ #include "../../out/mathc/types/vec4.h"
/*/ 0 /*/ typedef vec4 vec__X__;
/*/ 0 /*/ #define __X__ 4

#include <stdio.h>
#include <locale.h>

#include "../sca/float.h"
/*/ 1 /*///#include "../types/vec__X__.h"
#include "terminalcolor.h"


/*/ X==2 /*/ #define VEC__X___PRINT_FORMAT "(vec__X__) {{ %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER " }}"

/*/ X==2 /*/ #define VEC__X___PRINT_FORMAT_COLORED "(vec__X__)"\
/*/ X==2 /*/ MATHC_TERMINALCOLOR_CYAN " {{ %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER " }}"\
/*/ X==2 /*/ MATHC_TERMINALCOLOR_RESET

/*/ X==2 /*/ #define VEC__X___PRINT_FORMAT_VALUES "%" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER


/*/ X==3 /*/ #define VEC__X___PRINT_FORMAT "(vec__X__) {{  %" SCA_PRINT_FORMAT_SPECIFIER \
/*/ X==3 /*/ ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER " }}"

/*/ X==3 /*/ #define VEC__X___PRINT_FORMAT_COLORED "(vec__X__)"\
/*/ X==3 /*/ MATHC_TERMINALCOLOR_CYAN " {{  %" SCA_PRINT_FORMAT_SPECIFIER \
/*/ X==3 /*/ ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER " }}"\
/*/ X==3 /*/ MATHC_TERMINALCOLOR_RESET

/*/ X==3 /*/ #define VEC__X___PRINT_FORMAT_VALUES  "%" SCA_PRINT_FORMAT_SPECIFIER \
/*/ X==3 /*/ ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER


/*/ X==4 /*/ #define VEC__X___PRINT_FORMAT "(vec__X__) {{  %" SCA_PRINT_FORMAT_SPECIFIER \
/*/ X==4 /*/ ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER " }}"

/*/ X==4 /*/ #define VEC__X___PRINT_FORMAT_COLORED "(vec__X__)" \
/*/ X==4 /*/ MATHC_TERMINALCOLOR_CYAN " {{  %" SCA_PRINT_FORMAT_SPECIFIER \
/*/ X==4 /*/ ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER " }}"\
/*/ X==4 /*/ MATHC_TERMINALCOLOR_RESET

/*/ X==4 /*/ #define VEC__X___PRINT_FORMAT_VALUES "%" SCA_PRINT_FORMAT_SPECIFIER \
/*/ X==4 /*/ ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER

/**
 * Example:
 * vec__X__ v = vec__X___unit_x();
 * char buf[128];
 * vec__X___snprint(buf, sizeof buf, v);
 * // (vec__X__) {{ 1.0, 0.0, ...}}
 */
static size_t vec__X___snprint(char *str, size_t size, vec__X__ v) {
    setlocale(LC_ALL, "C");
    if(!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = 0;
    used += snprintf(str, size, "(vec__X__) {{ ");
    for(int i=0; i<__X__; i++) {
        used += snprintf(!str? NULL : str+used, !size? 0 : size - used,
                         "%" SCA_PRINT_FORMAT_SPECIFIER "%s", v.v[i], i<__X__-1? ", " : "");
    }
    used += snprintf(!str? NULL : str+used, !size? 0 : size - used, " }}");
    return used;
}

/** Calls vec__X___snprint and adds a newline */
static size_t vec__X___snprintln(char *str, size_t size, vec__X__ v) {
    if(!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = vec__X___snprint(str, size, v);
    used += snprintf(!str? NULL : str+used, !size? 0 : size - used, "\n");
    return used;
}

/**
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * vec__X__ v = vec__X___unit_x();
 * vec__X___fprint(stdout, v);
 * // (vec__X__) {{ 1.0, 0.0, ...}}
 */
static size_t vec__X___fprint(FILE *stream, vec__X__ v) {
    setlocale(LC_ALL, "C");
    size_t used = 0;
    used += fprintf(stream, "(vec__X__) ");
#ifndef MATHC_NO_PRINT_COLOR
    mathc_terminalcolor_start();
    used += fprintf(stream, MATHC_TERMINALCOLOR_CYAN);
#endif
    used += fprintf(stream, "{{ ");
    for(int i=0; i<__X__; i++) {
        used += fprintf(stream,"%" SCA_PRINT_FORMAT_SPECIFIER "%s", v.v[i], i<__X__-1? ", " : "");
    }
    used += fprintf(stream, " }}");
#ifndef MATHC_NO_PRINT_COLOR
    used += fprintf(stream, MATHC_TERMINALCOLOR_RESET);
    mathc_terminalcolor_stop();
#endif
    return used;
}

/** Calls vec__X___fprint and adds a newline */
static size_t vec__X___fprintln(FILE *stream, vec__X__ v) {
    size_t used = vec__X___fprint(stream, v);
    used += fprintf(stream, "\n");
    return used;
}

/**
 * Calls vec__X___fprint(stdout, v)
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * vec__X__ v = vec__X___unit_x();
 * vec__X___print(v);
 * // (vec__X__) {{ 1.0, 0.0, ...}}
 */
static size_t vec__X___print(vec__X__ v) {
    return vec__X___fprint(stdout, v);
}

/** Calls vecN_print and adds a newline (Just calls vec__X___print(stdout, v)*/
static size_t vec__X___println(vec__X__ v) {
    return vec__X___fprintln(stdout, v);
}

#endif //MATHC_IO_VEC__X___H
