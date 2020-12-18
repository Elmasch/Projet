#include<iostream>
#include<cmath>
#include"vector.h"
#include"point.h"

namespace geom
{

vector::vector() : vector {0.0,0.0}
{}

vector::vector(double x,double y) : d_x{x}, d_y{y}
{}

vector::vector(const point& p,const point& q) :
        d_x{q.x()-p.x()}, d_y{q.y()-p.y()}
{}

double vector::x() const
{
  return d_x;
}

double vector::y() const
{
  return d_y;
}

void vector::change(double x, double y)
{
  d_x = x;  d_y = y;
}

void vector::print(std::ostream& ost) const
{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void vector::read(std::istream& ist)
{
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

std::ostream& operator<<(std::ostream& ost, const vector& v)
{
  v.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, vector& v)
{
  v.read(ist);
  return ist;
}

}

