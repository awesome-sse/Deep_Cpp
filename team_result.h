#pragma once 

struct team;
typedef struct team team;
struct team_list;
typedef struct team_list team_list;

int first_team_is_heigher(team * team1, team * team2);
void add_team_in_list(team * NewTeam);
void add_team(int Number, char* Name, float Time, int Items); 
void print_team_result(team * T);
void print_team_table(team * teams, int size);
void incert_in_toplist(team * T, team * toplist, int size_of_toplist);
team * create_top_list(team_list * tlist, int size_of_toplist);
void print_top_teams();

