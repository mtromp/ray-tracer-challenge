#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

namespace raytracer
{
class color : public raytracer::tuple
{
public:
    color(float red, float green, float blue);

    float getRed() const;
    float getGreen() const;
    float getBlue() const;

};
} //namespace raytracer
#endif // COLOR_H
