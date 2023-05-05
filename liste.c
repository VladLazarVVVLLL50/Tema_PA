#include "liste.h"

void add_player_at_beginning_of_team(Player **head, char *first_n, char *second_n, int p){

    Player *newPlayer = (Player*)malloc(sizeof(Player));
    newPlayer->firstName=(char*)malloc(strlen(first_n)*sizeof(char));
    strcpy(newPlayer->firstName,first_n);
    newPlayer->secondName=(char*)malloc(strlen(second_n)*sizeof(char));
    strcpy(newPlayer->secondName,second_n);
    newPlayer->points=p;
    newPlayer->next_player=*head;
    *head=newPlayer;
}

void add_player_at_end_of_team(Player **head, char *first_n, char *second_n, int p){

    Player *aux=*head;
    Player *newPlayer = (Player*)malloc(sizeof(Player));
    newPlayer->firstName=(char*)malloc(strlen(first_n)*sizeof(char));
    strcpy(newPlayer->firstName,first_n);
    newPlayer->secondName=(char*)malloc(strlen(second_n)*sizeof(char));
    strcpy(newPlayer->secondName,second_n);
    newPlayer->points=p;

    if(*head == NULL) add_player_at_beginning_of_team(&*head,first_n,second_n,p);
    else{
        while(aux->next_player != NULL)aux=aux->next_player;
        aux->next_player = newPlayer;
        newPlayer->next_player = NULL;
    }

}

void add_team_at_beginning_of_list(Team **head, Player *member_list, int nr_members, char *name){

    Team *newTeam = (Team*)malloc(sizeof(Team));
    newTeam->number_of_members = nr_members;
    newTeam->team_name=(char*)malloc(strlen(name)*sizeof(char));
    strcpy(newTeam->team_name,name);
    newTeam->list_of_members = member_list;
    newTeam->next_team = *head;
    *head = newTeam;

}

void display(Team *head){

   FILE *g1;
   g1=fopen("r.out","w");
   if(g1 == NULL){
    printf("eroare!");
    exit(1);
   }

   while(head != NULL){
    fprintf(g1,"%s\n",head->team_name);
    head=head->next_team;
   }
   fclose(g1);


}
