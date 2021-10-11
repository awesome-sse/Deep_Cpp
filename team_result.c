#include <stdio.h>
#define N_TOP 10

struct team {
    int number;
    char* name;
    double time;
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
    t_list.size ++;
    t_list.teams = (team *)realloc((&t_list)->teams, sizeof(team) * t_list.size);
    t_list.teams[t_list.size - 1] = *NewTeam;
}

void swap_team_in_list(team *team1, team *team2) {
    team temp = *team1;
    *team1 = *team2;
    *team2 = temp;
}

void add_team(int Number, char* Name, double Time, int Items) {
    team NewTeam;
    NewTeam.number = Number;
    NewTeam.name = Name;
    NewTeam.time = Time;
    NewTeam.items = Items;
    add_team_in_list(&NewTeam);
}

void qsort_teams(team * teams, int left, int right, int comparator(team * team1, team * team2)) {
    int l = left;
    int r = right;
    team * pivot = &teams[left];
    while (l <= r) {
        while (comparator(&teams[l], pivot)) ++l;
        while (comparator(pivot, &teams[r])) --r; 
        if (l <= r) {
            swap_team_in_list(&teams[l], &teams[r]);
            ++l;
            --r;
        }
    }
    
    if (left < r) qsort_teams(teams, left, r, comparator);
    if (right > l) qsort_teams(teams, l, right, comparator);
}

void print_team_result(team T) {
    printf("Team number %i, name = %s, time = %f, items = %i\n", T.number, T.name, T.time, T.items);
}

void print_team_table(int size) {
    int i = 0;
    while (i < t_list.size && i < size) {
        printf("#%i ", i + 1);
        print_team_result(t_list.teams[i]);
        ++i;
    }
}

void print_top_teams() {
    qsort_teams(t_list.teams, 0, t_list.size - 1, first_team_is_heigher);
    print_team_table(N_TOP);
}

