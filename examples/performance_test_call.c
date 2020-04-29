#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// see performance_test_lib.c
float performance_manuel(const float *vectors_a, const float *vectors_b, int n);
float performance_mathc1(const float *vectors_a, const float *vectors_b, int n);
float performance_mathc2(const float *vectors_a, const float *vectors_b, int n);
float performance_mathc3(const float *vectors_a, const float *vectors_b, int n);


static double monotonic() {
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    return (double) time.tv_sec + (double) time.tv_nsec / 1000000000.0;
}

int main(int argc, char **argv) {
    srand(time(NULL));

    puts("how many random vectors?");
    int n;
    if(scanf("%d", &n) != 1) {
        puts("failed to get an input!");
        exit(EXIT_FAILURE);
    }

    float *vec_a = malloc(n * 3 * sizeof(float));
    float *vec_b = malloc(n * 3 * sizeof(float));
    for(int i=0; i<n*3; i++) {
        vec_a[i] = rand() *2.0f / RAND_MAX - 1;
        vec_b[i] = rand() *2.0f / RAND_MAX - 1;
    }

    // let the cpu run...
    performance_manuel(vec_a, vec_b, n);

    double time = monotonic();
    float res_manual = performance_manuel(vec_a, vec_b, n);
    double time_manuel = monotonic() - time;

    time = monotonic();
    float res_mathc1 = performance_mathc1(vec_a, vec_b, n);
    double time_mathc1 = monotonic() - time;

    time = monotonic();
    float res_mathc2 = performance_mathc2(vec_a, vec_b, n);
    double time_mathc2 = monotonic() - time;

    time = monotonic();
    float res_mathc3 = performance_mathc3(vec_a, vec_b, n);
    double time_mathc3 = monotonic() - time;


    printf("result manual: %f\n", res_manual);
    printf("result mathc1: %f\n", res_mathc1);
    printf("result mathc2: %f\n", res_mathc2);
    printf("result mathc3: %f\n", res_mathc3);
    printf("time manual: %f s\n", time_manuel);
    printf("time mathc1: %f s\n", time_mathc1);
    printf("time mathc2: %f s\n", time_mathc2);
    printf("time mathc3: %f s\n", time_mathc3);

    free(vec_a);
    free(vec_b);

    // result on my machine are (for n=1.000.000):
    // debug mode:
    //time manual: 0.008240 s
    //time mathc1: 0.042722 s
    //time mathc2: 0.041226 s
    //time mathc3: 0.039459 s

    // release mode:
    //time manual: 0.003047 s
    //time mathc1: 0.001329 s
    //time mathc2: 0.001370 s
    //time mathc3: 0.001350 s

    // as expected, in debug mode the manual mode is faster, because it calcs everything in the for xyz loop
    // in this example the compiler made a more optimized version for the mathc functions
}
