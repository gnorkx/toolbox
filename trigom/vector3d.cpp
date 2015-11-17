
#include"vector3d.h"

vector3d vector3d::operator +(const vector3d& rhs) const
{
  return vector3d(_x+rhs.getX(), _y+rhs.getY(), _z+rhs.getZ());
}

vector3d vector3d::operator -(const vector3d& rhs) const
{
  return vector3d(_x-rhs.getX(), _y-rhs.getY(), _z-rhs.getZ());
}

vector3d& vector3d::operator +=(const vector3d& rhs)
{
  _x += rhs.getX();
  _y += rhs.getY();
  _z += rhs.getZ();
  return *this;
}
vector3d& vector3d::operator -=(const vector3d& rhs)
{
  _x -= rhs.getX();
  _y -= rhs.getY();
  _z -= rhs.getZ();

  return *this;
}
float vector3d::operator* (const vector3d& rhs) const
{
   return _x*rhs.getX() + _y*rhs.getY() + _z*rhs.getZ();
}

void vector3d::swap(vector3d& c2)
{
    vector3d tmp(*this);
    *this = c2;
    c2 = tmp;


}

std::ostream& operator << (std::ostream& os, const vector3d& co)
{
  os<<"("<<co.getX()<<", "<<co.getY()<<", "<<co.getZ()<<")";
  return os;
}

//non class member functions


vector3d operator* (const float& a , const vector3d& rhs)
{
  return vector3d(a*rhs.getX(), a*rhs.getY(), a*rhs.getZ());
};


void vector3d::rotateRad(float alpha, char axis)
{
    float ca = cos(alpha);
    float sa = sin(alpha);

    if(axis == 'x') {
        _y= ca*_y - sa*_z;
        _z= sa*_y + ca*_z;
    } else if (axis == 'y'){
        _x= ca*_x + sa*_z;
        _z= -sa*_x + ca*_z;
    } else if (axis == 'z'){
        _x= ca*_x - sa*_y;
        _y= sa*_x + ca*_y;
    }
    return;
}

vector3d vector3d::cross(vector3d &v) const
{
    return vector3d(
        _y*v.getZ() - _z*v.getY(),
        _z*v.getX() - _x*v.getZ(),
        _x*v.getY() - _y*v.getX()
    );
}

bool vector3d::sameDirection(const vector3d &v) const
{
    vector3d Diff = v - *this;
    vector3d vLarge = v.absqr()>this->absqr()?v:*this;

    if( fabs(Diff*vLarge)/vLarge.absqr() < 1. ) //divided b_y |v|
        return true;
    else
        return false;
}


float vector3d::theta360(const vector3d &v) const
{
    float phi =cross(v)/sqrt(absqr()*v.absqr());
    if(phi>1.) phi = 1.;
    else if(phi<-1.) phi = -1.;

    phi = asin(phi);
    if(sameDirection(v))
    {
        if(phi>0)
            return phi;
        else
            return 2*M_PI + phi;
    }
    else
        return M_PI - phi;

}
float vector3d::theta180(const vector3d &v) const
{
    float phi =cross(v)/sqrt(absqr()*v.absqr());
    if(phi>1.) phi = 1.;
    else if(phi<-1.) phi = -1.;

    phi = asin(phi);
    if(sameDirection(v))
    {
        return fabs(phi);
    }
    else
        return M_PI - fabs(phi);

}

void vector3d::setRPhiTheta(float r, float phi, float theta)
{
    _x= r*cos(phi)*sin(theta);
    _y= r*sin(phi)*sin(theta);
    _z= r*cos(theta);
}
