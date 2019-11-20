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




    delete b;
    return 0;
}
