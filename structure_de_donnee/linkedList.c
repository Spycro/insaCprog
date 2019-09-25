#include <stdio.h>
#include <stdlib.h>





typedef struct tag_linkedList{
  int value;
  struct tag_linkedList * next;
} linkedList ;


void insertHeadNode(linkedList ** root, int newValue);
int removeHeadNode(linkedList ** root);
void printList(linkedList * list);
int insertArbitraryNode(linkedList ** list, int newValue, int place);

int removeAValue(linkedList ** list, int valueToRemove);



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
  removeHeadNode(&list);
  printList(list);
  removeAValue(&list, 5);
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

int removeHeadNode(linkedList ** root){
  int val = (*root)->value;
  linkedList * placeHolder = *root;
  *root= (*root)->next;
  free(placeHolder);
  return val;
}

void printList(linkedList * list){

  printf("[ ");
    while(list != NULL){
        printf("%d ", list->value);
        list = list->next;
    }
    printf(" ]\n");
}

int removeAValue(linkedList ** list, int valueToRemove){
  linkedList * precedent;
  linkedList * courant;
  int returnVal;


  if((*list)->value == valueToRemove){
    return removeHeadNode(list);
  }

  do {
    precedent = courant;
    courant = courant->next;
  } while(courant->next != NULL && courant->value != valueToRemove);

  if(courant->value == valueToRemove){
    returnVal = courant->value;
    precedent->next = courant->next;
    free(courant);
    return returnVal;
  }
  return 0;
}
