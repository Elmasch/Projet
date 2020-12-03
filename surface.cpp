#include "surface.h"

surface::surface() : d_estMorte{false} {}

surface::~surface()
{
    //dtor
}
int surface::getVitesse() const {
    return d_vitesse;
}


bool surface::getMorte() const {
    return d_estMorte;
}

