#include "task_1.h"


 void create_team(Player **curent,int *number,char **name,int offset,int *result){
    
    FILE *f1;
    f1 = fopen("d.in","r");
    if(f1 == NULL){
      printf("eroare");
      exit(1);
    }
    char t_name[100],f_name[100],s_name[100];
    int j,points;
  

    fseek(f1,offset,SEEK_SET);
    fscanf(f1,"%d",number);
    fgets(t_name,100,f1);
    (*name)=(char*)malloc(strlen(t_name)*sizeof(char));
    strcpy((*name),t_name);
    
    for(j=0;j<(*number);j++){
      fscanf(f1,"%s%s%d",f_name,s_name,&points);
      add_player_at_end_of_team(&(*curent),f_name,s_name,points);
    }
    (*result)=ftell(f1);
    fclose(f1);  
}


void solve_task_1(){

    FILE *f1;
    f1 = fopen("d.in","r");
    if(f1 == NULL){
        printf("eroare");
        exit(1);
    }

    int number_of_teams=0,i=0,offset=0;
    Team *list_head = NULL;
    fscanf(f1,"%d",&number_of_teams);
    
    Team *list_of_teams = NULL;
    for(i=0;i<number_of_teams;i++){
      int number_of_members=0,result=0;
      char *name;
      Player *current_team = NULL;
      create_team(&current_team,&number_of_members,&name,offset,&rezult);
      offset=result;   
      add_team_at_beginning_of_list(&list_head,current_team,number_of_members,name);
    }
   display(list_head);
}