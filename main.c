#include <stdio.h>
#include "team_list.h"
#define STR_CONST_LEN 255

int print_team_table(team_list * t_list) {
    if(t_list == NULL) {
        return 1;
    }
    int i = 0;
    while (i < t_list->size) {
        printf("#%i ", i + 1);
        printf("Team number %i, name = %s, time = %f, items = %i\n", t_list->teams[i]->number, t_list->teams[i]->name, t_list->teams[i]->time, t_list->teams[i]->items);
        ++i;
    }
    return 0;
}

int print_top_teams(team_list * t_list) {
    if(t_list == NULL) {
        return 1;
    }
    printf("\tTOP LIST\n");
    team_list toplist = create_top_list(t_list);
    print_team_table(&toplist);
    clear_team_list(&toplist);
    return 0;
}

int add_team(team_list * t_list) {
    if(t_list == NULL) {
        return 1;
    }
    int number;
    char name[STR_CONST_LEN];
    float time;
    int items;
    printf("Team number = ");
    scanf("%i", &number); 
    printf("Team name = ");
    scanf("%254s", name);
    printf("Team time = ");
    scanf("%f", &time);
    printf("Team items = ");
    scanf("%i", &items);
    return add_team_in_list(t_list, number, name, time, items);
}

int processor_of_command(int cmd, team_list * t_list) {
    if (t_list == NULL) {
        return 1;
    }
    switch (cmd) {
        case 1: return add_team(t_list);
        case 2: return print_team_table(t_list);
        case 3: return print_top_teams(t_list);
        case 0: return 0;
        default: 
            printf("Command is not recognized\n");
            return 0;
    }
}

int run() {
    team_list t_list = create_team_list();
    printf("1 - Add team, 2 - Print list of all teams, 3 - Print TOP list of teams, 0 - exit\n");
    int command = 1;
    while (command) {
        printf("Input command: ");
        scanf("%i", &command);
        int return_code = processor_of_command(command, &t_list);
        if (return_code == 1) {
            clear_team_list(&t_list);
            return return_code;
        }
    }
    clear_team_list(&t_list);
    return 0;
}

int main() {
    return run();
}
