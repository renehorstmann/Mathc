#include "mathc/mathc.h"


int main() {
    // some tests here...

    mat4 a = mat4_eye();
    a.m02 = 12.345;
    a.m33 = 99.1;
    dmat4 b = dmat4_cast_from_float(a.v);
    imat4 c = imat4_cast_from_double(b.v);
    a = mat4_cast_from_int(c.v);
    mat4_println(a);
    dmat4_println(b);
    imat4_println(c);


    mat4_println((mat4){{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}});
    mat4_println_repr((mat4){{1, 2, 3, 4, 5, 6, 7, 8, 9}});


}
