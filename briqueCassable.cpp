#include "briqueCassable.h"
#include <iostream>
briqueCassable::briqueCassable(geom::point& basGauche, geom::point& hautDroite, surface* surface, int nombre) : brique{basGauche, hautDroite, surface}, d_nombre{nombre}{
}

briqueCassable::~briqueCassable(){
}

void briqueCassable::affiche() {
    setcolor(BLUE);
    rectangle(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}

bool briqueCassable::casse(){
    d_nombre--;
    return d_nombre <1 ;
}

void briqueCassable::efface(){
    setcolor(BLACK);
    rectangle(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}
