#include <stdio.h>
#include <stdlib.h>

int main(){

 FILE *f;
 int i;
 char c;

 f=fopen("c.in","r");
 if(f==NULL){
  printf("eroare");
  exit(1);
 }

 for(i=1;i<=5;i++){
     c=fgets(f);
     if( ch == '1' && i==1) solve_task_1();
     else if( ch == '1' && i==2) solve_task_2();
     else if( ch == '1' && i==3) solve_task_3();
     else if( ch == '1' && i==4) solve_task_4();
     else if( ch == '1' && i==5) solve_task_5();
 }

 fclose(f);

}