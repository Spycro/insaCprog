using namespace std;
#include <iostream>

#include "TrajetSimple.h"
#include "TrajetCompose.h"


int main(){
    /*ajetSimple* a1 = new TrajetSimple("Paris", "Lyon", AVION);
    a1->Afficher();
    TrajetSimple* a2 = new TrajetSimple("Lyon", "Tours", TRAIN);
    a2->Afficher();*/
    TrajetSimple **  tab = new TrajetSimple*[2];
    tab[0] = new TrajetSimple("Paris", "Lyon", AVION);
    tab[1] = new TrajetSimple("Lyon", "Tours", TRAIN);
    TrajetSimple* b=new TrajetCompose("Paris","Toulouse",2,tab);
    b->Afficher();

    int val=10;
    while(val!=0){
        cout<<"Menu : "<<endl;
        cout<<"1 : Ajouter"<<endl;
        cout<<"2 : Afficher"<<endl;
        cout<<"3 : Rechercher pas mieux"<<endl;
        cout<<"4 : Rechercher mieux"<<endl;
        cout<<"0 : Quitter ce programme pas ouf"<<endl;
        cin>>val;
        switch(val){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default : cout<<"bah alors on pue la merde"<<endl;
                break;
        }
    }
    cout << "Ciao les nullos" << endl;


    delete b;
    return 0;
}
