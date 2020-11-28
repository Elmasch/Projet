#include "briqueCassable.h"

briqueCassable::briqueCassable(double positionX, double positionY, surface& type, int nombre) : brique{positionX,positionY,type}, d_nombre{nombre}{
}

briqueCassable::~briqueCassable(){
}

void briqueCassable::affiche() {
    setcolor(BLUE);
    rectangle (getX(),getY(),getX()+100, getY()+10);
}
