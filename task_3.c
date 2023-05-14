#include "task_3.h"

Team *find_team(Team *list, char *name)
{Team *head = list;
 while(head != NULL){
    if(!strcmp(head->team_name,name))return head;
    head = head->next_team;
 }

}

void raise_score(Team *team){
 team->team_score = team->team_score+1;
 while(team->list_of_members != NULL){
    team->list_of_members->points = team->list_of_members->points+1;
    team->list_of_members=team->list_of_members->next_player;
 }


}


void solve_task_3(Team *initial_list, int number_of_teams, FILE *g1){

 Team *stack_of_winners = NULL;
 Team *stack_of_loosers = NULL;
 Queue *queue_of_matches = create_Queue();
 int round_number = 1;

 display(initial_list,g1);

 Team *val = initial_list;
 while(val != NULL){
    enQueue(queue_of_matches,val->team_name,(val->next_team)->team_name);
    val = val->next_team->next_team;
 }

 while(!is_the_queue_Empty(queue_of_matches)){
    fprintf(g1,"\n--- ROUND NO:%d\n",round_number);
    Match *aux = queue_of_matches->Front;
    while(aux != NULL){
        fprintf(g1,"%-10s - %-10s\n",aux->first_team,aux->second_team);
        Team *team_1 = find_team(initial_list,aux->first_team);
        Team *team_2 = find_team(initial_list,aux->second_team);
        if(team_1->team_score > team_2->team_score){
         raise_score(team_1);
         push(&stack_of_winners,team_1);
         push(&stack_of_loosers,team_2);
        }
        else{
          raise_score(team_2);
          push(&stack_of_winners,team_2);
          push(&stack_of_loosers,team_1);
        }
        aux = aux->next_match;
        deQueue(queue_of_matches);
    }
    fprintf(g1,"\n");
    fprintf(g1," WINNERS OF ROUND NO:%d\n",round_number);
    val = stack_of_winners;
    while(val != NULL){
     fprintf(g1,"%s - %0.2f\n",val->team_name,val->team_score);
     if(val->next_team != NULL){
        fprintf(g1,"%s - %0.2f\n",val->next_team->team_name,val->next_team->team_score);
        enQueue(queue_of_matches,val->team_name,val->next_team->team_name);
        pop(&stack_of_winners);pop(&stack_of_winners);
        val = val->next_team->next_team;
     }
     else{pop(&stack_of_winners); val = val->next_team;}
    }
    deleteStack(&stack_of_loosers);
    round_number++;
  }



}
