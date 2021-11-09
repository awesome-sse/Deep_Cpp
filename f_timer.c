#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <sys/mman.h>
#include "f_timer.h"

int clear_for_multyproccess(top_words * t_words, const char * dirname) {
    return munmap(t_words, n_files(dirname) * sizeof(top_words));
}

int f_timer(top_words* (*fptr)(const char * dirname, size_t proc), const char * dirname, size_t proc) {
    if (unlikely(fptr == NULL)) {
        return 1;
    }

    if (proc == 0) {
        clock_t start = clock();
        top_words * p = fptr(dirname, proc);
        clock_t end = clock();
        float seconds = (float)(end - start) / CLOCKS_PER_SEC;
        printf("Time: %f\n", seconds);
        free(p);
        return 0;
    }

    else {
        struct timespec start, finish;
        float elapsed;

        clock_gettime(CLOCK_MONOTONIC, &start);

        top_words * p = fptr(dirname, proc);

        clock_gettime(CLOCK_MONOTONIC, &finish);

        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("Time: %f\n", elapsed);
        return clear_for_multyproccess(p, dirname);
    }
}