#ifndef TUEUSE_H
#define TUEUSE_H


#include "brique.h"
#include "balle.h"
class tueuse : public brique
{
    public:
        tueuse(double positionX, double positionY);
        virtual ~tueuse();
        virtual void affiche() override ;
        virtual void collision (balle b) override;
    protected:

    private:
};

#endif // TUEUSE_H
