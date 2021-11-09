#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib_file_data_consistent.h"
#include "lib_file_data_parallel.h"
#include "generate_files.h"
#include "tools.h"
#include "f_timer.h"

#define DIR_PATH "../test_files"


void print_top_words(top_words * top_list, int size) {
    for (int i = 0; i < size; ++i) {
        printf("TOP WORD in file %s:\n", top_list[i].file_name);
        for (int j = 0; j < N_TOP; ++j) {
            printf("%i %s\n", j + 1, top_list[i].top_words[j]);
        }
    }
}

int processor_of_command(int cmd) {
    top_words * top_w;
    switch (cmd) {
        case 1: 
            printf("Input : number of file, min words, max words\n");
            int num_files, min_w, max_w;
            scanf("%i %i %i", &num_files, &min_w, &max_w);
            return generate_files_txt(num_files, min_w, max_w);
        case 2: 
            top_w = files_top_words_consistent(DIR_PATH, 0);
            
            if (top_w == NULL) {
                return 1;
            }
            else {
                print_top_words(top_w, n_files(DIR_PATH));
                free(top_w);
                return 0;
            }

        case 3: 
            printf("Input max numbers of proccess\n");
            int max_n_proc;
            scanf("%i", &max_n_proc);
            if (max_n_proc < 1) {
                max_n_proc = 1;
            }
            top_w = files_top_words_parallel(DIR_PATH, max_n_proc);
            if (top_w == NULL) {
                return 1;
            }
            else {
                print_top_words(top_w, n_files(DIR_PATH));
                return 0;
            }
        case 4:
            printf("Input numbers of proccess\n");
            int num;
            scanf("%i", &num);
            if (num == 1) {
                return f_timer(files_top_words_consistent, DIR_PATH, num);                
            }
            else {
                return f_timer(files_top_words_parallel, DIR_PATH, num);
            }
        case 0: return 0;
        default: 
            printf("Command is not recognized\n");
            return 0;
    }
}

int run() {
    printf("1 - Generate files, 2 - Print top words in files constist, 3 - Print top words in files parallel, 4 - Function time, 0 - exit\n");
    int command = 1;
    while (command) {
        printf("Input command: ");
        scanf("%i", &command);
        int return_code = processor_of_command(command);
        if (return_code == 1) {
            return return_code;
        }
    }
    return 0;
}

int main() {
    return run();
}
