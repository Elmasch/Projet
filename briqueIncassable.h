#ifndef BRIQUEINCASSABLE_H
#define BRIQUEINCASSABLE_H

#include "brique.h"
class briqueIncassable : public brique
{
    public:
        briqueIncassable(geom::point& p, surface* surface);
        virtual ~briqueIncassable();
        virtual void affiche() override;
};

#endif // BRIQUEINCASSABLE_H
