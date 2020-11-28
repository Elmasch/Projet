#ifndef BALLE_H
#define BALLE_H
#include "graphics.h"
#include <cmath>
#include "brique.h"

class balle
{
    public:
        balle();
        balle(double vitesse, double positionX, double positionY);
        ~balle();
        double getVitesse() const;
        double getX() const;
        double getY() const;
        void setVitesse(double valeur);
        void setPosition(double x, double y);
        void collison(brique& b);
        void avance();
        void affiche();
        void efface();
    protected:

    private:
        double d_vitesse;
        double d_X, d_Y;
};

#endif // BALLE_H
