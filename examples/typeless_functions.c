#include "mathc/mathc.h"

int main() {
    float a[7];
    float res[7];
    vecN_scale(res, a, 1000, 7);
    vecN_add(res, res, 50, 7);
}
