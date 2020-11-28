#include "balle.h"
#include <iostream>

balle::balle(geom::vector& vitesse, geom::point& p) : d_vitesse{vitesse}, d_position{p}{
}

balle::~balle(){
}

geom::vector balle::getVitesse() const{
    return d_vitesse;
}

geom::point balle::getPosition() const{
    return d_position;
}

void balle::avance(){
    efface();
    d_position += d_vitesse;
    affiche();
}

void balle::affiche(){
    setcolor(BLUE);
    circle(d_position.x(),d_position.y(),5);
}

void balle::efface(){
    setcolor(WHITE);
    circle(d_position.x(),d_position.y(),5);
}

void balle::setPosition(const geom::point& p){
    d_position = p;
}

void balle::setVitesse(const geom::vector& v){
    d_vitesse = v;
}

void balle::collision(const brique& b){
    std::cout << d_position.distance(b.getPosition()) << std::endl;
    if(d_position.distance(b.getPosition()) < 40){
        d_vitesse = -d_vitesse;
    }
    avance();
}
