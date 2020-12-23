#ifndef RAQUETTE_H
#define RAQUETTE_H

#include "brique.h"
#include "balle.h"
class raquette : public brique
{
    public:
        raquette(geom::point& basGauche, geom::point& hautDroite,surface* surface);
        raquette();
        virtual ~raquette();

        void bouge(const char& direction, int largeur);

        virtual bool casse() override;
        virtual bool cassable() override;

        virtual void affiche() override;
        virtual void efface() override;

};

#endif // RAQUETTE_H
