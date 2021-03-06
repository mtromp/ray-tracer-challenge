#ifndef TUPLE_H
#define TUPLE_H

namespace raytracer
{
class tuple
{
public:
    tuple(float xVal, float yVal, float zVal, float wVal);
    tuple(const tuple& oldTuple);

    bool isPoint();
    bool isVector();

    bool operator==(const tuple& rhs) const;
    tuple operator+(const tuple& rhs) const;

    tuple operator-(const tuple& rhs) const;
    tuple operator-() const;
    tuple operator*(float value) const;
    tuple operator/(float value) const;
    virtual void operator=(const tuple& rhs);

    float x, y, z, w;

private:
    bool equal(const float a, const float b) const;
};

class vector;
class point
{
public:
    point(float xVal, float yVal, float zVal);

    const tuple getTuple() const;

    bool operator==(const point& rhs) const;
    vector operator-(const point &rhsPoint) const;
    point operator-(const vector &rhsVector) const;
    point operator+(const vector &rhsVector) const;


private:
    tuple innerTuple;

};

class vector
{
public:
    vector(float xVal, float yVal, float zVal);

    const tuple getTuple() const;

    bool operator==(const vector& rhs) const;
    point operator-(const point &rhs) const;
    vector operator-(const vector &rhs) const;
    vector operator+(const vector &rhs) const;
    vector operator*(const float rhs);

    float magnitude() const;
    vector normalize() const;
    float dot(const vector &rhs) const;
    vector cross(const vector &rhs) const;

private:
    tuple innerTuple;

};

}

#endif // TUPLE_H
