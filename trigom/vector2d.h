
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<iostream>
#include<cmath>
#include<cstdio>


class vector2d{
  private:
    float _x;
    float _y;

  public:

    vector2d(){_x=0;_y=0;};
    vector2d(float a, float b): _x(a), _y(b) {};
    vector2d(const vector2d &v): _x(v.getX()), _y(v.getY()) {};
    ~vector2d(){};

    float getX() const {return _x;};
    float getY() const {return _y;};

    void setX(float x){_x = x;};
    void setY(float y){_y = y;};

    vector2d operator + (const vector2d&) const;
    vector2d operator - (const vector2d&) const;
    vector2d& operator += (const vector2d&);
    vector2d& operator -= (const vector2d&);
    float operator* (const vector2d&) const;
    friend std::ostream& operator << (std::ostream&, const vector2d&);

    void scale(float a){_x*=a; _y*=a;};
    void swap(vector2d&);
    float abs() const {return sqrt(_x*_x + _y*_y);} ;
    float absqr() const {return _x*_x + _y*_y;} ;
    float cosTheta( const vector2d &v ) const {return (*this)*v/sqrt(absqr()*v.absqr());};
    float sinTheta( const vector2d &v ) const {return cross(v)/sqrt(absqr()*v.absqr());};
    float theta( const vector2d &v ) const {return acos(cosTheta(v));};
    vector2d unit() const {return vector2d(_x/abs(),_y/abs());} ;
    float cross(const vector2d &v) const {return _x*v.getY()-_y*v.getX();}; // "3rd component"
    void rotateRad(float);
    vector2d perp() const;
    bool sameDirection(const vector2d&) const;
    float theta180(const vector2d &) const;
    float theta360(const vector2d &) const;

    void setRPhi(float, float);

};


//non class member functions


vector2d operator* (const float& , const vector2d&);


#endif
