#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dirent.h"
#include "assert.h"
#include "lib_file_data_consistent.h"


top_words * files_top_words_consistent(char * dirname, int zero) {
    size_t dir_size = n_files(dirname);

    top_words *top_list = (top_words *)malloc(sizeof(top_words) * dir_size);
    if (top_list == NULL) {
        assert(0);
    } 
    init_top_list(top_list, dirname);

    DIR * dir = opendir(dirname);
    if (dir == NULL) {
        assert(0);
    }

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            char path [100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            
            file_info f_info = create_file_info(path, entity->d_name);
            add_in_top_list(top_list, dir_size, &f_info);   
            clear_file_info(&f_info);
        }
        entity = readdir(dir);
    }
    closedir(dir);
    return top_list;
}