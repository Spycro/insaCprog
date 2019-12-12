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
    // Contrat :
    //
    void Ajouter(TrajetSimple* trajet);
    void Afficher() const;
    void Rechercher(const char * dep, const char * arr) const;
    void RechercheAvancee(const char * dep, const char * arr) const;

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi :
    //   Appel simple
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //  Delete d'une zone memoire allouee
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
void recursion (Liste* liste,const char * dep, const char * arr) const;
//----------------------------------------------------- Attributs protégés
    uint tailleActuelle;
    uint tailleMax;
    TrajetSimple ** catalogue;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
