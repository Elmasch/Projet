#include "raquette.h"

raquette::raquette(double positionX, double positionY, surface& type) : brique{positionX, positionY, type}{
}

raquette::~raquette()
{
    //dtor
}

void raquette::affiche(){
    setcolor(YELLOW);
    rectangle (getX(),getY(),getX()+100, getY()+10);
}


