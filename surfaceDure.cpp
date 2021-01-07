#include "surfaceDure.h"

surfaceDure::surfaceDure() : d_vitesse{1.2}, d_couleur{10}
{
    //ctor
}


surfaceDure::~surfaceDure()
{
    //dtor
}

double surfaceDure::getVitesse() const{
    return d_vitesse;
}

bool surfaceDure::getMorte() const {
        return false;
}

int surfaceDure::getCouleur() const{
    return d_couleur;
}
