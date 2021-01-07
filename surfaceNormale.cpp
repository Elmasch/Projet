#include "surfaceNormale.h"

surfaceNormale::surfaceNormale() : d_vitesse{1}, d_couleur{7}
{
    //ctor
}

surfaceNormale::~surfaceNormale()
{
    //dtor
}

double surfaceNormale::getVitesse() const{
    return d_vitesse;
}

bool surfaceNormale::getMorte() const {
        return false;
}

int surfaceNormale::getCouleur() const{
    return d_couleur;
}
