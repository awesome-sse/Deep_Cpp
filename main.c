#include <stdio.h>
#include "team_list.h"
#define STR_CONST_LEN 254

void print_team_result(team * T) {
    printf("Team number %i, name = %s, time = %f, items = %i\n", T->number, T->name, T->time, T->items);
}

void print_team_table(team_list * t_list) {
    int i = 0;
    while (i < t_list->size) {
        printf("#%i ", i + 1);
        print_team_result(&(t_list->teams)[i]);
        ++i;
    }
}

void print_top_teams(team_list * t_list) {
    team_list toplist = create_top_list(t_list);
    print_team_table(&toplist);
    clear_team_list(&toplist);
}


int main() {
    team_list tlist = create_team_list();
    for (int i = 0; i < 10; ++i) {
        int number;
        char name[STR_CONST_LEN];
        float time;
        int items;
        printf("NUM = ");
        scanf("%i", &number);
        printf("Name = ");
        scanf("%254s", name);
        printf("TIME = ");
        scanf("%f", &time);
        printf("ITEMS = ");
        scanf("%i", &items);
        add_team_in_list(&tlist, number, name, time, items);
    }
    printf("\n");
    print_top_teams(&tlist);
    clear_team_list(&tlist);
    return 0;
}