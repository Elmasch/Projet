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
    private:
        double d_vitesse;
        int d_couleur;
};

#endif // SURFACEMOLLE_H
