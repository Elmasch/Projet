#ifndef BRIQUEINCASSABLE_H
#define BRIQUEINCASSABLE_H

#include "brique.h"
class briqueIncassable : public brique
{
    public:
        briqueIncassable(geom::point& basGauche, geom::point& hautDroite, surface* surface);
        virtual ~briqueIncassable();
        virtual void affiche() override;
        virtual void efface() override;
        virtual bool casse() override;
};

#endif // BRIQUEINCASSABLE_H
