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
        geom::point getBasGauche() const;
        geom::point getHautDroite() const;
        surface* getSurface() const;
        virtual void affiche() =0;
    private:
        geom::point d_basGauche, d_hautDroite;
        surface* d_surface;
};

#endif // BRIQUE_H
