#include "raquette.h"

raquette::raquette(geom::point& basGauche, geom::point& hautDroite, surface* surface) : brique{basGauche, hautDroite, surface}{
}

raquette::~raquette()
{
    //dtor
}

void raquette::bouge(const char& direction, int hauteur, int largeur){
    efface();
    deplace(direction,hauteur,largeur);
    affiche();
}

void raquette::affiche(){
    setcolor(9);
    bar(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}


bool raquette::casse(){
    return false;
}

void raquette::efface(){
    setcolor(BLACK);
    bar(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}
