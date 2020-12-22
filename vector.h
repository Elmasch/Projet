#ifndef VECTOR_H
#define VECTOR_H

#include<iosfwd>

namespace geom{

class point;

class vector {
public:
  vector();
  vector(int x,int y);
  vector(const point& p,const point& q);

  int x() const;
  int y() const;

  void change(int x, int y);

  void print(std::ostream& ost) const;
  void read(std::istream& ist);
private:
  int d_x,d_y;
};

}

#endif
