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


bool Ensemble::EstEgal( const Ensemble & unEnsemble ) const
{
  if (this->tailleAct != unEnsemble.tailleAct) return false;

  for (int i = 0; i < tailleAct; i++) {
    if(this->contenu[i] != unEnsemble.contenu[i]) return false;
  }

  return true;
}


crduEstInclus Ensemble::EstInclus ( const Ensemble & unEnsemble ) const
{
  if( this->EstEgal(unEnsemble) ) return INCLUSION_LARGE;

  if(this->tailleAct>unEnsemble.tailleAct) return NON_INCLUSION;

  int cmt=0;
  for(int i=0;i<this->tailleAct;i++){
    for(int j=0;j<unEnsemble.tailleAct;j++){
        if(this->contenu[i]==unEnsemble.contenu[j]){
          cmt++;
        }
    }
  }

  if(cmt==this->tailleAct){
    return INCLUSION_STRICTE;
  }else{
    return NON_INCLUSION;
  }
}


crduAjouter Ensemble::Ajouter ( int a )
{
  for (size_t i = 0; i < this->tailleAct; i++) {
    if (this->contenu[i] == a) return DEJA_PRESENT;
  }
  if(tailleAct == tailleMax) return PLEIN;

  contenu[tailleAct] = a;
  tailleAct++;
  selectionSort();
  return AJOUTE;

}

unsigned int Ensemble::Ajuster(int delta)
{
  if(delta>0){
    tailleMax+=delta;
    int * temp = contenu;
    contenu = new int[tailleMax];
    for (size_t i = 0; i < tailleAct; i++) {
      contenu[i] = temp[i];
    }
    delete []temp;
    return tailleMax;
  }
  if(delta==0){
    return tailleMax;
  }
  if(tailleMax-tailleAct<abs(delta)){
    tailleMax=tailleAct;
    int * temp = contenu;
    contenu = new int[tailleMax];
    for (size_t i = 0; i < tailleAct; i++) {
      contenu[i] = temp[i];
    }
    delete []temp;
    return tailleMax;
  }else{
    tailleMax+=delta;
    int * temp = contenu;
    contenu = new int[tailleMax];
    for (size_t i = 0; i < tailleAct; i++) {
      contenu[i] = temp[i];
    }
    delete []temp;
    return tailleMax;
  }
}

bool Ensemble::Retirer( int element )
{
  bool present=false;
  for(int i=0;i<tailleAct;i++){
    if(contenu[i]==element){
      present=true;
    }
  }
  if(present){
    int* temp=contenu;
    contenu=new int[tailleAct-1];
    int cmt=0;
    for(int i=0;i<tailleAct;i++){
      if(temp[i]!=element){
        contenu[cmt]=temp[i];
        cmt++;
      }

    }
    delete []temp;
    tailleAct--;
    tailleMax = tailleAct;
    return true;
  }else{
    tailleMax=tailleAct;
    return false;
  }
}

unsigned int Ensemble::Retirer(const Ensemble & unEnsemble)
{
  std::cout << "____________________" << '\n' << unEnsemble.tailleMax << unEnsemble.tailleAct;

  std::cout << "____________________" << '\n';
  int tailleMaxBackup = tailleMax;
  int cmt = 0;
  for (size_t i = 0; i < unEnsemble.tailleAct; i++) {
    if(this->Retirer(unEnsemble.contenu[i])){

      cmt++;
    }
  }
  this->tailleMax = tailleMaxBackup;
  return cmt;
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


selectionSort();
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
  selectionSort();
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
  selectionSort();
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
