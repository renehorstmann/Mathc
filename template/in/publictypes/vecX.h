#ifndef MATHC_PUBLICTYPES_<{VEC}><{X}>_H
#define MATHC_PUBLICTYPES_<{VEC}><{X}>_H
<% if X==2 %>
typedef union {
    <{float}> v[2];
    struct {
        <{float}> v0, v1;
    };
    struct {
        <{float}> x, y;
    };
    struct {
        <{float}> r, g;
    };
} mathc_<{vec}>2;
<% elif X==3 %>
#include "<{vec}>2.h"

typedef union {
    <{float}> v[3];
    struct {
        <{float}> v0, v1, v2;
    };
    mathc_<{vec}>2 xy;
    struct {
        <{float}> x;
        union {
            struct {
                <{float}> y, z;
            };
            mathc_<{vec}>2 yz;
        };
    };
    mathc_<{vec}>2 rg;
    struct {
        <{float}> r;
        union {
            struct {
                <{float}> g, b;
            };
            mathc_<{vec}>2 gb;
        };
    };
} mathc_<{vec}>3;
<% elif X==4 %>
#include "<{vec}>2.h"
#include "<{vec}>3.h"

typedef union {
    <{float}> v[4];
    struct {
        <{float}> v0, v1, v2, v3;
    };
    mathc_<{vec}>2 xy;
    mathc_<{vec}>3 xyz;
    struct {
        <{float}> x;
        union {
            struct {
                <{float}> y;
                union {
                    struct {
                        <{float}> z, w;
                    };
                    mathc_<{vec}>2 zw;
                };
            };
            mathc_<{vec}>2 yz;
            mathc_<{vec}>3 yzw;
        };
    };
    mathc_<{vec}>2 rg;
    mathc_<{vec}>3 rgb;
    struct {
        <{float}> r;
        union {
            struct {
                <{float}> g;
                union {
                    struct {
                        <{float}> b, a;
                    };
                    mathc_<{vec}>2 ba;
                };
            };
            mathc_<{vec}>2 gb;
            mathc_<{vec}>3 gba;
        };
    };
} mathc_<{vec}>4;
<% else %>
typedef union {
    <{float}> v[<{X}>];
    struct {
        <{float}> v0<% for i in range(1, X) %>, v<{i}><% endfor %>;
    };
} mathc_<{vec}><{X}>;
<% endif %>
static_assert(sizeof(mathc_<{vec}><{X}>) == sizeof(<{float}>) * <{X}>, "[Mathc] wrong expected size");
#endif //MATHC_PUBLICTYPES_<{VEC}><{X}>_H
