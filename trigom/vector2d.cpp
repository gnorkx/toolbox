
#include"vector2d.h"

vector2d vector2d::operator +(const vector2d& rhs) const
{
  return vector2d(_x+rhs.getX(), _y+rhs.getY());
}

vector2d vector2d::operator -(const vector2d& rhs) const
{
  return vector2d(_x-rhs.getX(), _y-rhs.getY());
}

vector2d& vector2d::operator +=(const vector2d& rhs)
{
  _x += rhs.getX();
  _y += rhs.getY();
  return *this;
}
vector2d& vector2d::operator -=(const vector2d& rhs)
{
  _x -= rhs.getX();
  _y -= rhs.getY();
  return *this;
}
float vector2d::operator* (const vector2d& rhs) const
{
   return _x*rhs.getX() + _y*rhs.getY();
}

void vector2d::swap(vector2d& c2)
{
    vector2d tmp(*this);
    *this = c2;
    c2 = tmp;


}

std::ostream& operator << (std::ostream& os, const vector2d& co)
{
  os<<"("<<co.getX()<<", "<<co.getY()<<")";
  return os;
}

//non class member functions


vector2d operator* (const float& a , const vector2d& rhs)
{
  return vector2d(a*rhs.getX(), a*rhs.getY());
};


void vector2d::rotateRad(float alpha)
{
    float _x1 = cos(alpha)*_x + sin(alpha)*_y;
    float _y1 = cos(alpha)*_y - sin(alpha)*_x;
    _x= _x1; _y= _y1;

}

vector2d vector2d::perp() const
{
    return vector2d(_y,-_x);
}

bool vector2d::sameDirection(const vector2d &v) const
{
    vector2d Diff = v - *this;
    vector2d vLarge = v.absqr()>this->absqr()?v:*this;

    if( fabs(Diff*vLarge)/vLarge.absqr() < 1. ) //divided b_y |v|
        return true;
    else
        return false;
}


float vector2d::theta360(const vector2d &v) const
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
float vector2d::theta180(const vector2d &v) const
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

void vector2d::setRPhi(float r, float phi)
{
    _x= r*cos(phi);
    _y= r*sin(phi);
}
