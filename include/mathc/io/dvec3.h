#ifndef MATHC_IO_DVEC3_H
#define MATHC_IO_DVEC3_H


#include <stdio.h>
#include <locale.h>

#include "../sca/double.h"
#include "../types/dvec3.h"
#include "terminalcolor.h"


#define DVEC3_PRINT_FORMAT "(dvec3) {{  %" DSCA_PRINT_FORMAT_SPECIFIER \
 ", %" DSCA_PRINT_FORMAT_SPECIFIER ", %" DSCA_PRINT_FORMAT_SPECIFIER " }}"

#define DVEC3_PRINT_FORMAT_COLORED "(dvec3)"\
 MATHC_TERMINALCOLOR_CYAN " {{  %" DSCA_PRINT_FORMAT_SPECIFIER \
 ", %" DSCA_PRINT_FORMAT_SPECIFIER ", %" DSCA_PRINT_FORMAT_SPECIFIER " }}"\
 MATHC_TERMINALCOLOR_RESET

#define DVEC3_PRINT_FORMAT_VALUES  "%" DSCA_PRINT_FORMAT_SPECIFIER \
 ", %" DSCA_PRINT_FORMAT_SPECIFIER ", %" DSCA_PRINT_FORMAT_SPECIFIER


/**
 * Example:
 * dvec3 v = dvec3_unit_x();
 * char buf[128];
 * dvec3_snprint(buf, sizeof buf, v);
 * // (dvec3) {{ 1.0, 0.0, ...}}
 */
static size_t dvec3_snprint(char *str, size_t size, dvec3 v) {
    setlocale(LC_ALL, "C");
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = 0;
    used += snprintf(str, size, "(dvec3) {{ ");
    for (int i = 0; i < 3; i++) {
        if (used >= size) {
            str = NULL;
        }
        used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used,
                         "%" DSCA_PRINT_FORMAT_SPECIFIER "%s", v.v[i], i < 3 - 1 ? ", " : "");
    }
    if (used >= size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, " }}");
    return used;
}

/** Calls dvec3_snprint and adds a newline */
static size_t dvec3_snprintln(char *str, size_t size, dvec3 v) {
    if (!str || !size) {
        str = NULL;
        size = 0;
    }
    size_t used = dvec3_snprint(str, size, v);
    if (used >= size) {
        str = NULL;
    }
    used += snprintf(!str ? NULL : str + used, !size ? 0 : size - used, "\n");
    return used;
}

/**
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * dvec3 v = dvec3_unit_x();
 * dvec3_fprint(stdout, v);
 * // (dvec3) {{ 1.0, 0.0, ...}}
 */
static size_t dvec3_fprint(FILE *stream, dvec3 v) {
    setlocale(LC_ALL, "C");
    size_t used = 0;
    used += fprintf(stream, "(dvec3) ");
#ifndef MATHC_NO_PRINT_COLOR
    mathc_terminalcolor_start();
    used += fprintf(stream, MATHC_TERMINALCOLOR_CYAN);
#endif
    used += fprintf(stream, "{{ ");
    for (int i = 0; i < 3; i++) {
        used += fprintf(stream, "%" DSCA_PRINT_FORMAT_SPECIFIER "%s", v.v[i], i < 3 - 1 ? ", " : "");
    }
    used += fprintf(stream, " }}");
#ifndef MATHC_NO_PRINT_COLOR
    used += fprintf(stream, MATHC_TERMINALCOLOR_RESET);
    mathc_terminalcolor_stop();
#endif
    return used;
}

/** Calls dvec3_fprint and adds a newline */
static size_t dvec3_fprintln(FILE *stream, dvec3 v) {
    size_t used = dvec3_fprint(stream, v);
    used += fprintf(stream, "\n");
    return used;
}

/**
 * Calls dvec3_fprint(stdout, v)
 * Uses terminal colors, unless MATHC_NO_PRINT_COLOR is set
 * Example:
 * dvec3 v = dvec3_unit_x();
 * dvec3_print(v);
 * // (dvec3) {{ 1.0, 0.0, ...}}
 */
static size_t dvec3_print(dvec3 v) {
    return dvec3_fprint(stdout, v);
}

/** Calls dvecN_print and adds a newline (Just calls dvec3_print(stdout, v)*/
static size_t dvec3_println(dvec3 v) {
    return dvec3_fprintln(stdout, v);
}

#endif //MATHC_IO_DVEC3_H
