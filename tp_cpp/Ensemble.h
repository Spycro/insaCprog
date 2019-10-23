/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const int CARD_MAX = 5;
//------------------------------------------------------------------ Types
typedef enum crduEstInclus{NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE  } crduEstInclus;
typedef enum crduAjouter{DEJA_PRESENT, PLEIN, AJOUTE} crduAjouter;
//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher( void );
    bool EstEgal( const Ensemble & unEnsemble ) const;
    crduEstInclus EstInclus (const Ensemble & unEnsemble ) const;
    crduAjouter Ajouter(int a);
    unsigned int Ajuster(int delta);
    bool Retirer(int element);
    unsigned int Retirer(const Ensemble & unEnsemble);
//------------------------------------------------- Surcharge d'opérateurs
  //    Ensemble & operator = ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ensemble ( const Ensemble & unEnsemble );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ensemble ( unsigned int cardMax = CARD_MAX );
    // Mode d'emploi :
    //
    // Contrat :

    Ensemble ( int t[], unsigned int nbElements );

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  void selectionSort();
//----------------------------------------------------- Attributs protégés
  unsigned int tailleMax;
  unsigned int tailleAct;
  int *contenu;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H
