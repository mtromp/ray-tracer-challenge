#ifndef TUPLE_H
#define TUPLE_H

namespace raytracer
{
class tuple
{
public:
    tuple(float xVal, float yVal, float zVal, float wVal);

    bool isPoint();
    bool isVector();

    bool operator==(const tuple& rhs) const;
    tuple* operator+(const tuple& rhs) const;

    tuple* operator-(const tuple& rhs) const;

    float x, y, z, w;

private:
    bool equal(const float a, const float b) const;
};
}

#endif // TUPLE_H
