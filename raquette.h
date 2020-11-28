#ifndef RAQUETTE_H
#define RAQUETTE_H

#include "brique.h"
#include "balle.h"
class raquette : public brique
{
    public:
        raquette(double positionX, double positionY);
        virtual ~raquette();
        virtual void affiche() override ;
        virtual void collision (balle b) override;

    protected:

    private:
};

#endif // RAQUETTE_H
