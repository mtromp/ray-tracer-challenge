#include "point.h"

using namespace raytracer;

point::point(float xVal, float yVal, float zVal) : tuple(xVal,yVal,zVal,1.0)
{
}

vector point::operator-(const point& rhs)
{
    return vector(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

