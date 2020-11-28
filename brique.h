#ifndef BRIQUE_H
#define BRIQUE_H
#include "graphics.h"
#include "surface.h"

class brique
{
    public:
        brique(double positionX, double positionY, surface& type);
        virtual ~brique();
        double getX() const;
        double getY() const;
        virtual void affiche() =0;
    protected:

    private:
        double d_X, d_Y;
        surface d_type;
};

#endif // BRIQUE_H
