#ifndef NORMALE_H
#define NORMALE_H

#include "brique.h"
#include "balle.h"
class normale : public brique
{
    public:
        normale(double positionX, double positionY);
        virtual ~normale();
        virtual void affiche() override ;
        virtual void collision (balle b) override;
    protected:

    private:
};

#endif // NORMALE_H
