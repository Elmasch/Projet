#include "surfaceTueuse.h"

surfaceTueuse::surfaceTueuse() : d_vitesse{1} , d_couleur{6}
{
    //ctor
}

surfaceTueuse::~surfaceTueuse()
{
    //dtor
}

double surfaceTueuse::getVitesse() const{
    return d_vitesse;
}

bool surfaceTueuse::getMorte() const {
        return true;
}

int surfaceTueuse::getCouleur() const{
    return d_couleur;
}
