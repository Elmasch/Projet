#include "brique.h"

brique::brique(geom::point& basGauche, geom::point& hautDroite, surface* surface) : d_basGauche{basGauche}, d_hautDroite{hautDroite}, d_surface{surface}
{}

brique::brique()
{}

brique::~brique()
{}

geom::point brique::getBasGauche(){
    return d_basGauche;
}

geom::point brique::getHautDroite(){
    return d_hautDroite;
}

void brique::deplace(const char& direction, int largeur){
    int deplacement=largeur/30;
    if((direction == 'q' || direction == 'Q') && getBasGauche().x()>0){
        if(getBasGauche().x()<deplacement)
            deplacement=getBasGauche().x();
        d_basGauche.moveTo(getBasGauche().x()-deplacement, getBasGauche().y());
        d_hautDroite.moveTo(getHautDroite().x()-deplacement, getHautDroite().y());
    }
    else if ((direction == 'd' || direction == 'D') && getHautDroite().x()< largeur){
        if(getHautDroite().x()+deplacement>largeur)
            deplacement=largeur-getHautDroite().x();
        d_basGauche.moveTo(getBasGauche().x()+deplacement, getBasGauche().y());
        d_hautDroite.moveTo(getHautDroite().x()+deplacement, getHautDroite().y());
    }
}

surface* brique::getSurface() const{
    return d_surface;
}
