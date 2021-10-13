#include <stdio.h>
#include "team_list.h"
#define STR_CONST_LEN 254

int main() {
    team_list tlist = create_team_list();
    for (int i = 0; i < 7; ++i) {
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