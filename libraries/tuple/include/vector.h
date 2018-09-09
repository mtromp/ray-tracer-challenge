#ifndef VECTOR_H
#define VECTOR_H

#include "tuple.h"

namespace raytracer
{
class vector : public tuple
{
public:
    vector(float xVal, float yVal, float zVal);

};
}

#endif // VECTOR_H
