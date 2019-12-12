using namespace std;
#include <iostream>
#include <cstring>

#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

void ajouter(Catalogue * c);
void rechercher(Catalogue * c);
void rechercheAvancee(Catalogue * c);

int main(){

    //Variable de choix du menu
    int val=10;

    //INITIALISATION du Catalogue
    Catalogue * monCatalogue = new Catalogue();

    //Debut de la boucle de menu
    while(val!=0){
        cout<<"Menu : "<<endl;
        cout<<"1 : Ajouter"<<endl;
        cout<<"2 : Afficher"<<endl;
        cout<<"3 : Recherche Simple"<<endl;
        cout<<"4 : Rechercher Avancee"<<endl;
        cout<<"0 : Quitter ce programme"<<endl;
        cin>>val;
        switch(val){
            case 1:
                ajouter(monCatalogue);
                break;
            case 2:
                monCatalogue->Afficher();
                break;
            case 3:
                rechercher(monCatalogue);
                break;
            case 4:
                rechercheAvancee(monCatalogue);
                  break;
            case 0:
                break;
            default : cout<<"Valeur incorrecte"<<endl;
                break;
        }
    }
    cout << "Fin de programme." << endl;
    delete monCatalogue;
    return 0;
}

void ajouter(Catalogue * c){
    int choix = 0;
    char * ville1 = new char[100];
    char * ville2 = new char[100];
    int moyDeTransport;
    cout << "Voulez vous : " << endl << "1 - Trajet Simple" << endl << "2 - Trajet Compose" << endl;
    cin >> choix;

    //switch permettant de savoir si on ajoute un trajet simple ou composee
    switch (choix) {
      //Ajout de trajet Simple
      case 1:
      {
        cout << "Ville de depart : ";
        cin >> ville1;
        cout << endl << "Ville d'arrivee : ";
        cin >> ville2;
        cout << endl;


        cout<<"1 : Auto"<<endl;
        cout<<"2 : Avion"<<endl;
        cout<<"3 : Train"<<endl;
        cout<<"4 : Bateau"<<endl;
        cout<<"Default : Auto" << endl;
        cin >> moyDeTransport;
        switch (moyDeTransport) {
          case 1:
              c->Ajouter(new TrajetSimple(ville1, ville2, AUTO));
              break;
          case 2:
              c->Ajouter(new TrajetSimple(ville1, ville2, AVION));
              break;
          case 3:
              c->Ajouter(new TrajetSimple(ville1, ville2, TRAIN));
              break;
          case 4:
              c->Ajouter(new TrajetSimple(ville1, ville2, BATEAU));
              break;
          default:
              c->Ajouter(new TrajetSimple(ville1, ville2, AUTO));
              break;
        }

        break;
      }
      //Ajout de Trajet Compose
      case 2:
      {
        //Variable permettant de garder en mémoire la première ville choisie
        char * villeDep = new char[100];
        //Variable permettant de garder en mémoire la derniere ville choisie
        char * villeArrivee = new char[100];
        int nbTrajet;
        bool valide=true;
        cout << "Combien de d'escale (1 au minimum)" << endl;
        cin >> nbTrajet;
        ++nbTrajet;
        TrajetSimple ** trajet = new TrajetSimple*[nbTrajet];


        for(int i = 0; i<nbTrajet;i++){

          cout << "Ville de depart : ";
          cin >> ville1;
          cout << endl << "Ville d'arrivee : ";
          //Premier trajet :

          if(i==0){
            strcpy(villeDep, ville1);
          }

          //Comparaison avec nouveau depart et ancienne arrivee
          if(i>0 && strcmp(ville1,ville2)!=0){
            valide=false;
          }
          if(i!=0){
            ville2 = new char[100];
          }

          cin >> ville2;
          cout << endl;
          if(i == nbTrajet - 1) strcpy(villeArrivee, ville2);


          cout<<"1 : Auto"<<endl;
          cout<<"2 : Avion"<<endl;
          cout<<"3 : Train"<<endl;
          cout<<"4 : Bateau"<<endl;
          cout<<"Default : Auto" << endl;
          cin >> moyDeTransport;
          switch (moyDeTransport) {
            case 1:
                trajet[i]=new TrajetSimple(ville1, ville2, AUTO);
                break;
            case 2:
                trajet[i]=new TrajetSimple(ville1, ville2, AVION);
                break;
            case 3:
                trajet[i]=new TrajetSimple(ville1, ville2, TRAIN);
                break;
            case 4:
                trajet[i]=new TrajetSimple(ville1, ville2, BATEAU);
                break;
            default:
                trajet[i]=new TrajetSimple(ville1, ville2, AUTO);
                break;

        }
        ville1 = new char[100];

        }
        //On supprime le dernier ville1 allouee car il est inutile
        delete [] ville1;
        //Verification de la bonne integrite du trajet
        if(valide){
          c->Ajouter(new TrajetCompose(villeDep,villeArrivee,nbTrajet,trajet));
        }else{
          //suppression des trajets et des villes crees
          cout<<"Trajet non conforme"<<endl;
          for (int i = 0; i < nbTrajet; i++) {
            delete trajet[i];
          }
          delete [] trajet;
          delete [] villeDep;
          delete [] villeArrivee;
        }
        break;

      }

      default:
        cout << "valeur incorrecte" << endl;
        break;

    }
}

/*
  fonction ordinaire permettant la recherche simple d'un
  trajet dans le Catalogue.
*/
void rechercher(Catalogue * c){
  char * ville1 = new char[100];
  char * ville2 = new char[100];
  cout << "ville 1 : ";
  cin >> ville1;
  cout << endl << "Ville 2 : ";
  cin >> ville2;
  cout << endl;
  c->Rechercher(ville1, ville2);

  delete [] ville1;
  delete [] ville2;
}

void rechercheAvancee(Catalogue * c){
  char * ville1 = new char[100];
  char * ville2 = new char[100];
  cout << "ville 1 : ";
  cin >> ville1;
  cout << endl << "Ville 2 : ";
  cin >> ville2;
  cout << endl;
  c->RechercheAvancee(ville1, ville2);

  delete [] ville1;
  delete [] ville2;
}
