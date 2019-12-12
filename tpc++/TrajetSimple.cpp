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
void TrajetSimple::Afficher() const
//On affiche les caracterisques du trajet
{
    cout<<"---Trajet Simple---"<<endl;
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
    cout<<"-------------------"<<endl;
}
const char* TrajetSimple::getDepart() const{
  return this->depart;
}
const char* TrajetSimple::getArrivee() const{
  return this->arrivee;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple ( )
// Algorithme :
// Constructeur par defaut
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::TrajetSimple(const char* pDep,const  char* pArr, MT moyTransport)
//Constructeur utilisee
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetSimple>" << endl;
  #endif
    depart = pDep;
    arrivee = pArr;
    moyenDeTransport=moyTransport;
}

TrajetSimple::~TrajetSimple ( )
// Algorithme :
// On supprime les deux char * alloue dynamiquement
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete [] depart;
    delete [] arrivee;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
