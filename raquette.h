#ifndef RAQUETTE_H
#define RAQUETTE_H

#include "brique.h"
#include "balle.h"
class raquette : public brique
{
    public:
        raquette(geom::point& p,surface* type);
        virtual ~raquette();
        virtual void affiche() override ;


    private:
};

#endif // RAQUETTE_H
