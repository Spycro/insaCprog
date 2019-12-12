/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H
#include "TrajetSimple.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Liste {
  TrajetSimple* trajet;
  Liste* precedent;
  Liste* suivant;
}Liste;
//Struct Liste
//C'est une liste doublement chainee
//Elle nous sera utile lors de l'algrotihme de recherche avancee.


//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Catalogue contenant des TrajetSimple ou des TrajetCompose
// Il possède une taille maximum et une taille actuelle
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    void Ajouter(TrajetSimple* trajet);
    // Mode d'emploi :
    // Prend un TrajetSimple dynamique en parametre et l'ajoute au catalogue
    // tout en verifiant si il faut reallouer le tableau dynamique

    void Afficher() const;
    // Mode d'emploi :
    // Affiche simplement le catalogue


    void Rechercher(const char * dep, const char * arr) const;
    void RechercheAvancee(const char * dep, const char * arr) const;

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi :
    //   Appel simple


    virtual ~Catalogue ( );
    // Mode d'emploi :
    //  suppression d'une zone memoire allouee


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
void recursion (Liste* liste,const char * dep, const char * arr) const;
//----------------------------------------------------- Attributs protégés
    uint tailleActuelle;
    uint tailleMax;
    TrajetSimple ** catalogue;
};
// Mode d'emploi : Methode recurive
// Utilisee lors de la recherche avancee
// elle prend en parametre une liste doublement chaine vide ou sinon
// un parametre dep qui changera a chaque recursion
// un parametre arr qui nous servira de condition d'arret lors de la recherche
//


//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
