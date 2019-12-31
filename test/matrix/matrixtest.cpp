#include "matrix.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

float matrix4by4[4][4] =
{
    { 1.0,  2.0,  3.0,  4.0},
    { 5.5,  6.5,  7.5,  8.5},
    { 9.0, 10.0, 11.0, 12.0},
    {13.5, 14.5, 15.5, 16.5}
};

float matrix2by2[2][2] =
{
    {-3.0, 5.0},
    { 1.0,-2.0}
};

float matrix3by3[3][3] =
{
    {-3.0, 5.0, 0.0},
    { 1.0,-2.0, 7.0},
    { 0.0, 1.0, 1.0}
};


class MatrixTest : public Test
{

protected:
    MatrixTest() : expected2Size(2)
                 , expected3Size(3)
                 , expected4Size(4)
    {
        init2by2();
        init3by3();
        init4by4();
    }
    ~MatrixTest()
    {
        delete2by2();
        delete3by3();
        delete4by4();
    }

    int expected2Size, expected3Size, expected4Size;

    float **expected2by2;
    float **expected3by3;
    float **expected4by4;

private:
    void init2by2()
    {
        this->expected2by2 = new float*[this->expected2Size];
        for (int i=0; i< this->expected2Size; ++i)
        {
            this->expected2by2[i] = new float[this->expected2Size];
            for (int j=0; j < this->expected2Size; ++j)
            {
                this->expected2by2[i][j] = matrix2by2[i][j];
            }
        }
    }
    void init3by3()
    {
        this->expected3by3 = new float*[this->expected3Size];
        for (int i=0; i< this->expected3Size; ++i)
        {
            this->expected3by3[i] = new float[this->expected3Size];
            for (int j=0; j < this->expected3Size; ++j)
            {
                this->expected3by3[i][j] = matrix3by3[i][j];
            }
        }
    }
    void init4by4()
    {
        this->expected4by4 = new float*[this->expected4Size];
        for (int i=0; i< this->expected4Size; ++i)
        {
            this->expected4by4[i] = new float[this->expected4Size];
            for (int j=0; j < this->expected4Size; ++j)
            {
                this->expected4by4[i][j] = matrix4by4[i][j];
            }
        }
    }
    void delete2by2()
    {
        for (int i=0; i< this->expected2Size; ++i)
        {
            delete [] this->expected2by2[i];
        }
        delete [] this->expected2by2;
    }
    void delete3by3()
    {
        for (int i=0; i< this->expected3Size; ++i)
        {
            delete [] this->expected3by3[i];
        }
        delete [] this->expected3by3;
    }
    void delete4by4()
    {
        for (int i=0; i< this->expected4Size; ++i)
        {
            delete [] this->expected4by4[i];
        }
        delete this->expected4by4;
    }

};

TEST_F(MatrixTest, Initialize4by4Matrix)
{
    raytracer::matrix actualMatrix(this->expected4by4, this->expected4Size);

    EXPECT_EQ(1.0, actualMatrix.getValue(0,0));
    EXPECT_EQ(6.5, actualMatrix.getValue(1,1));
}

TEST_F(MatrixTest, Initialize2by2Matrix)
{
    raytracer::matrix actualMatrix(this->expected2by2, this->expected2Size);

    EXPECT_EQ(-3.0, actualMatrix.getValue(0,0));
    EXPECT_EQ(-2.0, actualMatrix.getValue(1,1));
}

TEST_F(MatrixTest, Initialize3by3Matrix)
{
    raytracer::matrix actualMatrix(this->expected3by3, this->expected3Size);

    EXPECT_EQ(5.0, actualMatrix.getValue(0,1));
    EXPECT_EQ(7.0, actualMatrix.getValue(1,2));
}

TEST_F(MatrixTest, SizeOf3by3MatrixIs3)
{
    raytracer::matrix actualMatrix(this->expected3by3, this->expected3Size);

    EXPECT_EQ(this->expected3Size, actualMatrix.getSize());

}
TEST_F(MatrixTest, SizeOf2by2MatrixIs2)
{
    raytracer::matrix actualMatrix(this->expected2by2, this->expected2Size);

    EXPECT_EQ(this->expected2Size, actualMatrix.getSize());

}
TEST_F(MatrixTest, MatrixIsEqualWhenSameSizeAndValuesAreCompared)
{
    raytracer::matrix actualMatrix(this->expected4by4, this->expected4Size);
    raytracer::matrix otherMatrix(this->expected4by4, this->expected4Size);
    EXPECT_TRUE(actualMatrix == otherMatrix);
}
