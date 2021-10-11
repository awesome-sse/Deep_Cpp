
#pragma once 

struct team;
typedef struct team team;
struct team_list;
typedef struct team_list team_list;

int first_team_is_heigher(team * team1, team * team2);
void add_team_in_list(team * NewTeam);
void swap_team_in_list(team *team1, team *team2);
void add_team(int Number, char* Name, double Time, int Items);
void qsort_teams(team * teams, int left, int right, int comparator(team * team1, team * team2));
void print_team_result(team T);
void print_team_table(int size);
void print_top_teams();
