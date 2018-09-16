#ifndef VECTOR_H
#define VECTOR_H

#include "tuple.h"

namespace raytracer
{
class point;
class vector
{
public:
    vector(float xVal, float yVal, float zVal);

    const tuple& getTuple() const;

    bool operator==(const vector& rhs) const;
    point* operator-(const point &rhs) const;
    vector* operator-(const vector &rhs) const;

private:
    tuple innerTuple;

};
}

#endif // VECTOR_H
