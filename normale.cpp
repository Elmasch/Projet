#include "normale.h"
#include <iostream>
normale::normale(double positionX, double positionY) : brique{positionX, positionY}{
}

normale::~normale()
{
    //dtor
}

void normale::affiche(){
    setcolor(BLUE);
    rectangle (getX(),getY(),getX()+100, getY()+10);
}

void normale::collision (balle b) {
    if((b.getX()>=getX() && b.getX()<=getX()+100) && (b.getY()<=getY() && b.getY()>=getY()-10))
    {

    }
}
