#ifndef TUPLES_H
#define TUPLES_H


class tuples
{
public:
    tuples(float xVal, float yVal, float zVal, float wVal);
    float xAxis();
    float yAxis();
    float zAxis();
    float wAxis();

    bool isPoint();
    bool isVector();

private:
    float x, y, z, w;
};

#endif // TUPLES_H
