#include "tueuse.h"

tueuse::tueuse(double positionX, double positionY) : brique{positionX, positionY}{
}

tueuse::~tueuse()
{
    //dtor
}

void tueuse::affiche(){
    setcolor(RED);
    rectangle (getX(),getY(),getX()+100, getY()+10);
}
void tueuse::collision (balle b){
    b.~balle();
}
