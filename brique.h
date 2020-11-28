#ifndef BRIQUE_H
#define BRIQUE_H

#include "graphics.h"
#include "surface.h"
#include "point.h"

class brique
{
    public:
        brique(geom::point& p, surface* surface);
        virtual ~brique();
        geom::point getPosition() const;
        surface* getSurface() const;
        virtual void affiche() =0;
    private:
        geom::point d_position;
        surface* d_surface;
};

#endif // BRIQUE_H
