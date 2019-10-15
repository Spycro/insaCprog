#include <stdio.h>
#include <stdlib.h>


typedef struct elem{
  int value;
  struct elem * next;
} elem ;

void printList(elem * list);
void ajouterEnTete(elem ** first,int val);
int rechercher(elem* list,int valWanted);
void ajouter_en_queue(elem * list, int valeur);
void supprimer(elem ** list,int valor);
void dupliquer(elem ** list, int valed);
int estTrie(elem* list);
void ajouterEnPlace(elem ** list, int valad);
void retourner (elem ** list);


int main(int argc, char const *argv[]) {
  elem * list;
  list=(elem *)malloc(sizeof(elem));
  list->value = 15;
  list->next = NULL;
  while(1)
  {
    printf("\n");
    printf("menu:\n");
    printf("\t1: ajouter en tete\n");
    printf("\t2: afficher la liste\n");
    printf("\t3: ntm\n");
    printf("\t4: Ajouter en fin\n");
    printf("\t5: Retirer une valeur\n");
    printf("\t6: dupliquer une valeur\n");
    printf("\t7: verifier si la liste est triee\n");
    printf("\t8: ajoute une val a la bonne place\n");
    printf("\t9: retourner la liste\n", );
    printf("\t0: quitter\n");
    int choix;
    scanf("%d", &choix);
    int val;
    switch(choix)
    {
      case 0:
        goto fin;
        case 1:
        scanf("%d",&val );
          ajouterEnTete(&list,val);
          break;
        case 2:
          printList(list);
          break;
        case 3:
          scanf("%d",&val );
          printf("%d\n",rechercher(list,val));
          break;
        case 4:
          scanf("%d", &val);
          ajouter_en_queue(list, val);
          break;
        case 5:
          scanf("%d",&val);
          supprimer(&list,val);
          break;
        case 6:
          scanf("%d", &val);
          dupliquer(&list, val);
          break;
        case 7:
          if(estTrie(list)){
              printf("OUI\n");
          }else{
            printf("NEIN\n");
          }
          break;
        case 8:
          scanf("%d", &val);
          ajouterEnPlace(&list, val);
          break;
        case 9:
          scanf("%d", &val);
          retourner(&list);
          break;
        default:
          printf("choix incorrect\n");
          continue ;
          // revenir au menu
        }
    }
    fin:
      printf("au revoir\n");



  return 0;
}

void ajouterEnTete(elem ** first,int val){
  elem * newNode = malloc(sizeof(elem));
  newNode->value=val;
  newNode->next=*first;
  *first = newNode;
}


void printList(elem * myList){

  printf("[ ");
    while(myList != NULL){
        printf("%d ", myList->value);
        myList = myList->next;
    }
    printf(" ]\n");
}

int rechercher(elem* list,int valWanted){
  int position=0;
  while(list->next!=NULL){
    if(list->value==valWanted){
      return position;
    }
    position++;
    list=list->next;
  }
  return -1;
}

void ajouter_en_queue(elem * list, int valeur){
  elem * suivant = list;
  while(suivant->next !=NULL){
    suivant=suivant->next;
  }
  elem * newNode = malloc(sizeof(elem));
  newNode->value = valeur;
  newNode->next = NULL;
  suivant->next = newNode;
}

void supprimer(elem ** list,int valor){
  elem * precedent= *list;
  elem * suivant= *list;
  int pos=0;

  while(suivant!=NULL) {

    if(suivant->value==valor){
      if(pos==0){
        suivant = (*list)->next;
        precedent->next = suivant;
        elem * placeholder = *list;
        *list=(*list)->next;
        free(placeholder);
      }else{
        printf("suppression\n");
        suivant=suivant->next;
        free(precedent->next);
        precedent->next=suivant;
      }

    }
    else{
      precedent=suivant;
      suivant=suivant->next;
      pos++;
    }

  }
}

void dupliquer(elem ** list, int valed)
{
  elem * suivant = *(list);

  while(suivant != NULL){
    if (suivant->value == valed){
      //creation d'un nouvel element
      elem * newNode = malloc(sizeof(elem));
      newNode->value = valed;
      //on attache le nouvel element
      newNode->next = suivant->next;
      suivant->next = newNode;
      //on avance d'une case, pour eviter de redupliquer ce nouvel element
      suivant = suivant->next;
    }
    suivant = suivant->next;

  }
}

int estTrie (elem* list)
{
  while(list->next!=NULL){
    if(list->next->value<list->value){
      return 0;
    }
    list=list->next;
  }
  return 1;
}


void ajouterEnPlace(elem ** list, int valad)
{



  int add = 0;



  if(estTrie(*list)){
    if((*list)->value > valad){
      ajouterEnTete(list, valad);
      add = 1;
    }
    elem * suivant = *(list);

    while(suivant->next != NULL && !add){
      if (suivant->next->value > valad){
        //creation d'un nouvel element
        elem * newNode = malloc(sizeof(elem));
        newNode->value = valad;
        //on attache le nouvel element
        newNode->next = suivant->next;
        suivant->next = newNode;
        add = 1;
        break;
      }
      suivant = suivant->next;
    }
    if(!add)
      ajouter_en_queue(*list, valad);
  }
  else{
    printf("La liste n'est pas triee\n");
  }

}


void retourner (elem ** list)
{
  elem * precedent = NULL;
  elem * courant = * list;
  elem * suivant (*list)->next;

  while (suivant !=NULL) {
    
  }

}
