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
#define MAP

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Ajouter(TrajetSimple* trajet){
    if(tailleActuel==tailleMax){
      tailleMax+=5;
      TrajetSimple ** temp = catalogue;
      catalogue = new TrajetSimple*[tailleMax];
      for (size_t i = 0; i < tailleActuel; i++) {
        catalogue[i] = temp[i];
      }
      delete temp;
    }
    catalogue[tailleActuel++] = trajet;
}
// Algorithme :
// si tailleActuel = tailleMax on agrandi le catalogue de 5 trajet
// avant de faire l'ajout
// sinon on ajoute simplement le trajet
// On augmente tailleActuel de 1
//


void Catalogue::Afficher() const{
    for(int i=0; i<tailleActuel; i++){
      catalogue[i]->Afficher();
    }
}
// Algorithme :
// on parcourt tout le tableau de TrajetSimple du catalogue
// Pour chaque Trajet on appelle la méthode Afficher
//



void Catalogue::Rechercher(char * dep, char * arr) const{
  for(int i=0;i<tailleActuel;i++){
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
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Catalogue::Catalogue ()
//Création d'un catalogue de tailleActuel = 0 de tailleMax = 5
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    tailleMax=5;
    tailleActuel=0;
    catalogue=new TrajetSimple*[tailleMax];
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

  for(int i = 0; i<tailleActuel; i++){
    delete catalogue[i];
  }
  delete [] catalogue;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
