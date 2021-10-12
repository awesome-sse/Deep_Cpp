#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_TOP 10

struct team {
    int number;
    char* name;
    float time;
    int items;
}; 

typedef struct team team;

struct team_list {
    int size;
    team* teams;
} t_list;

typedef struct team_list team_list;

int first_team_is_heigher(team * team1, team * team2) {
    if (team1->items == team2->items) return team1->time < team2->time; 
    return team1->items > team2->items;
}

void add_team_in_list(team * NewTeam) {
    t_list.size++;
    t_list.teams = (team *)realloc((&t_list)->teams, sizeof(team) * t_list.size);
    t_list.teams[t_list.size - 1] = *NewTeam;
}

void add_team(int Number, char* Name, float Time, int Items) {
    team NewTeam;
    NewTeam.number = Number;
    NewTeam.name = (char *)malloc(sizeof(Name));
    strcpy(NewTeam.name, Name);
    NewTeam.time = Time;
    NewTeam.items = Items;
    add_team_in_list(&NewTeam);
}

void print_team_result(team * T) {
    printf("Team number %i, name = %s, time = %f, items = %i\n", T->number, T->name, T->time, T->items);
}

void print_team_table(team * teams, int size) {
    int i = 0;
    while (i < size) {
        printf("#%i ", i + 1);
        print_team_result(&teams[i]);
        ++i;
    }
}

void incert_in_toplist(team * T, team * toplist, int size_of_toplist) {
    int i = 0;
    while (i < size_of_toplist && first_team_is_heigher(&toplist[i], T)) ++i;
    if (i < size_of_toplist) {
        for (int j = size_of_toplist - 1; j > i; --j) toplist[j] = toplist[j - 1];
        toplist[i] = *T;
    }
}

team * create_top_list(team_list * tlist, int size_of_toplist) {
    team * top_list;
    top_list = (team *)malloc(sizeof(team) * size_of_toplist);
    team T0;
    T0.number = -1;
    T0.name = "";
    T0.time = -1;
    T0.items = -1;
    for (int i = 0; i < size_of_toplist; ++i) top_list[i] = T0;
    for (int i = 0; i < tlist->size; ++i) incert_in_toplist(&(tlist->teams)[i], top_list, size_of_toplist);
    return top_list;
}

void print_top_teams() {
    int size_of_toplist = N_TOP;
    if (size_of_toplist > t_list.size) size_of_toplist = t_list.size;
    team * top_list = create_top_list(&t_list, size_of_toplist);
    print_team_table(top_list, size_of_toplist);
}

/*
void print_all_teams() {
    int i = 0;
    while (i < t_list.size) {
        print_team_result(&t_list.teams[i]);
        ++i;
    }
}
*/