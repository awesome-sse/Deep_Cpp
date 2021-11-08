#pragma once 
#define N_TOP 5

typedef struct word_info {
    char word_name[30];
    int count; 
    float tf_idf; 
} word_info; 

typedef struct file_info {
    char* name;
    size_t n_words;
    word_info * file_prop;
    size_t size;
    size_t buf_size;
    word_info * top_words[N_TOP];
} file_info;

file_info create_file_info(char * name_file);
void clear_file_info(file_info * f_info);
