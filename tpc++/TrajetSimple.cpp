/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#define MAP

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void TrajetSimple::Afficher() const {
    cout<<"Depart : "<<depart<<" --Arrivee : "<<arrivee<<endl;
    switch(this->moyenDeTransport){
        case AUTO:
            cout << "Moyen de Transport : Auto" << endl;
            break;
        case AVION:
            cout << "Moyen de Transport : AVION" << endl;
            break;
        case TRAIN:
            cout << "Moyen de Transport : Train" << endl;
            break;
        case BATEAU:
            cout << "Moyen de Transport : BATEAU" << endl;
            break;
    }
}
const char* TrajetSimple::getDepart() const{
  return this->depart;
}
const char* TrajetSimple::getArrivee() const{
  return this->arrivee;
}

//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::TrajetSimple(const char* pDep,const  char* pArr, MT moyTransport){
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetSimple>" << endl;
  #endif
    depart = pDep;
    arrivee = pArr;
    moyenDeTransport=moyTransport;
}

TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete [] depart;
    delete [] arrivee;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
