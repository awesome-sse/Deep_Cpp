#pragma once 

typedef struct team {
    int number;
    char* name;
    float time;
    int items;
} team; 

typedef struct team_list {
    int size;
    int buffer_size;
    team* teams;
} team_list;


team_list create_team_list();
int first_team_is_heigher(team * team1, team * team2);
void add_team_in_list(team_list * t_list, int Number, char* Name, float Time, int Items);
team make_team(int Number, char* Name, float Time, int Items);
void print_team_result(team * T);
void print_team_table(team_list * t_list);
void incert_in_toplist(team_list * top_list, team * T);
team_list * create_top_list(team_list * t_list);
void print_top_teams(team_list * t_list);
void clear_team_list(team_list * t_list);
