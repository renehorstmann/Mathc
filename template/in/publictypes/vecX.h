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
} <{vec}>2;
<% elif X==3 %>
#include "<{vec}>2.h"

typedef union {
    <{float}> v[3];
    struct {
        <{float}> v0, v1, v2;
    };
    <{vec}>2 xy;
    struct {
        <{float}> x;
        union {
            struct {
                <{float}> y, z;
            };
            <{vec}>2 yz;
        };
    };
    <{vec}>2 rg;
    struct {
        <{float}> r;
        union {
            struct {
                <{float}> g, b;
            };
            <{vec}>2 gb;
        };
    };
} <{vec}>3;
<% elif X==4 %>
#include "<{vec}>2.h"
#include "<{vec}>3.h"

typedef union {
    <{float}> v[4];
    struct {
        <{float}> v0, v1, v2, v3;
    };
    <{vec}>2 xy;
    <{vec}>3 xyz;
    struct {
        <{float}> x;
        union {
            struct {
                <{float}> y;
                union {
                    struct {
                        <{float}> z, w;
                    };
                    <{vec}>2 zw;
                };
            };
            <{vec}>2 yz;
            <{vec}>3 yzw;
        };
    };
    <{vec}>2 rg;
    <{vec}>3 rgb;
    struct {
        <{float}> r;
        union {
            struct {
                <{float}> g;
                union {
                    struct {
                        <{float}> b, a;
                    };
                    <{vec}>2 ba;
                };
            };
            <{vec}>2 gb;
            <{vec}>3 gba;
        };
    };
} <{vec}>4;
<% else %>
typedef union {
    <{float}> v[<{X}>];
    struct {
        <{float}> v0<% for i in range(1, X) %>, v<{i}><% endfor %>;
    };
} <{vec}><{X}>;
<% endif %>
static_assert(sizeof(<{vec}><{X}>) == sizeof(<{float}>) * <{X}>, "[Mathc] wrong expected size");
#endif //MATHC_PUBLICTYPES_<{VEC}><{X}>_H
