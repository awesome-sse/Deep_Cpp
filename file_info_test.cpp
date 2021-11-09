#include <gtest/gtest.h>
#include <cstring>
#include <iostream>
extern "C" {
    #include "file_info.c"
}

TEST(TEAM_LIST_TEST, test_clear_list) {
  file_info f_info = create_file_info("test_files/1.txt", "1.txt");
  clear_file_info(&f_info);
  EXPECT_EQ(f_info.file_prop, nullptr);
}

TEST(TEAM_LIST_TEST, test_creating_file_info) {
  file_info f_info = create_file_info("test_files/2.txt", "2.txt");
  EXPECT_EQ(f_info.size, 0);
  EXPECT_EQ(f_info.buf_size, 4);
  clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, test_file_properties_count) {
    file_info f_info = create_file_info("test_files/1.txt", "1.txt");
    EXPECT_EQ(f_info.top_words[0]->count, 5);
    EXPECT_EQ(f_info.top_words[1]->count, 4);
    EXPECT_EQ(f_info.top_words[2]->count, 3);
    EXPECT_EQ(f_info.top_words[3]->count, 2);
    EXPECT_EQ(f_info.top_words[4]->count, 1);
    clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, test_file_properties_name) {
    file_info f_info = create_file_info("test_files/1.txt", "1.txt");
    EXPECT_EQ(f_info.file_prop[0].word_name, "a");
    EXPECT_EQ(f_info.file_prop[1].word_name, "r");
    EXPECT_EQ(f_info.file_prop[2].word_name, "s");
    EXPECT_EQ(f_info.file_prop[3].word_name, "f");
    EXPECT_EQ(f_info.file_prop[4].word_name, "o");
    clear_file_info(&f_info);
}

TEST(TEAM_LIST_TEST, test_increase_buf_size) {
  file_info f_info = create_file_info("test_files/3.txt", "3.txt");
    EXPECT_EQ(f_info.size, 5);
    EXPECT_EQ(f_info.buf_size, 8);
    clear_file_info(&f_info);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
