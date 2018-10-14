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

TEST(ColorMath, AddingColorsGivesExpectedResult)
{
    raytracer::color c1(0.9, 0.6, 0.75);
    raytracer::color c2(0.7, 0.1, 0.25);
    raytracer::color expectedColor(1.6, 0.7, 1.0);

    EXPECT_TRUE(expectedColor == (c1 + c2));
}

TEST(ColorMath, SubtractingColorsGivesExpectedResult)
{
    raytracer::color c1(0.9, 0.6, 0.75);
    raytracer::color c2(0.7, 0.1, 0.25);
    raytracer::color expectedColor(0.2, 0.5, 0.5);

    EXPECT_TRUE(expectedColor == (c1 - c2));
}

TEST(ColorMath, MultiplyColorByScalar)
{
    raytracer::color c1(0.2, 0.3, 0.4);

    raytracer::color expectedColor(0.4, 0.6, 0.8);

    EXPECT_TRUE(expectedColor == (c1 * 2.0));
}

TEST(ColorMath, MultiplyingColorsGivesExpectedResult)
{
    raytracer::color c1(1.0, 0.2, 0.4);
    raytracer::color c2(0.9, 1.0, 0.1);
    raytracer::color expectedColor(0.9, 0.2, 0.04);

    EXPECT_TRUE(expectedColor == (c1 * c2));
}
