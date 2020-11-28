#include "raquette.h"

raquette::raquette(double positionX, double positionY) : brique{positionX, positionY}{
}

raquette::~raquette()
{
    //dtor
}

void raquette::affiche(){
    setcolor(YELLOW);
    rectangle (getX(),getY(),getX()+100, getY()+10);
}

void raquette::collision (balle b){
}
