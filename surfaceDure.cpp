#include "surfaceDure.h"

surfaceDure::surfaceDure()
{
    //ctor
}


surfaceDure::~surfaceDure()
{
    //dtor
}

double surfaceDure::getVitesse() const{
    return 1.2;
}

bool surfaceDure::getMorte() const {
        return false;
}

int surfaceDure::getCouleur() const{
    return 10;
}
