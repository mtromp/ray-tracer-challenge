#ifndef MATRIX_H
#define MATRIX_H

namespace raytracer
{
class matrix
{
public:
    matrix(int size);
    matrix(float ** values, int size);
    ~matrix();

    float getValue(int i, int j) const;


private:
    int size;
    float **theMatrix;
};

}

#endif // MATRIX_H
