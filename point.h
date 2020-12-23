#ifndef POINT_H
#define POINT_H

#include<iosfwd>

namespace geom{

class vector;

class point {
public:
  point();
  point(int x, int y);

  int x()  const;
  int y()  const;

  void moveTo(int x, int y);
  void move(int dx, int dy);
  void move(const vector& v);
  //bool operator > (const point &p);
  point& operator+=(const vector& v);

  void print(std::ostream& ost) const;
  void read(std::istream& ist);
private:
  int d_x,d_y;
};

}

#endif
