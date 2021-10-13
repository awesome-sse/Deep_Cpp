#include <gtest/gtest.h>
#include <cstring>
#include "team_list.c"

TEST(TEAM_LIST_TEST, Assert_1) {
  team_list t_list = create_team_list();
  char team_name[10] = "TEAM";
  add_team_in_list(&t_list, 1, team_name, 100, 7);
  clear_team_list(&t_list);
  EXPECT_EQ(t_list.teams, nullptr);
}

TEST(TEAM_LIST_TEST, Assert_2) {
  team_list t_list = create_team_list();
  EXPECT_EQ(t_list.size, 0);
  EXPECT_EQ(t_list.buffer_size, 10);
  clear_team_list(&t_list);
}

TEST(TEAM_LIST_TEST, Assert_3) {
  team_list t_list = create_team_list();
  char team_name[10] = "TEAM";
  add_team_in_list(&t_list, 1, team_name, 100, 10);
  EXPECT_EQ(t_list.size, 1);
  EXPECT_EQ(t_list.buffer_size, 10);
  clear_team_list(&t_list);
}

TEST(TEAM_LIST_TEST, Assert_4) {
  team_list t_list = create_team_list();
  char team_name[10] = "TEAM";
  add_team_in_list(&t_list, 1, team_name, 100, 10);
  add_team_in_list(&t_list, 2, team_name, 70, 8);
  add_team_in_list(&t_list, 3, team_name, 150, 9);
  add_team_in_list(&t_list, 4, team_name, 50, 5);
  add_team_in_list(&t_list, 5, team_name, 200, 8);
  EXPECT_EQ(t_list.size, 5);
  EXPECT_EQ(t_list.buffer_size, 10);
  clear_team_list(&t_list);
}

TEST(TEAM_LIST_TEST, Assert_5) {
  team_list t_list = create_team_list();
  char team_name[10] = "TEAM";
  add_team_in_list(&t_list, 1, team_name, 100, 10);
  add_team_in_list(&t_list, 2, team_name, 70, 8);
  add_team_in_list(&t_list, 3, team_name, 150, 9);
  add_team_in_list(&t_list, 4, team_name, 50, 5);
  add_team_in_list(&t_list, 5, team_name, 200, 8);
  add_team_in_list(&t_list, 6, team_name, 100, 4);
  add_team_in_list(&t_list, 7, team_name, 70, 8);
  add_team_in_list(&t_list, 8, team_name, 140, 9);
  add_team_in_list(&t_list, 9, team_name, 30, 5);
  add_team_in_list(&t_list, 10, team_name, 169, 2);
  add_team_in_list(&t_list, 11, team_name, 54, 5);
  add_team_in_list(&t_list, 12, team_name, 20, 3);
  EXPECT_EQ(t_list.size, 12);
  EXPECT_EQ(t_list.buffer_size, 20);
  clear_team_list(&t_list);
}

TEST(TEAM_LIST_TEST, Assert_6) {
  team_list t_list = create_team_list();
  char team_name[10] = "TEAM";
  add_team_in_list(&t_list, 1, team_name, 100, 7);
  add_team_in_list(&t_list, 2, team_name, 70, 9);
  add_team_in_list(&t_list, 3, team_name, 150, 9);
  add_team_in_list(&t_list, 4, team_name, 1, 4);
  add_team_in_list(&t_list, 5, team_name, 200, 6);
  team_list top = create_top_list(&t_list);
  int real_top_numbers[5] = {2, 3, 1, 5, 4};
  int my_top_numbers[5];
  for (int i = 0; i < 5; ++i) my_top_numbers[i] = top.teams[i].number;
  EXPECT_TRUE(0 == std::memcmp(real_top_numbers, my_top_numbers, sizeof(real_top_numbers)));
  clear_team_list(&top);
  clear_team_list(&t_list);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}