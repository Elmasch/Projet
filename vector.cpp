#include<iostream>
#include<cmath>
#include"vector.h"
#include"point.h"

namespace geom{

vector::vector() : vector {0,0}
{}

vector::vector(double x, double y) : d_x{x}, d_y{y}
{}

vector::vector(const point& p1,const point& p2) :d_x{p2.x()-p1.x()}, d_y{p2.y()-p1.y()}
{}

double vector::x() const{
  return d_x;
}

double vector::y() const{
  return d_y;
}

void vector::change(double x, double y){
    if((std::abs(x) < Max && std::abs(y) < Max )&& (std::abs(x) > Min && std::abs(y) > Min)){
        d_x = x;  d_y = y;
    }
    else{
        d_x = d_x; d_y = -d_y;
    }
}

void vector::print(std::ostream& ost) const{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void vector::read(std::istream& ist){
  char c;
  ist>>c;
  if (c == '(')
  {
    double x;
    ist>>x>>c;
    if (c == ',')
    {
      double y;
      ist>>y>>c;
      if (c == ')') { d_x = x; d_y = y; }
    }
  }
}

}

