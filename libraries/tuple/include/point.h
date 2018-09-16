#ifndef POINT_H
#define POINT_H

#include "tuple.h"

namespace raytracer
{
class vector;

class point
{
public:
    point(float xVal, float yVal, float zVal);

    const tuple& getTuple() const;

    bool operator==(const point& rhs) const;
    vector* operator-(const point &rhsPoint) const;
    point* operator-(const vector &rhsVector) const;


private:
    tuple innerTuple;

};
}

#endif // POINT_H
