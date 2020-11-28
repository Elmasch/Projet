#include "brique.h"



brique::brique(geom::point& basGauche, geom::point& hautDroite, surface* surface) : d_basGauche{basGauche}, d_hautDroite{hautDroite}, d_surface{surface} {
}
brique::~brique() {
}

geom::point brique::getBasGauche() const{
    return d_basGauche;
}

geom::point brique::getHautDroite() const{
    return d_hautDroite;
}


surface* brique::getSurface() const{
    return d_surface;
}
