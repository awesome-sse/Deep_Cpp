#include <stdio.h>
#include "team_result.h"
#define STR_CONST_LEN 255

int main() {

    for (int i = 0; i < 5; ++i) {
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
        add_team(number, name, time, items);
    }
    printf("\n");
    print_top_teams();

    return 0;
}