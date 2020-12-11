#include "brique.h"

brique::brique(geom::point& basGauche, geom::point& hautDroite, surface* surface) : d_basGauche{basGauche}, d_hautDroite{hautDroite}, d_surface{surface} {
}
brique::~brique() {
}

geom::point brique::getBasGauche(){
    return d_basGauche;
}

geom::point brique::getHautDroite(){
    return d_hautDroite;
}

void brique::deplace(const char& direction){
    if(direction == 'q' && getBasGauche().x()>0){
        d_basGauche.moveTo(getBasGauche().x()-20, getBasGauche().y());
        d_hautDroite.moveTo(getHautDroite().x()-20, getHautDroite().y());
    }
    else if (direction == 'd' && getHautDroite().x()< 800){
        d_basGauche.moveTo(getBasGauche().x()+20, getBasGauche().y());
        d_hautDroite.moveTo(getHautDroite().x()+20, getHautDroite().y());
    }
}


surface* brique::getSurface() const{
    return d_surface;
}
