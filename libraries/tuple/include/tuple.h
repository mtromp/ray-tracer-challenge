#ifndef TUPLE_H
#define TUPLE_H

namespace raytracer
{
class tuple
{
public:
    tuple(float xVal, float yVal, float zVal, float wVal);
    float xAxis() const;
    float yAxis() const;
    float zAxis() const;
    float wAxis() const;

    bool isPoint();
    bool isVector();

    virtual bool operator==(const tuple& rhs);
    virtual tuple operator+(const tuple& rhs);

protected:
    virtual tuple operator-(const tuple& rhs);

    bool equal(const float a, const float b);
    float x, y, z, w;
};
}

#endif // TUPLE_H
