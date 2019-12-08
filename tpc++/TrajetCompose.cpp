/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void TrajetCompose::Afficher() const{
    cout << "---TrajetCompose----------------" << endl;
    for(uint i = 0; i<nbTrajet; i++)
    {
        chemin[i]->Afficher();
    }
    cout << "--------------------------------" << endl << endl;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
/*
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)
*/

TrajetCompose::TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::TrajetCompose (const char * pDep, const char * pArr, int taille,TrajetSimple * pChemin[] )
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetCompose>" << endl;
  #endif
    depart=pDep;
    arrivee=pArr;
    nbTrajet=taille;
    chemin = pChemin;

}


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    for (uint i = 0; i < nbTrajet; i++) {
      delete chemin[i];
    }

    delete [] chemin;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
