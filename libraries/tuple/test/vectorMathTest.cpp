#include "tuple.h"

#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

//===============
// vector_state must be copyable: have a copy constructor??
class vector_state
{
public:
    float x;
    float y;
    float z;
    float magnitude;
    vector_state(float paramX, float paramY, float paramZ, float paramMagnitude)
        : x(paramX)
        , y(paramY)
        , z(paramZ)
        , magnitude(paramMagnitude)
    {}
    vector_state(const vector_state &rhs)
        : x(rhs.x)
        , y(rhs.y)
        , z(rhs.z)
        , magnitude(rhs.magnitude)
    {}
};


class VectorMathFixture : public ::testing::TestWithParam<vector_state>
{
public:
    VectorMathFixture()
    {
        vector_state vectorState = GetParam();
        paramVector = new raytracer::vector(vectorState.x, vectorState.y, vectorState.z);
    }
    virtual ~VectorMathFixture()
    {
        delete paramVector;
    }

    raytracer::vector* paramVector;
};

INSTANTIATE_TEST_CASE_P(default, VectorMathFixture,
                        ::testing::Values(
                              vector_state(1.0, 0.0, 0.0, 1.0)
                            , vector_state(0.0, 1.0, 0.0, 1.0)
                            , vector_state(0.0, 0.0, 1.0, 1.0)
                            , vector_state(1.0, 2.0, 3.0, sqrt(14.0))
                            , vector_state(-1.0, -2.0, -3.0, sqrt(14.0))
                            , vector_state(3.0, 1.0, 2.0, sqrt(14.0))
                            , vector_state(-3.0, -1.0, -2.0, sqrt(14.0))
                        ));

TEST_P(VectorMathFixture, MagnitudeOfVector)
{
    EXPECT_TRUE(GetParam().magnitude == paramVector->magnitude());
}
