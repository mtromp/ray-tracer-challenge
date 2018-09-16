#include "vector.h"
#include "point.h"

using namespace raytracer;

vector::vector(float xVal, float yVal, float zVal) : innerTuple(xVal,yVal,zVal,0.0)
{
}

const tuple& vector::getTuple() const
{
    return innerTuple;
}

bool vector::operator==(const vector &rhs) const
{
    return (this->innerTuple == rhs.innerTuple);
}

point* vector::operator-(const point& rhs) const
{
    const tuple& tmp = rhs.getTuple();
    return new point(this->innerTuple.x - tmp.x
                     , this->innerTuple.y - tmp.y
                     , this->innerTuple.z - tmp.z
                     );
}

