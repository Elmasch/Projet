#ifndef BALLE_H
#define BALLE_H
#include "graphics.h"
#include <cmath>
#include "brique.h"
#include "point.h"
#include "vector.h"
#include <vector>
#include <memory>
class balle
{
    public:
        balle();
        balle(geom::vector& vitesse, geom::point& p);
        ~balle();

        geom::vector getVitesse() const;
        geom::point getPosition() const;

        void setPosition(const geom::point& p);
        void setVitesse(const geom::vector& v);
        void avance();
        void collision(std::vector<std::unique_ptr<brique>> &b);
        void affiche();
        void efface();


    private:
        geom::vector d_vitesse;
        geom::point d_position;
};

#endif // BALLE_H
