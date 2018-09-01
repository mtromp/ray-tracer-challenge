#include "tuples.h"
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
    {

    }
    ~TuplesTest() {}

    float expectedX, expectedY, expectedZ, wPoint, wVector, delta;
    tuples aPoint;
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
