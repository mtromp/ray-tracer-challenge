#include "tuple.h"

#include <cmath>

using namespace raytracer;

tuple::tuple(float xVal, float yVal, float zVal, float wVal) : x(xVal), y(yVal),z(zVal),w(wVal)
{

}
float tuple::xAxis() const
{
    return this->x;
}
float tuple::yAxis() const
{
    return this->y;
}
float tuple::zAxis() const
{
    return this->z;
}
float tuple::wAxis() const
{
    return this->w;
}

bool tuple::isPoint()
{
    return (this->w > 0.0);
}

bool tuple::isVector()
{
    return (this->w < 1.0);
}

bool tuple::operator==(const tuple &rhs)
{
    if (! equal(this->wAxis(),rhs.wAxis()))
    {
        return false;
    }
    if (! equal(this->xAxis(),rhs.xAxis()))
    {
        return false;
    }
    if (! equal(this->yAxis(),rhs.yAxis()))
    {
        return false;
    }
    if (! equal(this->zAxis(),rhs.zAxis()))
    {
        return false;
    }

    return true;
}

tuple tuple::operator+(const tuple &rhs)
{
    return tuple(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

tuple tuple::operator-(const tuple& rhs)
{
    return tuple(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
}

bool tuple::equal(const float a, const float b)
{
    const float epsilon = 0.00001;
    if ( abs(a - b) < epsilon)
    {
        return true;
    } else {
        return false;
    }
}
