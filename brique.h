#ifndef BRIQUE_H
#define BRIQUE_H
#include "graphics.h"
#include "balle.h"

class brique
{
    public:
        brique(double positionX, double positionY);
        virtual ~brique();
        double getX() const;
        double getY() const;
        virtual void affiche() =0;
        virtual void collision (balle b ) =0;
    protected:

    private:
        double d_X, d_Y;
};

#endif // BRIQUE_H
