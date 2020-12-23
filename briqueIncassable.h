#ifndef BRIQUEINCASSABLE_H
#define BRIQUEINCASSABLE_H

#include "brique.h"
class briqueIncassable : public brique
{
    public:
        briqueIncassable(geom::point& basGauche, geom::point& hautDroite, surface* surface);
        virtual ~briqueIncassable();

        virtual bool casse() override;
        virtual bool cassable() override;

        virtual void affiche() override;
        virtual void efface() override;
};

#endif // BRIQUEINCASSABLE_H
