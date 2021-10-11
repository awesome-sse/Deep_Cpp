#include <stdio.h>
#include "team_result.h"

int main() {

    for (int i = 0; i < 30; ++i) {
        int r = rand();
        add_team(i, "Hello", r / 123, r / 1000);
    }
    print_all_teams();
    printf("\n");
    print_top_teams();

    return 0;
}