#include "tuples.h"

tuples::tuples(float xVal, float yVal, float zVal, float wVal) : x(xVal), y(yVal),z(zVal),w(wVal)
{

}
float tuples::xAxis()
{
    return this->x;
}
float tuples::yAxis()
{
    return this->y;
}
float tuples::zAxis()
{
    return this->z;
}
float tuples::wAxis()
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
