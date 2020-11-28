#include "raquette.h"

raquette::raquette(geom::point& basGauche, geom::point& hautDroite, surface* surface) : brique{basGauche, hautDroite, surface}{
}

raquette::~raquette()
{
    //dtor
}

void raquette::affiche(){
    setcolor(YELLOW);
    rectangle(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}


