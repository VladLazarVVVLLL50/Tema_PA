#include "task_1.h"
#include "task_2.h"
int main(){

 FILE *f;
 int i,number_of_teams;
 char ch;

 f=fopen("c.in","r");
 if(f==NULL){
  printf("eroare");
  exit(1);
 }

 Team* list_of_teams=NULL;
 list_of_teams=solve_task_1(&number_of_teams);

// printf("%d",number_of_teams);
 solve_task_2(&list_of_teams,&number_of_teams);
free_team_list(&list_of_teams);

 /*
 for(i=1;i<=5;i++){
     fscanf(f,"%c",&ch);
     if( ch == '1' && i==1) solve_task_1();
     /*
     else if( ch == '1' && i==2) solve_task_2();
     else if( ch == '1' && i==3) solve_task_3();
     else if( ch == '1' && i==4) solve_task_4();
     else if( ch == '1' && i==5) solve_task_5();

 }
*/
 fclose(f);
 return 0;
}
