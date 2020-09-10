#include "mathc/float.h"
#include "mathc/utils/float.h"
#include "assert.h"

int main() {

    vec4 plane_a = {{0, 0, 1, -2}};
    vec4 plane_b = {{1, 0, 0, -10}};
    vec3 pos, dir;
    bool success = intersection_plane_plane(&pos, &dir, plane_a, plane_b);
    assert(success);
    vec3_print(pos);
    vec3_print(dir);


}
