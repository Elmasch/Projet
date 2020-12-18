#ifndef VECTOR_H
#define VECTOR_H

#include<iosfwd>

namespace geom
{

class point;

class vector {
public:
///Default constructor: null vector (0,0)
  vector();
/**
  Constructor with cartesian coordinates
  @param x x-coordinate
  @param y y-coordinate
*/
  vector(double x,double y);
/**
  Constructor with point extremities: vector pq
  @param p point
  @param q point
*/
  vector(const point& p,const point& q);
///@return the x-coordinate of the vector
  double x()         const;
///@return the y-coordinate of the vector
  double y()         const;

/**
  Change the coordinates of the vector
  @param x the new x-coordinate
  @param y the new y-coordinate
*/
  void change(double x, double y);

/**
  Ouput of a vector: (x,y)
  @param ost the stream on which the vector is written
*/
  void print(std::ostream& ost) const;
/**
  Input of a vector: (x,y)
  @param ist the stream from which the vector is read
*/
  void read(std::istream& ist);
private:
  double d_x,d_y;
};

std::ostream& operator<<(std::ostream& , const vector& );
std::istream& operator>>(std::istream&, vector& );

}

#endif
