#include "brique.h"



brique::brique(geom::point& p, surface* surface) : d_position{p}, d_surface{surface} {
}
brique::~brique() {
}

geom::point brique::getPosition() const{
    return d_position;
}

surface* brique::getSurface() const{
    return d_surface;
}
