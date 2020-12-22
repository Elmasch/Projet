#ifndef BRIQUECASSABLE_H
#define BRIQUECASSABLE_H

#include "brique.h"

class briqueCassable : public brique
{
    public:
        briqueCassable(geom::point& basGauche, geom::point& hautDroite, surface* surface, int nombre);
        virtual ~briqueCassable();

        int getNombre() const;

        virtual bool casse() override;

        virtual void efface() override;
        virtual void affiche() override;
    private:
        int d_nombre;
};

#endif // BRIQUECASSABLE_H
