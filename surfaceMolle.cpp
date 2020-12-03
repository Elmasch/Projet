#include "surfaceMolle.h"

surfaceMolle::surfaceMolle()
{
    //ctor
}

surfaceMolle::~surfaceMolle()
{
    //dtor
}

double surfaceMolle::getVitesse() const{
    return 0.8 ;
}

bool surfaceMolle::getMorte() const {
        return false;
}

int surfaceMolle::getCouleur() const{
    return 8;
}
