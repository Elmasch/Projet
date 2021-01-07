#ifndef SURFACETUEUSE_H
#define SURFACETUEUSE_H


#include "surface.h"

class surfaceTueuse : public surface
{
    public:
        surfaceTueuse();
        virtual ~surfaceTueuse();
        virtual double getVitesse() const override;
        virtual bool getMorte() const override;
        virtual int getCouleur() const override;
    private:
        double d_vitesse;
        int d_couleur;
};

#endif // SURFACETUEUSE_H
