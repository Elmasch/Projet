#ifndef SURFACEDURE_H
#define SURFACEDURE_H


#include "surface.h"

class surfaceDure : public surface
{
    public:
        surfaceDure();
        virtual ~surfaceDure();
        virtual double getVitesse() const override;
        virtual bool getMorte() const override;
        virtual int getCouleur() const override;
};

#endif // SURFACEDURE_H
