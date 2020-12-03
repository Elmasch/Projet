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
};

#endif // SURFACETUEUSE_H
