#pragma once
#define N_TOP 5
#define START_BUFFER_TF_IDF 4
#define MAX_FILENAME_LENGTH 256
#define MAX_WORD_LENGTH 30

#define likely(x)   __builtin_expect((x),1)
#define unlikely(x) __builtin_expect((x),0)

typedef struct top_words {
    char file_name[MAX_FILENAME_LENGTH];
    char top_words[N_TOP][MAX_WORD_LENGTH];
} top_words;

typedef struct word_info {
    char word_name[MAX_WORD_LENGTH];
    int count; 
    float tf_idf; 
} word_info; 

typedef struct file_info {
    char name[MAX_FILENAME_LENGTH];
    size_t n_words;
    word_info * file_prop;
    size_t size;
    size_t buf_size;
    word_info * top_words[N_TOP];
} file_info;

int n_files(const char * dirname);
char lower(char sym);
int new_word_in_file_tf_idf(file_info * f_info, const char * word);
void add_word_in_file_tf_idf(file_info * f_info, const char * word);
int words_info(file_info * f_info, const char * name_file);
void file_tf_idf(file_info * f_info);
void incert_in_top_list(word_info * w_info, word_info * top[N_TOP]);
void create_file_top_words(file_info * f_info);
file_info create_file_info(const char * path, const char * name_file);
void clear_file_info(file_info * f_info);
void add_in_top_list(top_words * top_list, int size, file_info * f_info);
void init_top_list(top_words * top_list, const char * dirname);
