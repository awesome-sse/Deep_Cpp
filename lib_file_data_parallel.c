#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include "dirent.h"
#include "assert.h"
#include "lib_file_data_parallel.h"


top_words * files_top_words_parallel(char * dirname, int max_proc) {
    pid_t pid;

    size_t dir_size = n_files(dirname);

    top_words *shared_mem = mmap(NULL, sizeof(top_words) * dir_size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1 , 0);
    if (shared_mem == MAP_FAILED) {
        return NULL;    
    }
    init_top_list(shared_mem, dirname);

    int * n_proc = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1 , 0);
    if (n_proc == MAP_FAILED) {
        return NULL;    
    }
    DIR * dir = opendir(dirname);
    if (dir == NULL) {
        return NULL;
    }
    *n_proc = 1;
    struct dirent* entity;
    entity = readdir(dir);
    char path [100];
    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            pid = fork();
            if (pid == -1) {
                perror("fork"); 
                exit(1); 
            }
            else if (pid == 0) {
                *n_proc = *n_proc + 1; 
                path[0] = '\0';
                strcat(path, dirname);
                strcat(path, "/");
                strcat(path, entity->d_name);
                file_info f_info = create_file_info(path, entity->d_name);
                add_in_top_list(shared_mem, dir_size, &f_info);
                clear_file_info(&f_info);
                *n_proc = *n_proc - 1; 
                exit(0);
            }
            else {
                while (*n_proc > max_proc) {
                    wait(0);
                }
            }

        }
        entity = readdir(dir);
    }
    while (*n_proc != 1) {
        wait(0);
    }
    closedir(dir);
    return shared_mem;
}