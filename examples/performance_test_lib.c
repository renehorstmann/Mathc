#include <mathc/mathc.h>

// this example seems trivial and more or less easy to read in manuel, but it can easily get more complicated
float performance_manuel(const float *vectors_a, const float *vectors_b, int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        const float *vec_a = &vectors_a[i * 3];
        const float *vec_b = &vectors_b[i * 3];

        for(int xyz=0; xyz<3; xyz++)
            result += vec_a[xyz] * 10 * -vec_b[xyz];
    }
    return result;
}

// first mathc example copies the current vectors and calls the generic mathc functions
float performance_mathc1(const float *vectors_a, const float *vectors_b, int n) {
    float result = 0;
    for(int i=0; i<n; i++) {
        vec3f vec_a = Vec3f(&vectors_a[i*3]);
        vec3f vec_b = Vec3f(&vectors_b[i*3]);

        vec_a = vec_scale(vec_a, 10);
        vec_b = vec_neg(vec_b);

        result += vec_dot(vec_a, vec_b);
    }
    return result;
}

// second mathc example holds a reference of current vectors and calls the generic mathc functions
float performance_mathc2(const float *vectors_a, const float *vectors_b, int n) {
    float result = 0;
    for(int i=0; i<n; i++) {
        const vec3f *vec_a = (const vec3f *) &vectors_a[i*3];
        const vec3f *vec_b = (const vec3f *) &vectors_b[i*3];

        vec3f a = vec_scale(*vec_a, 10);
        vec3f b = vec_neg(*vec_b);

        result += vec_dot(a, b);
    }
    return result;
}

// third mathc example calls the vector mathc functions (_v) which take float pointers instead of vec3fs
float performance_mathc3(const float *vectors_a, const float *vectors_b, int n) {
    float result = 0;
    for(int i=0; i<n; i++) {
        const float *vec_a = &vectors_a[i * 3];
        const float *vec_b = &vectors_b[i * 3];

        vec3f a = vec3_scale_v(vec_a, 10);
        vec3f b = vec3_neg_v(vec_b);

        result += vec_dot(a, b);
    }
    return result;
}
