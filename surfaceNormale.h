#ifndef SURFACENORMALE_H
#define SURFACENORMALE_H

#include "surface.h"

class surfaceNormale : public surface
{
    public:
        surfaceNormale();
        virtual ~surfaceNormale();
        virtual double getVitesse() const override;
        virtual bool getMorte() const override;
        virtual int getCouleur() const override;
    private:
        double d_vitesse;
        int d_couleur;
};

#endif // SURFACENORMALE_H
