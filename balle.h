#ifndef BALLE_H
#define BALLE_H
#include "graphics.h"
#include <cmath>
#include "brique.h"
#include "raquette.h"
#include "point.h"
#include "vector.h"
#include <vector>
#include <memory>

class raquette;

class balle
{
    public:
        balle(geom::vector& vitesse, geom::point& p);
        balle();
        balle(geom::point& p);

        ~balle();

        geom::vector getVitesse() const;
        geom::point getPosition() const;
        int getRayon() const;

        void setPosition(geom::point& newPoisiton);
        void setMorte(bool newValeur);
        bool morte() const;

        void avance(int hauteur, int largeur);
        void collision(std::vector<std::unique_ptr<brique>> &b, raquette &r, int hauteur, int largeur);

        void affiche();
        void efface();
    private:
        geom::vector d_vitesse;
        geom::point d_position;
        int d_rayon;
        bool d_morte;
};

#endif // BALLE_H
