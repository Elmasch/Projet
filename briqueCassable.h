#ifndef BRIQUECASSABLE_H
#define BRIQUECASSABLE_H

#include "brique.h"
class briqueCassable : public brique
{
    public:
        briqueCassable(double positionX, double positionY, surface& type, int nombre);
        virtual ~briqueCassable();
        virtual void affiche() override;
    protected:

    private:
        int d_nombre;
};

#endif // BRIQUECASSABLE_H
