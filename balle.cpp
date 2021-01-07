#include "balle.h"
#include "terrain.h"
#include <iostream>

balle::balle(geom::vector& vitesse, geom::point& p) : d_vitesse{vitesse}, d_position{p}, d_rayon{7} , d_morte{false}
{}

balle::balle(): d_vitesse{5,5} , d_position{} , d_rayon{7} , d_morte{false}
{}

balle::balle(geom::point& p): d_vitesse{5,5} , d_position{p} , d_rayon{7} , d_morte{false}
{}

balle::~balle()
{}

geom::vector balle::getVitesse() const{
    return d_vitesse;
}

geom::point balle::getPosition() const{
    return d_position;
}

void balle::setMorte(bool newValeur){
    d_morte = newValeur;
}

int balle::getRayon() const{
    return d_rayon;
}

void balle::setPosition(geom::point& newPosition){
    d_position = newPosition;
}


bool balle::morte() const{
    return d_morte;
}

void balle::avance(int hauteur, int largeur){
    if ( d_position.y() - d_rayon <= 0 && d_position.x() - d_rayon <= 0 || d_position.y() - d_rayon <= 0 && d_position.x() +d_rayon >= largeur){
        d_vitesse.change(-d_vitesse.x(),-d_vitesse.y());
    }else if(d_position.y() - d_rayon <= 0){
        d_vitesse.change(d_vitesse.x(),-d_vitesse.y());
    }else if (d_position.x() - d_rayon <= 0 || d_position.x() +d_rayon >= largeur){
        d_vitesse.change(-d_vitesse.x(),d_vitesse.y());
    }else if(d_position.y() + d_rayon >= hauteur){
        d_morte = true;
    }
    efface();
    d_position += d_vitesse;
    affiche();
}

void balle::affiche(){
    setcolor(WHITE);
    circle(d_position.x(),d_position.y(),d_rayon);
}

void balle::efface(){
    setcolor(BLACK);
    circle(d_position.x(),d_position.y(),d_rayon);
}

void balle::collision(std::vector<std::unique_ptr<brique>> &b, raquette &r, int hauteur, int largeur){
    for(int i = 0; i < b.size(); ++i){
        if(d_position.x() >= b[i]->getBasGauche().x() && d_position.x() <= b[i]->getHautDroite().x() && d_position.y() >= b[i]->getBasGauche().y() && d_position.y() <= b[i]->getHautDroite().y()){
            d_morte = b[i]->getSurface()->getMorte();
            efface();
            if (d_position.x() > b[i]->getBasGauche().x()+1 && d_position.x() < b[i]->getHautDroite().x()-1 && d_position.y() > b[i]->getBasGauche().y()-1 && d_position.y() < b[i]->getHautDroite().y()+1){
                 d_position = {d_position.x() - d_vitesse.x(),d_position.y() - d_vitesse.y()};
                 d_vitesse.change(d_vitesse.x()*b[i]->getSurface()->getVitesse(),-d_vitesse.y()*b[i]->getSurface()->getVitesse());
            }
            else {
                d_position = {d_position.x() - d_vitesse.x(),d_position.y() - d_vitesse.y()};
                d_vitesse.change(-d_vitesse.x()*b[i]->getSurface()->getVitesse(),d_vitesse.y()*b[i]->getSurface()->getVitesse());
            }

            if(b[i]->casse()){
                b[i]->efface();
                b.erase(b.begin() + i);
            }
        }
        if(b[i])
            b[i]->affiche();
    }
    if(d_position.x() > r.getBasGauche().x() && d_position.x() < r.getHautDroite().x() && d_position.y() > r.getBasGauche().y() && d_position.y() < r.getHautDroite().y()){
            efface();
            d_position = {d_position.x() - d_vitesse.x(),d_position.y() - d_vitesse.y()};
            d_vitesse.change(d_vitesse.x()*r.getSurface()->getVitesse(),-d_vitesse.y()*r.getSurface()->getVitesse());
        }
    avance(hauteur, largeur);

}
