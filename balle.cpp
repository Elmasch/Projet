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

void balle::collison(brique& b){
    if((getX()>=b.getX() && getX()<=b.getX()+100) && (getY()<=b.etY() && getY()>=b.getY()-10))
    {
        /*regarde le type de la brique
        si ma brique est normale : rebondir nomalement
        si ma brique est molle ou dure : ralentir ou accelerer getVitesse ralenti ou accélaire

        */

    }
}
void balle::avance(){
    efface();
    setPosition(getX()-getVitesse(),getY()-getVitesse());
    affiche();
}

void balle::affiche(){
    setcolor(BLUE);
    circle(d_X,d_Y,5);
}

void balle::efface(){
    setcolor(WHITE);
    circle(d_X,d_Y,5);
}
