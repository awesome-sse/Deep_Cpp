#include <gtest/gtest.h>
#include <cstring>
#include <iostream>
extern "C" {
    #include "tools.h"
    #include "f_timer.h"
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

TEST(TEAM_LIST_TEST, test_increase_buf_size) {
  file_info f_info = create_file_info("../test_files/3.txt", "3.txt");
    EXPECT_EQ(f_info.size, 5);
    EXPECT_EQ(f_info.buf_size, 8);
    clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, test_file_proferties) {
    file_info f_info = create_file_info("../test_files/1.txt", "1.txt");
    EXPECT_EQ(f_info.file_prop[0].count, 5);
    ASSERT_STREQ(f_info.file_prop[0].word_name, "a");
    EXPECT_EQ(f_info.n_words, 15);
    ASSERT_FLOAT_EQ(f_info.file_prop[0].tf_idf, (float) 5 / 15);
    clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, test_lib_file_data_consistent) {
    EXPECT_EQ(0, f_timer(files_top_words_consistent, "../test_files", 0));
}

TEST(TEAM_LIST_TEST, test_lib_file_data_paralllel_1_proc) {
    EXPECT_EQ(0, f_timer(files_top_words_parallel, "../test_files", 1));
}

TEST(TEAM_LIST_TEST, test_lib_file_data_paralllel_10proc) {
    EXPECT_EQ(0, f_timer(files_top_words_parallel, "../test_files", 10));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
