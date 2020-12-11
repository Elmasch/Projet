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
        balle();
        balle(geom::vector& vitesse, geom::point& p, double rayon);
        ~balle();

        geom::vector getVitesse() const;
        geom::point getPosition() const;
        bool morte() const;

        void setPosition(const geom::point& p);
        void setVitesse(const geom::vector& v);
        void avance(int hauteur, int largeur);
        void collision(std::vector<std::unique_ptr<brique>> &b, raquette &r, int hauteur, int largeur);
        void affiche();
        void efface();
    private:
        geom::vector d_vitesse;
        geom::point d_position;
        double d_rayon;
        bool d_morte;
};

#endif // BALLE_H
