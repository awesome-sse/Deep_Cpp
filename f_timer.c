#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include "f_timer.h"

int f_timer(top_words* (*fptr)(char * dirname, int proc), char * dirname, int proc) {
    if (fptr == NULL) {
        return 1;
    }

    if (proc == 1) {
        clock_t start = clock();
        top_words * p = fptr(dirname, proc);
        clock_t end = clock();
        free(p);
        float seconds = (float)(end - start) / CLOCKS_PER_SEC;
        printf("Time: %f\n", seconds);
    }
    else {
        struct timespec start, finish;
        float elapsed;

        clock_gettime(CLOCK_MONOTONIC, &start);

        fptr(dirname, proc);

        clock_gettime(CLOCK_MONOTONIC, &finish);

        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("Time: %f\n", elapsed);
    }
    return 0;
}