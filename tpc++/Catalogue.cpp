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
