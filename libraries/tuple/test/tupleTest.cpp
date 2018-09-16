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
    EXPECT_NEAR(expectedX, aPoint.x, delta);
}
TEST_F(TupleTest, PointTupleHasExpectedY)
{
    EXPECT_NEAR(expectedY, aPoint.y, delta);
}
TEST_F(TupleTest, PointTupleHasExpectedZ)
{
    EXPECT_NEAR(expectedZ, aPoint.z, delta);
}
TEST_F(TupleTest, PointTupleHasExpectedW)
{
    EXPECT_NEAR(wPoint, aPoint.w, delta);
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
    EXPECT_NEAR(expectedX, aVector.x, delta);
}
TEST_F(TupleTest, VectorTupleHasExpectedY)
{
    EXPECT_NEAR(expectedY, aVector.y, delta);
}
TEST_F(TupleTest, VectorTupleHasExpectedZ)
{
    EXPECT_NEAR(expectedZ, aVector.z, delta);
}
TEST_F(TupleTest, VectorTupleHasExpectedW)
{
    EXPECT_NEAR(wVector, aVector.w, delta);
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
    raytracer::tuple t = p.getTuple();
    EXPECT_TRUE(t.isPoint());
    EXPECT_NEAR(wPoint, t.w, delta);
}
TEST_F(TupleTest, VectorCreatesAVector)
{
    raytracer::vector v(expectedX, expectedY, expectedZ);
    raytracer::tuple t = v.getTuple();
    EXPECT_TRUE(t.isVector());
    EXPECT_NEAR(wVector, t.w, delta);
}
TEST_F(TupleTest, ComparingTupleToItselfYieldsEqual)
{
    EXPECT_TRUE(aPoint == aPoint);
}
TEST_F(TupleTest, ComparingTupleToOtherYieldsNotEqual)
{
    EXPECT_FALSE(aPoint == aVector);
}
