#include "briqueIncassable.h"

briqueIncassable::briqueIncassable(geom::point& basGauche, geom::point& hautDroite, surface* surface) : brique {basGauche, hautDroite, surface} {
}

briqueIncassable::~briqueIncassable(){
}

int briqueIncassable::getNombre() const{
    return 0;
}

void briqueIncassable::affiche() {
    setcolor(getSurface()->getCouleur());
    bar(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}

bool briqueIncassable::casse(){
    return false;
}

bool briqueIncassable::cassable(){
    return false;
}

void briqueIncassable::efface(){
    setcolor(BLACK);
    bar(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}
