#ifndef DURE_H
#define DURE_H


#include "brique.h"
#include "balle.h"
class dure : public brique
{
    public:
        dure(double positionX, double positionY);
        virtual ~dure();
        virtual void affiche() override ;
        virtual void collision (balle b) override;
    protected:

    private:
};

#endif // DURE_H
