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

color color::operator*(float value) const
{
    return color(this->x * value, this->y * value, this->z * value);
}
// hadamard product
color color::operator*(const color& rhs) const
{
    return color(this->x * rhs.x
                ,this->y * rhs.y
                ,this->z * rhs.z
                );
}
