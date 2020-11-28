#include "briqueCassable.h"

briqueCassable::briqueCassable(geom::point& basGauche, geom::point& hautDroite, surface* surface, int nombre) : brique{basGauche, hautDroite, surface}, d_nombre{nombre}{
}

briqueCassable::~briqueCassable(){
}

void briqueCassable::affiche() {
    setcolor(BLUE);
    rectangle(getBasGauche().x(),getBasGauche().y(),getHautDroite().x(), getHautDroite().y());
}

int briqueCassable::getNombre() const{
    return d_nombre;
}
