#include <iostream>
#include "briqueCassable.h"

briqueCassable::briqueCassable(geom::point& basGauche, geom::point& hautDroite, surface* surface, int nombre) : brique{basGauche, hautDroite, surface}, d_nombre{nombre}{
}

briqueCassable::~briqueCassable(){
}

int briqueCassable::getNombre() const{
    return d_nombre;
}

void briqueCassable::affiche() {
    setcolor(getSurface()->getCouleur());
    bar(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}

bool briqueCassable::casse(){
    d_nombre--;
    return d_nombre <1 ;
}

bool briqueCassable::cassable(){
    return true;
}

void briqueCassable::efface(){
    setcolor(BLACK);
    bar(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}
