
#include "mathc/mathc.h"
#include "mathc/utils/float.h"
#include "mathc/utils/double.h"

int main() {
    vec3 x = vec3_unit_x();
    vec3 y = vec3_unit_y();
    vec3 z = vec3_cross(x, y);
    vec3_println(z);
}
