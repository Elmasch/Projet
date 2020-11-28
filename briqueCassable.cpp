#include "briqueCassable.h"

briqueCassable::briqueCassable(geom::point& p, surface* surface, int nombre) : brique{p,surface}, d_nombre{nombre}{
}

briqueCassable::~briqueCassable(){
}

void briqueCassable::affiche() {
    setcolor(BLUE);
    rectangle(getPosition().x()-50,getPosition().y()-5,getPosition().x()+50, getPosition().y()+5);
}

int briqueCassable::getNombre() const{
    return d_nombre;
}
