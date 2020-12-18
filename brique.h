#ifndef BRIQUE_H
#define BRIQUE_H

#include "graphics.h"
#include "surface.h"
#include "point.h"

class brique
{
    public:
        brique(geom::point& basGauche, geom::point& hautDroite, surface* surface);
        virtual ~brique();
        geom::point getBasGauche();
        geom::point getHautDroite();
        void deplace(const char& direction, int hauteur, int largeur);
        surface* getSurface() const;
        virtual void affiche() =0;
        virtual void efface() = 0;
        virtual bool casse() = 0;
    private:
        geom::point d_basGauche, d_hautDroite;
        surface* d_surface;
};

#endif // BRIQUE_H
