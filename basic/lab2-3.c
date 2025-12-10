#include<stdio.h>
#include<string.h>

void explode(char chr1[],char split[]) ;

void explode(char chr1[],char split[]){
  int i = 0, count = 0 ;
  char *chr2 ;
  chr2 = strtok(chr1,split) ;
   while (chr2 != NULL){
    printf("chr2[%d] = %s\n",i,chr2) ;
    chr2 = strtok(NULL,split) ;
    i++,count++ ;
   }
 printf("\n\n Count = %d\n",count) ;
}

int main(){
    char text[] = "I/Love/you" ;
    char *split = "/" ;
    explode(text,split) ;
    return 0;
}
