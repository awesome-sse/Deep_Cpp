#include <stdio.h>
#include "generate_files.h"
#include "file_info.h"
#include <string.h>
#include "dirent.h"
#define DIR_PATH "../files"

void print_top_words(file_info * f_info) {
    for (int i = 0; i < N_TOP; ++i) {
        printf("%i Word: %s, Count: %i, TF-IDF: %f\n", i + 1, f_info->top_words[i]->word_name, f_info->top_words[i]->count, f_info->top_words[i]->tf_idf);
    }
}

int files_top_words_consistent(char * dirname) {
    DIR * dir = opendir(dirname);
    if (dir == NULL) {
        return 1;
    }
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            char path [100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            file_info f_info = create_file_info(path);
            printf("Words TOP List In file: %s\n", entity->d_name);
            print_top_words(&f_info);
            clear_file_info(&f_info);
        }
        entity = readdir(dir);
    }
    closedir(dir);
}

int processor_of_command(int cmd) {
    switch (cmd) {
        case 1: 
            printf("Input : number of file, min words, max words\n");
            int n_files, min_w, max_w;
            scanf("%i %i %i", &n_files, &min_w, &max_w);
            return generate_files_txt(n_files, min_w, max_w);
        case 2: return files_top_words_consistent(DIR_PATH);
        case 0: return 0;
        default: 
            printf("Command is not recognized\n");
            return 0;
    }
}

int run() {
    printf("1 - Generate files, 2 - Print top words in files, 0 - exit\n");
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
