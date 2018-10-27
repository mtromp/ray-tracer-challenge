#include "tuple.h"

#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

//===============
// vector_state must be copyable: have a copy constructor!!
class vector_magnitude
{
public:
    float x;
    float y;
    float z;
    float magnitude;
    vector_magnitude(float paramX, float paramY, float paramZ, float paramMagnitude)
        : x(paramX)
        , y(paramY)
        , z(paramZ)
        , magnitude(paramMagnitude)
    {}
    vector_magnitude(const vector_magnitude &rhs)
        : x(rhs.x)
        , y(rhs.y)
        , z(rhs.z)
        , magnitude(rhs.magnitude)
    {}
};

class VectorMagnitudeFixture : public ::testing::TestWithParam<vector_magnitude>
{
public:
    VectorMagnitudeFixture()
    {
        vector_magnitude vectorState = GetParam();
        paramVector = new raytracer::vector(vectorState.x, vectorState.y, vectorState.z);
    }
    virtual ~VectorMagnitudeFixture()
    {
        delete paramVector;
    }

    raytracer::vector* paramVector;
};

INSTANTIATE_TEST_CASE_P(default, VectorMagnitudeFixture,
                        ::testing::Values(
                              vector_magnitude(1.0, 0.0, 0.0, 1.0)
                            , vector_magnitude(0.0, 1.0, 0.0, 1.0)
                            , vector_magnitude(0.0, 0.0, 1.0, 1.0)
                            , vector_magnitude(1.0, 2.0, 3.0, sqrt(14.0))
                            , vector_magnitude(-1.0, -2.0, -3.0, sqrt(14.0))
                            , vector_magnitude(3.0, 1.0, 2.0, sqrt(14.0))
                            , vector_magnitude(-3.0, -1.0, -2.0, sqrt(14.0))
                        ));

TEST_P(VectorMagnitudeFixture, MagnitudeOfVector)
{
    EXPECT_TRUE(GetParam().magnitude == paramVector->magnitude());
}

class vector_normal
{
public:
    float x;
    float y;
    float z;
    float normalizedX;
    float normalizedY;
    float normalizedZ;

    vector_normal(float paramX, float paramY, float paramZ, float paramNormalX, float paramNormalY, float paramNormalZ)
        : x(paramX)
        , y(paramY)
        , z(paramZ)
        , normalizedX(paramNormalX)
        , normalizedY(paramNormalY)
        , normalizedZ(paramNormalZ)
    {}
    vector_normal(const vector_normal &rhs)
        : x(rhs.x)
        , y(rhs.y)
        , z(rhs.z)
        , normalizedX(rhs.normalizedX)
        , normalizedY(rhs.normalizedY)
        , normalizedZ(rhs.normalizedZ)
    {}
};

class VectorNormalizeFixture : public ::testing::TestWithParam<vector_normal>
{
public:
    VectorNormalizeFixture()
    {
        vector_normal vectorNormal = GetParam();
        paramVector = new raytracer::vector(vectorNormal.x, vectorNormal.y, vectorNormal.z);
    }
    virtual ~VectorNormalizeFixture()
    {
        delete paramVector;
    }

    raytracer::vector* paramVector;
};

// What should happen when the vector is zero?? Divide by zero error. Is that OK?
INSTANTIATE_TEST_CASE_P(default, VectorNormalizeFixture,
                        ::testing::Values(
                              vector_normal(4.0, 0.0, 0.0, 1.0, 0.0, 0.0)
                            , vector_normal(0.0, 4.0, 0.0, 0.0, 1.0, 0.0)
                            , vector_normal(0.0, 0.0, 4.0, 0.0, 0.0, 1.0)
                            , vector_normal(1.0, 2.0, 3.0, 1.0 / sqrt(14.0), 2.0 / sqrt(14.0), 3.0 / sqrt(14.0))
                        ));

TEST_P(VectorNormalizeFixture, NormalOfVector)
{
    raytracer::vector resultVector(GetParam().normalizedX, GetParam().normalizedY, GetParam().normalizedZ);

    raytracer::vector normalizedVector = paramVector->normalize();
    EXPECT_TRUE(resultVector == normalizedVector);
    EXPECT_TRUE(0.00001 > abs(1.0 - normalizedVector.magnitude()));
}
