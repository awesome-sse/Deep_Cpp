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

TEST(TEAM_LIST_TEST, test_increase_buf_size) {
  file_info f_info = create_file_info("../test_files/3.txt", "3.txt");
    EXPECT_EQ(f_info.size, 5);
    EXPECT_EQ(f_info.buf_size, 8);
    clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, test_file_proferties) {
    file_info f_info = create_file_info("../test_files/1.txt", "1.txt");
    EXPECT_EQ(f_info.file_prop[0].count, 5);
    
    EXPECT_EQ(f_info.n_words, 15);
    ASSERT_FLOAT_EQ(f_info.file_prop[0].tf_idf, (float) 5 / 15);
    clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, testfiles_lib_file_data_consistent) {
    top_words * t_w = files_top_words_consistent("../test_files", 0);
    ASSERT_STREQ(t_w[0].file_name, "1.txt");
    ASSERT_STREQ(t_w[1].file_name, "2.txt");
    ASSERT_STREQ(t_w[2].file_name, "3.txt");

    free(t_w);
}

TEST(TEAM_LIST_TEST, test_lib_file_data_consistent) {
    top_words * t_w = files_top_words_consistent("../test_files", 0);
    //1.txt
    ASSERT_STREQ(t_w[0].top_words[0], "a");
    ASSERT_STREQ(t_w[0].top_words[1], "b");
    ASSERT_STREQ(t_w[0].top_words[2], "c");
    ASSERT_STREQ(t_w[0].top_words[3], "d");
    ASSERT_STREQ(t_w[0].top_words[4], "e");
    //2.txt
    ASSERT_STREQ(t_w[1].top_words[0], "");
    ASSERT_STREQ(t_w[1].top_words[1], "");
    ASSERT_STREQ(t_w[1].top_words[2], "");
    ASSERT_STREQ(t_w[1].top_words[3], "");
    ASSERT_STREQ(t_w[1].top_words[4], "");
    //3.txt
    ASSERT_STREQ(t_w[2].top_words[0], "awegjn");
    ASSERT_STREQ(t_w[2].top_words[1], "woeignweg");
    ASSERT_STREQ(t_w[2].top_words[2], "oimewgoiw");
    ASSERT_STREQ(t_w[2].top_words[3], "emiewg");
    ASSERT_STREQ(t_w[2].top_words[4], "mewgmioweg");

    free(t_w);
}

TEST(TEAM_LIST_TEST, testfiles_lib_file_data_parallel) {
    top_words * t_w = files_top_words_parallel("../test_files", 10);
    ASSERT_STREQ(t_w[0].file_name, "1.txt");
    ASSERT_STREQ(t_w[1].file_name, "2.txt");
    ASSERT_STREQ(t_w[2].file_name, "3.txt");

    clear_top_words_for_parallel(t_w, "../test_files");
}

TEST(TEAM_LIST_TEST, test_lib_file_data_parallel) {
    top_words * t_w = files_top_words_parallel("../test_files", 10);
    //1.txt
    ASSERT_STREQ(t_w[0].top_words[0], "a");
    ASSERT_STREQ(t_w[0].top_words[1], "b");
    ASSERT_STREQ(t_w[0].top_words[2], "c");
    ASSERT_STREQ(t_w[0].top_words[3], "d");
    ASSERT_STREQ(t_w[0].top_words[4], "e");
    //2.txt
    ASSERT_STREQ(t_w[1].top_words[0], "");
    ASSERT_STREQ(t_w[1].top_words[1], "");
    ASSERT_STREQ(t_w[1].top_words[2], "");
    ASSERT_STREQ(t_w[1].top_words[3], "");
    ASSERT_STREQ(t_w[1].top_words[4], "");
    //3.txt
    ASSERT_STREQ(t_w[2].top_words[0], "awegjn");
    ASSERT_STREQ(t_w[2].top_words[1], "woeignweg");
    ASSERT_STREQ(t_w[2].top_words[2], "oimewgoiw");
    ASSERT_STREQ(t_w[2].top_words[3], "emiewg");
    ASSERT_STREQ(t_w[2].top_words[4], "mewgmioweg");

    clear_top_words_for_parallel(t_w, "../test_files");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
