#include "balle.h"
#include <iostream>

balle::balle(double vitesse, double positionX, double positionY) : d_vitesse{vitesse}, d_X{positionX}, d_Y{positionY}{
}

balle::~balle(){
}

double balle::getVitesse() const{
    return d_vitesse;
}

double balle::getX() const{
    return d_X;
}

double balle::getY() const{
    return d_Y;
}

void balle::setVitesse(double valeur){
    d_vitesse = valeur;
}

void balle::setPosition(double x, double y){
    d_X = x;
    d_Y = y;
}



void balle::avance(){
   setPosition(getX()+getVitesse(),getY()+getVitesse());
}

void balle::affiche(){
    setcolor(BLUE);
    circle(d_X,d_Y,5);
}

void balle::efface(){
    setcolor(WHITE);
    circle(d_X,d_Y,5);
}
