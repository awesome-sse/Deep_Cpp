#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dirent.h"
#include "assert.h"
#include "tools.h"

int n_files(const char * dirname) {
    int kol = 0;
    DIR * dir = opendir(dirname);
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            ++kol;
        }
        entity = readdir(dir);
    }
    return kol;
}

char lower(char sym) {
    if (sym >= 'A' && sym <= 'Z') {
        return sym - 'A' + 'a';
    }
    return sym;
}

int new_word_in_file_tf_idf(file_info * f_info, const char * word) {
    if (f_info->size == f_info->buf_size) {
        f_info->buf_size = f_info->buf_size * 2;
        f_info->file_prop = (word_info *)realloc(f_info->file_prop, sizeof(word_info) * f_info->buf_size);
    }
    if (likely(f_info->file_prop != NULL)) {
        strcpy(f_info->file_prop[f_info->size].word_name, word);
        f_info->file_prop[f_info->size].count = 1;
        f_info->size += 1;
        return 0;
    }
    else {
        return 1;
    }
}

void add_word_in_file_tf_idf(file_info * f_info, const char * word) {
    for (int i = 0; i < f_info->size; ++i) {
        if (strcmp(f_info->file_prop[i].word_name, word) == 0) {
            f_info->file_prop[i].count += 1;
            return;
        }
    }
    if (unlikely(new_word_in_file_tf_idf(f_info, word))) {
        assert(0);
    };
}

int words_info(file_info * f_info, const char * name_file) {
    FILE * text_file = fopen(name_file, "r");
    if (unlikely(text_file == NULL)) {
        return 1;
    }
    char str[30] = "";
    char sym;
    while ((sym = fgetc(text_file)) != EOF) {
        if (lower(sym) >= 'a' && lower(sym) <= 'z') {
            sym = lower(sym);
            strncat(str, &sym, 1); 
        }
        else {
            if (str[0] != '\0') {
                add_word_in_file_tf_idf(f_info, str);
                f_info->n_words += 1;
                str[0] = '\0';
            }
        }
    }
    if (str[0] != '\0') {
        add_word_in_file_tf_idf(f_info, str);
        f_info->n_words += 1;
    }
    fclose(text_file);
    return 0;
}

void file_tf_idf(file_info * f_info) {
    for (int i = 0; i < f_info->size; ++i) {
        f_info->file_prop[i].tf_idf = (float) f_info->file_prop[i].count / f_info->n_words;
    }
}

void incert_in_top_list(word_info * w_info, word_info * top[N_TOP]) {
    size_t i = 0;
    while (i < N_TOP && top[i] != NULL && w_info->count <= top[i]->count) {
        ++i;
    }
    if (i < N_TOP) {
        for (int j = N_TOP - 1; j > i; --j) {
            top[j] = top[j - 1];
        } 
        top[i] = w_info;
    }
}

void create_file_top_words(file_info * f_info) {
    for (int i = 0; i < N_TOP; ++i) {
        f_info->top_words[i] = NULL;
    }
    for (int i = 0; i < f_info->size; ++i) {
        incert_in_top_list(&(f_info->file_prop)[i], f_info->top_words);
    }
}

file_info create_file_info(const char * path, const char * name_file) {
    file_info f_info;
    strcpy(f_info.name, name_file);
    size_t n_words = 0;
    f_info.size = 0;
    f_info.buf_size = 0;
    f_info.n_words = 0;
    f_info.file_prop = (word_info *)malloc(sizeof(word_info) * START_BUFFER_TF_IDF);
    if (likely(f_info.file_prop != NULL)) {
        f_info.buf_size = START_BUFFER_TF_IDF;
    }
    if (unlikely(words_info(&f_info, path))) {
        assert(0);
    };

    file_tf_idf(&f_info);
    create_file_top_words(&f_info);
    return f_info;
}


void clear_file_info(file_info * f_info) {
    f_info->n_words = 0;
    f_info->name[0] = '\0';
    f_info->size = 0;
    f_info->buf_size = 0;
    f_info->n_words = 0;
    free(f_info->file_prop);
    f_info->file_prop = NULL;
    for (int i = 0; i < N_TOP; ++i) {
        f_info->top_words[i] = NULL;
    }
}

void add_in_top_list(top_words * top_list, int size, file_info * f_info) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(top_list[i].file_name, f_info->name) == 0) {
            for (int j = 0; j < N_TOP; ++j) {
                if (f_info->top_words[j] != NULL) {
                    strcpy(top_list[i].top_words[j], f_info->top_words[j]->word_name);
                }
            }
            break;
        }
    }
}

void init_top_list(top_words * top_list, const char * dirname) {
    int i = 0;
    DIR * dir = opendir(dirname);
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            strcpy(top_list[i].file_name, entity->d_name);
            ++i;
        }
        entity = readdir(dir);
    }
    closedir(dir);
}
