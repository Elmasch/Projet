#ifndef VECTOR_H
#define VECTOR_H

#include<iosfwd>

namespace geom{

class point;

class vector {
    const double Max =20.0;
    const double Min = 1.5;
public:
  vector();
  vector(double x,double y);
  vector(const point& p,const point& q);

  double x() const;
  double y() const;

  void change(double x, double y);

  void print(std::ostream& ost) const;
  void read(std::istream& ist);
private:
  double d_x,d_y;
};

}

#endif
