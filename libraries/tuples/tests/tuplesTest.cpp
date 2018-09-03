#include "tuples.h"
#include "point.h"
#include "vector.h"

#include <gtest/gtest.h>

using namespace testing;

class TuplesTest : public Test
{
protected:
    TuplesTest() : expectedX(4.3)
                  ,expectedY(-4.2)
                  ,expectedZ(3.1)
                  ,wPoint(1.0)
                  ,wVector(0.0)
                  ,delta(0.00001)
                  ,aPoint(expectedX,expectedY,expectedZ,wPoint)
                  ,aVector(expectedX,expectedY,expectedZ,wVector)
    {

    }
    ~TuplesTest() {}

    float expectedX, expectedY, expectedZ, wPoint, wVector, delta;
    tuples aPoint;
    tuples aVector;
};

TEST_F(TuplesTest, PointTupleHasExpectedX)
{
    EXPECT_NEAR(expectedX, aPoint.xAxis(), delta);
}
TEST_F(TuplesTest, PointTupleHasExpectedY)
{
    EXPECT_NEAR(expectedY, aPoint.yAxis(), delta);
}
TEST_F(TuplesTest, PointTupleHasExpectedZ)
{
    EXPECT_NEAR(expectedZ, aPoint.zAxis(), delta);
}
TEST_F(TuplesTest, PointTupleHasExpectedW)
{
    EXPECT_NEAR(wPoint, aPoint.wAxis(), delta);
}
TEST_F(TuplesTest, PointTupleIsAPoint)
{
    EXPECT_TRUE(aPoint.isPoint());
}
TEST_F(TuplesTest, PointTupleIsNotAVector)
{
    EXPECT_FALSE(aPoint.isVector());
}
// Vector tests
TEST_F(TuplesTest, VectorTupleHasExpectedX)
{
    EXPECT_NEAR(expectedX, aVector.xAxis(), delta);
}
TEST_F(TuplesTest, VectorTupleHasExpectedY)
{
    EXPECT_NEAR(expectedY, aVector.yAxis(), delta);
}
TEST_F(TuplesTest, VectorTupleHasExpectedZ)
{
    EXPECT_NEAR(expectedZ, aVector.zAxis(), delta);
}
TEST_F(TuplesTest, VectorTupleHasExpectedW)
{
    EXPECT_NEAR(wVector, aVector.wAxis(), delta);
}
TEST_F(TuplesTest, VectorTupleIsNotAPoint)
{
    EXPECT_FALSE(aVector.isPoint());
}
TEST_F(TuplesTest, VectorTupleIsAVector)
{
    EXPECT_TRUE(aVector.isVector());
}
TEST_F(TuplesTest, PointCreatesAPoint)
{
    point p(expectedX, expectedY, expectedZ);
    EXPECT_TRUE(p.isPoint());
    EXPECT_NEAR(wPoint, p.wAxis(), delta);
}
TEST_F(TuplesTest, VectorCreatesAVector)
{
    vector v(expectedX, expectedY, expectedZ);
    EXPECT_TRUE(v.isVector());
    EXPECT_NEAR(wVector, v.wAxis(), delta);
}
TEST_F(TuplesTest, ComparingTupleToItselfYieldsEqual)
{
    EXPECT_TRUE(aPoint == aPoint);
}
TEST_F(TuplesTest, ComparingTupleToOtherYieldsNotEqual)
{
    EXPECT_FALSE(aPoint == aVector);
}
