#include<iostream>
#include<cmath>
#include"point.h"
#include"vector.h"

namespace geom{

point::point() : point {0,0}
{}

point::point(int x, int y) : d_x{x}, d_y{y}
{}

int point::x() const {
  return d_x;
}

int point::y() const {
  return d_y;
}

void point::moveTo(int x, int y) {
  d_x = x; d_y = y;
}

void point::move(const vector& v) {
  move(v.x(),v.y());
}

void point::move(int dx, int dy) {
  d_x += dx; d_y += dy;
}

point& point::operator+=(const vector& v) {
  move(v);
  return *this;
}

void point::print(std::ostream& ost) const {
  ost<<'('<<d_x<<','<<d_y<<')';
}

void point::read(std::istream& ist) {
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

std::ostream& operator<<(std::ostream& ost, const point& p) {
  p.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, point& p) {
  p.read(ist);
  return ist;
}

}
