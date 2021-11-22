#ifndef MATHC_PUBLICTYPES_<{MAT}><{X}>_H
#define MATHC_PUBLICTYPES_<{MAT}><{X}>_H

#include "<{vec}><{X}>.h"

typedef union {
    <{float}> v[<{X*X}>];
    <{float}> m[<{X}>][<{X}>];
    mathc_<{vec}><{X}> col[<{X}>];
    struct {
        <{float}> v0<% for i in range(1, X*X) %>, v<{i}><% endfor %>;
    };
    struct {
        <% for r in range(X) -%>
        <{float}> m<{r}>0<% for c in range(1, X) %>, m<{r}><{c}><% endfor %>;
        <% endfor %>
    };
} mathc_<{mat}><{X}>;

static_assert(sizeof(mathc_<{mat}><{X}>) == sizeof(<{float}>) * <{X*X}>, "[Mathc] wrong expected size");

#endif //MATHC_PUBLICTYPES_<{MAT}><{X}>_H
