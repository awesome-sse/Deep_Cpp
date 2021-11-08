#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "assert.h"
#include "generate_files.h"

int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } 
    else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

char* random_word(size_t size) {
    if (size < 1) {
        size = 1;
    }
    
    char * word = (char*)malloc(sizeof(char) * size);
    if (word == NULL) {
        assert(0);
    }

    if (size == 1) {
        word[0] = 'a';
    }
    else {
        for (int i = 0; i < size; ++i) {
            word[i] = "eeeeeeeeeetttttttttaaaaaaaaoooooooiiiiiiinnnnnnnsssssnnnnhhhrrddllccumwfgypbvkxjqz"[random_number(0, 81)];
        }  
    }
    return word;
}

int generate_files_txt(int n_files, int min_words, int max_words) {
    FILE * pFile;
    char signs[6] = {' ', '!', '?', '-', '.', '\n'};
    for (int i = 0; i < n_files; ++i) { 
        char n_file[80];
        sprintf(n_file, "../files/%i.txt", i + 1);
        if ((pFile = fopen(n_file , "w")) == NULL) {
            return 1;
        }
        int n_words = random_number(min_words, max_words);
        for (int j = 0; j < n_words; ++j) {
            int len_word = random_number(1, 10);
            char* word = random_word(len_word);
            fwrite(word, 1, sizeof(char) * len_word, pFile);
            fwrite(&signs[random_number(0, 5)], 1, sizeof(char) , pFile);
            free(word);
        }
        fclose(pFile);
    }
    return 0;
}