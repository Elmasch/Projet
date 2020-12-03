#ifndef SURFACENORMALE_H
#define SURFACENORMALE_H

#include "surface.h"

class surfaceNormale : public surface
{
    public:
        surfaceNormale();
        virtual ~surfaceNormale();
        virtual int getVitesse() const override;
        virtual bool getMorte() const override;
    private:
};

#endif // SURFACENORMALE_H
