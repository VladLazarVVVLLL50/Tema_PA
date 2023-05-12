#include "task_1.h"
#include "task_2.h"

int main(){

 FILE *f;
 f=fopen("c.in","r");
 if(f==NULL){
  printf("eroare");
  exit(1);
 }

 int i,number_of_teams=0;
 Team* list_of_teams=NULL;

 int
 *tasks = (int*)malloc(6*sizeof(int));
 for(i=1;i<=5;i++)fscanf(f,"%d",&tasks[i]);

 list_of_teams=solve_task_1(&number_of_teams);

 if(tasks[1])display(list_of_teams);

 solve_task_2(&list_of_teams,&number_of_teams);

 if(tasks[2])display(list_of_teams);

 free_team_list(&list_of_teams);
 fclose(f);
 return 0;
}
