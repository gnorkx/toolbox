
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include<iostream>
#include<cmath>
#include<cstdio>


class vector3d{
  private:
    float _x;
    float _y;
    float _z;
  public:

    vector3d(){_x=0;_y=0;_z=0;};
    vector3d(float a, float b, float c): _x(a), _y(b), _z(c) {};
    vector3d(const vector3d &v): _x(v.getX()), _y(v.getY()), _z(v.getZ()) {};
    ~vector3d(){};



    //get
    float getX() const {return _x;};
    float getY() const {return _y;};
    float getZ() const {return _z;};

    //set
    void setX(float x){_x = x;};
    void setY(float y){_y = y;};
    void setZ(float z){_z = z;};
    void setRPhiTheta(float, float, float);
    void scale(float a){_x*=a; _y*=a; _z*=a;};


    //ops
    vector3d operator + (const vector3d&) const;
    vector3d operator - (const vector3d&) const;
    vector3d& operator += (const vector3d&);
    vector3d& operator -= (const vector3d&);
    float operator* (const vector3d&) const;
    friend std::ostream& operator << (std::ostream&, const vector3d&);



    void swap(vector3d&);
    float abs() const {return sqrt(absqr());} ;
    float absqr() const {return _x*_x + _y*_y + _z*_z;} ;
    float cosTheta( const vector3d &v ) const {return (*this)*v/sqrt(absqr()*v.absqr());};
    float sinTheta( const vector3d &v ) const {return sqrt(cross(v).absqr()/(absqr()*v.absqr()));};
    float theta( const vector3d &v ) const {return acos(cosTheta(v));};
    vector3d unit() const {return vector3d(_x/abs(),_y/abs(), _z/abs());} ;
    vector3d cross(const vector3d &v) const;

    void rotateRad(float, char);
    bool sameDirection(const vector3d&) const;
    float theta180(const vector3d &) const;
    float theta360(const vector3d &) const;



};


//non class member functions


vector3d operator* (const float& , const vector3d&);


#endif
