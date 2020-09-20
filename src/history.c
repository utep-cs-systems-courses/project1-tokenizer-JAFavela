#include <stdio.h>
#include <stdlib.h>
#include "history.h"

//This file will include all the methods defined in history.h

/* Initialize the linked list to keep the history. */
List *init_history(){
  List *history = malloc(sizeof(List));
  history->root = malloc(sizeof(Item));
  return history;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *temp = list->root;
  int nid=0;
  while(temp->next!=NULL){
    nid++;
    temp=temp->next;
  }
  temp->id=nid+1;
  temp->str=str;
  temp->next= malloc(sizeof(Item));
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *temp = list->root;
  int nid=0;
  while(temp->id!=id){
    if(temp->next->next==NULL){
      printf("Sorry, please enter a valid ID to retrieve string from history");
      char *err='\0';
      return err;
    }
    temp=temp->next;
  }
  return temp->str;
}

/*Print the entire contents of the list. */
void print_history(List *list){
  printf("Input History:\nID |  Input\n-------------------------------------------\n");
  Item *temp= list->root;
  while(1){
    if(temp->id<10)
      printf(" %d |  %s\n",temp->id,temp->str);
    else
      printf("%d |  %s\n",temp->id,temp->str);
    if(temp->next->next==NULL)
      break;
    temp=temp->next;
  }
  //printf(" %d |%s\n",temp->id,temp->str);
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *behind= list->root;
  Item *ahead;
  while(behind->next!=NULL){
    ahead=behind->next;
    free(behind->next);
    free(behind);
    behind=ahead;
  }
  free(behind->next);
  free(behind);
  behind=ahead;
  free(list);
}
