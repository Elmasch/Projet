#include "dure.h"

dure::dure(double positionX, double positionY) : brique{positionX, positionY}{
}

dure::~dure()
{
    //dtor
}

void dure::affiche(){
    setcolor(GREEN);
    rectangle (getX(),getY(),getX()+100, getY()+10);
}

void dure::collision (balle b){
}
