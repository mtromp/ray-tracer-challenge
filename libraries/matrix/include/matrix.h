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
    int getSize() const;
    bool operator==(const matrix& rhs) const;


private:
    int size;
    float **theMatrix;

    bool equal(const float a, const float b) const;
};

}

#endif // MATRIX_H