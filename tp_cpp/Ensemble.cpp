/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Ensemble::Afficher( void )
{

  selectionSort();
  cout << tailleAct << "\r\n";
  cout << tailleMax << "\r\n";

  if(tailleAct == 0){
    cout << "{}" << "\r\n";
  }
  else if(tailleAct==1){
    cout << "{"<< contenu[0]<<"}" << "\r\n";
  }
  else{
    cout << "{";
    for (size_t i = 0; i < tailleAct - 1; i++) {
      cout << contenu[i] << ",";
    }
    cout << contenu[tailleAct - 1] << "}" << "\r\n";
  }
}


//------------------------------------------------- Surcharge d'opérateurs
Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
{
} //----- Fin de operator =

//

//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble ( const Ensemble & unEnsemble )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble ( unsigned int cardMax )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif

  tailleMax = cardMax;
  tailleAct = 0;
  contenu = new int[tailleMax];
} //----- Fin de Ensemble


Ensemble::Ensemble ( int t[], unsigned int nbElements)
{
  tailleMax = nbElements;
  contenu = new int[tailleMax];
  int cmt=0;
  bool p = false;
  for (size_t i = 0; i < tailleMax; i++) {
    p = false;
    for (size_t k = 0; k < i; k++) {

      if(t[i] == t[k])
      {
        p = true;
      }
    }
    if(!p){
      contenu[cmt] = t[i];
      cmt++;
    }
  }
  tailleAct = cmt;
}

Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif

  delete []contenu;

} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE
void Ensemble::selectionSort() {
   int i, j, min, temp;
   for (i = 0; i < tailleAct - 1; i++) {
      min = i;
      for (j = i + 1; j < tailleAct; j++)
         if (contenu[j] < contenu[min])
            min = j;
         temp = contenu[i];
         contenu[i] = contenu[min];
         contenu[min] = temp;
   }
}
//----------------------------------------------------- Méthodes protégées
