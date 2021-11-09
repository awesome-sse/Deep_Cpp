#pragma once
#include "tools.h"

top_words * files_top_words_parallel(const char * dirname, size_t max_proc);
int clear_top_words_for_parallel(top_words * t_words, const char * dirname);