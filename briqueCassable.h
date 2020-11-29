#ifndef BRIQUECASSABLE_H
#define BRIQUECASSABLE_H

#include "brique.h"

class briqueCassable : public brique
{
    public:
        briqueCassable(geom::point& basGauche, geom::point& hautDroite, surface* surface, int nombre);
        virtual ~briqueCassable();
        virtual void affiche() override;
        int getNombre() const;
        virtual bool casse() override;
        void efface();
    private:
        int d_nombre;
};

#endif // BRIQUECASSABLE_H
