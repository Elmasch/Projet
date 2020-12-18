#ifndef POINT_H
#define POINT_H

#include<iosfwd>

namespace geom
{

class vector;

/**
  class representing a point in the plane
*/
class point {
public:
///Default constructor: point (0,0)
  point();
/**
  Constructor with cartesian coordinates
  @param x x-coordinate
  @param y y-coordinate
*/
  point(int x, int y);

///@return the x-coordinate of the point
  int x()  const;
///@return the y-coordinate of the point
  int y()  const;

/**
  Change the coordinates of the point
  @param x the new x-coordinate
  @param y the new y-coordinate
*/
  void moveTo(int x, int y);

 /**
  Move the point with a translation
  @param dx the deplacement along the x-axis
  @param dx the deplacement along the x-axis
*/
  void move(int dx, int dy);

/**
  Move the point with a translation
  @param v the deplacement vector
*/
  void move(const vector& v);

/**
  Operator +=: move the point with a translation
  @param v the deplacement vector
  @return the point itself
*/
  point& operator+=(const vector& v);

/**
  Ouput of a point: (x,y)
  @param ost the stream on which the point is written
*/
  void print(std::ostream& ost) const;
/**
  Input of a point: (x,y)
  @param ist the stream from which the point is read
*/
  void read(std::istream& ist);
private:
///Cartesian coordinates
  int d_x,d_y;
};

std::ostream& operator<<(std::ostream& , const point& );
std::istream& operator>>(std::istream& , point& );

}

#endif
