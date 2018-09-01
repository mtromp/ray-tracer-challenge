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
    {

    }
    ~TuplesTest() {}

    float expectedX, expectedY, expectedZ, wPoint, wVector, delta;
};

TEST_F(TuplesTest, TupleWithwEqualOneisPoint)
{
    tuples a(expectedX, expectedY, expectedZ, wPoint);
    EXPECT_NEAR(expectedX, a.xAxis(), delta);
    EXPECT_NEAR(expectedY, a.yAxis(), delta);
    EXPECT_NEAR(expectedZ, a.zAxis(), delta);
    EXPECT_NEAR(wPoint, a.wAxis(), delta);

    EXPECT_TRUE(a.isPoint());
    EXPECT_FALSE(a.isVector());
}
