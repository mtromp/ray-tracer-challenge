#include "tuple.h"

#include <cmath>

using namespace raytracer;

tuple::tuple(float xVal, float yVal, float zVal, float wVal) : x(xVal), y(yVal),z(zVal),w(wVal)
{
}

tuple::tuple(const tuple& oldTuple): x(oldTuple.x)
                                   , y(oldTuple.y)
                                   , z(oldTuple.z)
                                   , w(oldTuple.w)
{
}

void tuple::operator=(const tuple& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    this->w = rhs.w;
}

bool tuple::isPoint()
{
    return (this->w > 0.0);
}

bool tuple::isVector()
{
    return (this->w < 1.0);
}

bool tuple::operator==(const tuple &rhs) const
{
    return equal(this->w,rhs.w)
            && equal(this->x,rhs.x)
            && equal(this->y,rhs.y)
            && equal(this->z,rhs.z);
}

tuple tuple::operator+(const tuple &rhs) const
{
    return tuple(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

tuple tuple::operator-(const tuple& rhs) const
{
    return tuple(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
}

tuple tuple::operator-() const
{
    return tuple(-this->x, -this->y, -this->z, -this->w);
}

tuple tuple::operator*(float value) const
{
    return tuple(this->x * value, this->y * value, this->z * value, this->w * value);
}

tuple tuple::operator/(float value) const
{
    return tuple(this->x / value, this->y / value, this->z / value, this->w / value);
}

bool tuple::equal(const float a, const float b) const
{
    const float epsilon = 0.00001;
    if ( abs(a - b) < epsilon)
    {
        return true;
    } else {
        return false;
    }
}

point::point(float xVal, float yVal, float zVal)
            : innerTuple(xVal,yVal,zVal,1.0)
{
}

const tuple point::getTuple() const
{
    return innerTuple;
}

bool point::operator==(const point &rhs) const
{
    return (this->innerTuple == rhs.innerTuple);
}

vector point::operator-(const point& rhsPoint) const
{
    return vector(this->innerTuple.x - rhsPoint.innerTuple.x
                      , this->innerTuple.y - rhsPoint.innerTuple.y
                      , this->innerTuple.z - rhsPoint.innerTuple.z
                     );
}

point point::operator-(const vector& rhsVector) const
{
    tuple tmp = rhsVector.getTuple();
    return point(this->innerTuple.x - tmp.x
                      , this->innerTuple.y - tmp.y
                      , this->innerTuple.z - tmp.z
                     );
}

point point::operator+(const vector& rhsVector) const
{
    tuple tmp = rhsVector.getTuple();
    return point(this->innerTuple.x + tmp.x
                      , this->innerTuple.y + tmp.y
                      , this->innerTuple.z + tmp.z
                     );
}

vector::vector(float xVal, float yVal, float zVal) : innerTuple(xVal,yVal,zVal,0.0)
{
}

const tuple vector::getTuple() const
{
    return innerTuple;
}

bool vector::operator==(const vector &rhs) const
{
    return (this->innerTuple == rhs.innerTuple);
}

point vector::operator-(const point& rhs) const
{
    const tuple& tmp = rhs.getTuple();
    return point(this->innerTuple.x - tmp.x
                     , this->innerTuple.y - tmp.y
                     , this->innerTuple.z - tmp.z
                     );
}

vector vector::operator-(const vector& rhs) const
{
    const tuple& tmp = rhs.getTuple();
    return vector(this->innerTuple.x - tmp.x
                     , this->innerTuple.y - tmp.y
                     , this->innerTuple.z - tmp.z
                     );
}

vector vector::operator+(const vector& rhs) const
{
    const tuple& tmp = rhs.getTuple();
    return vector(this->innerTuple.x + tmp.x
                     , this->innerTuple.y + tmp.y
                     , this->innerTuple.z + tmp.z
                     );
}

vector vector::operator*(const float rhs)
{
    return vector(this->innerTuple.x * rhs
                  , this->innerTuple.y * rhs
                  , this->innerTuple.z * rhs
                  );
}

float vector::magnitude() const
{
    return sqrt(pow(this->innerTuple.x,2) + pow(this->innerTuple.y,2) + pow(this->innerTuple.z,2));
}

vector vector::normalize() const
{
    float magnitude = this->magnitude();
    return vector(this->innerTuple.x / magnitude,
                  this->innerTuple.y / magnitude,
                  this->innerTuple.z / magnitude
                 );
}

float vector::dot(const vector& rhs) const
{
    float result =   this->innerTuple.x * rhs.innerTuple.x
                   + this->innerTuple.y * rhs.innerTuple.y
                   + this->innerTuple.z * rhs.innerTuple.z
                   ;
    return result;
}

vector vector::cross(const vector &rhs) const
{
    float a_x = this->innerTuple.x;
    float a_y = this->innerTuple.y;
    float a_z = this->innerTuple.z;
    float b_x = rhs.innerTuple.x;
    float b_y = rhs.innerTuple.y;
    float b_z = rhs.innerTuple.z;

    return vector( a_y*b_z - a_z*b_y
                 , a_z*b_x - a_x*b_z
                 , a_x*b_y - a_y*b_x
                 );
}
