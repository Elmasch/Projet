#ifndef BRIQUECASSABLE_H
#define BRIQUECASSABLE_H

#include "brique.h"

class briqueCassable : public brique
{
    public:
        briqueCassable(geom::point& basGauche, geom::point& hautDroite, surface* surface, int nombre);
        virtual ~briqueCassable();
        virtual void affiche() override;
        virtual bool casse() override;
        virtual void efface() override;
        int getNombre() const;
    private:
        int d_nombre;
};

#endif // BRIQUECASSABLE_H
