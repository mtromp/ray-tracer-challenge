#include "tuple.h"

#include <cmath>

using namespace raytracer;

tuple::tuple(float xVal, float yVal, float zVal, float wVal) : x(xVal), y(yVal),z(zVal),w(wVal)
{

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

tuple* tuple::operator+(const tuple &rhs) const
{
    return new tuple(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

tuple* tuple::operator-(const tuple& rhs) const
{
    return new tuple(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
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
