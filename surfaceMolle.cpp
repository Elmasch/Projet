#include "surfaceMolle.h"

surfaceMolle::surfaceMolle() : d_vitesse{0.8}, d_couleur{8}
{
    //ctor
}

surfaceMolle::~surfaceMolle()
{
    //dtor
}

double surfaceMolle::getVitesse() const{
    return d_vitesse ;
}

bool surfaceMolle::getMorte() const {
        return false;
}

int surfaceMolle::getCouleur() const{
    return d_couleur;
}
