#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  struct studentNode
  {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode* next;
  };
  void saveNode(struct studentNode* child,char n[], int a, char s, float g);
  void Gonext(struct studentNode* walk);
 int main(){
   struct studentNode *start, *now1, *now2;
   start = (struct studentNode*)malloc(sizeof(struct studentNode));
   saveNode(start,"one",6,'F',3.11);

   start->next = (struct studentNode*)malloc(sizeof(struct studentNode));
   saveNode(start->next,"two",8,'M',3.22);

   start->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
   saveNode(start->next->next,"three",10,'M',3.33);    

   start->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
   saveNode(start->next->next->next,"four",12,'F',3.44);

   now1 = start;
   now2 = start->next;

   Gonext(now1);
   printf("Now - 1 %s\n",now1->name);
    Gonext(now2);
   printf("Now - 2 %s\n",now2->name);
    return 0;
 }
 void saveNode(struct studentNode* child,char n[], int a, char s, float g){
   strcpy(child->name,n);
   child->age = a;
   child->sex = s;
   child->gpa = g;
}
void Gonext(struct studentNode* walk){
  walk = walk->next;
}