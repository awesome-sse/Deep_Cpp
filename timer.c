#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>  
#include "timer.h"

float f_timer(top_words* (*fptr)(char * dirname, int proc), char * dirname, int proc) {
    clock_t start = clock();
    top_words * p = fptr(dirname, proc);
    clock_t end = clock();
    if (proc == 1) {
        free(p);
    }
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    return seconds;
}