#include "surfaceNormale.h"

surfaceNormale::surfaceNormale()
{
    //ctor
}

surfaceNormale::~surfaceNormale()
{
    //dtor
}

double surfaceNormale::getVitesse() const{
    return 1;
}

bool surfaceNormale::getMorte() const {
        return false;
}

int surfaceNormale::getCouleur() const{
    return 7;
}
