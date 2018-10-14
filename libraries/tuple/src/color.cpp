#include "color.h"

using namespace raytracer;

color::color(float red, float green, float blue) : tuple(red, green, blue, 0.0)
{

}

float color::getRed() const
{
    return this->x;
}

float color::getGreen() const
{
    return this->y;
}

float color::getBlue() const
{
    return this->z;
}
