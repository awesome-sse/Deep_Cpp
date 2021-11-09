#pragma once
#define N_TOP 5
#define START_BUFFER_TF_IDF 4

typedef struct top_words {
    char file_name[256];
    char top_words[N_TOP][30];
} top_words;

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

int n_files(char * dirname);
char lower(char sym);
int new_word_in_file_tf_idf(file_info * f_info, char * word);
void add_word_in_file_tf_idf(file_info * f_info, char * word);
void words_info(file_info * f_info, char * name_file);
void file_tf_idf(file_info * f_info);
void incert_in_top_list(word_info * w_info, word_info * top[N_TOP]);
void create_file_top_words(file_info * f_info);
file_info create_file_info(char * path, char * name_file);
void clear_file_info(file_info * f_info);
void add_in_top_list(top_words * top_list, int size, file_info * f_info);
void init_top_list(top_words * top_list, char * dirname);
