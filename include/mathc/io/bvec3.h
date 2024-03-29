#ifndef MATHC_IO_BVEC3_H
#define MATHC_IO_BVEC3_H


#include <stdio.h>
#include <locale.h>

#include "../sca/bool.h"
#include "../types/bvec3.h"
#include "terminalcolor.h"


#define BVEC3_PRINT_FORMAT "(bvec3) {{  %" BSCA_PRINT_FORMAT_SPECIFIER \
 ", %" BSCA_PRINT_FORMAT_SPECIFIER ", %" BSCA_PRINT_FORMAT_SPECIFIER " }}"

#define BVEC3_PRINT_FORMAT_COLORED "(bvec3)"\
 MATHC_TERMINALCOLOR_CYAN " {{  %" BSCA_PRINT_FORMAT_SPECIFIER \
 ", %" BSCA_PRINT_FORMAT_SPECIFIER ", %" BSCA_PRINT_FORMAT_SPECIFIER " }}"\
 MATHC_TERMINALCOLOR_RESET

#define BVEC3_PRINT_FORMAT_VALUES  "%" BSCA_PRINT_FORMAT_SPECIFIER \
 ", %" BSCA_PRINT_FORMAT_SPECIFIER ", %" BSCA_PRINT_FORMAT_SPECIFIER


/**
 * Example:
 * bvec3 v = bvec3_unit_x();
 * char buf[128];
 * bvec3_snprint(buf, sizeof buf, v);
 * // (bvec3) {{ 1.0, 0.0, ...}}
 */
static size_t bvec3_snprint(char *str, size_t size, bvec3 v) {
    setlocale(LC_ALL, "C");
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = 0;
    used += snprintf(str, size, "(bvec3) {{ ");
    for (int i = 0; i < 3; i++) {
        if (used >= size) {
            str = NULL;
        }
        used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used,
                         "%" BSCA_PRINT_FORMAT_SPECIFIER "%s", v.v[i], i < 3 - 1 ? ", " : "");
    }
    if (used >= size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, " }}");
    return used;
}

/** Calls bvec3_snprint and adds a newline */
static size_t bvec3_snprintln(char *str, size_t size, bvec3 v) {
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = bvec3_snprint(str, size, v);
    if (used >= size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, "\n");
    return used;
}

/**
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * bvec3 v = bvec3_unit_x();
 * bvec3_fprint(stdout, v);
 * // (bvec3) {{ 1.0, 0.0, ...}}
 */
static size_t bvec3_fprint(FILE *stream, bvec3 v) {
    setlocale(LC_ALL, "C");
    size_t used = 0;
    used += fprintf(stream, "(bvec3) ");
#ifndef MATHC_NO_PRINT_COLOR
    mathc_terminalcolor_start();
    used += fprintf(stream, MATHC_TERMINALCOLOR_CYAN);
#endif
    used += fprintf(stream, "{{ ");
    for (int i = 0; i < 3; i++) {
        used += fprintf(stream, "%" BSCA_PRINT_FORMAT_SPECIFIER "%s", v.v[i], i < 3 - 1 ? ", " : "");
    }
    used += fprintf(stream, " }}");
#ifndef MATHC_NO_PRINT_COLOR
    used += fprintf(stream, MATHC_TERMINALCOLOR_RESET);
    mathc_terminalcolor_stop();
#endif
    return used;
}

/** Calls bvec3_fprint and adds a newline */
static size_t bvec3_fprintln(FILE *stream, bvec3 v) {
    size_t used = bvec3_fprint(stream, v);
    used += fprintf(stream, "\n");
    return used;
}

/**
 * Calls bvec3_fprint(stdout, v)
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * bvec3 v = bvec3_unit_x();
 * bvec3_print(v);
 * // (bvec3) {{ 1.0, 0.0, ...}}
 */
static size_t bvec3_print(bvec3 v) {
    return bvec3_fprint(stdout, v);
}

/** Calls bvecN_print and adds a newline (Just calls bvec3_print(stdout, v)*/
static size_t bvec3_println(bvec3 v) {
    return bvec3_fprintln(stdout, v);
}

#endif //MATHC_IO_BVEC3_H
