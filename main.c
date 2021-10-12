#include <stdio.h>
#include "team_result.h"
#define STR_CONST_LEN 255

int main() {
    team_list * tlist = create_team_list();
    for (int i = 0; i < 7; ++i) {
        int number;
        char name[STR_CONST_LEN];
        float time;
        int items;
        printf("NUM = ");
        scanf("%i", &number);
        printf("Name = ");
        scanf("%s", &name);
        printf("TIME = ");
        scanf("%f", &time);
        printf("ITEMS = ");
        scanf("%i", &items);
        add_team_in_list(tlist, number, name, time, items);
    }
    printf("\n");
    print_top_teams(tlist);

    return 0;
}