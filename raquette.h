#ifndef RAQUETTE_H
#define RAQUETTE_H

#include "brique.h"
#include "balle.h"
class raquette : public brique
{
    public:
        raquette(geom::point& basGauche, geom::point& hautDroite,surface* surface);
        virtual ~raquette();
        void bouge(const char& direction);
        virtual void affiche() override;
        virtual void efface() override;
        virtual bool casse() override;

};

#endif // RAQUETTE_H
