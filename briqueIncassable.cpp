#include "briqueIncassable.h"

briqueIncassable::briqueIncassable(geom::point& basGauche, geom::point& hautDroite, surface* surface) : brique {basGauche, hautDroite, surface} {
}

briqueIncassable::~briqueIncassable(){
}

void briqueIncassable::affiche() {
    setcolor(GREEN);
    rectangle(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}

bool briqueIncassable::casse(){
    return false;
}

void briqueIncassable::efface(){
    setcolor(BLACK);
    rectangle(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}
