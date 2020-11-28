#include "brique.h"



brique::brique(double positionX, double positionY, surface& type) : d_X{positionX}, d_Y{positionY}, d_type{type} {
}
brique::~brique() {
}

double brique::getX() const{
    return d_X;
}

double brique::getY() const{
    return d_Y;
}


