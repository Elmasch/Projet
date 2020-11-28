#include "brique.h"



brique::brique(double positionX, double positionY, surface& surface) : d_X{positionX}, d_Y{positionY}, d_surface{surface} {
}
brique::~brique() {
}

double brique::getX() const{
    return d_X;
}

double brique::getY() const{
    return d_Y;
}

surface brique::getSurface() const{
    return d_surface;
}
