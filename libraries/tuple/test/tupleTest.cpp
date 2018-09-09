#include "tuple.h"
#include "point.h"
#include "vector.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class TupleTest : public Test
{
protected:
    TupleTest() : expectedX(4.3)
                  ,expectedY(-4.2)
                  ,expectedZ(3.1)
                  ,wPoint(1.0)
                  ,wVector(0.0)
                  ,delta(0.00001)
                  ,aPoint(expectedX,expectedY,expectedZ,wPoint)
                  ,aVector(expectedX,expectedY,expectedZ,wVector)
    {

    }
    ~TupleTest() {}

    float expectedX, expectedY, expectedZ, wPoint, wVector, delta;
    raytracer::tuple aPoint;
    raytracer::tuple aVector;
};

TEST_F(TupleTest, PointTupleHasExpectedX)
{
    EXPECT_NEAR(expectedX, aPoint.xAxis(), delta);
}
TEST_F(TupleTest, PointTupleHasExpectedY)
{
    EXPECT_NEAR(expectedY, aPoint.yAxis(), delta);
}
TEST_F(TupleTest, PointTupleHasExpectedZ)
{
    EXPECT_NEAR(expectedZ, aPoint.zAxis(), delta);
}
TEST_F(TupleTest, PointTupleHasExpectedW)
{
    EXPECT_NEAR(wPoint, aPoint.wAxis(), delta);
}
TEST_F(TupleTest, PointTupleIsAPoint)
{
    EXPECT_TRUE(aPoint.isPoint());
}
TEST_F(TupleTest, PointTupleIsNotAVector)
{
    EXPECT_FALSE(aPoint.isVector());
}
// Vector tests
TEST_F(TupleTest, VectorTupleHasExpectedX)
{
    EXPECT_NEAR(expectedX, aVector.xAxis(), delta);
}
TEST_F(TupleTest, VectorTupleHasExpectedY)
{
    EXPECT_NEAR(expectedY, aVector.yAxis(), delta);
}
TEST_F(TupleTest, VectorTupleHasExpectedZ)
{
    EXPECT_NEAR(expectedZ, aVector.zAxis(), delta);
}
TEST_F(TupleTest, VectorTupleHasExpectedW)
{
    EXPECT_NEAR(wVector, aVector.wAxis(), delta);
}
TEST_F(TupleTest, VectorTupleIsNotAPoint)
{
    EXPECT_FALSE(aVector.isPoint());
}
TEST_F(TupleTest, VectorTupleIsAVector)
{
    EXPECT_TRUE(aVector.isVector());
}
TEST_F(TupleTest, PointCreatesAPoint)
{
    raytracer::point p(expectedX, expectedY, expectedZ);
    EXPECT_TRUE(p.isPoint());
    EXPECT_NEAR(wPoint, p.wAxis(), delta);
}
TEST_F(TupleTest, VectorCreatesAVector)
{
    raytracer::vector v(expectedX, expectedY, expectedZ);
    EXPECT_TRUE(v.isVector());
    EXPECT_NEAR(wVector, v.wAxis(), delta);
}
TEST_F(TupleTest, ComparingTupleToItselfYieldsEqual)
{
    EXPECT_TRUE(aPoint == aPoint);
}
TEST_F(TupleTest, ComparingTupleToOtherYieldsNotEqual)
{
    EXPECT_FALSE(aPoint == aVector);
}
