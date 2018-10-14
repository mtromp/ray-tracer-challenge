#include "color.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class ColorTest : public Test
{
protected:
    ColorTest() : expectedRed(-0.5)
                , expectedGreen(0.4)
                , expectedBlue(1.7)
                , delta(0.00001)
                , aColor(expectedRed, expectedGreen, expectedBlue)
    {

    }
    float expectedRed, expectedGreen, expectedBlue, delta;
    raytracer::color aColor;
};

TEST_F(ColorTest, ColorHasExpectedRedValue)
{
    EXPECT_NEAR(expectedRed, aColor.getRed(), delta);
}

TEST_F(ColorTest, ColorHasExpectedGreenValue)
{
    EXPECT_NEAR(expectedGreen, aColor.getGreen(), delta);
}

TEST_F(ColorTest, ColorHasExpectedBlueValue)
{
    EXPECT_NEAR(expectedBlue, aColor.getBlue(), delta);
}
