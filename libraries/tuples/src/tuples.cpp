#include "tuples.h"

#include <cmath>

tuples::tuples(float xVal, float yVal, float zVal, float wVal) : x(xVal), y(yVal),z(zVal),w(wVal)
{

}
float tuples::xAxis() const
{
    return this->x;
}
float tuples::yAxis() const
{
    return this->y;
}
float tuples::zAxis() const
{
    return this->z;
}
float tuples::wAxis() const
{
    return this->w;
}

bool tuples::isPoint()
{
    return (this->w > 0.0);
}

bool tuples::isVector()
{
    return (this->w < 1.0);
}

bool tuples::operator==(const tuples &rhs)
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

bool tuples::equal(const float a, const float b)
{
    const float epsilon = 0.00001;
    if ( abs(a - b) < epsilon)
    {
        return true;
    } else {
        return false;
    }
}
