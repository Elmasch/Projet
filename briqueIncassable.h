#ifndef BRIQUEINCASSABLE_H
#define BRIQUEINCASSABLE_H

#include "brique.h"
class briqueIncassable : public brique
{
    public:
        briqueIncassable(double positionX, double positionY, surface& type);
        virtual ~briqueIncassable();
        virtual void affiche() override;
    protected:

    private:
};

#endif // BRIQUEINCASSABLE_H
