#include "balle.h"
#include <iostream>

balle::balle(geom::vector& vitesse, geom::point& p) : d_vitesse{vitesse}, d_position{p}, d_morte{false}{
}

balle::~balle(){
}

geom::vector balle::getVitesse() const{
    return d_vitesse;
}

geom::point balle::getPosition() const{
    return d_position;
}

bool balle::morte() const{
    return d_morte;
}


void balle::avance(int hauteur, int largeur){
    if(d_position.x() < 0 || d_position.x() > hauteur){
        d_vitesse.change(-d_vitesse.x(),d_vitesse.y());
    }else if(d_position.y() < 0){
        d_vitesse.change(d_vitesse.x(),-d_vitesse.y());
    }else if(d_position.y() > largeur){
        d_morte = true;
    }
    efface();
    d_position += d_vitesse;
    affiche();
}

void balle::affiche(){
    setcolor(WHITE);
    circle(d_position.x(),d_position.y(),5);
}

void balle::efface(){
    setcolor(BLACK);
    circle(d_position.x(),d_position.y(),5);
}

void balle::setPosition(const geom::point& p){
    d_position = p;
}

void balle::setVitesse(const geom::vector& v){
    d_vitesse = v;
}

void balle::collision(std::vector<std::unique_ptr<brique>> &b, int hauteur, int largeur){
    for(int i = 0; i < b.size(); ++i){
        if(d_position.x() > b[i]->getBasGauche().x() && d_position.x() < b[i]->getHautDroite().x() && d_position.y() > b[i]->getBasGauche().y() && d_position.y() < b[i]->getHautDroite().y()){
            d_morte = b[i]->getSurface()->getMorte();
            d_vitesse.change(d_vitesse.x()*b[i]->getSurface()->getVitesse(),-d_vitesse.y()*b[i]->getSurface()->getVitesse());
            if(b[i]->casse()){
                b[i]->efface();
                b.erase(b.begin() + i);
            }
        }
        b[i]->affiche();
    }
    avance(hauteur, largeur);
}
