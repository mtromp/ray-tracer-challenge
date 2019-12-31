#include "matrix.h"

using namespace raytracer;

matrix::matrix(int size) : size(size)
{
    this->theMatrix = new float*[this->size];
    for (int i=0; i<this->size; ++i)
    {
        this->theMatrix[i] = new float[this->size];
    }
    // initialize values to 0.0
    float value = 0.0;
    for (int i=0; i < this->size; ++i)
    {
        for (int j=0; j < this->size; ++j)
        {
            this->theMatrix[i][j] = value;
        }
    }
}
matrix::matrix(float ** values, int size) : size(size)
{
    this->theMatrix = new float*[this->size];
    for (int i=0; i<this->size; ++i)
    {
        this->theMatrix[i] = new float[this->size];
    }

    for (int i=0; i < this->size; ++i)
    {
        for (int j=0; j < this->size; ++j)
        {
            this->theMatrix[i][j] = values[i][j];
        }
    }
}

matrix::~matrix()
{
    for (int i=0; i<this->size; ++i)
    {
        delete [] this->theMatrix[i];
    }
    delete [] this->theMatrix;

}

float matrix::getValue(int i, int j) const
{
    return this->theMatrix[i][j];
}

int matrix::getSize() const
{
    return this->size;
}

bool matrix::operator ==(const matrix& rhs) const
{
    bool returnValue = false;


    return returnValue;
}
