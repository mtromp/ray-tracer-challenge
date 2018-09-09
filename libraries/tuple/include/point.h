#ifndef POINT_H
#define POINT_H

#include "tuple.h"
#include "vector.h"

namespace raytracer
{
class point : public tuple
{
public:
    point(float xVal, float yVal, float zVal);

    vector operator-(const point &rhs);

};
}

#endif // POINT_H
