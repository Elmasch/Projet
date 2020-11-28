#include "raquette.h"

raquette::raquette(geom::point& p, surface* surface) : brique{p, surface}{
}

raquette::~raquette()
{
    //dtor
}

void raquette::affiche(){
    setcolor(YELLOW);
    rectangle(getPosition().x()-50,getPosition().y()-5,getPosition().x()+50, getPosition().y()+5);
}


