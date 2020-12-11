#ifndef SURFACEMOLLE_H
#define SURFACEMOLLE_H


#include "surface.h"

class surfaceMolle : public surface
{
    public:
        surfaceMolle();
        virtual ~surfaceMolle();
        virtual double getVitesse() const override;
        virtual bool getMorte() const override;
        virtual int getCouleur() const override;
};

#endif // SURFACEMOLLE_H
