#ifndef TUPLES_H
#define TUPLES_H


class tuples
{
public:
    tuples(float xVal, float yVal, float zVal, float wVal);
    float xAxis() const;
    float yAxis() const;
    float zAxis() const;
    float wAxis() const;

    bool isPoint();
    bool isVector();

    bool operator==(const tuples &rhs);
private:
    bool equal(const float a, const float b);
    float x, y, z, w;
};

#endif // TUPLES_H
