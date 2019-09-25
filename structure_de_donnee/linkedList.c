#include <stdio.h>
#include <stdlib.h>





typedef struct tag_linkedList{
  int value;
  struct tag_linkedList * next;
} linkedList ;


void insertHeadNode(linkedList ** root, int newValue);
void removeHeadNode(linkedList * root);
void printList(linkedList * list);
int insertArbitraryNode(linkedList ** list, int newValue, int place);



int main(int argc, char const *argv[]) {
  linkedList * list;
  list = malloc(sizeof(list));
  list->value = 1;
  list->next = NULL;

  for(int i = 0; i< 10; i++){
    insertHeadNode(&list, i);
  }

  insertArbitraryNode(&list, 3, 0);

  printList(list);

  return 0;
}


void insertHeadNode(linkedList ** root, int newValue){
  linkedList * newNode = (linkedList*)malloc(sizeof(newNode));
  newNode->value = newValue;
  newNode->next = *root;
  printf("nouvelle valeur inseree: %d\n", newValue);
  *root = newNode;
}


int insertArbitraryNode(linkedList ** list, int newValue, int place){
  linkedList * newNode = malloc(sizeof(linkedList));
  linkedList * courant;
  linkedList * precedent;

  newNode->value = newValue;
  if(place == 0){
    insertHeadNode(list, newValue);
    return 1;
  }
  if((*list)->next == NULL){
    return 0;
  }

  courant =  (*list);

  int i = 0;

  do{
    precedent = courant;
    courant = courant->next;
    i++;
  } while((*list)->next != NULL && i<place);
  if(i == place--){
    precedent->next = newNode;
    newNode->next = courant;
    return 1;
  }
  return 0;
}

void removeHeadNode(linkedList * root){

  linkedList * placeHolder = root;
  root->next = root->next->next;
  free(placeHolder);
}

void printList(linkedList * list){
    while(list != NULL){
        printf("%d\n", list->value);
        list = list->next;
    }
}
