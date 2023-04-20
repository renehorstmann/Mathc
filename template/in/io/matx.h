#ifndef MATHC_IO_MAT__X___H
#define MATHC_IO_MAT__X___H

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
/*/ 0 /*/ #include "../../out/mathc/types/mat4.h"
/*/ 0 /*/ typedef mat4 mat__X__;
/*/ 0 /*/ #define __X__ 4

#include <stdio.h>
#include <locale.h>

#include "../sca/float.h"
/*/ 1 /*///#include "../types/mat__X__.h"
#include "terminalcolor.h"

/*/ X==2 /*/// #define MAT__X___PRINT_FORMAT "(mat__X__) {{"\
/*/ X==2 /*/// "\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==2 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"

/*/ X==2 /*/// #define MAT__X___PRINT_FORMAT_COLORED "(mat__X__)"\
/*/ X==2 /*/// MATHC_TERMINALCOLOR_CYAN" {{"\
/*/ X==2 /*/// "\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==2 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"\
/*/ X==2 /*/// MATHC_TERMINALCOLOR_RESET

/*/ X==2 /*/// #define MAT__X___PRINT_FORMAT_LINE "(mat__X__) {{"\
/*/ X==2 /*/// "%" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==2 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"

/*/ X==2 /*/// #define MAT__X___PRINT_FORMAT_VALUES \
/*/ X==2 /*/// "%" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==2 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER


/*/ X==3 /*/// #define MAT__X___PRINT_FORMAT "(mat__X__) {{"\
/*/ X==3 /*/// "\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"

/*/ X==3 /*/// #define MAT__X___PRINT_FORMAT_COLORED "(mat__X__)"\
/*/ X==3 /*/// MATHC_TERMINALCOLOR_CYAN " {{"\
/*/ X==3 /*/// "\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"\
/*/ X==3 /*/// MATHC_TERMINALCOLOR_RESET

/*/ X==3 /*/// #define MAT__X___PRINT_FORMAT_LINE "(mat__X__) {{"\
/*/ X==3 /*/// "%" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"

/*/ X==3 /*/// #define MAT__X___PRINT_FORMAT_VALUES \
/*/ X==3 /*/// "%" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==3 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER


/*/ X==4 /*/// #define MAT__X___PRINT_FORMAT "(mat__X__) {{"\
/*/ X==4 /*/// "\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"

/*/ X==4 /*/// #define MAT__X___PRINT_FORMAT_COLORED "(mat__X__)"\
/*/ X==4 /*/// MATHC_TERMINALCOLOR_CYAN " {{"\
/*/ X==4 /*/// "\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ",\n%12" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"\
/*/ X==4 /*/// MATHC_TERMINALCOLOR_RESET

/*/ X==4 /*/// #define MAT__X___PRINT_FORMAT_LINE "(mat__X__) {{"\
/*/ X==4 /*/// "%" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER" }}"

/*/ X==4 /*/// #define MAT__X___PRINT_FORMAT_VALUES \
/*/ X==4 /*/// "%" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER\
/*/ X==4 /*/// ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER ", %" SCA_PRINT_FORMAT_SPECIFIER


/**
 * Prints the mat__X__ in a single line
 * Example:
 * mat__X__ m = mat__X___eye();
 * char buf[128];
 * mat__X___snprint_line(buf, sizeof buf, m);
 * // (mat__X__) {{ 1.0, 0.0,   0.0, 1.1,   ... }}
 */
static size_t mat__X___snprint_line(char *str, size_t size, mat__X__ m) {
    setlocale(LC_ALL, "C");
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = 0;
    used += snprintf(str, size, "(mat__X__) {{ ");
    for (int c = 0; c < __X__; c++) {
        if(used>=size) {
            str = NULL;
        }
        used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, "%s", c > 0 ? ",   " : "");
        for (int r = 0; r < __X__; r++) {
            if(used>=size) {
                str = NULL;
            }
            used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used,
                             "%" SCA_PRINT_FORMAT_SPECIFIER "%s", m.m[c][r], r < __X__ - 1 ? ", " : "");
        }
    }
    if(used>=size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, " }}");
    return used;
}

/** Calls mat__X___snprint_line and adds a newline */
static size_t mat__X___snprintln_line(char *str, size_t size, mat__X__ m) {
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = mat__X___snprint_line(str, size, m);
    if(used>=size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, "\n");
    return used;
}

/**
 * Prints the matrix in multiple lines
 * Example:
 * mat__X__ m = mat__X___eye();
 * char buf[128];
 * mat__X___snprint(buf, sizeof buf, m);
 * // (mat__X__) {{
 * //        1.0,          0.0,
 * //        0.0,          1.0,
 * //        ...,          ... }}
 */
static size_t mat__X___snprint(char *str, size_t size, mat__X__ m) {
    setlocale(LC_ALL, "C");
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = 0;
    used += snprintf(str, size, "(mat__X__) {{ ");
    for (int c = 0; c < __X__; c++) {
        if(used>=size) {
            str = NULL;
        }
        used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, "%s\n    ", c > 0 ? "," : "");
        for (int r = 0; r < __X__; r++) {
            if(used>=size) {
                str = NULL;
            }
            used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used,
                             "%12" SCA_PRINT_FORMAT_SPECIFIER "%s", m.m[c][r], r < __X__ - 1 ? ", " : "");
        }
    }
    if(used>=size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, " }}");
    return used;
}

/** Calls mat__X___snprint and adds a newline */
static size_t mat__X___snprintln(char *str, size_t size, mat__X__ m) {
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = mat__X___snprint(str, size, m);
    if(used>=size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, "\n");
    return used;
}

/**
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * mat__X__ m = mat__X___eye();
 * mat__X___fprint_line(stdout, m);
 * // (mat__X__) {{ 1.0, 0.0,   0.0, 1.1,   ... }}
 */
static size_t mat__X___fprint_line(FILE *stream, mat__X__ m) {
    setlocale(LC_ALL, "C");
    size_t used = 0;
    used += fprintf(stream, "(mat__X__) ");
#ifndef MATHC_NO_PRINT_COLOR
    mathc_terminalcolor_start();
    used += fprintf(stream, MATHC_TERMINALCOLOR_CYAN);
#endif
    used += fprintf(stream, "{{ ");
    for (int c = 0; c < __X__; c++) {
        used += fprintf(stream, "%s", c > 0 ? ",   " : "");
        for (int r = 0; r < __X__; r++) {
            used += fprintf(stream, "%" SCA_PRINT_FORMAT_SPECIFIER "%s", m.m[c][r], r < __X__ - 1 ? ", " : "");
        }
    }
    used += fprintf(stream, " }}");
#ifndef MATHC_NO_PRINT_COLOR
    used += fprintf(stream, MATHC_TERMINALCOLOR_RESET);
    mathc_terminalcolor_stop();
#endif
    return used;
}

/** Calls mat__X___fprint_line and adds a newline */
static size_t mat__X___fprintln_line(FILE *stream, mat__X__ m) {
    size_t used = mat__X___fprint_line(stream, m);
    used += fprintf(stream, "\n");
    return used;
}

/**
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * mat__X__ m = mat__X___eye();
 * mat__X___fprint(stdout, m);
 * // (mat__X__) {
 * //        1.0,          0.0,
 * //        0.0,          1.0,
 * //        ...,          ... }
 */
static size_t mat__X___fprint(FILE *stream, mat__X__ m) {
    setlocale(LC_ALL, "C");
    size_t used = 0;
    used += fprintf(stream, "(mat__X__) ");
#ifndef MATHC_NO_PRINT_COLOR
    mathc_terminalcolor_start();
    used += fprintf(stream, MATHC_TERMINALCOLOR_CYAN);
#endif
    used += fprintf(stream, "{{ ");
    for (int c = 0; c < __X__; c++) {
        used += fprintf(stream, "%s\n    ", c > 0 ? "," : "");
        for (int r = 0; r < __X__; r++) {
            used += fprintf(stream, "%12" SCA_PRINT_FORMAT_SPECIFIER "%s", m.m[c][r], r < __X__ - 1 ? ", " : "");
        }
    }
    used += fprintf(stream, " }}");
#ifndef MATHC_NO_PRINT_COLOR
    used += fprintf(stream, MATHC_TERMINALCOLOR_RESET);
    mathc_terminalcolor_stop();
#endif
    return used;
}

/** Calls mat__X___fprint and adds a newline */
static size_t mat__X___fprintln(FILE *stream, mat__X__ m) {
    size_t used = mat__X___fprint(stream, m);
    used += fprintf(stream, "\n");
    return used;
}

/**
 * Calls mat__X___fprint_line(stdout, m)
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * mat__X__ m = mat__X___eye();
 * mat__X___print_line(m);
 * // (mat__X__) {{ 1.0, 0.0,   0.0, 1.1,   ... }}
 */
static size_t mat__X___print_line(mat__X__ m) {
    return mat__X___fprint_line(stdout, m);
}

/** Calls mat__X___fprint_line and adds a newline (Just calls mat__X___fprintln_line(stdout, m, n)*/
static size_t mat__X___println_line(mat__X__ m) {
    return mat__X___fprintln_line(stdout, m);
}

/**
 * Calls mat__X___fprint(stdout, m)
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * mat__X__ m = mat__X___eye();
 * mat__X___print(m);
 * // (mat__X__) {
 * //        1.0,          0.0,
 * //        0.0,          1.0,
 * //        ...,          ... }
 */
static size_t mat__X___print(mat__X__ m) {
    return mat__X___fprint(stdout, m);
}

/** Calls mat__X___fprint and adds a newline (Just calls mat__X___fprintln(stdout, m, n)*/
static size_t mat__X___println(mat__X__ m) {
    return mat__X___fprintln(stdout, m);
}

#endif //MATHC_IO_MAT__X___H
