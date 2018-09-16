#include "point.h"
#include "vector.h"

using namespace raytracer;

point::point(float xVal, float yVal, float zVal)
            : innerTuple(xVal,yVal,zVal,1.0)
{
}

const tuple& point::getTuple() const
{
    return innerTuple;
}

bool point::operator==(const point &rhs) const
{
    return (this->innerTuple == rhs.innerTuple);
}

vector* point::operator-(const point& rhsPoint) const
{
    return new vector(this->innerTuple.x - rhsPoint.innerTuple.x
                      , this->innerTuple.y - rhsPoint.innerTuple.y
                      , this->innerTuple.z - rhsPoint.innerTuple.z
                     );
}

point* point::operator-(const vector& rhsVector) const
{
    tuple tmp = rhsVector.getTuple();
    return new point(this->innerTuple.x - tmp.x
                      , this->innerTuple.y - tmp.y
                      , this->innerTuple.z - tmp.z
                     );
}

