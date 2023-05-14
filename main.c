#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
int main(){

 FILE *f,*g;

 f=fopen("c.in","r");
 if(f==NULL){
  printf("eroare");
  exit(1);
 }
 g=fopen("r.out","w");
 if(g==NULL){
  printf("eroare");
  exit(1);
 }
 int i,number_of_teams=0;
 Team* list_of_teams=NULL;

 int *tasks = (int*)malloc(6*sizeof(int));
 for(i=1;i<=5;i++)fscanf(f,"%d",&tasks[i]);

 list_of_teams=solve_task_1(&number_of_teams);

 if(tasks[1] && !tasks[2])display(list_of_teams,g);

 solve_task_2(&list_of_teams,&number_of_teams);

 if(tasks[2] && !tasks[3])display(list_of_teams,g);

 solve_task_3(list_of_teams,number_of_teams,g);

 free_team_list(&list_of_teams);
 fclose(f);
 fclose(g);
 return 0;
}
