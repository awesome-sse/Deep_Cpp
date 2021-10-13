#include <stdio.h>
#include "team_list.h"
#define STR_CONST_LEN 254

void print_team_table(team_list * t_list) {
    int i = 0;
    while (i < t_list->size) {
        printf("#%i ", i + 1);
        printf("Team number %i, name = %s, time = %f, items = %i\n", t_list->teams[i].number, t_list->teams[i].name, t_list->teams[i].time, t_list->teams[i].items);
        ++i;
    }
}

void print_top_teams(team_list * t_list) {
    team_list toplist = create_top_list(t_list);
    print_team_table(&toplist);
    clear_team_list(&toplist);
}

void add_team(team_list * t_list) {
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
    add_team_in_list(t_list, number, name, time, items);
}

int processor_of_command(int cmd, team_list * t_list) {
    if (cmd == 1) {
        add_team(t_list);
    }
    else if (cmd == 2) {
        print_top_teams(t_list);
    }
    else return 0;

    return 1;
}

int run() {
    team_list t_list = create_team_list();
    int command = 1;
    printf("1 - Add team, 2 - Print top list of teams, Another command - exit\n");
    while (command) {
        printf("Input command: ");
        scanf("%i", &command);
        command = processor_of_command(command, &t_list);
    }
    clear_team_list(&t_list);
}

int main() {
    run();
    return 0;
}