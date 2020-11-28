#include "briqueIncassable.h"

briqueIncassable::briqueIncassable(geom::point& p, surface* surface) : brique {p,surface} {
}

briqueIncassable::~briqueIncassable(){
}

void briqueIncassable::affiche() {
    setcolor(GREEN);
    rectangle(getPosition().x()-50,getPosition().y()-5,getPosition().x()+50, getPosition().y()+5);
}

