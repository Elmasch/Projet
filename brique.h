#ifndef BRIQUE_H
#define BRIQUE_H
#include "graphics.h"
#include "surface.h"

class brique
{
    public:
        brique(double positionX, double positionY, surface& surface);
        virtual ~brique();
        double getX() const;
        double getY() const;
        surface getSurface() const;
        virtual void affiche() =0;
    private:
        double d_X, d_Y;
        surface d_surface;
};

#endif // BRIQUE_H
