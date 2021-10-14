#pragma once 

typedef struct team {
    int number;
    char* name;
    float time;
    int items;
} team; 

typedef struct team_list {
    size_t size;
    size_t buffer_size;
    team* teams;
} team_list;


team_list create_team_list();
team_list create_top_list(team_list * t_list);
team make_team(int Number, char* Name, float Time, int Items);
int first_team_is_heigher(team * team1, team * team2);
int add_team_in_list(team_list * t_list, int Number, char* Name, float Time, int Items);
void incert_in_toplist(team_list * top_list, team * T);
void clear_team_list(team_list * t_list);
