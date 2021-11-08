#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_info.h"
#include "assert.h"
#define START_BUFFER_TF_IDF 4

char lower(char sym) {
    if (sym >= 'A' && sym <= 'Z') {
        return sym - 'A' + 'a';
    }
    return sym;
}

int new_word_in_file_tf_idf(file_info * f_info, char * word) {
    if (f_info->size == f_info->buf_size) {
        f_info->buf_size = f_info->buf_size * 2;
        f_info->file_prop = (word_info *)realloc(f_info->file_prop, sizeof(word_info) * f_info->buf_size);
    }
    if (f_info->file_prop != NULL) {
        strcpy(f_info->file_prop[f_info->size].word_name, word);
        f_info->file_prop[f_info->size].count = 1;
        f_info->size += 1;
        return 0;
    }
    else {
        return 1;
    }
}

void add_word_in_file_tf_idf(file_info * f_info, char * word) {
    for (int i = 0; i < f_info->size; ++i) {
        if (!strcmp(f_info->file_prop[i].word_name, word)) {
            f_info->file_prop[i].count += 1;
            return;
        }
    }
    if (new_word_in_file_tf_idf(f_info, word)) {
        assert(0);
    };
}

void words_info(file_info * f_info, char * name_file) {
    FILE * text_file = fopen(name_file, "r");
    if (text_file == NULL) {
        return;
    }
    char str[30] = "";
    char sym;
    while ((sym = fgetc(text_file)) != EOF) {
        if (lower(sym) >= 'a' && lower(sym) <= 'z') {
            sym = lower(sym);
            strncat(str, &sym, 1); 
        }
        else {
            if (str != "") {
                add_word_in_file_tf_idf(f_info, str);
                f_info->n_words += 1;
                str[0] = '\0';
            }
        }
    }
    fclose(text_file);
}

void file_tf_idf(file_info * f_info) {
    for (int i = 0; i < f_info->size; ++i) {
        f_info->file_prop[i].tf_idf = (float) f_info->file_prop[i].count / f_info->n_words;
    }
}

void incert_in_top_list(word_info * w_info, word_info * top[N_TOP]) {
    size_t i = 0;
    while (i < N_TOP && top[i] != NULL && w_info->count < top[i]->count) {
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

file_info create_file_info(char * name_file) {
    file_info f_info;
    f_info.name = name_file;
    size_t n_words = 0;
    f_info.size = 0;
    f_info.buf_size = 0;
    f_info.n_words = 0;
    f_info.file_prop = (word_info *)malloc(sizeof(word_info) * START_BUFFER_TF_IDF);
    if (f_info.file_prop != NULL) {
        f_info.buf_size = START_BUFFER_TF_IDF;
    }
    words_info(&f_info, name_file);
    file_tf_idf(&f_info);
    create_file_top_words(&f_info);
    return f_info;
}


void clear_file_info(file_info * f_info) {
    f_info->n_words = 0;
    f_info->name = "";
    f_info->size = 0;
    f_info->buf_size = 0;
    f_info->n_words = 0;
    free(f_info->file_prop);
    f_info->file_prop = NULL;
    for (int i = 0; i < N_TOP; ++i) {
        f_info->top_words[i] = NULL;
    }
}