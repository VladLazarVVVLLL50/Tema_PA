#include "task_2.h"


int reduce_number(int val){
 int p=0;
 int power_of_2=1;
 while(power_of_2 <= val/2){
    power_of_2*=2;
    p++;
 }
 return power_of_2;
}

int find_score(Team *team){
 int score=0;
 while(team->list_of_members->next_player != NULL){
    score += team->list_of_members->points;
    team->list_of_members=team->list_of_members->next_player;
 }
 return score;
}

void eliminate_teams(Team **head,int number){

 while(number>0){
    Team *aux=(*head);
    int nr=0,min_nr=999999;
    char *name=NULL;
    while(aux->next_team != NULL){
        nr = find_score(aux);

        if(nr>min_nr){
          min_nr=nr;
          name=(char*)malloc(strlen(aux->team_name)*sizeof(char));
          strcpy(name,aux->team_name);
        }
        aux=aux->next_team;
    }

    eliminate_team(head,name);
    number--;
 }



}




void solve_task_2(Team **list_of_teams,int *number_of_teams){
 printf("da");
 int new_number_of_teams=reduce_number(*number_of_teams);
 int nr_of_eliminated_teams=(*number_of_teams)- new_number_of_teams;
 eliminate_teams(list_of_teams,nr_of_eliminated_teams);
 *number_of_teams=new_number_of_teams;
 display(*list_of_teams);
}

