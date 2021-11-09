#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib_file_data_consistent.h"
#include "lib_file_data_parallel.h"
#include "generate_files.h"
#include "tools.h"
#include "f_timer.h"


void print_top_words(top_words * top_list, int size) {
    for (int i = 0; i < size; ++i) {
        printf("TOP WORD in file %s:\n", top_list[i].file_name);
        for (int j = 0; j < N_TOP; ++j) {
            printf("%i %s\n", j + 1, top_list[i].top_words[j]);
        }
    }
}

int run(char** argv) {
    char dirname[MAX_FILENAME_LENGTH];
    strcpy(dirname, argv[1]);
    int numb_files = atoi(argv[2]), min_words = atoi(argv[3]), max_words = atoi(argv[4]), proc = atoi(argv[5]);
    int return_code;
    return_code = generate_files_txt(dirname, numb_files, min_words, max_words);
    if (return_code) {
        return return_code;
    }
    top_words * top_w;
    if (proc <= 1) {
        top_w = files_top_words_consistent(dirname, 0);
        if (top_w == NULL) {
            return 1;
        }
        print_top_words(top_w, n_files(dirname));
        clear_top_words_for_parallel(top_w, dirname);
        return f_timer(files_top_words_consistent, dirname, 0);
    } 
    else {
        top_w = files_top_words_parallel(dirname, proc);
        if (top_w == NULL) {
            return 1;
        }
        print_top_words(top_w, n_files(dirname));
        clear_top_words_for_parallel(top_w, dirname);
        return f_timer(files_top_words_parallel, dirname, proc);
    }
}

int main(int argc, char** argv) {
    if (argc < 6) {
        printf("Not enough arguments\n");
        return 1;
    }
    return run(argv);
}
