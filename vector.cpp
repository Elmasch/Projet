#include<iostream>
#include<cmath>
#include"vector.h"
#include"point.h"

namespace geom{

vector::vector() : vector {0,0}
{}

vector::vector(int x, int y) : d_x{x}, d_y{y}
{}

vector::vector(const point& p1,const point& p2) :d_x{p2.x()-p1.x()}, d_y{p2.y()-p1.y()}
{}

int vector::x() const{
  return d_x;
}

int vector::y() const{
  return d_y;
}

void vector::change(int x, int y){
  d_x = x;  d_y = y;
}

void vector::print(std::ostream& ost) const{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void vector::read(std::istream& ist){
  char c;
  ist>>c;
  if (c == '(')
  {
    int x;
    ist>>x>>c;
    if (c == ',')
    {
      int y;
      ist>>y>>c;
      if (c == ')') { d_x = x; d_y = y; }
    }
  }
}

}

