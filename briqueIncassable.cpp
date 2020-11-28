#include "briqueIncassable.h"

briqueIncassable::briqueIncassable(double positionX, double positionY,surface& type) : brique {positionX,positionY,type} {
}

briqueIncassable::~briqueIncassable(){
}

void briqueIncassable::affiche() {
    setcolor(GREEN);
    rectangle (getX(),getY(),getX()+100, getY()+10);
}

