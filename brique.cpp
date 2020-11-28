#include "brique.h"



brique::brique(double positionX, double positionY) : d_X{positionX}, d_Y{positionY}{
}
brique::~brique() {
}

double brique::getX() const{
    return d_X;
}

double brique::getY() const{
    return d_Y;
}


