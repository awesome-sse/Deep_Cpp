#include <gtest/gtest.h>
#include <cstring>
#include <iostream>
extern "C" {
    #include "tools.h"
    #include "lib_file_data_consistent.h"
    #include "lib_file_data_parallel.h"
}

TEST(TEAM_LIST_TEST, test_clear_list) {
  file_info f_info = create_file_info("../test_files/1.txt", "1.txt");
  clear_file_info(&f_info);
  EXPECT_EQ(f_info.file_prop, nullptr);
}

TEST(TEAM_LIST_TEST, test_creating_file_info) {
  file_info f_info = create_file_info("../test_files/2.txt", "2.txt");
  EXPECT_EQ(f_info.size, 0);
  EXPECT_EQ(f_info.buf_size, 4);
  clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, test_lib_file_data_consistent) {
    top_words * t_w = files_top_words_consistent("../test_files", 0);
    EXPECT_EQ(t_w[0].top_words[0], "a");
    free(t_w);
}

TEST(TEAM_LIST_TEST, test_lib_file_data_parallel) {
    top_words * t_w = files_top_words_parallel("../test_files", 1);
    EXPECT_EQ(t_w[0].top_words[0], "a");
    EXPECT_EQ(t_w[0].top_words[1], "b");
    EXPECT_EQ(t_w[0].top_words[2], "c");
    EXPECT_EQ(t_w[0].top_words[3], "d");
    EXPECT_EQ(t_w[0].top_words[4], "e");
    free(t_w);
}

TEST(TEAM_LIST_TEST, test_increase_buf_size) {
  file_info f_info = create_file_info("../test_files/3.txt", "3.txt");
    EXPECT_EQ(f_info.size, 5);
    EXPECT_EQ(f_info.buf_size, 8);
    clear_file_info(&f_info);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
