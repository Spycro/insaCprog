/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Ajouter(TrajetSimple* trajet){
    if(tailleActuelle==tailleMax){
      tailleMax*=2;
      TrajetSimple ** temp = catalogue;
      catalogue = new TrajetSimple*[tailleMax];
      for (size_t i = 0; i < tailleActuelle; i++) {
        catalogue[i] = temp[i];
      }
      delete [] temp;
    }
    catalogue[tailleActuelle++] = trajet;
}
// Algorithme :
// si tailleActuelle = tailleMax on agrandi le catalogue de 5 trajet
// avant de faire l'ajout
// sinon on ajoute simplement le trajet
// On augmente tailleActuelle de 1
//


void Catalogue::Afficher() const{
    for(uint i=0; i<tailleActuelle; i++){
      catalogue[i]->Afficher();
    }
}
// Algorithme :
// on parcourt tout le tableau de TrajetSimple du catalogue
// Pour chaque TrajetSimple on appelle la méthode Afficher
//



void Catalogue::Rechercher(const char * dep, const char * arr) const{
  for(uint i=0;i<tailleActuelle;i++){
    if(strcmp(dep,this->catalogue[i]->getDepart())==0 && strcmp(arr,this->catalogue[i]->getArrivee())==0){
      catalogue[i]->Afficher();
    }
  }
}
// Algorithme :
// on parcourt tout le tableau de TrajetSimple du catalogue
// Pour chaque Trajet du catalogue on vérifie si les attributs depart et
// arrivee correspondent respectivement au parametre formel dep et arr
// que l'on recherche
// Si c'est le cas on affiche le trajet en appelant la méthode Afficher


void Catalogue::RechercheAvancee(const char * dep, const char * arr) const
{
  /*int adjacence[tailleActuelle][tailleActuelle];
  //creation de la matrice d'adjacence
  for (uint i = 0; i < tailleActuelle; i++) {
    for (uint j = 0; j < tailleActuelle; j++) {
      if(strcmp(this->catalogue[i]->getArrivee(), this->catalogue[j]->getDepart()) == 0){
        adjacence[i][j] = 1;
      }
      else{
        adjacence[i][j] = 0;
      }
    }
  }
  TrajetSimple** tab=new TrajetSimple*[]*/
  Liste* liste=new Liste;
  liste->precedent=nullptr;
  liste->suivant=nullptr;
/*  for (uint i = 0; i < tailleActuelle; i++) {
    if(strcmp(this->catalogue[i]->getDepart(), dep)){
      liste->trajet = this->catalogue[i];
      this->recursion(liste,catalogue[i]->getArrivee(),arr);
    }

  }*/
  this->recursion(liste,dep,arr);

  delete liste;

}




//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Catalogue::Catalogue ()
//Création d'un catalogue de tailleActuelle = 0 de tailleMax = 5
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    tailleMax=5;
    tailleActuelle=0;
    catalogue=new TrajetSimple*[tailleMax];
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

  for(uint i = 0; i<tailleActuelle; i++){
    delete catalogue[i];
  }
  delete [] catalogue;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Catalogue::recursion (Liste* liste,const char * dep, const char * arr) const{
  for(uint i=0;i<tailleActuelle;i++){

    bool test=true;
    Liste* previous=liste->precedent;
    if(strcmp(catalogue[i]->getDepart(),dep)==0){

      bool test=true;
      Liste* previous=liste;

      //bouvle verifiant si le trajet candidat qu'on vient de detecter est
      //deja dans la liste ou non
      while(previous!=nullptr){
        if(previous->trajet != nullptr
          && strcmp(catalogue[i]->getDepart(),previous->trajet->getDepart()) == 0
            && strcmp(catalogue[i]->getArrivee(),previous->trajet->getArrivee()) == 0)
        {
          test=false;
          cout << "test set to false" << endl;
        }
      previous=previous->precedent;
      }
      //On sort completement car on arrive a un deadend
      //Si test est faux
      if(!test) break;

      //On ajoute le trajet courant a la liste actuelle
      liste->trajet=catalogue[i];
      Liste* newNode=new Liste;
      newNode->precedent=liste;
      newNode->suivant=nullptr;
      liste->suivant=newNode;

      //On verifie si on est arrive au bout du trajet
      if(strcmp(liste->trajet->getArrivee(),arr)==0){
        Liste* current=liste;
        delete liste->suivant;
        current->suivant = nullptr;
        while(current->precedent!=nullptr){
          current=current->precedent;
        }
        cout << "++++Trajet Trouve++++" << endl;
        while(current!=nullptr){
          current->trajet->Afficher();
          current=current->suivant;
        }
        cout << "+++++++++++++++++++++" << endl;
      }else{
        recursion(liste->suivant,catalogue[i]->getArrivee(),arr);
      }
      delete liste->suivant;
    }
  }
}
